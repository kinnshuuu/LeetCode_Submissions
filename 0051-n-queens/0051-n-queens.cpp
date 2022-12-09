class Solution {
public:
    vector<vector<string>> ans;
    
    bool isPossible(vector<string> &s, int n, int i, int j)
    {
        for(int k = 0; k<i; k++)
        {
            if(s[k][j] == 'Q')
                return 0;
        }
        for(int k = 0; k<=min(i,j); k++)
        {
            if(s[i-k][j-k] == 'Q')
                return 0;
        }
        for(int k = 0; k<=min(i,(n-j+1)); k++)
        {
            if(s[i-k][j+k] == 'Q')
                return 0;
        }
        return 1;
    }
    
    void solve(int n, int i, vector<string> &s)
    {
        if(n == i)
        {
            ans.push_back(s);
            return ;
        }
        
        for(int j = 0; j<n; j++)
        {
            if(isPossible(s,n,i,j))
            {
                s[i][j] = 'Q';
                solve(n,i+1,s);
                s[i][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        string s;
        for(int i = 0; i<n; i++)
            s.push_back('.');
        
        vector<string> v(n);
        
        for(int i = 0; i < n; i++)
        {
            v[i] = s;
        }
        
        solve(n,0,v);
        
        return ans;
    }
};