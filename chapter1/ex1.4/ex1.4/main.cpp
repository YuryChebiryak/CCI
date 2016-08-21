//
//  main.cpp
//  ex1.4
//
//  Created by Yury Chebiryak on 21/08/16.
//  Copyright © 2016 Yury Chebiryak. All rights reserved.
//

#include <iostream>

/* 1.4 
 Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end of the string to hold the additional characters, and that you are given the "true" length of the string. (Note: if implementing in Java, please use a character array so that you can perform this operation inplace.)
*/

#include <string>
using namespace std;
void replaceSpaces(char* s, int len) {
    int spaces {0};
    for (int i = 0; i < len; ++i)
        if (' ' == s[i])
            ++spaces;
    int j = len-1 + spaces * 2;
    s[j+1] ='\0';
    for (int i = len-1; i >= 0; --i) {
        if (' ' == s[i]) {
            s[j--]='0';
            s[j--]='2';
            s[j--]='%';
        } else
            s[j--] = s[i];
    }
}

int main(int argc, const char * argv[]) {
    char url[] = {'r', 'e','p','l','a','c','e',' ','m','e',' ','p','l','e','a','s','e','\0','-','-','-','-','-','-','-'};
    char *ptr = url;
    cout << " before: " << ptr << endl;
    replaceSpaces(url, 25);
    cout << " after: " << ptr << endl;
    return 0;
}
