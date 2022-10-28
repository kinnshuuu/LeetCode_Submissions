class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) 
    {
        vector<string> t = s;
        map<string,vector<int> > mp;
        for(int i = 0; i< t.size(); i++)
        {
            sort(t[i].begin(),t[i].end());
            mp[t[i]].push_back(i);
        }
        vector<vector<string>> ans;
        
        for(auto i: mp)
        {
            vector<string> temp;
            for(auto j: i.second)
            {
                temp.push_back(s[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};