class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());

        unordered_map<int, int> rankMap;
        int rank = 1;

        for (int num : sortedArr) {
            if (rankMap.find(num) == rankMap.end()) {
                rankMap[num] = rank++;
            }
        }

        vector<int> ans(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            ans[i] = rankMap[arr[i]];
        }

        return ans;
    }
};
