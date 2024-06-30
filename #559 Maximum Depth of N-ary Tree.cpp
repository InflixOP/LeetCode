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
    int maxDepth(Node* root)
    {
        if(root == NULL) return 0;
        int n = root->children.size(); 
        if(n == 0) return 1;
        vector<int> arr(n);
        for(int i = 0; i < n; ++i)
        {
            arr[i] = maxDepth(root->children[i]);
        }
        int m_depth = 1 + *max_element(arr.begin(), arr.end());
        return m_depth;
    }
};