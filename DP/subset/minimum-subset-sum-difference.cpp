// problem link: https://leetcode.com/discuss/interview-question/1271034/count-no-of-subsets-with-given-difference-dp

// we have given an araay and we have to count the sum of difference of sum of subarrays
// having exact difference of k

// -> This problem is quite trival to subset sum

// okay followup:
// s1 - s2 = K
// s1 + s2 = sum of all the elements
// s1 = (k + sum)/2

// so we have to find the subsets having sum is equal to s1, hence this
// is a subset sum problem

int exactKdifferenceSubsetSum(std::vector<int> arr, int k) {

  int n = arr.size();
  int sum = 0;
  for(int x : arr) {
    sum += x;
  }

  int targetsum = (k+sum)/2;

  int dp[n+1][targetsum+1];

  for(int i = 0; i <=n; i++) {
    for(int j = 0; j <= targetsum; j++) {

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
  return dp[n][targetsum];
}
