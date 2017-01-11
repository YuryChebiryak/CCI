//
//  main.cpp
//  ex3.1
//
//  Created by Yury Chebiryak on 08/01/17.
//  Copyright © 2017 Yury Chebiryak. All rights reserved.
//

#include <iostream>

//Cracking the Coding Interview, 5th Edition
//3.1 Describe how you could use a single array to implement three stacks.

//two stacks: first one grows from the front, another from the back.
// three stacks: from the middle towards the smallest other stack. or divide equally giving 1/3 of storage per stack

template<typename T, int SZ>
class Stack{
public:
    void push(const T& value, int idx) {
        theArray[theIdx[idx]++] = value;
    }
    T   peek(int idx) {
        return theArray[theIdx[idx]-1];
    }
    T   pop(int idx) {
        return theArray[theIdx[idx]--];
    }
    friend std::ostream& operator<<(std::ostream& res, const Stack<T, SZ>& s) {
        for (int i = 0; i < SZ; ++i)
            res << s.theArray[i] << ", ";
        return res;
    }
private:
    int theIdx[3] = {0, SZ/3, SZ*2/3};
    T theArray[SZ];
};

//template<typename T, int SZ>
//std::ostream& operator<<(std::ostream& res, const Stack<T, SZ>& s) {
//    for (int i = 0; i < SZ; ++i)
//        res << s.theArray[i] << ", ";
//    return res;
//}


int main(int argc, const char * argv[]) {
    // insert code here...
    Stack<int, 12> s;
    s.push(12,0);
    s.push(13,1);
    s.push(14,1);
    s.push(15,2);
    
    std::cout << "peek 0: " << s.peek(0) << std::endl;
    std::cout << "peek 1: " << s.peek(1) << std::endl;
    std::cout << "peek 2: " << s.peek(2) << std::endl;
    
    std::cout << "first" << s;
    return 0;
}
