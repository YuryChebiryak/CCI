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

void removeDups(std::list<int>& l) {
    //std::sort(l.begin(), l.end());
    l.sort();
    for (int n : l)
        std::cout << n << '\t';
    std::cout << std::endl;
    l.unique();
//    auto iter = l.begin();
//    while (iter != l.end()) {
//        auto next = iter + 1;
//        if (*iter == *next) {
//            l.erase
//        }
//    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    std::list<int> l = { 7, 5, 16, 8,  25};
    
    l.push_front(25);
    l.push_back(13);
    
    // Iterate and print values of the list
    for (int n : l)
        std::cout << n << '\t';
    std::cout << std::endl;
    
    removeDups(l);
    
    // Iterate and print values of the list
    for (int n : l)
        std::cout << n << '\t';
    
    return 0;
}
