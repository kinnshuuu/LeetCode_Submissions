class Solution
{
    public:
        // vector<pair<int, int>> p;
    int n;

    vector<vector < int>> dp;
    int solve(int i, int k,vector<vector < int>> &arr) 
    {
        if(k == 0)
            return 0;
        
        if(i == n)
        {
            return 0;
        }
        if(dp[i][k] != -1)
        {
            return dp[i][k];
        }
        int sum = 0;
        sum = solve(i+1,k,arr);

        for(int j = 0; j<arr[i].size(); j++)
        {
            if(k >= j+1)
                sum = max(sum , arr[i][j] + solve(i+1, k - (j+1),arr));
            else
                break;
        }
        
        return dp[i][k] = sum;
    }
    int maxValueOfCoins(vector<vector < int>> &arr, int k)
    {
         n = arr.size();

        for (auto &p: arr)
        {
            for (int i = 1; i < p.size(); i++)
            {
                p[i] += p[i - 1];
            }
        }
        
        
        dp.resize(n, vector<int> (k + 1, -1));

        return solve(0, k,arr);
    }
};