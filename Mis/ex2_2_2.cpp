#include "convention.h"

// b is power of 2 4=>100
int mod(int a, int b)
{
    return a & (b - 1);
    //return a ^ b; //5 => 101 ^ 100 => 1, 10 => 1010 ^ 100 => 1110 = 14, should be 6 =>  110
}

int removeLSB(int a)
{
    //return a ^ (a & (-a));
    return ((a) & (a-1));
}

int removeLastZero(int a)
{
    return a | (a + 1);
}

int turnoffOnes(int a)
{
    return a & (a + 1);
}

int turnOnZeroes(int a)
{
    return a | (a - 1);
}

int main()
{
    cout << turnoffOnes(39) << "\n";
    return 0;
}

