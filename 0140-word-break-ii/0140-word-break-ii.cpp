class Solution
{
    public:
        vector<string> ans;
    void solve(string &s, set<string> &st, int i, string b, string word)
    {
       	// cout<<b<<endl;
        int n = s.length();
        if (i == n and st.find(word) != st.end())
        {
            ans.push_back(b);
            return;
        }
        if (i == n)
            return;

        word.push_back(s[i]);
        // b.push_back(s[i]);
        solve(s, st, i + 1, b+s[i], word);

        if (st.find(word) != st.end())
        {
            solve(s, st, i + 1, b+s[i] + ' ', "");
        }
    }
    vector<string> wordBreak(string s, vector<string> &arr)
    {

        set<string> st;

        for (auto i: arr)
        {
            st.insert(i);
        }
        string b = "";

        string word = "";
        solve(s, st, 0, b, word);
        return ans;
    }
};