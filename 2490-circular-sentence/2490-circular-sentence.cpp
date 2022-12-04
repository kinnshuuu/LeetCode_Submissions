class Solution {
public:
    bool isCircularSentence(string s) {
        int n = s.length();
        
        char ff = s[0];
        char ll  = s[n-1];
        if(abs(ff-ll) != 0 )
            return 0;
        
        char f = s[0];
        char l;
        int i = 1;
        for(int i = 0 ;i<n; i++)
        {
            if(s[i] == ' ')
            {
                if(i+1<n and i>0)
                {
                    l = s[i-1] ;
                    f = s[i+1];
                    if(abs(f-l) != 0 )
            return 0;
                }
            }
        }
        return 1;
    }
};