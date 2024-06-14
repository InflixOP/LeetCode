class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(left;left<=right;left++){
            int num=left;
            int c=0;
            while(num>0){
                if(num%10==0){
                    c=1;
                    break;
                }
                if(left%(num%10)!=0){
                    c=1;
                    break;
                }
                num=num/10;
            }
            if(c!=1)
                ans.push_back(left);
        }
        return ans;
    }
};