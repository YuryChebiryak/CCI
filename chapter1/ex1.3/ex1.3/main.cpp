//
//  main.cpp
//  ex1.3
//
//  Created by Yury Chebiryak on 19/08/16.
//  Copyright © 2016 Yury Chebiryak. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
// 1.3 Given two strings, write a method to decide if one is a permutation of the other.
using namespace std;

//! in case strings are very long, this solves the task in O(n)
//  We compute the number of each character in both strings and compare the character counts
bool isPermutationNaive(const std::string& a, const std::string& b) {
    vector<int> chars;
    chars.assign(32, 0);
    for (auto i = 0; i < a.length(); ++i)
        chars[ a[i] - 'a' ]++;
    for (auto i = 0; i < b.length(); ++i) {
        chars[ b[i] - 'a' ]--;
        if (chars[ b[i] - 'a'] < 0)
            return false;
    }
    for (auto count: chars)
        if (count != 0)
            return false;
    return true;
}

//! in case strings aren't too long, this solves the task in O(n log n)
//  We sort both strings and compare the results, if its identical one is a permutation of another
bool isPermutationSort(const string& a, const string& b) {
    string asorted {a}, bsorted {b};
    sort(asorted.begin(), asorted.end());
    sort(bsorted.begin(), bsorted.end());
    return asorted == bsorted;
}

int main(int argc, const char * argv[]) {
    string a = "apple", b1 = "pplea", b2 = "pple";
    cout << a << " perm of " << b1 << "? " << isPermutationNaive(a, b1) << endl;
    cout << a << " perm of " << b2 << "? " << isPermutationNaive(a, b2) << endl;
    cout << a << " perm of " << b1 << "? " << isPermutationSort(a, b1) << endl;
    cout << a << " perm of " << b2 << "? " << isPermutationSort(a, b2) << endl;
    return 0;
}
