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

struct man
{
    bool alive;
    int left;
    int right;
};

int S, B;
vector<man> mans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    mans.reserve(100000);

    while (cin >> S >> B, S != 0 && B != 0)
    {
        mans.clear();
        mans.push_back(man{true, -1, 1});
        for (int i = 1; i < S - 1; i++)
            mans.push_back(man{true, i - 1 ,i + 1});
        mans.push_back(man{true, S - 2, -1});
        mans.shrink_to_fit();

        int L, R;
        for (int i = 0; i < B; i++)
        {
            cin >> L >> R;
            L--, R--; //convert to zero-counting
            for (int i = L; i <= R; i++)
            {
                mans[i].alive = false;
                if (mans[i].right != -1) mans[mans[i].right].left = mans[i].left;
                if (mans[i].left != -1) mans[mans[i].left].right = mans[i].right;
            }

            /*for (int i = 0; i < mans.size(); i++)
            {
                cout << "Soldier " << i + 1 << ": " << "(" << mans[i].alive << ", " << mans[i].left << ", " << mans[i].right << ")\n";
            }*/
            if (L == 0) cout << "* ";
            else if (mans[L].left != -1) cout << mans[L].left + 1 << ' ';
            else cout << "* ";

            if (R == S - 1) cout << "*\n";
            else if (mans[R].right != -1) cout << mans[R].right + 1 << '\n';
            else cout << "*\n";
        }
        cout << "-\n";
    }
}