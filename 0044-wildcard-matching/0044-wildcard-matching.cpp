class Solution {
public:
    int n, m;
    vector<vector<int> > dp;
    bool solve(string &s, string &p, int i, int j)
    {
        if (i == -1 and j == -1)
            return 1;

        if (i == -1 )
        {
            while(j >= 0 and p[j] == '*')
                j--;
            
            if(j == -1)
            {
                return 1;
            }
            return 0;
        }
        
        
        if(j == -1)
            return 0;
        // cout<<i<<" "<<j<<endl;
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        bool ans = 0;

        if (s[i] == p[j] or p[j] == '?')
        {
            ans = ans | solve(s, p, i - 1, j - 1);
        }

        else if (p[j] == '*')
        {
            ans = ans | solve(s, p, i - 1, j - 1);
            ans = ans | solve(s, p, i - 1, j);
            ans = ans | solve(s, p, i, j - 1);
        }
        
        
        return dp[i][j]= ans;
    }
    bool isMatch(string s, string p) {
        n = s.size();
        m = p.size();
        
        
        dp.resize(n, vector<int> (m, -1));
        return solve(s,p,n-1,m-1);
    }
};