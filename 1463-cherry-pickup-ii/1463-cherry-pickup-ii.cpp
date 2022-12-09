class Solution
{
    public:
        int cherryPickup(vector<vector < int>> &arr)
        {
            int n = arr.size();
            int m = arr[0].size();

            int dp[n][m][m];

            memset(dp, 0, sizeof(dp));

            for (int i = 0; i < m; i++)
            {
                dp[0][0][m - 1] = arr[0][0] + arr[0][m - 1];
            }
            int col1 = 0, col2 = m - 1;
            for (int i = 1; i < n; i++)
            {
                for (int j = 0; j<m and j < i+1; j++)
                {
                    for (int k = m-1; k>=0 and k >=m-1-i ; k--)
                    {
                        for (int x:{-1,0, 1 })
                        {
                            if (j + x < m and j + x >= 0)
                                for (int y: {-1,0,1 })
                                {
                                    if (k + y < m and k + y >= 0) 
                                    {
                                        dp[i][j][k] = max(dp[i][j][k],dp[i-1][j+x][k+y]);
                                    }
                                }
                        }
                        dp[i][j][k] += (arr[i][j] + (arr[i][k] * (j != k)));
                    }
                }
            }
            
            // for(int i = 0; i<m; i++)
            // {
            //     for(int j = 0; j<m; j++)
            //     {
            //         cout<<dp[1][i][j]<<" ";
            //     }
            //     cout<<endl;
            // }
            int ans = 0;
            for(int i = 0; i<m; i++)
            {
                for(int j = 0; j<m; j++)
                {
                    ans = max(ans, dp[n-1][i][j]);
                }
            }
            return ans;
        }
};