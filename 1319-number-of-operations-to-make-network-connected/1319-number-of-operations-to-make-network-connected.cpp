class Solution {
public:
    
    int ans = 0;
    map<int,vector<int>> mp;
    
    int makeConnected(int n, vector<vector<int>>& arr) {
        int m = arr.size();
    vector<int> vis(n,0);
        
        if(n - 1 > m)
            return -1;
        
        for(auto a:arr)
        {
            mp[a[0]].push_back(a[1]);
            mp[a[1]].push_back(a[0]);
        }
        
        queue<int> q;
        
        for(int i = 0; i<n; i++)
        {
            if(vis[i] == 0)
            {
                ans++;
                vis[i] = 1;
                q.push(i);
                while(q.size())
                {
                    for(auto p:mp[q.front()])
                    {
                        if(vis[p] == 0)
                        {
                            vis[p] = 1;
                            q.push(p);
                        }
                    }
                    q.pop();
                }
            }
        }
        return ans-1;
    }
    
};