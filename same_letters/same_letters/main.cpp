//
//  main.cpp
//  same_letters
//
//  Created by Yury Chebiryak on 11/01/17.
//  Copyright © 2017 Yury Chebiryak. All rights reserved.
//

#include <iostream>
#include <unordered_set>

// chars in both strings
std::unordered_set<char> intersection(const std::string& a, const std::string& b) {
    std::unordered_set<char> aa, bb, res;
    for (char c: a)
        aa.insert(c);
    for (char c: b)
        bb.insert(c);
    for (int c=65; c<122; ++c)
        if ((aa.find((char) c) != aa.end()) and (bb.find((char) c) != bb.end()))
            res.insert((char) c);
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    auto res = intersection("abra", "kadabra");
    for (auto c: res)
        std::cout << c << ", ";
    return 0;
}
