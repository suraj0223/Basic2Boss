// we have to count total number of subset sum whose sum is equal to given sum

// followup to base problem 

int subsetSumWithGivenSum(std::vector<int> arr, int sum) {

  int n = arr.size();

  int dp[n+1][sum+1];

  for(int i = 0; i <=n; i++) {
    for(int j = 0; j <= sum; j++) {

      if(i == 0 && j != 0) {
        dp[i][j] = 0;
        continue;
      }

      if(j == 0) {
        dp[i][j] = 1;
        continue;
      }


      if(arr[i-1] > j) {
        dp[i][j] = dp[i-1][j];
      } else {
        dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
      }
    }
  }
  return dp[n][sum];
}
