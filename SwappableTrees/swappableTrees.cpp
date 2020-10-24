/*
Given two trees root0 and root1, return whether you can transform root0 into root1 by swapping any node's left and right subtrees any number of times.

For example, given these two trees

0                 0
 \               /
  2             2
 / \           / \
1   5         1   5

Return true.

Given these two trees

0                 0
 \               /
  2             5
 / \           / \
1   5         1   2

Return false.
Example 1

Input

root0 = [1, [3, null, null], [4, [0, null, [2, null, null]], null]]
root1 = [1, [3, null, null], [4, [0, null, [2, null, null]], null]]

Output

true


*/

Tree* checkInverse(Tree* root) {
    queue<Tree*> q;
    q.push(root);
    Tree* cur;
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        swap(cur -> left, cur -> right);
        if(cur -> left) q.push(cur -> left);
        if(cur -> right) q.push(cur -> right);
    }
    return root;
}

bool isIdentical(Tree* root1, Tree* root2) {
    queue<Tree*> q1, q2;
    q1.push(root1);
    q2.push(root2);
    while(!q1.empty() and !q2.empty()) {
        Tree* n1 = q1.front();
        Tree* n2 = q2.front();
        
        if(n1 -> val != n2 -> val) {
            return false;
        }
        
        q1.pop(); 
        q2.pop();
        
        if(n1 -> left and n2 -> left) {
            q1.push(n1 -> left);
            q2.push(n2 -> left);
        }
        
        if(n1 -> right and n2 -> right) {
            q1.push(n1 -> right);
            q2.push(n2 -> right);
        }
    }
    return true;
}
 
bool solve(Tree* root0, Tree* root1) {
    if(isIdentical(root0, root1)) {
        return true;
    } else {
        Tree* temp = checkInverse(root1);
        return isIdentical(root0, temp);
    }
}
