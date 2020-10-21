/*
Given a tree, find the largest subtree (the one with the most nodes) that is a binary search tree.

For example, given the following tree:

    1
   /
  3
 / \
2   5

Return the following tree:

  3
 / \
2   5

Since root is not a valid binary search tree, but the tree beginning at 3 is.

The tree is guaranteed to have exactly one largest binary search subtree.
Example 1

Input

root = [1, [3, [2, null, null], [5, null, null]], null]

Output

[3, [2, null, null], [5, null, null]]

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
    Tree* solve(Tree* root) {
        if (!root) return nullptr;
        return get<2>(r(root));
    }

    tuple<bool, int, Tree*> r(Tree* node) {
        if (!node) return {true, 0, nullptr};

        auto [left, leftsize, leftnode] = r(node->left);
        auto [right, rightsize, rightnode] = r(node->right);
        bool flag = true;

        if (node->left) flag = node->left->val < node->val and left;
        if (node->right) flag = node->right->val > node->val and right and flag;

        if (flag) return {true, 1 + leftsize + rightsize, node};

        if (left and right) {  // both are BSTs
            if (leftsize > rightsize) {
                return {false, leftsize, leftnode};
            }
            return {false, rightsize, rightnode};
        }

        if (left) return {false, leftsize, leftnode};

        return {false, rightsize, rightnode};
    }
};

Tree* solve(Tree* root) {
    return (new Solution())->solve(root);
}
