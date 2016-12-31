//
//  main.cpp
//  ex2.1
//
//  Created by Yury Chebiryak on 30/12/16.
//  Copyright © 2016 Yury Chebiryak. All rights reserved.
//

#include <iostream>
#include <list>
#include <algorithm>
#include <unordered_set>
#include <forward_list>

void removeDups(std::forward_list<int>& l) {
    l.sort();
    for (int n : l)
        std::cout << n << '\t';
    std::cout << std::endl;
    l.unique();
}

void removeDups2(std::forward_list<int>& l) {
    std::unordered_set<int> s;
    auto prev = l.before_begin();
    auto iter = l.begin();
    while (iter != l.end()) {
        if (s.find(*iter) != s.end()) {
            iter = l.erase_after(prev);
        } else {
            s.insert(*iter);
            ++iter;
            ++prev;
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    std::forward_list<int> l = { 16, 7, 5, 16, 8,  25};
    
    l.push_front(25);
//    l.push_back(16);
    
    // Iterate and print values of the list
    for (int n : l)
        std::cout << n << '\t';
    std::cout << std::endl;
    
    removeDups2(l);
    
    // Iterate and print values of the list
    for (int n : l)
        std::cout << n << '\t';
    
    return 0;
}
