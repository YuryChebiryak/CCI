//
//  main.cpp
//  ex3.7
//
//  Created by Yury Chebiryak on 19/10/18.
//  Copyright © 2018 Yury Chebiryak. All rights reserved.
//

#include <iostream>
#include <list>
/*
An animal shelter holds only dogs and cats, and operates on a strictly "first in, first out" basis. People must adopt either the "oldest" (based on arrival time) of all animals at the shelter, or they can select whether they would prefer a dog or a cat (and will receive the oldest animal of that type). They cannot select which specific animal they would like. Create the data structures to maintain this system and implement opera- tions such as enqueue, dequeueAny, dequeueDog and dequeueCat. You may use the built-in L inkedL ist data structure.
*/

/*
 keep a 'time' counter and two queues
 if the oldest animal is being adopted: peek at both queues and give the one with oldest timestamp
 otherwise fetch the last animal from the corresp queue
 */

// don't wanna make timestamp a part of the animal class.
//  -> use a policy to decorate animals with timestamps?
//  -> use a wrapper class for an animal and a corresp timestamp?
class Animal {
public:
    Animal(const std::string& n) : name (n) {}
    virtual ~Animal() {}
    virtual    void print() {};
protected:
    std::string name;
};
class Dog : public Animal {
public:
    Dog(const std::string& n) : Animal(n) {}
    virtual ~Dog() {}
    void print() { std::cout << " Dog named " << name << " "; }
};
class Cat : public Animal {
public:
    Cat(const std::string& n) : Animal(n) {}
    virtual ~Cat() {}
    void print() { std::cout << " Cat named " << name << " "; }
};
class Shelter {
public:
    Shelter() {
        timestamp = 0;
    }
    
    void enqueue(Animal* animal) {
        if (dynamic_cast<Dog*>(animal)) {
            dogs.push_front(dynamic_cast<Dog*>(animal));
            dogsTimestamps.push_front(timestamp++);
        }
        if (dynamic_cast<Cat*>(animal)) {
            cats.push_front(dynamic_cast<Cat*>(animal));
            catsTimestamps.push_front(timestamp++);
        }
    }
    Dog* dequeDog() {
        Dog* res = dogs.back();
        dogs.pop_back();
        dogsTimestamps.pop_back();
        return res;
    }
    Cat *dequeCat() {
        Cat* cat = cats.back();
        cats.pop_back();
        catsTimestamps.pop_back();
        return cat;
    }
    Animal* dequeAny() {
        if (dogs.empty() && cats.empty())
            return nullptr;
        if (dogs.empty())
            return dequeCat();
        if (cats.empty())
            return dequeDog();
        if (dogsTimestamps.back() < catsTimestamps.back()) {
            return dequeDog();
        } else {
            return dequeCat();
        }
    }
private:
    int timestamp;
    std::list<Dog*> dogs;
    std::list<int> dogsTimestamps;
    std::list<Cat*> cats;
    std::list<int> catsTimestamps;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Dog d1("Dingo");
    Dog d2("Zorro");
    Dog d3("King");
    Dog d4("Argo");
    Cat c1("Fluffy");
    Cat c2("Kitten");
    Cat c3("Cutie");
    Shelter s;
    s.enqueue(&d1); s.enqueue(&c1);
    s.enqueue(&d2); s.enqueue(&c2);
    s.enqueue(&d3); s.enqueue(&d4); s.enqueue(&c3);
    Animal* animal = s.dequeCat();
    std::cout << "adopted "; animal->print();
    animal = s.dequeAny();
    std::cout << "adopted "; animal->print();
    animal = s.dequeAny();
    std::cout << "adopted "; animal->print();
    animal = s.dequeCat();
    std::cout << "adopted "; animal->print();
    animal = s.dequeAny();
    std::cout << "adopted "; animal->print();
    animal = s.dequeAny();
    std::cout << "adopted "; animal->print();
    animal = s.dequeAny();
    std::cout << "adopted "; animal->print();

    return 0;
}
