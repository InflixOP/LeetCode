/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */



        

class Solution {

public:

    TreeNode* balanceBST(TreeNode* root) {

        vector<int> sortedElements;

        inOrderTraversal(root, sortedElements);

        return buildBalancedBST(sortedElements, 0, sortedElements.size() - 1);

    }

private:

    void inOrderTraversal(TreeNode* node, vector<int>& sortedElements) {

        if (!node) {

            return;

        }

        inOrderTraversal(node->left, sortedElements);

        sortedElements.push_back(node->val);

        inOrderTraversal(node->right, sortedElements);

    }

    

    TreeNode* buildBalancedBST(const vector<int>& elements, int start, int end) {

        if (start > end) {

            return nullptr;

        }

        int mid = start + (end - start) / 2;

        TreeNode* node = new TreeNode(elements[mid]);

        node->left = buildBalancedBST(elements, start, mid - 1);

        node->right = buildBalancedBST(elements, mid + 1, end);

        return node;

    }

};