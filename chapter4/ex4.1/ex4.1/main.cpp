//
//  main.cpp
//  ex4.1
//
//  Created by Yury Chebiryak on 19/10/18.
//  Copyright © 2018 Yury Chebiryak. All rights reserved.
//

#include <iostream>
#include <utility>
/*
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

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TreeNode<int> a {15, nullptr, nullptr};
    TreeNode<int> b {10, &a, nullptr };
    TreeNode<int> c {5, nullptr, nullptr };
    TreeNode<int> d {3, &b, &c };
    std::pair<bool, int> res { checkBalanced(&d) };
    std::cout << " is the tree balanced? " << res.first << std::endl;
    return 0;
}
