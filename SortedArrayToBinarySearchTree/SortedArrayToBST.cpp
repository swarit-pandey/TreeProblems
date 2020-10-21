/*
Given a sorted list nums of size n, construct a binary search tree by

    Taking nums[k] as the root where k = floor(n / 2).
    Recursively constructing the left subtree using the list nums[:k]
    Recursively constructing the right subtree using the list nums[k + 1:]

Example 1

Input

nums = [0, 1, 2, 3, 4]

Output

[2, [1, [0, null, null], null], [4, [3, null, null], null]]


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
    Tree* solve(vector<int>& num) {
        if (num.size() == 0) return NULL;
        if (num.size() == 1) {
            return new Tree(num[0]);
        }

        int middle = num.size() / 2;
        Tree* root = new Tree(num[middle]);

        vector<int> leftInts(num.begin(), num.begin() + middle);
        vector<int> rightInts(num.begin() + middle + 1, num.end());

        root->left = solve(leftInts);
        root->right = solve(rightInts);

        return root;
    }
};

Tree* solve(vector<int>& nums) {
    return (new Solution())->solve(nums);
}
