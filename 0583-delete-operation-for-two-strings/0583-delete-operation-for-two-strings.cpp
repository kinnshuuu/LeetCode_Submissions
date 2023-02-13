class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(s[i] == t[j])
                {
                    dp[i+1][j+1]  = dp[i][j]+1;
                    
                }
                else 
                    dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
                    
            }
        }
        
        return n+m - 2*dp[n][m];
    }
};