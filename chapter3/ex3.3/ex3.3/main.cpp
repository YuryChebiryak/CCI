//
//  main.cpp
//  ex3.3
//
//  Created by Yury Chebiryak on 15/01/17.
//  Copyright © 2017 Yury Chebiryak. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <deque>

//Cracking the Coding Interview, 5th Edition
//3.3 Imagine a (literal) stack of plates. If the stack gets too high, it might topple. Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold. Implement a data structure SetOfStacks that mimics this. SetOf- Stacks should be composed of several stacks and should create a new stack once the previous one exceeds capacity. SetOfStacks.push() and SetOfStacks. pop () should behave identically to a single stack (that is, pop () should return the same values as it would if there were just a single stack).
//FOLLOW UP
//Implement a function popAt(int index) which performs a pop operation on a specific sub-stack

template<typename T, size_t MAX_SZ>
class SetOfStacks{
public:
    void push(const T& v) {
        if (theContainer.empty())
            theContainer.push_back({});
        if (theContainer.back().size() == MAX_SZ)
            theContainer.push_back({});
        theContainer.back().push(v);
    }
    const T& top() const {
        return theContainer.back().top();
    }
    void pop() {
        theContainer.back().pop();
        if ((theContainer.back().empty()) and (nStacks() != 1))
            theContainer.pop_back();
    }
    size_t nStacks() const { return theContainer.size(); }
private:
    std::vector<std::stack<T>> theContainer{std::stack<T>{}};
};

template<typename T, size_t MAX_SZ>
class SetOfStacks2{
public:
    void push(const T& v) {
        if (theContainer.empty())
            theContainer.push_back({});
        if (theContainer.back().size() == MAX_SZ)
            theContainer.push_back({});
        theContainer.back().push_front(v);
    }
    const T& top() const {
        return theContainer.back().front();
    }
    void pop() {
        theContainer.back().pop_front();
        if ((theContainer.back().empty()) and (nStacks() != 1))
            theContainer.pop_back();
    }
    size_t nStacks() const { return theContainer.size(); }
    void popAt(size_t index) {
        //need to propagate the pop
        std::cout << "in popAt() function " <<  *this << std::endl;
        while (index != theContainer.size() - 2) {
            theContainer[index].pop_front();
            theContainer[index].push_front(theContainer[index+1].back());
            ++index;
            std::cout << " in the while loop " << *this << std::endl;
        }
        theContainer.back().pop_front();
        if (theContainer.back().empty() and (nStacks() != 1))
            theContainer.pop_back();
    }
    friend std::ostream& operator<<(std::ostream& stream, const SetOfStacks2& container) {
        for (auto i = 0; i < container.theContainer.size(); ++i) {
            stream << "(" << i << ":";
            for (auto j = 0; j < container.theContainer[i].size(); ++j)
                stream << container.theContainer[i][j] << ( j < container.theContainer[i].size() ? "," : "");
            stream << ")";
        }
        stream << std::endl;
        return stream;
    }
private:
    std::vector<std::deque<T>> theContainer{std::deque<T>{}};
};

int main(int argc, const char * argv[]) {
    SetOfStacks2	<int, 2> t;
    t.push(5);
    std::cout << "t.top=" << t.top() << ", size=" << t.nStacks() << std::endl;
    t.push(3);
    std::cout << "t.top=" << t.top() << ", size=" << t.nStacks() << std::endl;
    t.push(6);
    std::cout << "t.top=" << t.top() << ", size=" << t.nStacks() << std::endl;
    t.pop();
    std::cout << "t.top=" << t.top() << ", size=" << t.nStacks() << std::endl;
    t.push(2);
    std::cout << "t.top=" << t.top() << ", size=" << t.nStacks() << std::endl;
    t.push(3);
    std::cout << "t.top=" << t.top() << ", size=" << t.nStacks() << std::endl;
    t.pop();
    std::cout << "t.top=" << t.top() << ", size=" << t.nStacks() << std::endl;
    t.push(1);
    std::cout << "t.top=" << t.top() << ", size=" << t.nStacks() << std::endl;
    t.pop();
    std::cout << "t.top=" << t.top() << ", size=" << t.nStacks() << std::endl;
    t.push(0);
    std::cout << "t.top=" << t.top() << ", size=" << t.nStacks() << std::endl;
    t.push(3);
    std::cout << "t.top=" << t.top() << ", size=" << t.nStacks() << std::endl;
    t.push(4);
    std::cout << "t.top=" << t.top() << ", size=" << t.nStacks() << std::endl;
    t.push(5);
    std::cout << "t.top=" << t.top() << ", size=" << t.nStacks() << std::endl;
    t.push(6);
    std::cout << "t.top=" << t.top() << ", size=" << t.nStacks() << std::endl;
    std::cout << t;
    std::cout << "before pop at 1" << std::endl;
    t.popAt(1);
    std::cout << t;
    std::cout << "t.top=" << t.top() << ", size=" << t.nStacks() << std::endl;

    
    return 0;
}
