class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        sort(nums,0,nums.size()-1,ans);
        return nums;
    }
    void merge(vector <int>& nums,int l,int mid,int h, vector<int>& ans){
        int l1=l,r=mid+1;
        int s=h-l+1;
        for(int i=0;i<s;i++){
            int j=l+i;
            if(l1>mid){
                ans[j]=nums[r++];
            }else if(r>h){
                ans[j]=nums[l1++];
            }else if(nums[l1]<nums[r]){
                ans[j]=nums[l1++];
            }else
            ans[j]=nums[r++];
        }
        for(int i=l;i<l+s;i++)
        nums[i]=ans[i];
    }
    void sort(vector<int>& nums,int l,int h,vector<int>& ans){
        if(h<=l) return;
        int m=(l+h)/2;
        sort(nums,l,m,ans);
        sort(nums,m+1,h,ans);
        merge(nums,l,m,h,ans);
    }
};