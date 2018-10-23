//
//  main.cpp
//  ex4.1
//
//  Created by Yury Chebiryak on 19/10/18.
//  Copyright © 2018 Yury Chebiryak. All rights reserved.
//

#include <iostream>
#include <utility>
#include <set>
#include <queue>
#include <unordered_set>
/*
 
 ex 4.1
 Implement a function to check if a binary tree is balanced. For the purposes of this question, a balanced tree is defined to be a tree such that the heights of the two subtrees of any node never differ by more than one.
 */

template<typename T>
class TreeNode {
public:
    void print() { std::cout << "node: " << value << " "; }
    TreeNode(const T& val, TreeNode* l, TreeNode* r) : value(val), left(l), right(r) {}
    T value;
    TreeNode* left;
    TreeNode* right;
};

template<typename T>
std::pair<bool, int> checkBalanced(TreeNode<T>* root) {
    std::cout << "at " ; root->print();
    std::pair<bool, int> recurseLeft {false, 0};
    std::pair<bool, int> recurseRight {false, 0};
    if (root->right)
        recurseRight = checkBalanced(root->right);
    if (root->left)
        recurseLeft = checkBalanced(root->left);
    if (!recurseLeft.first || !recurseRight.first) {
        std::cout << " some sub-tree is unbalanced " << std::endl;
        return std::make_pair(false, 0);
    }
    if (abs(recurseLeft.second - recurseRight.second) > 1) {
        std::cout << " one sub-tree is much higher than the other ";
        return std::make_pair(false, 0);
    }
    int max_height {std::max(recurseRight.second, recurseLeft.second) + 1};
    std::cout << " node is balanced, max height of the sub-trees is " << max_height << " ";
    return std::make_pair(true, max_height);
    
}

/*
 4.2 Given a directed graph, design an algorithm to find out whether there is a route between two nodes.
 */

// just a BFS which stops when a given node is reached?
// too vague, need to elaborate: is the graph represented as an adjacency matrix? can the operation be destructive to that matrix?
// maintain a queue of unvisited nodes, mark those which are visited/put them into a set
class Graph {
public:
    bool adjacent(int a, int b) const {
        return links.find(std::make_pair(a, b)) != links.end();
    }
    std::vector<int> getLinks(int a) const {
        std::vector<int> res;
        for (auto link: links) {
            if (link.first == a)
                res.push_back(link.second);
        }
        return res;
    }
    void addLink(int a, int b) {
        links.insert(std::make_pair(a, b));
    }
private:
    std::set<std::pair<int, int>> links;
};

bool BFSreach(const Graph& g, int source, int target) {
    std::cout << " is node " << target << " reachable from " << source << "? ";
    std::queue<int> todo;
    todo.push(source);
    std::unordered_set<int> visited;
    while (!todo.empty()) {
        int process = todo.front();
        if (process == target) // the target node has been found, exiting
            return true;
        todo.pop();
        if (visited.find(process) == visited.end()) { // might have seen this node already due to other links
            visited.insert(process);
            //now have to go over all the links of that node (expensive for sparse graphs specified as adj matrix but what can we do :(
            for (auto outgoing : g.getLinks(process)) {
                //if (visited.find(outgoing) == visited.end()) { // probably more efficient without this check
                    todo.push(outgoing);
                //}
            }
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    std::cout << "ex4.1 \n";
    TreeNode<int> a {15, nullptr, nullptr};
    TreeNode<int> b {10, &a, nullptr };
    TreeNode<int> c {5, nullptr, nullptr };
    TreeNode<int> d {3, &b, &c };
    std::pair<bool, int> res { checkBalanced(&d) };
    std::cout << " is the tree balanced? " << res.first << std::endl;
    
    std::cout << "ex4.2 \n";
    Graph g;
    g.addLink(1, 2);
    g.addLink(2, 3);
    g.addLink(2, 5);
    g.addLink(5, 6);
    g.addLink(6, 4);
    std::cout << (BFSreach(g, 1, 2) ? " yes " : " no ") << std::endl;
    std::cout << (BFSreach(g, 2, 3) ? " yes " : " no ") << std::endl;
    std::cout << (BFSreach(g, 1, 3) ? " yes " : " no ") << std::endl;
    std::cout << (BFSreach(g, 2, 5) ? " yes " : " no ") << std::endl;
    std::cout << (BFSreach(g, 1, 5) ? " yes " : " no ") << std::endl;
    std::cout << (BFSreach(g, 5, 6) ? " yes " : " no ") << std::endl;
    std::cout << (BFSreach(g, 2, 6) ? " yes " : " no ") << std::endl;
    std::cout << (BFSreach(g, 6, 4) ? " yes " : " no ") << std::endl;
    std::cout << (BFSreach(g, 5, 4) ? " yes " : " no ") << std::endl;
    std::cout << (BFSreach(g, 2, 4) ? " yes " : " no ") << std::endl;
    std::cout << (BFSreach(g, 1, 4) ? " yes " : " no ") << std::endl;
    std::cout << (BFSreach(g, 2, 1) ? " yes " : " no ") << std::endl;
    std::cout << (BFSreach(g, 3, 1) ? " yes " : " no ") << std::endl;
    std::cout << (BFSreach(g, 3, 2) ? " yes " : " no ") << std::endl;
    std::cout << (BFSreach(g, 5, 2) ? " yes " : " no ") << std::endl;
    std::cout << (BFSreach(g, 4, 5) ? " yes " : " no ") << std::endl;
    return 0;
}
