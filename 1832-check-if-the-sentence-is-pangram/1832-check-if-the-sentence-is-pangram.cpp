class Solution {
public:
    bool checkIfPangram(string sentence) {
        bool arr[26]= {0};
        int n = sentence.length();
        
        for(int i = 0; i<n ;i++)
        {
            arr[sentence[i] - 'a'] = 1;
        }
        for(int i = 0; i<26 ;i++)
        {
            if(arr[i] == 0)
                return 0;
        }
        return 1;
    }
};