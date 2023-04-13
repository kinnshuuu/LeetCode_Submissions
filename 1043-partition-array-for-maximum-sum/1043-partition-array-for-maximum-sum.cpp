class Solution {
public:
    int n ;
    
    vector<int> dp;
    int solve(int x, vector<int>& arr, int k)
    {
        if(n == x)
        {
            return 0;
        }
        int ans = 0;
        int len = 0;
        int mx = INT_MIN;
        if(dp[x] != -1)
        {
            return dp[x];
        }
        
        for(int i = x ; i<min(n,x+k); i++)
        {
            len++;
            mx = max(mx,arr[i]);
            
            ans =max ((len*mx)+ solve(i+1,arr,k),ans);
        }
        
        return dp[x] =  ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        dp.resize(n,-1);
        return solve(0,arr,k);
    }
};