class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans=0;
        for(int i=0;i<arr.size();i++)
		{
            int sum=ceil((i+1)*(arr.size()-i)/2.0);
            ans+=(sum*arr[i]);
        }
        return ans; 
    }
};