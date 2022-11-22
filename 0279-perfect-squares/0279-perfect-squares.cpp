class Solution {
public:
    
    
    int numSquares(int n) {
    vector<int> s(101);
        
        vector<int> dp(n+1,INT_MAX);
        for(int i = 1 ; i<=100; i++)
        {
            s[i] = i*i;
        }
        
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i = 2; i<=n; i++)
        {
            for(int j = 1; j < 101; j++)
            {
                if(i-s[j] >= 0)
                {
                    dp[i] = min(dp[i], dp[i-s[j]]+1);
                }
            }
        }
        // for(int i = 1; i<= n; i++)
        // {
        //     cout<<dp[i]<<" ";
        // }
        return dp[n];
    }
};