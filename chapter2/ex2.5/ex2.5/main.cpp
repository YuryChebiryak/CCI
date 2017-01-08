//
//  main.cpp
//  ex2.5
//
//  Created by Yury Chebiryak on 02/01/17.
//  Copyright © 2017 Yury Chebiryak. All rights reserved.
//

#include <iostream>
#include <forward_list>
#include <iterator>
#include <algorithm>

// Cracking the Coding Interview, 5th Edition
//2.5 You have two numbers represented by a linked list, where each node contains a single digit.The digits are stored in reverse order,such that the 1's digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.
// FOLLOW UP
// Suppose the digits are stored in forward order. Repeat the above problem.

using baseT=int;
using typeT=std::forward_list<baseT>;
using typeTiter = typeT::iterator;
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

void printList(const typeT& l, const std::string& msg) {
    std::cout << msg << ": ";
    for (int n : l)
        std::cout << n << "->";
    std::cout << std::endl;
}

//forward sum is harder. Cant really do it iteratively, need recursion. First, we append zeros to have lists of same
// length, then go recursively to the end, propagating carry and start inserting the results of the summation to the front of the list
void recurse(const typeTiter& l1, const typeTiter& l2, const typeTiter& l1end, const typeTiter& l2end, baseT& carry, typeT& res) {
    typeTiter l1next {std::next(l1)};
    typeTiter l2next {std::next(l2)};
    if ( (l1next != l1end) and (l2next != l2end))
        recurse(l1next, l2next, l1end, l2end, carry, res);
    baseT current = carry;
    if (l1 != l1end)
        current += *l1;
    if (l2 != l2end)
        current += *l2;
    res.push_front(current % 10);
    carry = (current > 9) ? 1 : 0;
}

void forward_sum(typeT& l1, typeT& l2, typeT& res) {
    auto sz1 = std::count_if(l1.begin(), l1.end(), [](baseT i){ return true; });
    auto sz2 = std::count_if(l2.begin(), l2.end(), [](baseT i){ return true; });
    for (int i = 0; i < sz1-sz2; ++i)
        l2.emplace_front();
    for (int i = 0; i < sz2-sz1; ++i)
        l1.emplace_front();
    printList(l1, "after padding l1");
    printList(l2, "after padding l2");
    baseT carry {0};
    recurse(l1.begin(), l2.begin(), l1.end(), l2.end(), carry, res);
    printList(res, "after all recursion, res");
}

int main(int argc, const char * argv[]) {
    typeT l1 = {1,3,5};
    typeT l2 = {2,0,4,8};
    
    printList(l1, "list 1");
    printList(l2, "list 2");
    l1.reverse(); l2.reverse();
    printList(l1, "reversed list1");
    printList(l2, "reversed list2");
    auto l = reverse_sum(l1, l2);
    printList(l, "reverse sum");
    std::cout << "computing forward sum" << std::endl;
    l1.reverse(); l2.reverse();
    typeT revSum;
    forward_sum(l1, l2, revSum);
    return 0;
}
