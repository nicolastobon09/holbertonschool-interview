#!/usr/bin/python3
"""
rain function
"""


def rain(walls):
    """
    function that calculate how much water will be retained,
    after it rains
    """
    if not walls:
        return 0

    water_retained = 0
    top_right_wall = 0
    top_left_wall = 0

    idx = 0
    size = len(walls) - 1

    while (idx <= size):
        if walls[idx] < walls[size]:
            if walls[idx] > top_left_wall:
                top_left_wall = walls[idx]
            else:
                water_retained += top_left_wall - walls[idx]
            idx += 1
        else:
            if walls[size] > top_right_wall:
                top_right_wall = walls[size]
            else:
                water_retained += top_right_wall - walls[idx]
            size -= 1
    return water_retained
