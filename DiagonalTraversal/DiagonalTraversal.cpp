/*
Given a binary tree root, return the sum of each of the diagonals in the tree starting from the top to bottom right. For example, given

   1
  / \
 4   2
    / \
   5   3
  / \
 7   6

Return [6, 15, 7] since the diagonals are:

1 -> 2 -> 3
4 -> 5 -> 6
7

Example 1

Input

root = [1, [2, null, null], [3, null, null]]

Output

[4, 2]


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
    void getDiag(Tree* root, int diag, map<int, int>& m) {
        if (!root) return;

        m[diag] += root->val;

        getDiag(root->left, diag + 1, m);
        getDiag(root->right, diag, m);
    }

    vector<int> solve(Tree* root) {
        vector<int> res;
        map<int, int> m;
        getDiag(root, 0, m);
        for (auto& x : m) {
            res.push_back(x.second);
        }
        return res;
    }
};


vector<int> solve(Tree* root) {
    return (new Solution())->solve(root);
}
