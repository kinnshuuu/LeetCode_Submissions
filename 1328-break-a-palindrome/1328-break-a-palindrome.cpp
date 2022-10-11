class Solution {
public:
    string breakPalindrome(string palindrome) {
        int  n=palindrome.size();//calculating size
//there is no sense of performing if size<2 as there is no way to make it non-palindrome
        if(n<2)
        {
            return "";
        }
    int flag=0;
        
        for(int i=0;i<n/2;i++)
        {
            if(palindrome[i]!='a')
            {
                flag=1;
                palindrome[i]='a';
                break;
            }
        }
        if(flag==0)
        {
            palindrome[n-1]='b';
        }
        return palindrome;
    }
};