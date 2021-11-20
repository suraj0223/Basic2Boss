#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimise "Ofast"

// solution thinking process
// string a ->> Longest common subsequnce ->> string b
int minimumNumberOfInsetionDeletion(string a, string b) {
  int len1 = a.length();
  int len2 = b.length();

  int lcs = LCS(a, b, len1, len2);

  int totalDeletion = len1 - lcs;
  int totalExtraaddition = len2 - lcs;

  return totalDeletion + totalExtraaddition;
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
  string a = "lead";
  string b = "bed";
  return 0;
}
