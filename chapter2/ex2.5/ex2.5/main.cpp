//
//  main.cpp
//  ex2.5
//
//  Created by Yury Chebiryak on 02/01/17.
//  Copyright © 2017 Yury Chebiryak. All rights reserved.
//

#include <iostream>
#include <forward_list>

//2.5 You have two numbers represented by a linked list, where each node contains a single digit.The digits are stored in reverse order,such that the 1's digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.
// FOLLOW UP
// Suppose the digits are stored in forward order. Repeat the above problem.

using baseT=int;
using typeT=std::forward_list<baseT>;
typeT reverse_sum(const typeT& l1, const typeT& l2) {
    typeT res;
    auto res_iter = res.before_begin();
    auto i1 = l1.begin();
    auto i2 = l2.begin();
    baseT carry {};
    while (not ((i1 == l1.end()) and (i2 == l2.end()) and (carry == 0))) {
        baseT current = carry;
        if (i1 != l1.end())
            current += *i1++;
        if (i2 != l2.end())
            current += *i2++;
        if (current > 9)
            carry = 1;
        else
            carry = 0;
        res_iter = res.insert_after(res_iter, current % 10);
    }
    return res;
}

int main(int argc, const char * argv[]) {
    typeT l1 = {1,3,5};
    typeT l2 = {2,0,4,8};
    
    // Iterate and print values of the list
    for (int n : l1)
        std::cout << n << '\t';
    std::cout << std::endl;

    l1.reverse(); l2.reverse();
    auto l = reverse_sum(l1, l2);
    for (int n : l)
        std::cout << n << '\t';
    return 0;
}
