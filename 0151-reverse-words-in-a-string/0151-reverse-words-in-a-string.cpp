class Solution
{
    public:
        string reverseWords(string s)
        {
            string p;
            stack<char> q;
            int n = s.length();
            int j = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                if (s[i] != ' ')
                {
                    q.push(s[i]);
                }
                else
                {
                    while (q.size() != 0)
                    {
                        p = p + q.top();
                        q.pop();
                        if (q.size() == 0)
                        {
                            p = p + " ";
                        }
                    }
                }
            }
            if (q.size() != 0)
            {
                while (q.size() != 0)
                {
                    p = p + q.top();
                    q.pop();
                }
            }
            else
            {
                p.pop_back();
            }
            return p;
        }
};