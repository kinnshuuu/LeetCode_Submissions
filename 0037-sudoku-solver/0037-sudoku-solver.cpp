class Solution
{
    public:
    vector<pair<int, int>> arr;
    int n;
    vector<vector < char>> ans;
    bool possible(vector<vector < char>> &s, int x, int y, int v)
    {
        for (int i = 0; i < 9; i++)
        {
            if (s[i][y] == '0' + v)
            {
                return 0;
            }
        }
        for (int i = 0; i < 9; i++)
        {
            if (s[x][i] == '0' + v)
            {
                return 0;
            }
        }

        int b = x / 3;
        int c = y / 3;

        b = b * 3;
        c = c * 3;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (s[i + b][j + c] == '0' + v)
                    return 0;
            }
        }

        return 1;
    }
    void solve(vector<vector < char>> &s, int i)
    {

        if (i == n)
        {
            ans = s;
            return;
        }
        int x = arr[i].first;
        int y = arr[i].second;
        for (int j = 1; j < 10; j++)
        {
            if (possible(s, x, y, j))
            {
                s[x][y] = '0' + j;
                solve(s, i + 1);
                s[x][y] = '.';
            }
        }
    }

    void solveSudoku(vector<vector < char>> &s)
    {

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (s[i][j] == '.')
                    arr.push_back({ i,
                        j });
            }
        }

        n = arr.size();

        solve(s, 0);
        s = ans;
    }
};