//
//  main.cpp
//  ex1.2
//
//  Created by Yury Chebiryak on 19/08/16.
//  Copyright © 2016 Yury Chebiryak. All rights reserved.
//

#include <iostream>
//#include <algorithm>
#include <utility>
// Cracking the Coding Interview, 5th Edition
//1.2 Implement a function void reverse(char* str) in C or C++ which reverses a null-termi- nated string.

//! first pass to figure out the length of the string, second one swaps the characters
void reverseNaive(char* str) {
    int len = 0;
    for (char* i = str; *i != '\0'; ++i)
        len++;
    for (int i = 0; i < len/2; ++i) {
        std::swap(str[i], str[len-i-1]);
    }
}

int main(int argc, const char * argv[]) {
    char array[] = {'h','e','l','l','o',0};
    std::cout << " before: " << array;
    char* ptr = array;
    reverseNaive(ptr);
    std::cout << "after: " << ptr;
    return 0;
}
