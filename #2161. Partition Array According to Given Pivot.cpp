class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            int n=nums.size();
            vector<int> result(n);
            int i=0,j=n-1,k=0,l=n-1;
            while(i<n&&j>=0){
                if(nums[i]<pivot){
                    result[k++]=nums[i];
                }
                if(nums[j]>pivot)
                result[l--]=nums[j];
                i++;
                j--;
            }
            while(k<=l){
                result[k++]=pivot;
            }
            return result;
        }
    };