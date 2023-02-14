class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& arr) {
        vector<vector<int>> child(n+1);
        
        for(auto i : arr)
        {
            child[i[0]].push_back(i[1]);
            child[i[1]].push_back(i[0]);
        }
        
        int x = 0;
        vector<int> odd;
        for(int i = 1; i<=n;i++)
        {
            if(child[i].size()%2 ==1)
            {
                x++;
                odd.push_back(i);
            }
        }
        // cout<<x<<endl;
        // for(int i= 0; i<odd.size(); i++)
        // {
        //     cout<<odd[i]<<" ->";
        //     for(auto j:child[odd[i]])
        //     {
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        if(x%2 == 1 or x>4)
        {
            return 0;
        }
        if(x==0)return 1;
        if(x == 2)
        {
            bool ans = check(odd[0],odd[1],child);
            
            if(!ans)
            {
                set<int> st;
                for(auto i:child[odd[0]])
                {
                    st.insert(i);
                }
                for(auto i:child[odd[1]])
                {
                    st.insert(i);
                }
                if(st.size() == n)
                    return 0;
            }
            return 1;
        }
           
        if(x == 4)
        {
            bool flag1 = check(odd[0],odd[1],child) & check(odd[3],odd[2],child);
            bool flag2 = check(odd[0],odd[2],child) & check(odd[3],odd[1],child);
            bool flag3 = check(odd[0],odd[3],child) & check(odd[1],odd[2],child);
            return flag1|flag2|flag3;
        }
        
        return 1;
    }
    bool check(int a,int b, vector<vector<int>> &child)
    {
        for(auto i: child[a])
        {
            if(b == i)
                return 0;
        }
        return 1;
    }
    
};