#include "../stdc++.h"
#include <cstdio>
#include <cmath>
#include <cstring>

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

bitset<3001> bs;

int N;

int main()
{
    while(scanf("%d", &N) != EOF)
    {
        if (N == 1)
        {
            printf("Jolly\n");
            int tp; scanf("%d", &tp);
            continue;
        }
        bool no = false;
        int prev, next;
        scanf("%d", &prev);
        for (int i = 0; i < N - 1; i++)
        {
            scanf("%d", &next);
            bs.set(abs(next - prev));
            prev = next;
        }
        for (int i = 1; i < N; i++)
        {
            if (!bs.test(i))
            {
                printf("Not jolly\n");
                no = true;
                break;
            }
        }
        if (!no) printf("Jolly\n");
        bs.reset();
    }
}