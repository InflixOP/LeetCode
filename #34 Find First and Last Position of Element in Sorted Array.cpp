class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = findFirst(nums, target);
        int end = findLast(nums, target);
        return {start, end};
    }

private:
    int findFirst(const vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        int index = -1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] >= target) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
            if (nums[mid] == target) {
                index = mid;
            }
        }
        return index;
    }

    int findLast(const vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        int index = -1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] <= target) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
            if (nums[mid] == target) {
                index = mid;
            }
        }
        return index;
    }
};
