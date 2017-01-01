//
//  main.cpp
//  ex2.4
//
//  Created by Yury Chebiryak on 01/01/17.
//  Copyright © 2017 Yury Chebiryak. All rights reserved.
//

#include <iostream>
#include <forward_list>
#include <algorithm>

//2.4 Write code to partition a linked list around a value x, such that all nodes less than x come before alt nodes greater than or equal to x.

template<typename T>
void partition_around_x(std::forward_list<T>& list, const T& x) {
    int index = std::count_if(list.cbegin(), list.cend(), [&](T i){ return i < x; });
    auto less_iter = list.begin();
    auto higher_iter = list.begin();
    for (int i = 0; i < index; ++i)
        ++higher_iter;
    while (higher_iter != list.end()) {
        while (*less_iter < x)
            ++less_iter;
        while ((higher_iter != list.end()) and (*higher_iter >= x))
            ++higher_iter;
        if ((*less_iter >= x) and (higher_iter != list.end()) and (*higher_iter < x)) {
            std::swap(*less_iter, *higher_iter);
        for (int n : list)
            std::cout << n << '\t';
        std::cout << std::endl;
        }
    }
}

template<typename T>
void partition_2(std::forward_list<T>& list, const T& x) {
    auto iter = list.before_begin();
    while(std::next(iter) != list.end()) {
        if ((*std::next(iter) < x) and (iter != list.before_begin())) {
            list.push_front(*std::next(iter));
            list.erase_after(iter);
        } else {
            ++iter;
        }
    }
}

int main(int argc, const char * argv[]) {
    std::forward_list<int> l = { 1, 6,2,7,3,5,4,1,5,6};
    // Iterate and print values of the list
    for (int n : l)
        std::cout << n << '\t';
    std::cout << std::endl;
//    partition_around_x(l,4);
    partition_2(l, 2);
    for (int n : l)
        std::cout << n << '\t';
    return 0;
}
