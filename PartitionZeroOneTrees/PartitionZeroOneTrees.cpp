/*
You are given a binary tree root containing values 0, 1 and 2. The root has at least one 0 node and one 1 node. Consider an operation where we delete an edge in the tree and the tree becomes disjoint with two trees.

Return the number of ways we can delete one edge such that none of the two trees contain both a 0 node and a 1 node.

For example, given

   0
  / \
 0   2
    / \
   1   1

Return 1 since we can only delete the 0 to 2 edge.

Constraints

    n ≤ 100,000 where n is the number of nodes in root

Example 1

Input

root = [2, [1, null, null], [0, null, null]]

Output

2

Explanation

We can delete either the 2 to 1 edge or 2 to 0 edge.

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
    int solve(Tree* root) {
        int ans = 0;
        int ones = 0;
        int zeros = 0;
        helper1(root, ones, zeros);
        helper2(root, ans, ones, zeros);
        return ans;
    }

    void helper1(Tree* root, int& ones, int& zeros) {
        if (!root) {
            return;
        }

        helper1(root->left, ones, zeros);
        helper1(root->right, ones, zeros);
        if (root->val == 1) {
            ++ones;
        } else if (root->val == 0) {
            ++zeros;
        }
    }

    array<int, 2> helper2(Tree* root, int& ans, int& ones, int& zeros) {
        if (!root) {
            return array<int, 2>{0, 0};
        }

        auto l = helper2(root->left, ans, ones, zeros);
        auto r = helper2(root->right, ans, ones, zeros);

        if (l[0] == 0 && l[1] == ones) {
            ++ans;
        } else if (l[1] == 0 && l[0] == zeros) {
            ++ans;
        }

        if (r[0] == 0 && r[1] == ones) {
            ++ans;
        } else if (r[1] == 0 && r[0] == zeros) {
            ++ans;
        }

        array<int, 2> ret{l[0] + r[0], l[1] + r[1]};
        if (root->val == 0) {
            ++ret[0];
        } else if (root->val == 1) {
            ++ret[1];
        }
        return ret;
    }
};

int solve(Tree* root) {
    return (new Solution())->solve(root);
}
