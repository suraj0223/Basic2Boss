#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimise "Ofast"

// solution thinking process
//  string a = orignal string
// string b = reverse of original string
// find Longest common subsequence, it will be our longest palindromic subsequence

int longestPalindromicSubsequence(string a, string b) {
  int len1 = a.length();
  int len2 = b.length();

  int lcs = LCS(a, b, len1, len2);

  return lcs;
}

int LCS(string a, string b, int m, int n) {
  int dp[m+1][n+1];
  memset(dp, 0, sizeof(dp));
  for(int i = 0; i <= m; i++)
    for(int j = 0; j <=n; j++) {
      if(i == 0 or j == 0) {
        dp[i][j] = 0;
        continue;
      }

      if(a[i-1] == b[j-1]) {
        dp[i][j] = 1 + dp[i-1][j-1];
      } else
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
    return dp[m][n];
}


int main() {
  string a = "ashgshgshashasgas";
  cout << longestPalindromicSubsequence(a, reverse(a.begin(), a.end()));
  return 0;
}
