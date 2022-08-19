#include "../stdc++.h"
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

// shortcuts for "common" data types in contests
typedef long long ll;
typedef std::vector<int> vi;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::set<int> si;
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
// If you need to recall how to use memset
#define MEMSET_INF 127      // about 2B (byte)
#define MEMESET_HALF_INF 63 // about 1B
// memset (dist, MEMSET_INF, sizeof dist); //useful to initialize shortest path distances
// memset (dp_memo, -1, sizeof dp_memo); //useful to intialize DP memoization table
// memset(arr, 0, sizeof arr); //useful to clear array of integers

// Common shortcut
// index = (index + 1) % n; // index++; if (index >= n) index = 0;
// index  = (index + n - 1) % n; //index--; if (index < 0) index = n - 1;
// int ans = (int)((double)d + 0.5); //for rounding to the nearest integer
// ans = min(ans, new_computation); //min/max shortcut

// Accurate Math constant
double PI(2 * acos(0.0));

struct ppl
{
    int id;
    int pen;
    int solved;
    int ct;
    int Q[11];
    bool joined;
};

vector<ppl> ppls(101, ppl{1000, 0, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, false});
int TC, id, t, q, ct = 0;
char state;


//highest ranking lower priority
//if a has higher ranking, return true
bool comp(ppl a, ppl b)
{
    if (a.joined && b.joined)
    {
        if (a.ct < b.ct) return false;
        if (a.ct > b.ct) return true;
        if (a.pen > b.pen) return false;
        if (a.pen < b.pen) return true;
        if (a.id < b.id) return true; 
        if (a.id > b.id) return false;
    }
    if (a.joined == true && b.joined == false) return true;

    return false;
}

int main()
{
    cin >> TC;
    getchar();//first '\n after TC
    getchar(); //second '\n' in blank line
    int ct = 1;
    while (TC--) //each TC start from the judging queue
    {
        if (ct > 1)
        {
            cout << '\n';
            fill(ppls.begin(), ppls.end(), ppl{1000, 0, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, false});
        }
        ct++;
        string line;

        while (getline(cin, line))
        {
            if (line.empty())
            {
                getchar(); // the '\n' in blank line, prepared for next TC
                break; 
            }
            
            //cout << line << '\n';
            istringstream iss(line);
            if (iss >> id >> q >> t >> state)
            {
                ppls[id].joined = true;
                ppls[id].id = id;

                switch (state)
                {
                case 'I':
                    ppls[id].Q[q]++;
                    break;

                case 'C':
                    if (ppls[id].solved & (1 << q)) break;
                    else ppls[id].solved |= (1 << q);
                    ppls[id].pen += t + ppls[id].Q[q] * 20;
                    ppls[id].ct++;
                    break;

                default:
                    break;
                }
            }
        }

        sort(ppls.begin(), ppls.end(), comp);

        for (int i = 0; i <= 100; i++)
        {
            if (!ppls[i].joined) break;

            cout << ppls[i].id << ' ' << ppls[i].ct << ' ' << ppls[i].pen << '\n';
        }
    }
}