class Solution
{
    public:
        set<string> st;

    map<int, vector < string>> mp;
    vector<string> solve(string &s, int i)
    {

        vector<string> ans;
        for (int j = i; j < s.size(); j++)
        {

            if (st.count(s.substr(i, j - i + 1)))
            {
                if (j == s.size() - 1)
                {
                    ans.push_back(s.substr(i, j - i + 1));
                    break;
                }
                if (mp.find(j+1) != mp.end())
                {
                    for (auto t: mp[j+1])
                    {
                        ans.push_back(s.substr(i, j - i + 1) + " " + t);
                    }
                    continue;
                }
                auto vec = solve(s, j + 1);
                for (auto t: vec)
                {
                    ans.push_back(s.substr(i, j - i + 1) + " " + t);
                }
            }
        }
        mp[i] = ans;
        return ans;
    }
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        for (auto i: wordDict)
        {
            st.insert(i);
        }

        return solve(s, 0);
    }
};