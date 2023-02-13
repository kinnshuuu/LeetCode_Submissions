class Solution {
public:
    int n;
    int m;
    bool solve(int mid,vector<int> &pre, vector<int>&suf )
    {
        
        int x = -1;
        
        for(int i = 0; i<m; i++)
        {
            if(i+mid<m)
            {
                if(suf[i+mid]>x)
                {
                    return 1;
                }
                x = pre[i];
            }
            else
                return 1;
            
            if(pre[i] == -1)
                return 0;
        }
        return 0;
        
    }
    int minimumScore(string s, string t) {
        n = s.size();
        m = t.size();
        
        vector<int> pre(m),suf(m);
        
        int i = 0; int j = 0;
        
        while(j<m)
        {
            while(i<n and s[i] != t[j])
                i++;
            
            if(i == n)
            {
                pre[j] = -1;
            }
            else
            {
                pre[j] = i;
                i++;
            }
            j++;
        }
        j = m-1;
        i = n-1;
        while(j>=0)
        {
            while(i>=0 and s[i] != t[j])
            {
                i--;
            }
            if(i<0)
            {
                suf[j] = -1;
            }
            else
            {
                suf[j] = i;
                i--;
            }
            j--;
        }
        
        // for(int i = 0; i<m; i++)
        // {
        //     cout<<suf[i]<<" ";
        // }
        // cout<<endl;
        int ans = INT_MAX;
        int st = 0;
        int e = 100001;
        
        
        while(st<=e)
        {
            int mid = (st+e)/2;
            
            if(solve(mid,pre,suf))
            {
                ans = mid;
                e = mid-1;
            }
            else
            {
                st = mid+1;
            }
        }
        
        return ans;
        
        
        
    }
};