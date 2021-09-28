// problem from Leetcode
// link : https://leetcode.com/problems/partition-equal-subset-sum/
// Problem no : 416

class Solution {
public:
    /*
    // this approach gives TLE as complexity 2^n
    bool findSubset(vector<int>&nums, int size, int sum) {
        if(sum == 0)
            return true;

        if(size == 0 && sum != 0)
            return false;

        if(nums[size-1] > sum)
            return findSubset(nums, size-1, sum);
        else
            return findSubset(nums, size-1, sum - nums[size-1])
                    || findSubset(nums, size-1, sum);
    }
    */


    /*
    // solution 2 but does not feasible for large sum
    dpV1 = complexity (sz * sum/2)
    // time is also same

    bool findSubset(vector<int>& nums, int size, int sum,  vector<vector<int>>& dp) {
        if(sum == 0)
            return true;

        if(size == 0 && sum != 0)
            return false;

        if(dp[size][sum] != -1)
            return dp[size-1][sum];

        if(nums[size-1] > sum)
            return dp[size-1][sum] = findSubset(nums, size-1, sum, dp);
        else
            return dp[size-1][sum] = findSubset(nums, size-1, sum, dp)
                    || findSubset(nums, size-1, sum - nums[size-1], dp);

    }

    bool canPartition(vector<int>& nums) {

        int sz = nums.size();
        long long sm = 0;

        for(int x : nums)
            sm += x;

        if(sm % 2 != 0)
            return false;

        vector<vector<int>> dp(sz+1, vector<int>((sm/2)+1, -1));


        return  findSubset(nums, sz, sm/2, dp);
    }
    */

    // most optimal solution
    bool canPartition(vector<int>& nums) {

        int sz = nums.size();
        long long sm = 0;

        for(int x : nums)
            sm += x;

        if(sm % 2 != 0)
            return false;

        long long target =  sm/2;

        vector<vector<bool>> dp(sz+1, vector<bool>(target+1, false));

       for(int i = 0; i <= sz; i++)
        for(int j = 0; j <= target; j++) {

            if(j == 0) {
                dp[i][j] = true;
                continue;
            }

            if(i == 0 && j != 0) {
                dp[i][i] = false;
                continue;
            }


            if(nums[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }

        return dp[sz][target];
    }
};
