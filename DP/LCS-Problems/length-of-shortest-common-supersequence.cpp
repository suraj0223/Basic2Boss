
// Q. what is supersequence?
// > supersequence is a string that contain all the given string as a subsequene

// We have to find length of shortest common supersequence that is possible
// from given two string

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimise "Ofast"

// idea:
// 1. Find the longest common subsequene that is possibly made from given two strings
// 2. Largest possible supersequence is : string a + string b
// 3. result = length(a+b) - LCS

int lengthOfShortestCommonSubsequence(string a, string b) {
  int m = a.length();
  int n = b.length();

  int lcs = LCS(a, b, m, n);
  return (m+n)-lcs;
}

int LCS(string a, string b, int m, int n) {
  int dp[m+1][n+1];
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
  string a = "aasdf";
  string b = "asjhd";
  cout << "Length of smallest comon subsequene : " << lengthOfShortestCommonSubsequence(a,b);
  return 0;
}
