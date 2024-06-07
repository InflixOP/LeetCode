class Solution {
public:
    int addDigits(int num) {
        int f=0;
        if(num/10==0){
            return num;
        }else{
            int sum=0;
            while(num>0){
                sum=sum+num%10;
                num=num/10;
            }
            f=addDigits(sum);
        }
        return f;
    }
};