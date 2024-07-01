class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int n=0;
        int x=red,y=blue;
        int t1,t2;
        while(true){
            n++;
            if(n%2==0){
                if(blue<n){
                    t1= n-1;
                    break;
                }
                blue-=n;
            }
            else{
                if(red<n){
                    t1=n-1;
                    break;
                }
                red-=n;
            }
        }
        n=0;
        while(true){
             n++;
            if(n%2==0){
                if(x<n){
                    t2= n-1;
                    break;
                }
                x-=n;
            }
            else{
                if(y<n){
                    t2=n-1;
                    break;
                }
                y-=n;
            }
        }
        return max(t1,t2);
    }
};