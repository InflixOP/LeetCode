class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<int> numeve;
        vector<int> numodd;
        vector<int> tareve;
        vector<int> tarodd;
        sort(nums.begin(),nums.end());
        sort(target.begin(),target.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                numeve.push_back(nums[i]);
            }else{
                numodd.push_back(nums[i]);
            }if(target[i]%2==0){
                tareve.push_back(target[i]);
            }else{
                tarodd.push_back(target[i]);
            }
        }
        long ans=0;
        int e=numeve.size();
        int o=numodd.size();
        for(int i=0;i<e;i++){
            ans+=abs(numeve[i]-tareve[i])/2;
        }
        for(int i=0;i<o;i++){
            ans+=abs(numodd[i]-tarodd[i])/2;
        }
        return ans/2;
    }
};