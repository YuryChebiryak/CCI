//
//  main.cpp
//  ex3.4
//
//  Created by Yury Chebiryak on 03/09/17.
//  Copyright © 2017 Yury Chebiryak. All rights reserved.
//

//3.5 Implement a MyQueue class which implements a queue using two stacks.

// a queue has the following functions: push, pop, size
// if a push() is invoked, we move all the elements into the first stack and put the new element atop
// if the pop() is invoked, we move all the elements into the second stack and pop from it
// size is the sum of stack sizes

#include <iostream>
#include <stack>

template <typename T>
class MyQueue{
public:
    T front() {
        while(s1.size()) {
            T temp = s1.top();
            s2.push(temp);
            s1.pop();
        }
        return s2.top();
    }
    
    T back() {
        while (s2.size()) {
            T temp = s2.top();
            s1.push(temp);
            s2.pop();
        }
        return s1.top();
    }
    
    void push(const T& elem) {
        while (s2.size()) {
            T temp = s2.top();
            s2.pop();
            s1.push(temp);
        }
        s1.push(elem);
    }
    
    void pop() {
        while (s1.size()) {
            T temp = s1.top();
            s1.pop();
            s2.push(temp);
        }
        if (!s2.empty())
            s2.pop();
    }
    
    size_t size() const {
        return s1.size() + s2.size();
    }
    
    size_t empty() const {
        return s1.empty() && s2.empty();
    }
private:
    std::stack<T> s1;
    std::stack<T> s2;
};

int main(int argc, const char * argv[]) {
    MyQueue<char> q;
    q.push('q');
    std::cout << "top=" << q.front() << ", back=" << q.back() << std::endl;
    q.push('u');
    std::cout << "top=" << q.front() << ", back=" << q.back() << std::endl;
    q.push('e');
    std::cout << "top=" << q.front() << ", back=" << q.back() << std::endl;
    q.push('u');
    std::cout << "top=" << q.front() << ", back=" << q.back() << std::endl;
    q.push('e');
    std::cout << "top=" << q.front() << ", back=" << q.back() << std::endl;
    q.pop();
    std::cout << "top=" << q.front() << ", back=" << q.back() << std::endl;
    q.pop();
    std::cout << "top=" << q.front() << ", back=" << q.back() << std::endl;
    q.push('O');
    std::cout << "top=" << q.front() << ", back=" << q.back() << std::endl;
    q.push('K');
    std::cout << "top=" << q.front() << ", back=" << q.back() << std::endl;
    q.pop();
    std::cout << "top=" << q.front() << ", back=" << q.back() << std::endl;
    q.pop();
    std::cout << "top=" << q.front() << ", back=" << q.back() << std::endl;
    q.pop();
    std::cout << "top=" << q.front() << ", back=" << q.back() << std::endl;
    q.pop();
    std::cout << "top=" << q.front() << ", back=" << q.back() << std::endl;
    q.pop();

    return 0;
}
