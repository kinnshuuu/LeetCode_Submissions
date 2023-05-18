class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        set<int> s;
        // set<int> t;
        
        for(int i = 0; i<n; i++)
        {
            s.insert(i);
        }
        
        
        for(auto i:edges)
        {
            if(s.find(i[1]) != s.end())
            {
                s.erase(i[1]);
            }
        }
        
        vector<int> ans(s.begin(),s.end());

        return ans;
    }
};