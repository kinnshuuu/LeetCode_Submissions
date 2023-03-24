class Solution
{
    public:

    map<int, vector<int>> mp;
    set<pair<int, int>> st;
    int minReorder(int n, vector<vector < int>> &arr)
    {

        vector<int> vis(n, 0);

        for (auto i: arr)
        {
            st.insert({ i[0],i[1] });
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }
        
//         for(auto i:mp)
//         {
//             cout<<i.first<<"->";
//             for(auto j:i.second)
//             {
//                 cout<<j<<" ";
//             }
//             cout<<endl;
//         }
    
        queue<int> q;
        
        q.push(0);
        vis[0] = 1;
        int ans =0;
        while(q.empty() == 0)
        {
            
            int top = q.front();
            q.pop();
            
            // cout<<top<<endl;
            for(auto i:mp[top])
            {
                
                if(vis[i] == 0)
                {
                    // cout<<i<<endl;
                    
                    q.push(i);
                    vis[i] = 1;
                    if(st.find({i,top}) == st.end())
                    {
                        ans++;
                    }
                }
            }
            
            // cout<<q.size()<<endl;
        }
        return ans;
    }
};