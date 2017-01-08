//
//  main.cpp
//  ex1
//
//  Created by Yury Chebiryak on 01/08/16.
//  Copyright © 2016 Yury Chebiryak. All rights reserved.
//
#include <algorithm>
#include <iostream>
#include <array>
//#include <boost/flat_set>
#include <set>
#include <bitset>
// Cracking the Coding Interview, 5th Edition
// ex1.1 Implement an algorithm to determine if a string has all unique character.
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
bool uniqueChars(std::string in) {
//    std::string sorted { in};
    std::sort(in.begin(), in.end());
    char prevChar = '\0';
    for (char c : in)
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

//if we know the character set, we can use additional array with ascii codes (unicode) and mark characters
// we have seen already. That'd be the fastest solution, linear in time
bool uniqueChars2(const std::string& in) {
    if (in.size() > 256) return false;
    std::array<bool, 256> seen;
    seen.fill(false);
    for (char c : in)
        if (seen[static_cast<unsigned>(c)])
            return false;
        else
            seen[static_cast<unsigned>(c)] = true;
    return true;
}

//next optimization is for space: use bitsets
bool uniqueChars3(const std::string& in) {
    if (in.size() > 256) return false;
    std::bitset<256> seen;
    std::cout << "size of bitset: " << sizeof(std::bitset<256>) << std::endl;
    seen.reset();
    for (char c : in)
        if (seen[static_cast<unsigned>(c)])
            return false;
        else
            seen[static_cast<unsigned>(c)] = true;
    return true;
}

//if we assume english lowercase, can squeeze into 32 bit integer
bool uniqueChars4(const std::string& in) {
    if (in.size() > 32) return false;
    unsigned seen {0};
    for (char c : in)
        if (seen bitand (1 << (c - 'a')))
            return false;
        else
            seen = seen bitor (1 << (c - 'a'));
    return true;
}

int main(int argc, const char * argv[]) {
    std::string testing="afqnvz";
    std::cout << "testing using " << testing << std::endl;
    std::cout << naiveSolution(testing) << std::endl;
    std::cout << uniqueChars(testing) << std::endl;
    std::cout << uniqueChars2(testing) << std::endl;
    std::cout << uniqueChars3(testing) << std::endl;
    std::cout << uniqueChars4(testing) << std::endl;
    return 0;
}
