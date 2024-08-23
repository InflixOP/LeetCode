class Solution {
public:
    string fractionAddition(string expression) {
        
        int numtor=0,denmtor=1;

        char op;

        int num,den;

        istringstream ss(expression);

        while(ss>>num>>op>>den)
        {
            numtor=den*numtor+denmtor*num;
            denmtor*=den;

            int gcd=abs(__gcd(numtor,denmtor));
            numtor/=gcd;
            denmtor/=gcd;

        }
        return to_string(numtor)+"/"+to_string(denmtor);



    }
};