class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            unordered_map<int,int> mp1;
            unordered_map<int,int> mp2;
            int n1=nums1.size();
            int n2=nums2.size();
            for(int i=0;i<n1;i++){
                mp1[nums1[i][0]]=nums1[i][1];
            }
            for(int i=0;i<n2;i++){
                mp2[nums2[i][0]]=nums2[i][1];
            }
            for(int i=0;i<n1;i++){
                if(mp2[nums1[i][0]]){
                    nums1[i][1]+=mp2[nums1[i][0]];
                }
            }
            for(int i=0;i<n2;i++){
                if(!mp1[nums2[i][0]]){
                    nums1.push_back({nums2[i][0],nums2[i][1]});
                }
            }
            sort(nums1.begin(),nums1.end());
            return nums1;
        }
    };