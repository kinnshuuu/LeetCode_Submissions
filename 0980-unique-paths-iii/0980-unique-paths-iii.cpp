class Solution
{
    public:

        int dfs(vector<vector < int>> &arr, int x, int y, int zero)
        {
            int n = arr.size();
            int m = arr[0].size();

            if (x < 0 || y < 0 || x >= n || y >= m || arr[x][y] == -1)
                return 0;

            if (arr[x][y] == 2)
                return zero == -1 ? 1 : 0;

            arr[x][y] = -1;
            zero--;

            int ans = dfs(arr, x + 1, y, zero) +
                dfs(arr, x, y + 1, zero) +
                dfs(arr, x - 1, y, zero) +
                dfs(arr, x, y - 1, zero);
            
            arr[x][y] = 0;
            return ans;
        }
    int uniquePathsIII(vector<vector < int>> &arr)
    {
        int n = arr.size();
        int m = arr[0].size();
        int x, y, zero = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 0)
                    zero++;
                else if (arr[i][j] == 1)
                {
                    x = i;
                    y = j;
                }
            }
        }

        return dfs(arr, x, y, zero);
    }
};