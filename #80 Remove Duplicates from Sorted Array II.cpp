class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int ele:nums){
            if(i<2||nums[i-2]!=ele){
                nums[i++]=ele;
            }
        }
        return i;
    
    }
};