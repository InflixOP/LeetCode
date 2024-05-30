class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int nums3[n1+n2];
        int i=0,j=0,k=0;
        while(i<n1 && j<n2){
            if(nums1[i]>nums2[j]){
                nums3[k++]=nums2[j++];
            }else{
                nums3[k++]=nums1[i++];
            }
        }
        for(;i<n1;i++){
            nums3[k++]=nums1[i];
        }
        for(;j<n2;j++){
            nums3[k++]=nums2[j];
        }
        if(k%2==0){
            return (nums3[k/2]+nums3[(k/2)-1])/2.0;
        }else{
            return nums3[(int)(k/2)];
        }
    }
};