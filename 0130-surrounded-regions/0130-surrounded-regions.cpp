class Solution {
public:
    void solve(vector<vector<char>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        queue<pair<int,int>> q;
        for(int i = 0; i<n; i++)
        {
            if(arr[i][0] == 'O')
            {
                q.push({i,0});
            }
            if(arr[i][m-1] == 'O')
            {
                q.push({i,m-1});
            }
        }
        for(int j = 1; j<m-1; j++)
        {
            if(arr[0][j] == 'O')
            {
                q.push({0,j});
            }
            if(arr[n-1][j] == 'O')
            {
                q.push({n-1,j});
            }
        }
        vector<vector<int> > v(n,vector<int>(m,0));
        
        while(q.size())
        {
            auto p = q.front();
            
            q.pop();
            int i = p.first;
            int j = p.second;
            
            // cout<<i<<" "<<j<<endl;
            if(v[p.first][p.second] == 0)
            {
                v[p.first][p.second] = 1;
                // arr[i][j] = 'X';
                if(i+1<n and arr[i+1][j] == 'O')
                {
                    q.push({i+1,j});
                }
                if(j+1<m and arr[i][j+1] == 'O')
                {
                    q.push({i,j+1});
                }
                if(i-1>=0 and arr[i-1][j] == 'O')
                {
                    q.push({i-1,j});
                }
                if(j-1>=0 and arr[i][j-1] == 'O')
                {
                    q.push({i,j-1});
                } 
            }
        }
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(v[i][j] == 0)
                {
                    arr[i][j] = 'X';
                }
            }
        }
    }
};