class Solution {
    public:
        vector<int> closestPrimes(int left, int right) {
            vector<bool> sieve(right+1,true);
            sieve[0]=sieve[1]=false;
            for(int i=2;i*i<=right;i++){
                if(sieve[i]){
                    for(int j=i*i;j<=right;j+=i){
                        sieve[j]=false;
                    }
                }
            }
            vector<int> prime;
            for(int i=left;i<=right;i++)
            {
                if(sieve[i])
                prime.push_back(i);
            }
            vector<int> result(2,-1);
            if(prime.size()<2)
            return result;
            int min=INT_MAX;
            for(int i=1;i<prime.size();i++){
                if(prime[i]-prime[i-1]<min){
                    min=prime[i]-prime[i-1];
                    result[0]=prime[i-1];
                    result[1]=prime[i];
                }
            }
            return result;
        }
    };