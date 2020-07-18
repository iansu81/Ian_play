import math

from functools import reduce
import operator
import math


# Calculate the polygon with ordered X and Y points
def calculate_area(X,Y):
    area = 0
    j = (len(X) - 1)
    for i in range(0, len(X)):
        area += (X[j] + X[i]) * (Y[j] - Y[i])
        j = i
    return abs(area/2)

# The main function
def polygon_area_calculation(pts):
    # Make points ordered
    center = tuple(map(operator.truediv, reduce(lambda x, y: map(operator.add, x, y), pts), [len(pts)] * 2))
    ordered_list = sorted(pts, key=lambda coord: (-135 - math.degrees(math.atan2(*tuple(map(operator.sub, coord, center))[::-1]))) % 360)
    X_list = []
    Y_list = []
    for item in ordered_list:
        X_list.append(item[0])
        Y_list.append(item[1])
    return calculate_area(X_list, Y_list)


if __name__ == '__main__':
    pts = [[0,0], [4,4], [0,4],[4,0]]
    print(polygon_area_calculation(pts) == 16.0)