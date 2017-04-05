// ex3.3.cpp : main project file.

#include <iostream>
#include <stack>
#include <vector>
#include <string>
/*
Imagine a(literal) stack of plates.If the stack gets too high, it might topple.
Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold. 
Implement a data structure SetOfStacks that mimics this. SetOfStacks should be composed of several stacks and should create a new stack once the previous one exceeds capacity.
SetOfStacks.push() and SetOfStacks.pop() should behave identically to a single stack (that is, pop() should return the same values as it would if there were just a single stack.
	FOLLOW UP
	Implement a function popAt(int index) which performs a pop operation on a specific sub-stack.
*/

// Since we know the max size of each sub-stack, it's natural to use vectors to implement substacks, then pop(), push() and top() operations remain O(1)
using namespace std;

template<typename T, int SZ>
class SetOfStacks {
public:
	SetOfStacks() {
		auto v = std::vector<T>{};
		v.reserve(SZ);
		theContainer.push_back(v);
	}

	void push(const T& val) {
		auto& back = theContainer.back();
		if (back.size() < SZ) 
			back.push_back(val);
		else {
			auto vec = std::vector<T>{val};
			vec.reserve(SZ);
			theContainer.push_back(vec);
		}
	}

	void pop()	{
		auto& back = theContainer.back();
		back.pop_back();
		if (theContainer.size() > 1 && back.size() == 0)
			theContainer.pop_back();
	}

	const T& top() const {
		auto& back = theContainer.back();
		if (back.size())
			return back.back();
		else 
			return T{};
	};

	const auto size() const	{
		return theContainer.size();
	}

	void popAt(int index) {
		if (index == size() - 1)
			pop();
		else {
			int j = index;
			while (j + 1 < size()) {
				// take out the topmost, replace it with the bottom of the next one and shift the next one
				theContainer[j][SZ-1] = theContainer[j+1][0];
				for (int i = 0; i < theContainer[j+1].size() - 1; ++i)
					theContainer[j+1][i] = theContainer[j+1][i+1];
				++j;
			}
			pop(); // need to purge the last element, which was copied, but not erased
		}
	};

	string toString() const	{
		string res = "(";
		for (auto& v : theContainer) {
			res += "[";
			for(auto& el : v)
				res += string(el) + ","; //""std::to_string(el) + ",";
			res += "],";
		}
		return res + ")";
	}
	
private:
	std::vector<std::vector<T>> theContainer;
};

int main(int argc, const char * argv[]) {
	SetOfStacks<int, 2> t;
	t.push(5);
	std::cerr << t.toString() << std::endl;
	t.push(3);
	std::cerr << t.toString() << std::endl;
	t.push(6);
	std::cerr << t.toString() << std::endl;
	t.push(7);
	std::cerr << t.toString() << std::endl;
	t.push(8);
	std::cerr << t.toString() << std::endl;
	t.popAt(0);
	std::cerr << t.toString() << std::endl;
	t.push(9);
	std::cerr << t.toString() << std::endl;
	t.push(10);
	std::cerr << t.toString() << std::endl;
	t.push(11);
	std::cerr << t.toString() << std::endl;
	t.push(12);
	std::cerr << t.toString() << std::endl;
	t.popAt(1);
	std::cerr << t.toString() << std::endl;
	t.popAt(0);
	std::cerr << t.toString() << std::endl;


	t = SetOfStacks<int, 2>{};
	t.push(5);
	std::cerr << "t.top=" << t.top() << " size=" << t.size() << std::endl;
	t.push(3);
	std::cerr << "t.top=" << t.top() << " size=" << t.size() << std::endl;
	t.popAt(0);
	std::cerr << "t.top=" << t.top() << " size=" << t.size() << std::endl;

	t.push(6);
	std::cerr << "t.top=" << t.top() << " size=" << t.size() << std::endl;
	t.pop();
	std::cerr << "t.top=" << t.top() << " size=" << t.size() << std::endl;
	t.push(2);
	std::cerr << "t.top=" << t.top() << " size=" << t.size() << std::endl;
	t.push(3);
	std::cerr << "t.top=" << t.top() << " size=" << t.size() << std::endl;
	t.pop();
	std::cerr << "t.top=" << t.top() << " size=" << t.size() << std::endl;
	t.push(1);
	std::cerr << "t.top=" << t.top() << " size=" << t.size() << std::endl;
	t.pop();
	std::cerr << "t.top=" << t.top() << " size=" << t.size() << std::endl;
	t.push(0);
	std::cerr << "t.top=" << t.top() << " size=" << t.size() << std::endl;
	t.push(12);
	std::cerr << "t.top=" << t.top() << " size=" << t.size() << std::endl;
	t.push(13);
	std::cerr << "t.top=" << t.top() << " size=" << t.size() << std::endl;
	t.pop();
	std::cerr << "t.top=" << t.top() << " size=" << t.size() << std::endl;
	t.pop();
	std::cerr << "t.top=" << t.top() << " size=" << t.size() << std::endl;

	return 0;
}
