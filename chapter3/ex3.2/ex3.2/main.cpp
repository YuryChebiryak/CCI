//
//  main.cpp
//  ex3.2
//
//  Created by Yury Chebiryak on 14/01/17.
//  Copyright © 2017 Yury Chebiryak. All rights reserved.
//

#include <iostream>
#include <stack>

//3.2 How would you design a stack which, in addition to push and pop, also has a function min which returns the minimum element? Push, pop and min should all operate in 0(1) time.

template<typename T>
class MinStack {
public:
    void push(const T& v) {
        theValues.push(v);
        if ((theMin.size() == 0) or (theMin.top() >= v))
            theMin.push(v);
    }
    
    void pop() {
        if ((theMin.size() > 0) and (theMin.top() == theValues.top()))
            theMin.pop();
        return theValues.pop();
    }
    
    const T& top() const {
        return theValues.top();
    }
    
    const T& min() const {
        return theMin.top();
    }
private:
    std::stack<T> theValues;
    std::stack<T> theMin;
};

int main(int argc, const char * argv[]) {
    MinStack<int> t;
    t.push(5);
    std::cout << "t.top=" << t.top() << ", min=" << t.min() << std::endl;
    t.push(3);
    std::cout << "t.top=" << t.top() << ", min=" << t.min() << std::endl;
    t.push(6);
    std::cout << "t.top=" << t.top() << ", min=" << t.min() << std::endl;
    t.pop();
    std::cout << "t.top=" << t.top() << ", min=" << t.min() << std::endl;
    t.push(2);
    std::cout << "t.top=" << t.top() << ", min=" << t.min() << std::endl;
    t.push(3);
    std::cout << "t.top=" << t.top() << ", min=" << t.min() << std::endl;
    t.pop();
    std::cout << "t.top=" << t.top() << ", min=" << t.min() << std::endl;
    t.push(1);
    std::cout << "t.top=" << t.top() << ", min=" << t.min() << std::endl;
    t.pop();
    std::cout << "t.top=" << t.top() << ", min=" << t.min() << std::endl;
    t.push(0);
    std::cout << "t.top=" << t.top() << ", min=" << t.min() << std::endl;
    return 0;
}
