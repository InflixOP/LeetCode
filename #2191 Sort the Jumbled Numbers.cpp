class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
    vector<pair<int,int>> vp;
    for(int i=0;i<nums.size();i++){
        long long p=nums[i],q=0,r=0;
        if(p==0){
            vp.push_back({mapping[0],i});
            continue;
        }
        while(p>0){
            r+=(mapping[(p%10)]*pow(10,q));
            q++; 
            p/=10;
        }
        vp.push_back({r,i});
    }
    sort(vp.begin(),vp.end());
    vector<int> a(nums.size());
    int k=0;
    for(auto it:vp){
        a[k]=nums[it.second];
        k++;
    }   
    return a;
    }
};