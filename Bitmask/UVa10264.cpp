#include "../stdc++.h"

using namespace std;

//shortcuts for "common" data types in contests
typedef long long                       ll;
typedef std::vector<int>                vi;
typedef std::pair<int, int>             ii;
typedef std::vector<ii>                 vii;
typedef std::set<int>                   si;
typedef std::map<std::string, int> msi;

// Abandoned, beacuse of confusion
/*#define REP(i, a, a) 
    for (int i = int(a), i <= int(b), i++) // a to b, and variable i is local!
#define TRvi(c, it)
    for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it)
    for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it)
    for (msi::iterator it = (c).begin(); it != (c).end(); it++)*/


#define INF 1000000000 // 1 billion
//If you need to recall how to use memset
#define MEMSET_INF 127 // about 2B (byte)
#define MEMESET_HALF_INF 63 //about 1B
//memset (dist, MEMSET_INF, sizeof dist); //useful to initialize shortest path distances
//memset (dp_memo, -1, sizeof dp_memo); //useful to intialize DP memoization table
//memset(arr, 0, sizeof arr); //useful to clear array of integers

// Common shortcut
// index = (index + 1) % n; // index++; if (index >= n) index = 0;
// index  = (index + n - 1) % n; //index--; if (index < 0) index = n - 1;
// int ans = (int)((double)d + 0.5); //for rounding to the nearest integer
// ans = min(ans, new_computation); //min/max shortcut

//Accurate Math constant
double PI (2 * acos(0.0));

int n;
array<short, (1 << 15)> masses; short mass; int sum; //extra space
array<int, (1 << 15)> allsum; int res;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (scanf("%d", &n) != EOF)
    {
        masses.fill(0); allsum.fill(0); res = 0;
        int noC = 1 << n;
        for (int i = 0; i < noC; i++) 
        {
            scanf("%hd", &mass);
            masses[i] = mass;
        }
        
        for (int i = 0; i < noC; i++)
        {
            sum = 0;
            for (int j = 0; j < n; j++)
            {
                short nbindex = i ^ (1 << j);
                sum += masses[nbindex];
            }
            allsum[i] = sum;
        }

        
        for (int i = 0; i < noC; i++)
        {
            for (int j = 0; j < n; j++)
            {
                short nbindex = i ^ (1 << j);
                int tsum = allsum[i] + allsum[nbindex];
                if (tsum > res) res = tsum;
            }
        }

        printf("%d\n", res);
    }
}