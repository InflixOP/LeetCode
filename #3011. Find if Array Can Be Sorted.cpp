class Solution {
public:
    using int2=pair<int, int>;
    bool canSortArray(vector<int>& nums) {
        int2 prev={INT_MIN, INT_MIN}, curr;
        const int n=nums.size();
        int prevBit=-1;
        for(int i=0; i<n; i++){
            int x=nums[i];
            int b=__builtin_popcount(x);
            if (prevBit!=b){
                if (curr.first<prev.second) return 0;
                prev=curr;
                curr={x, x};
                prevBit=b;
            }
            else{
                curr.first=min(curr.first, x);
                curr.second=max(curr.second, x);
            }
        }
        return curr.first>=prev.second;
    }
};


auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();