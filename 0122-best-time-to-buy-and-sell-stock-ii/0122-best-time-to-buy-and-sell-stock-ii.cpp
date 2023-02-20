class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int mx = arr[0];
        int mn = arr[0];
        int n = arr.size();
        int ans = 0; 
        
        for(int i = 1; i<n; i++)
        {
            if(arr[i] > mn)
            {
                ans += arr[i] - mn;
                mn = arr[i];
            }
            if(mn> arr[i])
            {
                mn = arr[i];
            }
        }
        return ans;
    }
};