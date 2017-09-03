//
//  main.cpp
//  ex6.6
//
//  Created by Yury Chebiryak on 03/09/17.
//  Copyright © 2017 Yury Chebiryak. All rights reserved.
//

#include <iostream>

/*
3.6 Write a program to sort a stack in ascending order (with biggest items on top). You may use at most one additional stack to hold items, but you may not copy the elements into any other data structure (such as an array). The stack supports the following operations: push, pop, peek, and isEmpty.
*/

/*
 
 all we can use is another stack and the swap oporation on the tops of the stacks.
 
 6
 1
 3
 4
 
 1 6
 3
 4
 
 6 1
 3
 4
 
 3 6
 4 1
 
 so w can apply sort of bubble sort, where the biggest elements "buble up" towards the ends of the second stack thus taking O(n^2) operations
 it has to be 
 
 
 
 */
 
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
