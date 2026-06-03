#!/usr/bin/env python3
"""
detect.py — Face identification script for the KiBub identify_face skill.

Uses DeepFace to compare the robot's camera frame (or a provided image) against
a local database of known faces stored in ~/.openclaw/workspace/known_faces/.

Usage:
    # Capture from camera (default device 0):
    python detect.py

    # Capture from a specific camera device:
    python detect.py --camera 2

    # Use an existing image file:
    python detect.py --image /path/to/photo.jpg

    # Use a custom faces database path:
    python detect.py --db /custom/path/to/known_faces

    # Show help:
    python detect.py --help

Output (stdout, JSON):
    {"name": "Alice"}        — if a known person is identified
    {"name": "Unknown"}      — if the face is not in the database
    {"error": "...message"}  — if something went wrong (no face, model error, etc.)

Exit codes:
    0 — success (name or "Unknown" returned)
    1 — error (see JSON output for details)
"""

import argparse
import json
import os
import sys
import tempfile

# ---------------------------------------------------------------------------
# Constants
# ---------------------------------------------------------------------------
DEFAULT_KNOWN_FACES_DIR = os.path.expanduser("~/.openclaw/workspace/known_faces")
DEFAULT_CAMERA_INDEX = 0
DEEPFACE_MODEL = "VGG-Face"        # Accurate model that ships with deepface
DISTANCE_METRIC = "cosine"         # cosine similarity works well for VGG-Face
DETECTOR_BACKEND = "opencv"        # Fast; swap to "retinaface" for higher accuracy


def _capture_frame(camera_index: int) -> str:
    """Capture a single frame from the camera and save to a temp file.

    Returns the path to the saved image (caller is responsible for cleanup).
    Raises RuntimeError if the camera cannot be opened or a frame cannot be read.
    """
    try:
        import cv2  # opencv-python-headless
    except ImportError as exc:
        raise RuntimeError(
            "opencv-python-headless is not installed. "
            "Run: pip install opencv-python-headless"
        ) from exc

    cap = cv2.VideoCapture(camera_index)
    if not cap.isOpened():
        raise RuntimeError(f"Cannot open camera at index {camera_index}.")

    ret, frame = cap.read()
    cap.release()

    if not ret or frame is None:
        raise RuntimeError(f"Failed to read a frame from camera {camera_index}.")

    # Create a named temporary file, get its path, and close it before writing.
    with tempfile.NamedTemporaryFile(suffix=".jpg", delete=False) as tmp:
        tmp_path = tmp.name

    # Write the captured frame to the closed temporary file path.
    if not cv2.imwrite(tmp_path, frame):
        raise RuntimeError("Failed to write captured frame to temporary file.")

    return tmp_path


def _find_best_match(img_path: str, db_path: str) -> str:
    """Run DeepFace.find() and extract the top identity.

    Returns the person's name (the subfolder name inside db_path) or "Unknown".
    Raises RuntimeError on unexpected DeepFace errors.
    """
    try:
        from deepface import DeepFace
    except ImportError as exc:
        raise RuntimeError(
            "deepface is not installed. Run: pip install deepface"
        ) from exc

    if not os.path.isdir(db_path):
        raise RuntimeError(
            f"Known-faces database not found at '{db_path}'. "
            "Run setup_known_faces.sh and add reference images first."
        )

    # DeepFace.find() returns a list of DataFrames (one per face in the image).
    # Each DataFrame has columns: identity, distance, …
    # We raise ValueError internally when no face is detected — catch that.
    try:
        results = DeepFace.find(
            img_path=img_path,
            db_path=db_path,
            model_name=DEEPFACE_MODEL,
            distance_metric=DISTANCE_METRIC,
            detector_backend=DETECTOR_BACKEND,
            enforce_detection=True,
            silent=True,
        )
    except ValueError as exc:
        # Typical message: "Face could not be detected."
        raise RuntimeError(f"No face detected in the image: {exc}") from exc

    # results is a list of DataFrames (one per detected face in the query image).
    if not results or results[0].empty:
        return "Unknown"

    # The first DataFrame corresponds to the first (usually largest) detected face.
    top_match = results[0].iloc[0]
    identity_path: str = top_match["identity"]

    # identity_path is the full path to the matched reference image, e.g.:
    # ~/.openclaw/workspace/known_faces/Alice/alice_front.jpg
    # So we extract the immediate parent directory name as the person's name.
    person_name = os.path.basename(os.path.dirname(identity_path))
    return person_name if person_name else "Unknown"


def identify_face(image_path: str | None, camera_index: int, db_path: str) -> dict:
    """Main identification logic. Returns a result dict."""
    tmp_path = None
    try:
        if image_path:
            if not os.path.isfile(image_path):
                return {"error": f"Image file not found: '{image_path}'"}
            img_path = image_path
        else:
            tmp_path = _capture_frame(camera_index)
            img_path = tmp_path

        name = _find_best_match(img_path, db_path)
        return {"name": name}

    except RuntimeError as exc:
        return {"error": str(exc)}
    except Exception as exc:  # noqa: BLE001
        return {"error": f"Unexpected error: {exc}"}
    finally:
        if tmp_path and os.path.exists(tmp_path):
            os.unlink(tmp_path)


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Identify a person's face using DeepFace and a local reference database.",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog=__doc__,
    )
    source = parser.add_mutually_exclusive_group()
    source.add_argument(
        "--camera",
        type=int,
        default=DEFAULT_CAMERA_INDEX,
        metavar="INDEX",
        help=f"Camera device index to capture from (default: {DEFAULT_CAMERA_INDEX}).",
    )
    source.add_argument(
        "--image",
        type=str,
        default=None,
        metavar="PATH",
        help="Path to an existing image file to use instead of the camera.",
    )
    parser.add_argument(
        "--db",
        type=str,
        default=DEFAULT_KNOWN_FACES_DIR,
        metavar="DIR",
        help=f"Path to the known-faces database directory (default: {DEFAULT_KNOWN_FACES_DIR}).",
    )

    args = parser.parse_args()

    result = identify_face(
        image_path=args.image,
        camera_index=args.camera,
        db_path=args.db,
    )

    print(json.dumps(result))

    # Exit 1 only on hard errors, not on "Unknown"
    return 1 if "error" in result else 0


if __name__ == "__main__":
    sys.exit(main())
