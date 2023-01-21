class Solution
{
    public:
        int slidingPuzzle(vector<vector < int>> &board)
        {
            int x;
            int y;
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (board[i][j] == 0)
                    {
                        x = i;
                        y = j;
                        break;
                    }
                }
            }
            set<vector<vector< int>>> st;

            queue<pair<vector< vector< int >>, vector< int>>> q;
            vector<int> vrr(3);

            vrr[0] = x;
            vrr[1] = y;
            vrr[2] = 0;
            q.push(make_pair
            (
                board,
                vrr ));

            vector<vector < int>> ans(2,vector<int>(3));
            int var = 1;
            for(int i =0; i<2; i++)
            {
                for(int j = 0; j<3; j++)
                {
                    ans [i][j] = var++;
                }
            }
            ans[1][2] = 0; 
            
            while (q.empty() == 0)
            {
                auto p = q.front();
                q.pop();
            
                auto v = p.second;
                auto arr = p.first;
                
                // for(int i = 0; i<2; i++)
                // {
                //     for(int j = 0; j<3; j++)
                //     {
                //         cout<<arr[i][j];
                //     }
                //     cout<<endl;
                // }
                if(arr == ans)
                {
                    return v[2];
                }
                if (v[0] + 1 < 2)
                {
                    swap(arr[v[0]][v[1]], arr[v[0] + 1][v[1]]);
                    vrr[0] = v[0] + 1;
                    vrr[1] = v[1];
                    vrr[2] = v[2] +1; 
                    if(st.find(arr) == st.end())
                    {
                        q.push({arr,vrr});
                        st.insert(arr);
                    }
                    
                    swap(arr[v[0]][v[1]], arr[v[0] + 1][v[1]]);
                }
                if (v[0] - 1 >= 0)
                {
                    swap(arr[v[0]][v[1]], arr[v[0] - 1][v[1]]);
                    vrr[0] = v[0] -1;
                    vrr[1] = v[1];
                    vrr[2] = v[2] +1; 
                    if(st.find(arr) == st.end())
                    {
                        q.push({arr,vrr});
                        st.insert(arr);
                    }
                    swap(arr[v[0]][v[1]], arr[v[0] - 1][v[1]]);
                }

                if (v[1] + 1 < 3)
                {
                    swap(arr[v[0]][v[1]], arr[v[0]][v[1] + 1]);
                    vrr[0] = v[0] ;
                    vrr[1] = v[1]+1;
                    vrr[2] = v[2] +1; 
                    if(st.find(arr) == st.end())
                    {
                        q.push({arr,vrr});
                        st.insert(arr);
                    }
                    swap(arr[v[0]][v[1]], arr[v[0]][v[1] + 1]);
                }
                             
                if (v[1] - 1 >= 0)
                {
                    swap(arr[v[0]][v[1]], arr[v[0]][v[1] - 1]);
                    vrr[0] = v[0];
                    vrr[1] = v[1] - 1;
                    vrr[2] = v[2] + 1; 
                    if(st.find(arr) == st.end())
                    {
                        q.push({arr,vrr});
                        st.insert(arr);
                    }
                    swap(arr[v[0]][v[1]], arr[v[0]][v[1] - 1]);
                }
            
            }
                             
        
            return -1;
        }
        
};
                             