/*********************************************
PROBLEM STATEMENT:

Given a binary tree root containing unique values and an integer k, return the number of k-length unique paths in the tree. Paths can go either parent to child or child to parent. Two paths are different if some node appears in one path but not the other.

For example, given the following tree with k = 3

   1
  / \
 2   3
    / \
   4   5

Return 4 since we can have the following 3 length paths: [2, 1, 3], [1, 3, 4], [1, 3, 5], [4, 3, 5]. Note that reversing the path does not count as a new path.

Constraints

    n ≤ 100,000 where n is the number of nodes in root
    2 ≤ k ≤ 20

Example 1

Input

root = [1, [2, null, null], [3, [4, null, null], [5, null, null]]]
k = 3

Output

4
**********************************************/

/*********************************************
INTUITION:
Credits to @xiaowuc1: https://binarysearch.com/@/xiaowuc1

https://binarysearch.com/problems/Counting-K-Length-Paths-on-Binary-Tree/editorials/1623159
**********************************************/

int dfs(Tree* root, int k, vector<int>& depth) {
    depth.resize(k + 1);
    if (root == NULL) return 0;
    int ret = 0;
    vector<int> lhs, rhs;
    ret += dfs(root->left, k, lhs);
    ret += dfs(root->right, k, rhs);
    ret += lhs[k];
    for (int i = 1; i < k; i++) {
        ret += lhs[i] * rhs[k - i];
    }
    ret += rhs[k];
    depth[1]++;
    for (int i = 1; i + 1 <= k; i++) {
        depth[i + 1] += lhs[i];
        depth[i + 1] += rhs[i];
    }
    return ret;
}
int solve(Tree* root, int k) {
    vector<int> depth;
    return dfs(root, --k, depth);
}
