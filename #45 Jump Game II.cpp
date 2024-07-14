class Solution {
public:
    int jump(vector<int>& nums) {
        int near = 0, far = 0, jumps = 0;
        while (far < nums.size() - 1) {
            int farthest = 0;
            for (int i = near; i <= far; i++) {
                farthest = max(farthest, i + nums[i]);
            }
            near = far + 1;
            far = farthest;
            jumps++;
        }

        return jumps;        
    }
};