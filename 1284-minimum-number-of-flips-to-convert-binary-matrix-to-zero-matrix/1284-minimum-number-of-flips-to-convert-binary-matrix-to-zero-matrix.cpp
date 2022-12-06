class Solution
{
    public:
        int n = 0;
    int m = 0;
    int ans = INT_MAX;

    vector<int> des;
    void solve(vector<int> &arr, int x, int i, int steps)
    {
        if (arr == des)
        {
            ans = min(steps, ans);
            return;
        }
        if (i >= x)
            return;
        // cout << i << " ";
        // for (auto d: arr)
        // {
        //     cout << d;
        // }
        // cout << endl;
        solve(arr, x, i + 1, steps);

        arr[i] ^= 1;
        if (i%m < (i+1)%m) arr[i + 1] ^= 1;
        if (i-1>=0 and (i - 1)%m < i%m) arr[i - 1] ^= 1;
        if (i + m < x) arr[i + m] ^= 1;
        if (i - m >= 0) arr[i - m] ^= 1;

        // cout << i << "' ";
        // for (auto d: arr)
        // {
        //     cout << d;
        // }
        // cout << endl;
        solve(arr, x, i + 1, steps + 1);
        arr[i] ^= 1;
        
        if (i%m < (i+1)%m) arr[i + 1] ^= 1;
        if (i-1>=0 and (i - 1)%m < i%m) arr[i - 1] ^= 1;
        if (i + m < x) arr[i + m] ^= 1;
        if (i - m >= 0) arr[i - m] ^= 1;

    }
    int minFlips(vector<vector < int>> &a)
    {
        vector<int> arr;
        n = a.size();
        m = a[0].size();
        des.resize(n *m, 0);

        if (m >= n)
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    arr.push_back(a[i][j]);
                }
            }
        else
        {
            // swap(n,m);
            
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    arr.push_back(a[j][i]);
                }
            }
            swap(n,m);
            
            
        }
//         cout<<n<<" "<<m<<endl;
// for (auto d: arr)
//         {
//             cout << d;
//         }
//         cout << endl;
        solve(arr, n *m, 0, 0);

        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};