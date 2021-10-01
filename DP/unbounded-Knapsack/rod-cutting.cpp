//link: https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
// this question is nothing but unbounded knapsack problem
// exact similar
// complexity:
// time: 2^n
int cutRod(int price[], int n) {
   if (n <= 0)
     return 0;
   int max_val = INT_MIN;
   for (int i = 0; i<n; i++)
         max_val = max(max_val, price[i] + cutRod(price, n-i-1));

   return max_val;
}

// ------------------------------------------------------------
// using dp
// complexity: O(n)
// space: O(n)

int cutRod(int price[], int n) {
   int val[n+1];
   val[0] = 0;
   int i, j;

   for (i = 1; i<=n; i++) {
       int max_val = INT_MIN;
       for (j = 0; j < i; j++)
         max_val = max(max_val, price[j] + val[i-j-1]);
       val[i] = max_val;
   }
   return val[n];
}
