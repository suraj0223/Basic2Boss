// This is a basic problem of all the problem of such type

// This problem is quite popular problem 0/1 knapsack

// Link: https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

// Complexity : 2^n
// method 1

// unbounded knapSack problems means you can have multiple instances of
// any particular product.

int knapSack(int W, int wt[], int val[], int n) {

    // Base Case if size of array is 0
    // or if there is weight is 0
    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
    else {
      // return maximum of included current weight or exclude current weight
        return max(val[n - 1]+ knapSack(W - wt[n - 1],wt, val, n),knapSack(W, wt, val, n - 1));
      }
}


// --------------------------------------------------------------------------------
// method 2
// optimised sum
// just add 2 more line and you are ready to make a dp solution
// create a memorisation table to prevent multiple recusrive calls of size
// changed varible is recursive function
// weight(W) and size(n)


vector<vector<int>> dp(1000, vector<int>(10000, 0));

int knapSack(int W, int wt[], int val[], int n) {

    // Base Case if size of array is 0
    // or if there is weight is 0
    if (n == 0 || W == 0)
        return 0;

    // if allready exist return calculated value
    if (dp[n][W] != -1)
        return dp[n][w];

    if (wt[n - 1] > W)
        return dp[n-1][W] = knapSack(W, wt, val, n - 1);
    else {
      // return maximum of included current weight or exclude current weight
        return dp[n-1][W] = max(val[n - 1]+ knapSack(W - wt[n - 1],wt, val, n),knapSack(W, wt, val, n - 1));
      }
}

// --------------------------------------------------------------------------------
// method 3: create a top down table for storing past calculated values
// convert above recursive calls to top down table
// create a 2d matrix of size n+1 * w+1
// transform above recusive calls to array indexed
// pretty simple

int knapSack(int W, int wt[], int val[], int n) {

  vector<vector<int>> dp(n+1, vector<int>(w+1, 0));

  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= W; j++) {

      if(i == 0 && j != 0) {
        // if there is empty array we cannot achieve weight
        dp[i][j] = 0;
        continue;
      }

      if(j == 0) {
        // if weight is 0 then we are able to select empty
        dp[i][j] = 1;
        continue;
      }

      if(wt[i-1] > j) {
        // knapSack(W, wt, val, n - 1);
        // covert to array indexed of w and n-1
        dp[i][j] = dp[i-1][j];
      } else {
        // return dp[n-1][W] = max(val[n - 1]+ knapSack(W - wt[n - 1],wt, val, n - 1),knapSack(W, wt, val, n - 1));
        // convert this line to array indexed
        dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i][j-wt[i-1]]);
      }
    }
  }
  return dp[n][W];
}
