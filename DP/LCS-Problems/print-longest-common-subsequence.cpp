#include<bits/stdc++.h>
using namespace std;

void printLCS(vector<vector<int>> &dp, string s1, string s2);

int LCS(string s1, string s2, int n, int m) {

  vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
        if(s1[i] == s2[j])
            dp[i][j] = 1 + dp[i-1][j-1];
        else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }
  printLCS(dp, s1, s2);
  return dp[n][m];
}

void printLCS(vector<vector<int>> &dp, string s1, string s2) {
  int l1 = dp.size();
  int l2 = dp[0].size();

  int i = l1-1;
  int j = l2 - 1;

  while(i >= 1 and j >= 1) {
    if(s1[i] == s2[j]) {
      // i.e it comes from diagonal
      i = i - 1;
      j = j - 1;
      cout << s1[i];
    } else {
      // go to maximum in dp i-1, j or i, j-1
      dp[i][j-1] > dp[i-1][j]
      ? j--
      : i--;
    }
  }
  cout << '\n';
  // we are done
}
int main() {
  string s1 = "abcdef";
  string s2 = "bfcgdef";

  cout << LCS(s1, s2, 6, 8) << '\n';
}
