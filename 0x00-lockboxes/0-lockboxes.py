#!/usr/bin/python3
"""
Method that determines if all the boxes can be opened.
"""


def canUnlockAll(boxes):
    """
    Function that determines
    if all boxes can be opened
    args:
        boxes: is a list of lists
    """
    keys = [0]
    for new_key in keys:
        for key in boxes[new_key]:
            if key not in keys and new_key != key:
                keys.append(key)
    if len(keys) == len(boxes):
        return True
    return False
