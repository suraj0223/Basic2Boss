//link: https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
// complexity: Time - O(n)
// space : O(1)

int cutRod(int price[], int n) {
   if (n <= 0)
     return 0;
   int max_val = INT_MIN;
   for (int i = 0; i<n; i++)
         max_val = max(max_val, price[i] + cutRod(price, n-i-1));

   return max_val;
}
