/*
Given the root of a binary tree, return whether its height is balanced. That is, for every node in the tree, the absolute difference of the height of its left subtree and the height of its right subtree is 0 or 1.

For example, this is false since the root's right subtree has height of 2, and left has height of 0.

1
 \
  4
   \
    12

This is height balanced:

  1
 / \
0   4
     \
     12

Example 1

Input

root = [1, null, [4, null, [12, null, null]]]

Output

false

Example 2

Input

root = [1, [0, null, null], [4, null, [12, null, null]]]

Output

true


*/

class Solution {
    public:
    bool check(Tree* root, int& height) {
        if (!root) {
            height = -1;
            return true;
        }
        int left, right;
        if (check(root->left, left) and check(root->right, right) and abs(left - right) < 2) {
            height = max(left, right) + 1;
            return true;
        }
        return false;
    }

    bool solve(Tree* root) {
        int height = 0;
        return check(root, height);
    }
};


bool solve(Tree* root) {
    return (new Solution())->solve(root);
}
