// link: https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1#

// problem geeksforgeeks

// more clear understanding:
// https://www.youtube.com/watch?v=-GtpxG6l_Mc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=10


// idea building:
  // - look you have two subrray to find such that their sum of difference is min
  // find the minimum of s2 - s1
  //if s1 + s2 = sum
  //=> s2 = sum - s1;
  // mimimise sum - 2s1;
  // find all the possible subsets sums possible from the given numbers
  // we are sure that all those lie between 0 to sum of all a[i]
  // s1 varies from 0 to sum/2;


int minDifference(int arr[], int n)  {
	    // first of all find all the subset that is possible between
	   // code is very much similar ot partion equal sum

     if(n == 0)
      return 0;

      if(n== 1)
        return arr[0];

	   int sum = 0;
	   for(int i = 0; i < n; i++)
	        sum += arr[i];

	    bool dp[n+1][sum+1];

	    for(int i =0; i <= n; i++) {
	        for(int j = 0; j <= sum; j++) {

	            if( j == 0) {
	                dp[i][j] = true;
	                continue;
	            }

	            if(i == 0 && j != 0)  {
	                dp[i][j] = false;
	                continue;
	            }

	            if(arr[i-1] > j) {
	                dp[i][j] = dp[i-1][j];
	            } else {
	                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
	            }
	        }
	     }

	       // we have got ready our answer in last row of dp array
	       int result = INT_MAX;
	       for(int i = 0; i <= sum/2 ; i++) {
	           if(dp[n][i] == true) {
	               result = min(result, sum - 2*i);
	           }
	       }
	       return result;
	}
