class Solution {
public:
    int numTimesAllBlue(vector<int>& arr) {
        int n = arr.size();
        vector<long long> brr(n,0);
        brr[0] = arr[0];
        
        for(int i = 1; i<n; i++)
        {
            brr[i] += arr[i]+ brr[i-1];
        }
        long long ans = 0;
        for(long long i = 0; i<n; i++)
        {
            if(brr[i] == ((i+1)*(i+2))/2)
            {
                ans++;
            }
        }
        return ans;
    }
};