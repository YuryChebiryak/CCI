//
//  main.cpp
//  ex1
//
//  Created by Yury Chebiryak on 01/08/16.
//  Copyright © 2016 Yury Chebiryak. All rights reserved.
//

#include <iostream>

#include <set>
// Implement an algorithm to determine if a string has all unique character.
// What if you cannot use additional data structures?

bool naiveSolution(const std::string in) {
    std::set<char> visited;
    for (char c : in)
        if (visited.find(c) == visited.end())
            visited.insert(c);
        else
            return false;
    return true;
}

int main(int argc, const char * argv[]) {
    std::string testing="aafqnvz";
    std::cout << "testing using " << testing << std::endl;
    std::cout << naiveSolution(testing);
    return 0;
}
