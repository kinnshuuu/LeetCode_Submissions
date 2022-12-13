class Solution
{
    public:
        int minOperations(vector<int> &nums, int x)
        {
            int i = 0, n = nums.size(), j = 0;
            int cnt = -1;
            long long sum = accumulate(nums.begin(), nums.end(), 0);
            long long t = sum - x;
            sum = 0;
            while (j < n and i<n)
            {
                sum += nums[j];
                if (sum < t)
                    j++;
                else if (sum > t)
                {
                    while (sum > t and i<n)
                    {
                        sum -= nums[i];
                        i++;
                    }
                    if(sum == t)
                    {
                        cnt = max(cnt, j - i + 1);
                    }
                    j++;
                    
                }
                else
                {
                    cnt = max(cnt, j - i + 1);
                    j++;
                }
            }
            return cnt == -1 ? -1 : n - cnt;
        }
};