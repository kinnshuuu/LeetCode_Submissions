class Solution {
public:
    
    
    bool dfs(set<string> &st,map<string,vector<string>> &mp,map<string,bool> &v, string &p )
    {
        v[p] = 1;
        bool x = 1;
        for(auto i:mp[p])
        {
            if(st.find(i) == st.end())
            {
                if(v.find(i) != v.end() and v[i] == 0)
                {
                    x = x&&dfs(st,mp,v,i);
                }
                else
                    return 0;
            }
        }
        if(x) st.insert(p);
        return x;
    }
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        set<string> st (supplies.begin(),supplies.end());
        map<string,vector<string>> mp;
        vector<string> ans;
        map<string,bool> v;
        int n = recipes.size();
        for(int i = 0; i<n; i++)
        {
            mp[recipes[i]] = ingredients[i];
            v[recipes[i]] = 0;
        }
        for(auto i:recipes)
        {
            bool x = 0;
            
            if(v[i] == 0)
            {
                x = dfs(st,mp,v,i);
                if(x == 1)
                    ans.push_back(i);
            }
            else if(st.find(i) != st.end())
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};