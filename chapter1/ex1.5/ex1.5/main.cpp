//
//  main.cpp
//  ex1.5
//
//  Created by Yury Chebiryak on 23/08/16.
//  Copyright © 2016 Yury Chebiryak. All rights reserved.
//

#include <iostream>

//1.5 Implement a method to perform basic string compression using the counts of repeated characters. For example, the string a a b c c c c c a a a would become a2blc5a3. If the "compressed" string would not become smaller than the original string, your method should return the original string
#include <string>
#include <sstream>
using namespace std;
string compress(const string& s) {
    stringstream out;
    char prev='\0';
    int count = 0;
    for (char c: s) {
        if (c != prev) {
            if (count) {
                out << prev;
                out << count;
            }
            count = 1;
            prev = c;
        } else count++;
    }
    out << prev;
    out << count;
    string str = out.str();
    if (str.length() < s.length())
        return str;
    return s;
}

int main(int argc, const char * argv[]) {
    string test = "aabcccccaaa";
    string test2 = "abb";
    string test3 = "aabb";
    string test4 = "aaaab";
    cout << " in: " << test << ", out: " << compress(test) << endl;
    cout << " in: " << test2 << ", out: " << compress(test2) << endl;
    cout << " in: " << test3 << ", out: " << compress(test3) << endl;
    cout << " in: " << test4 << ", out: " << compress(test4) << endl;
    
    return 0;
}
