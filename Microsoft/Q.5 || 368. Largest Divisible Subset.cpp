class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> pre(n, -1);
        int max_size = 0;
        int last_index = -1;
        for (int i = 0; i < n; i++) {
            int max_dp = 0;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] > max_dp) {
                    max_dp = dp[j];
                    pre[i] = j;
                }
            }
            dp[i] = max_dp + 1;
            if (dp[i] > max_size) {
                max_size = dp[i];
                last_index = i;
            }
        }
        vector<int> ans;
        while (last_index != -1) {
            ans.push_back(nums[last_index]);
            last_index = pre[last_index];
        }
        return ans;
    }
};
