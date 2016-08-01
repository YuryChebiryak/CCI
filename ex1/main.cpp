//
//  main.cpp
//  ex1
//
//  Created by Yury Chebiryak on 01/08/16.
//  Copyright © 2016 Yury Chebiryak. All rights reserved.
//
#include <algorithm>
#include <iostream>
//#include <boost/flat_set>
#include <set>
// Implement an algorithm to determine if a string has all unique character.
// What if you cannot use additional data structures?

// quick solution using std::set
//   we insert characters we've seen already into the set
//   once we encounter a character we haven't seen already => not unique chars
// complexity: going thru all characters in string is linear, inserting is log n, thus \bigO(n log n)
bool naiveSolution(const std::string& in) {
    std::set<char> visited;
    for (char c : in)
        if (visited.find(c) == visited.end())
            visited.insert(c);
        else
            return false;
    return true;
}

//if we can't use additional data structures, we still can simply sort the string,
// and then go through it and figure out if there are non-unique characters
// for the same complexity: sorting is O(n log n) + linear pass-through = O(n log n)
bool uniqueChars(const std::string& in) {
    std::string sorted { in};
    std::sort(sorted.begin(), sorted.end());
    char prevChar = '\0';
    for (char c : sorted)
        if (prevChar == '\0') {
            prevChar = c;
            continue;
        } else {
            if (c == prevChar)
                return false;
            prevChar = c;
        }
    return true;
}


int main(int argc, const char * argv[]) {
    std::string testing="aafqnvz";
    std::cout << "testing using " << testing << std::endl;
    std::cout << naiveSolution(testing);
    return 0;
}
