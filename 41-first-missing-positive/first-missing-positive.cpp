class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = (int)nums.size();

        for (int i = 0; i < n; ++i) {
            while (nums[i] >= 1 && nums[i] <= n) {
                int correctIdx = nums[i] - 1;
                if (nums[correctIdx] == nums[i]) break;
                swap(nums[i], nums[correctIdx]);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};
