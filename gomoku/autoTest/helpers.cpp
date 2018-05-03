//
//  helpers.cpp
//  autoTest
//
//  Created by Ricky Peng on 5/2/18.
//

#include "helpers.hpp"

bool isIntersection(int x, int y) {
    int width = 765;
    int height = 765;
    int size = 15;
    if (x == 0 || y == 0) {
        return false;
    }
    return ((x % (width / size) == 0) && (y % (height / size) == 0));
}
