// problem statement : we have to find the longest common subsequence in between
                    // given two strings

// example:
// X: abcdef
// Y: bcdfg

// longest subsequence is : bcdf i.e 4(length)

// recusive solution
int LCS(string s1, string s2, int n, int m) {
  if(n == 0 || m == 0)
    return 0;

  if(s1[n-1] == s2[m-1])
    return 1 + LCS(s1, s2, n-1, m-1);
  else
    return max( LCS(s1, s2, n-1, m), LCS(s1, s2, n, m-1) );
}

// ---------------------MEMORIZATION------------------------------------

//setp2:  Now we use memorization table to optimise the problem

// two d array size should be the chane value in the function
int dp[n+1][m+1];
memset(dp, -1, sizeof(dp));

int LCS(string s1, string s2, int n, int m) {
  if(n == 0 || m == 0)
    return 0;

    if(dp[n][m] != -1)
      return dp[n][m];

      if(s1[n-1] == s2[m-1])
        return dp[n][m] = 1 + LCS(s1, s2, n-1, m-1);
      else
        return dp[n][m] = max( LCS(s1, s2, n-1, m), LCS(s1, s2, n, m-1) );
}

// ------------------------Top down dp -----------------------------------------
// we say top down because we solve small problem first and then use it for solving larger problems
// we have to make a 2d top down matrix
int LCS(string s1, string s2, int n, int m) {

  vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
        if(s1[i-1] == s2[j-1])
            dp[i][j] = 1 + dp[i-1][j-1];
        else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }
  return dp[n][m];
}
