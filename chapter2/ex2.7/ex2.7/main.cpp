//
//  main.cpp
//  ex2.7
//
//  Created by Yury Chebiryak on 06/01/17.
//  Copyright © 2017 Yury Chebiryak. All rights reserved.
//

#include <iostream>

// Cracking the Coding Interview, 5th Edition
//2.7 Implement a function to check if a linked list is a palindrome


#include <forward_list>
#include <iterator>
#include <algorithm>

using baseT=int;
using typeT=std::forward_list<baseT>;
using typeTiter = typeT::iterator;

void printList(const typeT& l, const std::string& msg) {
    std::cout << msg << ": ";
    for (int n : l)
        std::cout << n << "->";
    std::cout << std::endl;
}

bool palindrome(typeTiter& left, const typeTiter& right, const typeTiter& end, bool& done) {
//    std::cout << "left: " << *left << ", right << " << *right << std::endl;
    typeTiter next = std::next(right);
    if (next != end)
        if (!palindrome(left, next, end, done))
            return false;
//    std::cout << "left: " << *left << ", right << " << *right << std::endl;
    if (done)
        return true;
    if (*left == *right) {
        if ((left != right) and (std::next(left) != right) and not done)
            left++;
        else
            done = true;
        return true;
    } else
        return false;
}

int main(int argc, const char * argv[]) {
    typeT l1 = {1,3,5};
    typeT l2 = {2,0,4,8,6,8,4,0,2};
    printList(l1, "list 1");
    typeTiter begin = l1.begin();
    bool done = false;
    std::cout << "palindrom? " << palindrome(begin, l1.begin(), l1.end(), done);
    printList(l2, "list 2");
    printList(l2, "list2");
    begin = l2.begin();
    done = false;
    std::cout << "palindrom? " << palindrome(begin, l2.begin(), l2.end(), done) << std::endl;

    return 0;
}
