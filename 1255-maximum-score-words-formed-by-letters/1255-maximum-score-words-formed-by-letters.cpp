class Solution {
public:
    map<char,int> freq;
    map<char,int> val;
    
    int ans = 0;
    
    bool isLegal(unordered_map<char,int> &mp)
    {
        for(auto i:mp)
        {
            if(i.second > freq[i.first])
                return false;
        }
        return 1;
    }
    void solve(vector<string>& words )
    {
        int n = words.size();
        int m = pow(2,n);
        
        unordered_map<char,int> mp;
        for(int i = 1; i < m; i++)
        {
            int temp = i;
            int x= 0;
            int j = 0;
            int sum = 0;
            while(temp)
            {
                
                if(temp%2 == 1)
                {
                    for(auto s: words[j])
                    {
                        mp[s]++;
                        sum+= val[s];
                    }
                }
                
                j++;
                temp/=2;
            }
            if(isLegal( mp))
            {
                ans = max(sum,ans);
            }
            mp.clear();
        }
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score)
    {
        for(int i =0;i<letters.size();i++)
        {
            freq[letters[i]]++;
        }
        for(int i =0; i< score.size();i++)
        {
            val[i+'a']= score[i];
        }
        
        solve(words);
        
        return ans;
    }
};