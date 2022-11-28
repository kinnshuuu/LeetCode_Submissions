class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& arr) {
        vector<vector<int>> ans(2);
        
        int n = arr.size();
        
        map<int,int> mp;
        
        for(int i = 0; i<n; i++)
        {
            mp[arr[i][0]] = 0;
        }
        
        for(int i = 0; i<n; i++)
        {
            mp[arr[i][1]]++;
        }
        
        for(auto i: mp)
        {
            if(i.second == 0)
            {
                ans[i.second].push_back(i.first);
            }
            if(i.second == 1)
            {
                ans[i.second].push_back(i.first);
            }
        }
        return ans;
    }
};