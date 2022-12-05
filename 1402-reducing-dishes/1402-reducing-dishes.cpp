class Solution
{
    public:
        int maxSatisfaction(vector<int> &arr)
        {
            int n = arr.size();

            sort(arr.begin(), arr.end());
           	// reverse(arr.begin(),arr.end());

            long long ans = 0;
            int i = 0;
            while (i < n)
            {
                long long sum = 0;

                for (int j = i; j < n; j++) 
                {
                    sum += (arr[j] * (j-i+1));
                }
                i++;
                ans = max(sum,ans);
            }
            return ans;
        }
};