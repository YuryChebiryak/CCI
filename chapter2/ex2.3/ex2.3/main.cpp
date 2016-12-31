//
//  main.cpp
//  ex2.3
//
//  Created by Yury Chebiryak on 31/12/16.
//  Copyright © 2016 Yury Chebiryak. All rights reserved.
//
//2.3 Implement an algorithm to delete a node in the middle of a singly linked list, given only access to that node.

#include <iostream>
#include <forward_list>

using listT = std::forward_list<int>;
void delete_middle(listT& list, listT::iterator iter) {
    auto current = iter;
    auto prev = current;
    while (std::next(current) != list.end()) {
        *current = *std::next(current);
        prev = current;
        ++current;
    }
    if (std::next(prev) != list.end())
        list.erase_after(prev);
    else {
        *prev = 0;
        prev = list.end();
        //doesn't really work if the element to be removed is the last one!
    }
}

int main(int argc, const char * argv[]) {
    std::forward_list<int> l = { 16, 7, 5, 16, 8,  25};
    l.push_front(26);
    
    
    // Iterate and print values of the list
    for (int n : l)
        std::cout << n << '\t';
    std::cout << std::endl;
    delete_middle(l, l.begin());
    for (int n : l)
        std::cout << n << '\t';
    std::cout << std::endl;
    listT::iterator iter = l.begin();
    iter++;
    delete_middle(l, iter);
    for (int n : l)
        std::cout << n << '\t';
    std::cout << std::endl;
    
    iter = l.begin();
    iter++; iter++; iter++; iter++;
    delete_middle(l, iter);
    for (int n : l)
        std::cout << n << '\t';
    std::cout << std::endl;
    return 0;
}
