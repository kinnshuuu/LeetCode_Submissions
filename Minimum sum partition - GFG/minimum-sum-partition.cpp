//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

    vector<vector<int>> dp;
  public:
  
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0;
	    for(int i = 0; i<n; i++)
	    {
	        sum += arr[i];
	    }
	    dp.resize(n+1,vector<int>(sum+1,-1));
	    return solve(arr, n - 1, 0, 0);
	    
	} 
	int solve(int S[], int n, int S1, int S2)
    {
        // Base case: if the list becomes empty
        if (n < 0) {
            return abs(S1 - S2);
        }
        // Construct a unique map key from dynamic elements of the input.
        if(dp[n][S1]!=-1)
        return dp[n][S1];
        int ans=INT_MAX;
        int inc = solve(S, n - 1, S1 + S[n], S2);
        int exc = solve(S, n - 1, S1, S2 + S[n]);
        
        ans=min(inc,exc);
        return dp[n][S1] = ans;
    }
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends