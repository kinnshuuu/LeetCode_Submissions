class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int m = arr[0];
        int ans = 0;
        int n = arr.size();
        for(int i = 1; i<n; i++)
        {
            if(arr[i] > m)
            {
                ans = max(ans,arr[i] - m);
            }
            else
            {
                m = min(m,arr[i]);
            }
        }
        return ans;
    }
};