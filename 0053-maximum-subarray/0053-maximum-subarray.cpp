class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int ans = INT_MIN;
        int sum = 0;
        int n = arr.size();
        
        for(int i = 0; i<n; i++)
        {
            sum += arr[i];
                ans = max(ans,sum);
            if(sum<0)
                sum = 0 ;
        }
        
        return ans;
    }
};