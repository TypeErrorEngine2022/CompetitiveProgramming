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

int n, m, i, j;
bitset<1000000> bs; //index of bitset is the start for each interval (mins)
//intervals: [0, 1], [1, 2], ... , [99..9, 1000000]

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    bool stop = false;

    while (cin >> n >> m, n + m != 0)
    {
        bs.reset();
        int s, e, r; stop = false;
        for (i = 0; i < n; i++)
        {
            cin >> s >> e;
            if (stop) continue;

            //interval: [s, s+ 1], [s + 2, s + 3], ... , [e - 1, e]
            //ends at e
            for (j = s; j < e; j++)
            {
                if (stop) break;

                if (bs.test(j))
                {
                    cout <<  "CONFLICT\n";
                    stop = true;
                }
                else
                {
                    bs.set(j);
                    //cout << "Set at " << j << " - " << j + 1 << '\n';
                }
            }
        }

        //cout << "hellp\n";

        for (i = 0; i < m; i++)
        {
            cin >> s >> e >> r;
            //cout << s << " " << e << " " << r << '\n';
            if (stop) continue;
            for (j = s; j < 1000000; j += r, e += r)
            {
                if (stop) break;

                for (int k = j; k < e && k < 1000000; k++)
                {
                    if (stop) break;

                    if (bs.test(k))
                    {
                        cout <<  "CONFLICT\n";
                        //cout << "Conflict at " << k << " - " << k + 1 << '\n';
                        stop = true;
                    }
                    else
                    {
                        bs.set(k);
                        //cout << "Set at " << k << " - " << k + 1 << '\n';
                    }
                }
            }
        }

        if (stop) continue;

        cout << "NO CONFLICT\n";
    }
}