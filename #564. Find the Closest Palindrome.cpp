class Solution {
public:
typedef long long ll;
    ll getPalin(string s)
    {
        ll n=s.size();
        ll l=(n-1)/2,r=(n)/2;

        while(l>=0)
        {
            s[r++]=s[l--];
        }
        return stoll(s);
    }

    ll binarySearchLeft(ll n)
    {
        ll l=n/2,r=n;

        ll res=LLONG_MIN;
        while(l<=r)
        {
            ll mid=l+(r-l)/2;

            ll palin=getPalin(to_string(mid));

            if(palin>=n)
            r=mid-1;

            else
            {
                l=mid+1;
                res=max(palin,res);
            }
        }
        return res;
    }

    ll binarySearchRight(ll n)
    {
        ll l=n,r=1e18-1;
        ll res=LLONG_MAX;
        while(l<=r)
        {
            ll mid=l+(r-l)/2;
            ll palin=getPalin(to_string(mid));
            if(palin<=n)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
                res=min(res,palin);
            }
        }
        return res;
    }

    string nearestPalindromic(string n) {
        ll num=stoll(n);

        ll left=binarySearchLeft(num);
        cout<<"k"<<endl;
        ll right=binarySearchRight(num);

        return num-left > right-num ? to_string(right):to_string(left);
      
    }
};