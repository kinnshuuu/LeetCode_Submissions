class Solution
{
    public:
        int takeCharacters(string s, int k)
        {
            if (k == 0)
                return 0;
            int n = s.length();
           	// cout<<n<<  " ";
            map<char, vector < int>> mp;
            for (int i = 0; i < n; i++)
            {
                mp[s[i]].push_back(i);
            }

            if (mp['a'].size() < k or mp['b'].size() < k or mp['c'].size() < k)
                return -1;

            map<int, int> a, b, c;

            a[0] = n;
            b[0] = n;
            c[0] = n;
            int ca, cb, cc;

            ca = cb = cc = 0;

            for (int i = n - 1; i >= 0; i--)
            {
                if (s[i] == 'a')
                {
                    ca++;
                    a[ca] = i;
                }
                if (s[i] == 'b')
                {
                    cb++;
                    b[cb] = i;
                }
                if (s[i] == 'c')
                {
                    cc++;
                    c[cc] = i;
                }
            }
           	// cout<<n - a[333] << " "<<n - b[333] << " "<<n - c[333]<<endl;
            int ans = INT_MAX;

            ca = cb = cc = 0;
            int x = n - min(a[max(0, k - ca)], min(b[max(0, k - cb)],  c[max(0,k - cc)]));
            ans = min(ans, x);
            for (int i = 0; i < n; i++)
            {
                if (s[i] == 'a')
                {
                    ca++;
                   	// a[ca] = i;
                }
                if (s[i] == 'b')
                {
                    cb++;
                   	// b[cb] = i;
                }
                if (s[i] == 'c')
                {
                    cc++;
                   	// c[cc] = i;
                }

                int y = n - min(a[max(0, k - ca)], min(b[max(0, k - cb)],  c[max(0,k - cc)]));

                ans = min(ans, y + 1 + i);
            }
            return ans;
        }
};