//
//  main.cpp
//  ex5_1
//
//  Created by Yury Chebiryak on 30/01/19.
//  Copyright © 2019 Yury Chebiryak. All rights reserved.
//
#include <iostream>
#include <utility>
#include <set>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <list>
#include <stack>
#include <stdlib.h>
#include <assert.h>

/* You are given two 32-bit numbers,N and M, and two bit positions, i and j. 
 Write a method to insert M into N such that M starts at bit j and ends at bit i. You can assume that the bits j through i have enough space to fit all of M. That is,if M= 10011, you can assume that there are at least 5 bits between j and i. You would not, for example, have j-3 and i=2, because M could not fully fit between bit 3 and bit 2.
 EXAMPLE:
 Input:N=10000000000, M=10011, i =2, j =6 Output: N = 10001001100
 
 Q1 does this assume that inside N for the places from i to j there are only zeros?
 
 shift M by i bits to the left, then perform bitwise or
 
 */

int ex5_2(int M, int N, int i, int j) {
    int shifted_M = M << i;
    //std::cout << " shifted_M equals " << shifted_M << std::endl;
    int res = N | shifted_M;
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    std::cout << " ex 5.1 " << ex5_2(19, 1024, 2, 6) << std::endl;
    return 0;
}
