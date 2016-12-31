//
//  main.cpp
//  ex2.2
//
//  Created by Yury Chebiryak on 31/12/16.
//  Copyright © 2016 Yury Chebiryak. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <forward_list>
//2.2 Implement an algorithm to find the kth to last element of a singly linked list.

template<typename T>
T k_th_element(const std::forward_list<T>& list, size_t n) {
    //size_t sz = std::count(list.begin(), list.end());
    size_t sz = 0;
    for (int i : list)
        ++sz;
    auto iter = list.begin();
    size_t i =0;
    while (iter != list.end()) {
        if (i == sz - n - 1)
            return *iter;
        ++iter;
        ++i;
    }
    return T();
}

template<typename T>
T k_th_element2(const std::forward_list<T>& list, size_t k) {
    auto iter1 = list.begin();
    auto iter2 = iter1;
    for (int i = 0; i < k; ++i)
        ++iter2;
    while (std::next(iter2) != list.end()) {
        ++iter2;
        ++iter1;
    }
    return *iter1;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    std::forward_list<int> l = { 16, 7, 5, 16, 8,  25};
    
    std::cout << k_th_element2(l, 0);
    
    std::cout << std::endl << k_th_element2(l, 5);
    
    return 0;
}
