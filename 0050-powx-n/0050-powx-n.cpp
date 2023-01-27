class Solution {
public:
    double myPow(double x, long long n) {
        if(x == 1)
            return 1;
        if(n < 0)
        {
            return 1/ myPow(x, n*-1);
        }
        if(n == 0)
        {
            return 1;
        }
        double res = myPow(x,n/2);
        
        if(n&1)
        {
            return x*res*res;
        }
        else
        {
            return res*res;
        }
    }
};

// int power(int a, int b)
// {
//     if (b == 0)
//         return 1;
//     int res = power(a, b / 2);
//     if (b & 1)
//     {
//         return a * res * res;
//     }
//     else
//         return res * res;
// }