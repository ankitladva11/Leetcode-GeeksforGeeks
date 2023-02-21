class Solution {
public:
    int divide(int divident, int divisor)
{
    if(divident == -2147483648 && divisor == -1) return 2147483647;
    if(divisor == 1) return divident;
    long long a = abs(divident), b = abs(divisor);
    long long res = 0;
    while (a >= b)
    {
        long long x = 0;
        while (a >= (b << x))
        {
            x++;
        }
        x--;
        res += pow(2, x);
        a = (a - (b << x));
    }
    if ((divident < 0) ^ (divisor < 0))
        return -res;
    return res;
}
};