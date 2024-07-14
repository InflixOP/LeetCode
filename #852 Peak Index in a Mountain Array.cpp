class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 1;
        int high = arr.size() - 2 ;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1])
                return mid;

            if(arr[mid-1] > arr[mid])
                high = mid - 1;

            else{
                low = mid + 1;
            }
        }
        return -1;
    }
};