def is_low_confidence(value: float, threshold: float = 0.6) -> bool:
    return value < threshold


def normalize_confidence(raw_score: float) -> float:
    if raw_score < 0:
        return 0.0
    if raw_score > 1:
        return 1.0
    return raw_score
