//
//  main.cpp
//  ex1.8
//
//  Created by Yury Chebiryak on 30/12/16.
//  Copyright © 2016 Yury Chebiryak. All rights reserved.
//

//1.8 Assume you have a method isSubstring which checks if one word is a substring of another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring (e.g., "waterbottLe" is a rotation of "erbottleewat").
#include <iostream>
#include <string>

bool isSubstring(const std::string& s1, const std::string& s2) {
    return s1.find(s2) < s1.size();
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    std::string s1 = "waterbottle";
    std::string s2 = "erbottlewat";
    auto s3 = s1 + s1;
    std::cout << " rotation? " << (isSubstring(s3, s2) ? "yes" : "no") << std::endl;
    
    return 0;
}
