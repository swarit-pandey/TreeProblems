/*
You are given a tree root and a list of strings moves consisting of "RIGHT", "LEFT" and "UP". Starting from root, traverse the tree by performing each move in moves where:

    "RIGHT" means to traverse to the right child.
    "LEFT" means to traverse to the left child.
    "UP" means to traverse to its parent.

Return the value of the last node after all moves. You can assume that the moves are valid.

For example, given root:

   9
  / \
 1   8
    / \
   6   0
  / \
 3   2

And moves = ["RIGHT", "RIGHT", "UP", "LEFT", "RIGHT"], return 2.
Example 1

Input

root = [0, null, [1, null, null]]
moves = ["RIGHT"]

Output

1
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
    int solve(Tree* root, vector<string>& moves) {
        deque<char> queue;

        int size(moves.size());
        for (int i(0); i < size; i++)
            if (moves[i] == "UP")
                queue.pop_back();
            else
                queue.push_back(moves[i][0]);

        while (!queue.empty()) {
            if (queue.front() == 'L')
                root = root->left;
            else
                root = root->right;
            queue.pop_front();
        }

        return root->val;
    }
};

int solve(Tree* root, vector<string>& moves) {
    return (new Solution())->solve(root, moves);
}
