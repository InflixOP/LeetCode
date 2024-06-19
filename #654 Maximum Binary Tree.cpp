class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        return maxii(0, nums.size() - 1, nums);
    }
    
    TreeNode* maxii(int i, int j, vector<int>& nums) {
        if (i > j) return nullptr;
        
        int maxi = i;
        for (int k = i + 1; k <= j; ++k) {
            if (nums[k] > nums[maxi]) {
                maxi = k;
            }
        }
        
        TreeNode* n = new TreeNode(nums[maxi]);
        
        n->left = maxii(i, maxi - 1, nums);
        n->right = maxii(maxi + 1, j, nums);
        
        return n;
    }
};
