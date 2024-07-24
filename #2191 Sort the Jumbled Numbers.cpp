class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
    vector<pair<int,int>> ans;
    for(int i=0;i<nums.size();i++){
        long long p=nums[i],q=0,r=0;
        if(p==0){
            ans.push_back({mapping[0],i});

            continue;
        }
        while(p>0){
            r+=(mapping[(p%10)]*pow(10,q));
            q++; 
            p/=10;
        }
        ans.push_back({r,i});
    }
    sort(ans.begin(),ans.end());
    vector<int> a(nums.size());
    int k=0;
    for(auto ele:ans){
        a[k]=nums[ele.second];

        k++;
    }   
    return a;
    }
};