#!/usr/bin/env bash
# setup_known_faces.sh
#
# Creates the known-faces database directory structure for the identify_face skill.
# Run this once to get started, then add subfolders with reference photos for each person.
#
# Usage:
#   bash skills/identify-face/scripts/setup_known_faces.sh

set -euo pipefail

KNOWN_FACES_DIR="${HOME}/.openclaw/workspace/known_faces"

echo "==> Setting up known-faces database at: ${KNOWN_FACES_DIR}"
mkdir -p "${KNOWN_FACES_DIR}"

echo ""
echo "✅  Directory created successfully!"
echo ""
echo "Next steps:"
echo "  1. Create a subfolder for each known person:"
echo "       mkdir -p \"${KNOWN_FACES_DIR}/Alice\""
echo "       mkdir -p \"${KNOWN_FACES_DIR}/Bob\""
echo ""
echo "  2. Copy 2–5 clear, front-facing photos of each person into their folder:"
echo "       cp alice_photo1.jpg \"${KNOWN_FACES_DIR}/Alice/\""
echo "       cp alice_photo2.jpg \"${KNOWN_FACES_DIR}/Alice/\""
echo ""
echo "  3. Supported formats: .jpg, .jpeg, .png"
echo ""
echo "  4. Tips for best accuracy:"
echo "       - Use well-lit, front-facing photos"
echo "       - Include a variety of angles / lighting conditions"
echo "       - Avoid group photos (one person per image)"
echo ""
echo "  5. Test the skill:"
echo "       python skills/identify-face/scripts/detect.py --image /path/to/test/photo.jpg"
echo ""
echo "Current database contents:"
if [ -z "$(ls -A "${KNOWN_FACES_DIR}" 2>/dev/null)" ]; then
    echo "  (empty — no people added yet)"
else
    ls -1 "${KNOWN_FACES_DIR}"
fi
