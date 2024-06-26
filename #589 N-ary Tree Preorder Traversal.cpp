/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> output;
    vector<int> preorder(Node* root) {
        output.clear();
        traverse(root);
        return output;
    }
    void traverse(Node* root){
        if(!root)
            return;
        output.push_back(root->val);
        for(auto node:root->children)
            traverse(node);
    }
};