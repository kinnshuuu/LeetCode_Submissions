class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        
        int dp[510][510] = {0};
        
        
        for(int i = 1; i<=n; i++)
        {
            dp[i][0] = i;
        }
        for(int i = 1; i<=m; i++)
        {
            dp[0][i] = i;
        }
        
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=m;j++)
            {
                if(s[i-1] == t[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = 1+ min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
                }
            }
        }
        // for(int i = 0; i<=n; i++)
        // {
        //     for(int j = 0; j<=m; j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[n][m];
    }
};