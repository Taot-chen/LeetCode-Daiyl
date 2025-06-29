class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n, 0);
        for (int i = 0; i < n; i++) {
            if (!i) {
                sum[i] = nums[i];
            } else {
                sum[i] = sum[i - 1] + nums[i];
            }
        }
        return sum;
    }
};
