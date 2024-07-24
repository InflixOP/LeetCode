class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size()+1;
        vector<int> temp (n,0);
        int maximum = 0;
        for(int i : nums){
            temp[i]++;
            maximum = max(maximum,temp[i]);
        }
        vector<vector<int>> mat;
        for(int i =0 ;i< maximum ;i++){
            vector<int> v1;
            for(int j = 0;j<n ; j++){
                if (temp[j]){
                    v1.push_back(j);
                    temp[j]--;
                }
            }
            mat.push_back(v1);
        }
        return mat;
    }
};