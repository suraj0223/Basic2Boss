// 494. Target Sum leetcode
// link: https://leetcode.com/problems/target-sum/

// this problem is very similar to difference of subsets sum
// with difference equal k

// s1- s2 = k
// s1 - s2 = sum
// s1 = (k+sum)/2

// we have to count the subsets having sum equal to s1

// okay cool


int countSubset(vector < int > & arr, int n, int sum) {
  int t[n + 1][sum + 1];

  for (int i = 0; i <= n; i++)
    t[i][0] = 1;

  for (int i = 1; i <= sum; i++)
    t[0][i] = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= sum; j++) {

      if (arr[i - 1] <= j)
        t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
      else
        t[i][j] = t[i - 1][j];

    }
  }
  return t[n][sum];
}
int findTargetSumWays(vector < int > & nums, int target) {
  int total = 0;

  for (int i = 0; i < nums.size(); i++) {
    total += nums[i];
  }
  if (((total + target) % 2 != 0) || (target > total))
    return 0;

  int sum = (target + total) / 2;

  return countSubset(nums, nums.size(), abs(sum));
}
