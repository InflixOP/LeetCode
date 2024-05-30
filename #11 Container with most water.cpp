class Solution {
public:
    int maxArea(vector<int>& height) {
        int area=0,i=0,j=height.size()-1,carea;
        while(i<j){
            carea=min(height[i],height[j])*(j-i);
             area=max(carea,area);
            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
        }
        return area;
    }
};