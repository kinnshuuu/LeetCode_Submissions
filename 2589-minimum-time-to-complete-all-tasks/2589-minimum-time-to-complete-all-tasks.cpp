class Solution {
public:
    int findMinimumTime(vector<vector<int>>& arr) {
        bool time[2001] = {0};
        sort(arr.begin(),arr.end(),[](const auto &t1, const auto &t2)
             {
                 return t1[1]<t2[1];
             });
        for(auto task : arr)
        {
            int start = task[0];
            int end = task[1];
            int dead = task[2];
            
            for(int i = start; i<= end; i++)
            {
                if(time[i])
                    dead--;
            }
            for(int i = end; dead>0; i--)
            {
                if(time[i])
                {
                    continue;
                }
                time[i] = 1;
                dead--;
            }
        }
        int ans = 0;
        
        for(auto i:time)
        {
            if(i == 1)
            {
                ans++;
            }
        }
        return ans;
        
    }
};