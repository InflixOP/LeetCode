class Solution {
    private:
        bool solve(int n, vector<int>& quantities, int item)
        {
            if(item == 0) return false;
            int store = 0;
            for(auto product : quantities)
            {
                store += (product - 1) / item + 1;
                if(store > n) return false;
            }
            return true;
        }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1;
        int high = *max_element(quantities.begin(), quantities.end());
        int ans = -1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(solve(n, quantities, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};