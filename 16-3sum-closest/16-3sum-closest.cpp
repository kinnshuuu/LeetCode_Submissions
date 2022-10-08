class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) {
        long long sum = 0;
        long long ans = INT_MAX;

        sort(arr.begin(),arr.end());
        
        for(int i = 0; i < (arr.size() - 2); i++)
        {
            int s = i+1;
            int e = arr.size()-1;

            while(s < e)
            {
                sum = arr[i] + arr[s] + arr[e];
                if(sum == target)
                    return sum;
                if(sum > target)
                {
                    e--;
                }
                else if(sum < target)
                    s++;
                if(abs(ans - target) > abs(sum - target))
                    ans = sum;
            }
        }
        return ans;
    }
};