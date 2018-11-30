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
#include <algorithm>
#include <unordered_set>
#include <list>
#include <stack>
#include <stdlib.h>
#include <assert.h>
/*
 
 ex 4.1
 Implement a function to check if a binary tree is balanced. For the purposes of this question, a balanced tree is defined to be a tree such that the heights of the two subtrees of any node never differ by more than one.
 */

template<typename T>
class TreeNode {
public:
    void print() { std::cout << "node: " << value << " "; }
    TreeNode(const T& val, TreeNode* l, TreeNode* r) : value(val), left(l), right(r) { parent = nullptr; }
    T value;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
};

template<typename T>
std::pair<bool, int> checkBalanced(TreeNode<T>* root) {
//    std::cout << "at " ; root->print();
    std::pair<bool, int> recurseLeft {false, 0};
    std::pair<bool, int> recurseRight {false, 0};
    if (root->right)
        recurseRight = checkBalanced(root->right);
    if (root->left)
        recurseLeft = checkBalanced(root->left);
    if (!recurseLeft.first || !recurseRight.first) {
  //      std::cout << " some sub-tree is unbalanced " << std::endl;
        return std::make_pair(false, 0);
    }
    if (abs(recurseLeft.second - recurseRight.second) > 1) {
    //    std::cout << " one sub-tree is much higher than the other ";
        return std::make_pair(false, 0);
    }
    int max_height {std::max(recurseRight.second, recurseLeft.second) + 1};
    //std::cout << " node is balanced, max height of the sub-trees is " << max_height << " ";
    return std::make_pair(true, max_height);
}

template<typename T>
int getHeight(TreeNode<T>* root) {
    int recurseLeft { 0 };
    int recurseRight { 0 };
    if (root->right)
        recurseRight = getHeight(root->right);
    if (root->left)
        recurseLeft = getHeight(root->left);
    return std::max(recurseLeft, recurseRight) + 1;
}

void ex4_1() {
    std::cout << "ex4.1 \n";
    TreeNode<int> a {15, nullptr, nullptr};
    TreeNode<int> b {10, &a, nullptr };
    TreeNode<int> c {5, nullptr, nullptr };
    TreeNode<int> d {3, &b, &c };
    std::pair<bool, int> res { checkBalanced(&d) };
    std::cout << " is the tree balanced? " << res.first << std::endl;
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


void ex4_2() {
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
}
/*
4.3 Given a sorted (increasing order) array with unique integer elements, write an algo- rithm to create a binary search tree with minimal height.
*/

// 1 3 6 7 8 20 24 33 35 39 41 46 50 90 121
// isn't it just cutting every time in half? integers are unique
// minimal height is log (n)

template<typename T>
TreeNode<T>* createBST(const std::vector<T>& sorted, int first, int last) {
    int rootInd = (last - first) / 2 + first;
    if (last == first + 1) // base case
        return new TreeNode<T>(sorted[first], nullptr, nullptr);
    TreeNode<T>* leftPtr = nullptr;
    if (first != rootInd)
        leftPtr = createBST(sorted, first, rootInd);
    TreeNode<T>* rightPtr = nullptr;
    if (rootInd + 1 != last)
        rightPtr= createBST(sorted, rootInd + 1, last);
    TreeNode<T>* res = new TreeNode<T>(sorted[rootInd], leftPtr, rightPtr);
    if (leftPtr)
        leftPtr->parent = res;
    if (rightPtr)
        rightPtr->parent = res;
    return res;
}

void ex4_3() {
    std::cout << "ex4.3 \n";
    for (int cases = 0; cases < 50; ++cases) {
        std::vector<int> in;
        for (int sample = 0; sample < std::rand() % 10000; ++sample)
            in.push_back(std::rand() % 20);
        std::sort(in.begin(), in.end());
        auto node = createBST(in, 0, (int) in.size()) ;
        auto height = getHeight(node) ;
        std::cout << " sample size=" << in.size() << ", max height = " << height << ", log(size)=" << log2(in.size()) << std::endl;
    }
}

/* 4.4 Given a binary tree, design an algorithm which creates a linked list of all the nodes at
 each depth (e.g., if you have a tree with depth D, you'll have D linked lists).
 */

template<typename T>
std::vector<std::list<TreeNode<T>* > > createLists(TreeNode<T>* root) {
    int depth = 0;
    std::vector<std::list<TreeNode<T>* > > res;
    std::list<TreeNode<T>* > level;
    level.push_back(root);
    res.push_back(level);
    do {
        // look at the current level, collect the descendant nodes
        std::list<TreeNode<T>* > nextLevel;
        for (auto node : res[depth]) {
            if (node->left)
                nextLevel.push_back(node->left);
            if (node->right)
                nextLevel.push_back(node->right);
        }
        if (nextLevel.empty())
            return res;
        ++depth;
        res.push_back(nextLevel);
    } while (true);
    return res;
}

void ex4_4() {
    std::cout << "ex4.4 \n";
        std::vector<int> in;
        for (int sample = 0; sample < std::rand() % 10000; ++sample)
            in.push_back(std::rand() % 20);
        std::sort(in.begin(), in.end());
        auto node = createBST(in, 0, (int) in.size()) ;
        auto height = getHeight(node) ;
        std::cout << " sample size=" << in.size() << ", max height = " << height << ", log(size)=" << log2(in.size()) << std::endl;
    auto lists = createLists(node);
    for (int depth = 0; depth < lists.size(); ++depth) {
        std::cout << " level " << depth << ": ";
        for (auto elem : lists[depth]) {
            std::cout << elem->value << ", ";
        }
        std::cout << std::endl;
    }
}

/* 4.5 Implement a function to check if a binary tree is a binary search tree.
 */
template<typename T>
bool checkBST(TreeNode<T>* node) {
    // value of left child must be less, value of the right one must be greater
    if (node->left) {
        if (node->left->value >= node->value)
            return false;
        if (!checkBST(node->left))
            return false;
    }
    if (node->right) {
        if (node->right->value < node->value)
            return false;
        if (!checkBST(node->right))
            return false;
    }
    return true;
}

void ex4_5() {
    std::cout << "ex4.5 \n";
    std::vector<int> in;
    for (int sample = 0; sample < std::rand() % 10000; ++sample)
        in.push_back(std::rand() % 20);
    std::sort(in.begin(), in.end());
    auto node = createBST(in, 0, (int) in.size()) ;
//    std::cout << " sample size=" << in.size() << ", max height = " << height << ", log(size)=" << log2(in.size()) << std::endl;
    std::cout << "is it a BST? " << checkBST(node);
}

/* 4.6 Write an algorithm to find the 'next'node (i.e., in-order successor) of a given node in
 a binary search tree. You may assume that each node has a link to its parent.
 */
template<typename T>
TreeNode<T>* getNextNode(TreeNode<T>* node) {
    if (node->right) { // need to take the route to the right once and then downwards taking left all the time if possible
        TreeNode<T>* current = node->right;
        while (current->left)
            current = current->left;
        return current;
    } else {
        // this is incorrect!
        /*// need to go up till we have a route to the right and then take right turn and slide downwards taking left all the time
        TreeNode<T>* junction = node->parent;
        while (junction != nullptr && junction->right == nullptr)
            junction = junction->parent;
        if (junction->right == nullptr) return junction;
        TreeNode<T>* current = junction->right;
        while (current->left)
            current = current->left;
        return current;
         */
        /*
         But what if the node doesn't have a right subtree? This is where it gets a bit trickier.
         If a node n doesn't have a right subtree, then we are done traversing n's subtree. We need to pick up where we left off with n's parent, which we'll call q.
         If n was to the left of q, then the next node we should traverseshould be q (again, since le ft -> current -> right).
         If n were to the right of q, then we have fully traversed q's subtree as well. We need to traverse upwards from q until we find a node x that we have nof fully traversed.How do we know that we have not fully traversed a node x? We know we have hit this case when we move from a left node to its parent. The left node is fully traversed, but its parent is not.
         */
        TreeNode<T>* q = node;
        TreeNode<T>* x = q->parent;
        while (x != nullptr && x->left != q) {
            q = x;
            x = x->parent;
        }
        return x;
    }
    return nullptr;
}

void ex4_6() {
    std::cout << "ex4.6 \n";
    std::vector<int> in;
    for (int sample = 0; sample <  10; ++sample)
        in.push_back(std::rand() % 2000);
    std::sort(in.begin(), in.end());
    TreeNode<int>* node = createBST(in, 0, (int) in.size()) ;
    auto root = node;
    TreeNode<int>* rightmost = root;
    std::cout << "root.value=" << root->value << ", node.value=" << node->value << ", rightmost.value=" << rightmost->value << std::endl;
    rightmost = rightmost->right;
    rightmost = rightmost->right;
    auto next = getNextNode(rightmost);
    std::cout << "next node of node "  << rightmost->value << " is " << (next ? next->value : -1 ) << std::endl;   //    std::cout << " sample size=" << in.size() << ", max height = " << height << ", log(size)=" << log2(in.size()) << std::endl;
    //std::cout << "is it a BST? " << checkBST(node);
    auto lists = createLists(node);
    for (int depth = 0; depth < lists.size(); ++depth) {
        std::cout << " level " << depth << ": ";
        for (auto elem : lists[depth]) {
            std::cout << elem->value << ", ";
        }
        std::cout << std::endl;
    }
   
    std::cout << "next node of node "  << node->value << " is " << getNextNode(node)->value << std::endl;
    node = node->right;
    std::cout << "next node of node "  << node->value << " is " << getNextNode(node)->value << std::endl;
    node = node->left;
    std::cout << "next node of node "  << node->value << " is " << getNextNode(node)->value << std::endl;
    node = node->left;
    std::cout << "next node of node "  << node->value << " is " << getNextNode(node)->value << std::endl;
}

/* 4.7 Design an algorithm and write code to find the first common ancestor of two nodes in a binary tree. Avoid storing additional nodes in a data structure.NOTE: This is not necessarily a binary search tree.
 */
// we have to either assume that we have links to parents at nodes or that we are given the root node
template<typename T>
std::stack<TreeNode<T>*> getPath(TreeNode<T>* a) {
    std::stack<TreeNode<T> *> path;
    TreeNode<T>* aParent = a->parent;
    while (aParent != nullptr) {
        path.push(aParent);
        aParent = aParent->parent;
    };
    return path;
}

template<typename T>
TreeNode<T>* firstCommonAncestor(TreeNode<T>* a, TreeNode<T>* b) {
    std::stack<TreeNode<T>* > aPath = getPath(a), bPath = getPath(b);
    //now consider them in the reversed order
    TreeNode<T>* commonAncestor = nullptr;
    while ( !aPath.empty() && !bPath.empty() && aPath.top() == bPath.top()) {
        commonAncestor = aPath.top();
        
        aPath.pop();
        bPath.pop();
    }
    return commonAncestor;
}

template<typename T>
TreeNode<T>* commonAncestorDescendRec(TreeNode<T>* root, TreeNode<T>* a, TreeNode<T>* b, bool& coversA, bool& coversB) {
    if (root == nullptr) {
        return nullptr; // we don't update values of coversA and coversB
    }
    // need to check if both nodes are in the same subtree
    TreeNode<T>* leftRes = nullptr;
    bool leftCoversA = false;
    bool leftCoversB = false;
    if (root->left != nullptr) {
        leftRes = commonAncestorDescendRec(root->left, a, b, leftCoversA, leftCoversB);
    }
    TreeNode<T>* rightRes = nullptr;
    bool rightCoversA = false;
    bool rightCoversB = false;
    if (root->right != nullptr) {
        rightRes = commonAncestorDescendRec(root->right, a, b, rightCoversA, rightCoversB);
    }
    coversA = coversA || (root == a) || leftCoversA || rightCoversA;
    coversB = coversB || (root == b) || rightCoversA || rightCoversB;
    if (leftCoversA && leftCoversB)
        return leftRes;
    if (rightCoversA && rightCoversB)
        return rightRes;
    if ((leftCoversA && rightCoversB) || (leftCoversB && rightCoversA))
        return root;
    return nullptr;
}



void ex4_7() {
    std::cout << "ex4.7 \n";
    std::vector<int> in;
    for (int sample = 0; sample <  10; ++sample)
        in.push_back(std::rand() % 2000);
    std::sort(in.begin(), in.end());
    TreeNode<int>* node = createBST(in, 0, (int) in.size()) ;
    auto root = node;
    TreeNode<int>* rightmost = root;
    std::cout << "root.value=" << root->value << ", node.value=" << node->value << ", rightmost.value=" << rightmost->value << std::endl;
    rightmost = rightmost->right;
    TreeNode<int>* oneToLeft = rightmost->left;
    rightmost = rightmost->right;
    
    
    auto next = getNextNode(rightmost);
    std::cout << "next node of node "  << rightmost->value << " is " << (next ? next->value : -1 ) << std::endl;   //    std::cout << " sample size=" << in.size() << ", max height = " << height << ", log(size)=" << log2(in.size()) << std::endl;
    //std::cout << "is it a BST? " << checkBST(node);
    auto lists = createLists(node);
    for (int depth = 0; depth < lists.size(); ++depth) {
        std::cout << " level " << depth << ": ";
        for (auto elem : lists[depth]) {
            std::cout << elem->value << ", ";
        }
        std::cout << std::endl;
    }
    
    //auto common = firstCommonAncestor(rightmost, oneToLeft);
    bool coversA = false; bool coversB = false;
    auto common = commonAncestorDescendRec(root, rightmost, oneToLeft, coversA, coversB);
    assert(common->value == 1709);
    coversA = false; coversB = false;
  //  common = firstCommonAncestor(root, rightmost);
    common = commonAncestorDescendRec(root, root, rightmost, coversA, coversB);
    assert(common == nullptr);
    std::cout << "common ancestor = " << (common ? common->value : 0) << std::endl;
}

/*4.8 You have two very large binary trees: Tl, with millions of nodes, and T2, with
hundreds of nodes. Create an algorithm to decideifT2 isa subtree ofTl.
A tree T2 is a subtree of Tl if there exists a node n in Tl such that the subtree ofn is identical to T2. That is, if you cut off the tree at node n, the two trees would be identical.
*/

template<typename T>
class Metrics {
public:
    T    root_value;
    bool has_left_child;
    bool has_right_child;
    T    left_value;
    T    right_value;
    size_t depth;
    size_t n_nodes;
    T hash;
    
};

template<typename T>
Metrics<T> collectMetrics(TreeNode<T>* root) {
    Metrics<T> res;
    if (root != nullptr) {
        res.root_value = root->value;
        res.has_left_child = (root->left != nullptr);
        res.has_right_child = (root->right != nullptr);
        if (root->left)
            res.left_value = root->left.value;
        if (root->right)
            res.right_value = root->right.value;
        
        
    }
    return res;
}

template<typename T>
bool findSubtree(TreeNode<T>* t1, TreeNode<T>* t2) {
    // for T2, collect the following metrics: depth, number of nodes and hash of their values, then
    //  for each node in T1 which is the same with T2's root invoke the DFS algorithm to compute the aformentioned metrics,
    //    and which aborts if the depth is higher than the T2's depth, or if the number of nodes in the subtree exceeds (T1 is very large!)
    //  IF all the metrics are identical, the actual comparison of every nodes commenses
    // metrics can be extended/minimized (e.g. checking that left and right children are the same before proceeding
    auto metrics = collectMetrics(t2);
    auto metrics2 = collectMetrics(t1->left);
    auto metrics3 = collectMetrics(t1->right);
    return metrics2.root_value == metrics.root_value;
}

void ex_4_8() {
    std::vector<int> in;
    //seed48(2018);
    for (int sample = 0; sample <  20180000; ++sample)
        in.push_back(std::rand() % 200);
    std::sort(in.begin(), in.end());
    TreeNode<int>* node = createBST(in, 0, (int) in.size()) ;
    auto root = node;
    std::cout << "subtree " << (findSubtree(root, root->left) ? " exists " : " doesn't exist ") << std::endl;
}


int main(int argc, const char * argv[]) {
    //ex4_1();
    //    ex4_3();
//    ex4_4();
  //  ex4_5();
//    ex4_6();
//    ex4_7();
    ex_4_8();
    return 0;
}
