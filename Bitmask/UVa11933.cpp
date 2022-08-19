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

int n, i = 0, ct = 1, an = 0, bn = 0;
vector<int> a, b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n, n != 0)
    {
        i = 0; ct = 1; an = 0; bn = 0;
        a.clear(); b.clear();
        while (n != 0)
        {
            if (n & 1) //6: 110
            {
                if (ct % 2 != 0)
                    a.push_back(i);
                else b.push_back(i);
                ct++;
            }
            i++;
            n = n >> 1;
        }

        for (int i = 0; i < a.size(); i++)
            an |= (1 << a[i]);
        for (int i = 0; i < b.size(); i++)
            bn |= (1 << b[i]);
        
        cout << an << " " << bn << '\n';
    }
}