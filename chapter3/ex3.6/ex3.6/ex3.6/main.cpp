//
//  main.cpp
//  ex6.6
//
//  Created by Yury Chebiryak on 03/09/17.
//  Copyright © 2017 Yury Chebiryak. All rights reserved.
//
#include <stack>
#include <iostream>
#include <stdlib.h>
/*
3.6 Write a program to sort a stack in ascending order (with biggest items on top). You may use at most one additional stack to hold items, but you may not copy the elements into any other data structure (such as an array). The stack supports the following operations: push, pop, peek, and isEmpty.
*/

/*
 
 all we can use is another stack and the swap oporation on the tops of the stacks.
 
 6
 1
 3
 4
 push
 
 1 6
 3
 4
 swap 
 
 6 1
 3
 4
 push
 
 3 6
 4 1
swap
 
 6 3
 4 1
 push
 
 4 6
   3
   1
 swap
 6 4 
   3
   1
 push
   6
   4
   3
   1
 */

template <typename T>
class Stack {
public:
    void push(const T& el) {
        theStack.push(el);
    }
    T& pop() {
        T& res = peek();
        theStack.pop();
        return res;
    }
    T& peek() {
        return theStack.top();
    }
    bool isEmpty() {
        return theStack.empty();
    }
    size_t size() { return theStack.size(); }
    void print();
private:
    std::stack<T> theStack;
};

template<typename T>
void shiftUpwards(Stack<T>& one, Stack<T>& another) {
    T& tmp = one.pop();
    another.push(tmp);
}

template<typename T>
void Stack<T>::print() {
        Stack<T> tmp;
        while (!isEmpty()) {
            std::cout <<  peek() << ",";
            shiftUpwards(*this, tmp);
        };
        std::cout << std::endl;
        //return everything back
        while (!tmp.isEmpty()) {
            shiftUpwards(tmp, *this);
        }
}

template<typename T>
bool swapStackTops(Stack<T>& one, Stack<T>& another) {
//    if (std::greater<T>(one.peek(), another.peek())) {
    if (one.isEmpty() || another.isEmpty()) return false;
    if (one.peek() > another.peek()) {
//        std::swap(
        T tmp1 = one.pop();
        T tmp2 = another.pop();
        one.push(tmp2);
        another.push(tmp1);
        return true;
    }
    return false;
}
template <typename T>
void sortAscending(Stack<T>& orig) {
    Stack<T> tmp;
    bool changes { false };
    do {
        changes = false;
        while(!orig.isEmpty()) {
            shiftUpwards(orig, tmp);
            changes |= swapStackTops(orig, tmp);
        }
        //now move it back
        while (!tmp.isEmpty()) {
            shiftUpwards(tmp, orig);
        }
    } while (changes);
    
}

template<typename T>
bool checkSorted(const Stack<T>& s) {
    Stack<T> copy { s };
    T topmost = copy.pop();
    while(!copy.isEmpty()) {
        //std::cout << "topmost=" << topmost << std::endl;
        T next = copy.pop();
        if (next > topmost) return false;
        topmost = next;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "question 3.6 \n";
    Stack<int> s;
    s.push(4); s.push(3); s.push(1); s.push(6);
    std::cout << " size of stack " << s.size() << std::endl;
    std::cout << "is stack sorted? : " << checkSorted(s) << std::endl;
    sortAscending(s);
    std::cout << "is stack sorted? : " << checkSorted(s) << std::endl;
    //test on a hundred pseudo random samples
    for (int i = 0; i < 100; ++i) {
        Stack<int> stack;
        for (int j = 0; j < 15; ++j)
            stack.push(std::rand() % 20);
        stack.print();
        sortAscending(stack);
        std::cout << "after sorting: ";
        stack.print();
        if (!checkSorted(stack))
            return true; // error code
    }
    return 0;
}
