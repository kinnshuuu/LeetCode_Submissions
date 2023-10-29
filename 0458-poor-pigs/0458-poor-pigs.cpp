class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if(buckets == 1)
            return 0;
        
        int total_try = (minutesToTest/ minutesToDie)+1;
        
        return ceil(log2(buckets)/log2(total_try));
        
    }
};


/***

***/