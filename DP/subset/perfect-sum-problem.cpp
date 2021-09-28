// link: https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1#

//time : n * sum
// space : n * sum

// similar to base problem nothing new 

class Solution{
	public:
	int perfectSum(int arr[], int n, int sum) {
        // we have to count total number of subsets
        vector<vector<long long>>dp(n+1, vector<long long>(sum+1, 0));
        int mod = 1000000007;

        for(int i = 0; i <=n; i++) {
            for(int j = 0; j <= sum; j++) {

                if(i == 0 && j != 0) {
                    dp[i][j] = 0;
                    continue;
                }

                if(i == 0 and j == 0) {
                    dp[i][j] = 1;
                    continue;
                }

                if(arr[i-1] > j) {
                    dp[i][j] = dp[i-1][j] % mod;
                } else {
                    dp[i][j] = (dp[i-1][j] % mod + dp[i-1][j-arr[i-1]] % mod) % mod;
                }
            }
        }

        return dp[n][sum]%mod;
    }

};
