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
    for (vi::iterator it = (c).begin(); it != (c).e(); it++)
#define TRvii(c, it)
    for (vii::iterator it = (c).begin(); it != (c).e(); it++)
#define TRmsi(c, it)
    for (msi::iterator it = (c).begin(); it != (c).e(); it++)*/


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

string line; istringstream iss;
list<char> ls, tmp;
bool home = false, e = true;
int ct = 1;

int main()
{
    while (getline(cin, line))
    {
        if (line.empty()) break;

        if (ct > 1) cout << '\n';
        ct++;

        ls.clear(); tmp.clear();

        for (int i = 0; i < line.size(); i++)
        {
            if (line[i] == '[')
            {
                home = true; e = false;
                continue;
            }
            else if (line[i] == ']')
            {
                home = false; e = true;
                ls.splice(ls.begin(), tmp);
                continue;
            }

            if (home)
            {
                tmp.push_back(line[i]);
            }
            else if (e) ls.push_back(line[i]);
        }

        for (auto it = ls.begin(); it != ls.end(); it++)
        {
            cout << *it;
        }
    }
}