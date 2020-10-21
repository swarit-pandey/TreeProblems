/*
Given two lists of integers preorder and inorder representing the pre-order and in-order traversals of a binary tree, reconstruct the tree and return the root.
Example 1

Input

preorder = [4, 2, 1, 0, 3]
inorder = [2, 1, 0, 3, 4]

Output

[4, [2, null, [1, null, [0, null, [3, null, null]]]], null]


*/

#include "solution.hpp"
using namespace std;

/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
class Solution {
    public:
    Tree* create(vector<int>& preorder, vector<int>& inorder, int start, int end, int& pos) {
        if (start > end) {
            return nullptr;
        }

        auto newNode = new Tree;
        newNode->val = preorder[pos++];

        int midInInorder;
        for (int i = start; i <= end; ++i) {
            if (inorder[i] == preorder[pos - 1]) {
                midInInorder = i;
                break;
            }
        }
        newNode->left = create(preorder, inorder, start, midInInorder - 1, pos);
        newNode->right = create(preorder, inorder, midInInorder + 1, end, pos);
        return newNode;
    }

    Tree* solve(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 or inorder.size() == 0) return nullptr;
        int end = preorder.size() - 1;
        int x = 0;
        return create(preorder, inorder, 0, end, x);
    }
};

Tree* solve(vector<int>& preorder, vector<int>& inorder) {
    return (new Solution())->solve(preorder, inorder);
}
