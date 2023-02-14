class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& arr) {
        vector<vector<int>> a(n+1,vector<int> (n+1,0));
        
        vector<int> degree(n+1,0);
        
        
        for(auto i:arr)
        {
            a[i[0]][i[1]] = 1;
            a[i[1]][i[0]] = 1;
            
            degree[i[0]]++;
            degree[i[1]]++;
            
        }
        
        int ans = INT_MAX;
        
        for(int i = 1; i<=n; i++)
        {
            for(int j = i+1;j<=n; j++)
            {
                for(int k = j+1; k<=n; k++)
                {
                    if(a[i][j] == 1 and a[i][k] == 1 and a[j][k] == 1)
                    {
                        int x = 0;
                        x+=degree[i];
                        x+=degree[j];
                        x+=degree[k];
                        ans = min(ans,x);
                    }
                }
            }
        }
        
        if(ans == INT_MAX)
            return -1;
        
        return ans-6;
    }
};