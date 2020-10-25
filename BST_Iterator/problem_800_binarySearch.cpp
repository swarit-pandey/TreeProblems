/*
Implement a binary search tree iterator with the following methods:

    1) next returns the next smallest element in the tree
    2) hasnext returns whether there is a next element in the iterator
    3) prev returns the next bigger element in the tree
    4) hasprev returns whether there is a previous element in the iterator

For example, given the following tree root

   4
  / \
 2   7
    /
   5

Then we have

it = BSTIterator(root)
it.next() == 2
it.next() == 4
it.hasnext() == True
it.next() == 5
it.next() == 7
it.hasnext() == False
it.hasprev() == True
it.prev() == 5

Example 1

Input

methods = ["constructor", "hasnext", "hasnext", "hasprev", "hasprev", "next", "hasnext", "hasnext", "hasprev"]
arguments = [[[0, null, [2, [1, null, null], null]]], [], [], [], [], [], [], [], []]

Output

[null, true, true, false, false, 0, true, true, false]
*/

class BSTIterator {
    public:
    vector<int> v;
    int index;
    
    BSTIterator(Tree* root) {
        index = -1;
        inorder(root);
    }

    int next() {
        return v[++index];
    }

    bool hasnext() {
        return index + 1 < v.size();
    }

    int prev() {
        return v[--index];
    }

    bool hasprev() {
        return index - 1 >= 0;
    }
    
    void inorder(Tree* root) {
        if(!root) return ;
        inorder(root -> left);
        v.push_back(root -> val);
        inorder(root -> right);
    }
};

