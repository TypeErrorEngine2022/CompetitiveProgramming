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

int tc, paid, line; double sum;
array<double, 256> ascii;
char text[10002];

int main()
{   
    scanf("%d", &tc);
    //printf("tc is %d", tc);
    while (tc--)
    {
        sum = 0.0;
        ascii.fill(0.0);
        scanf("%d", &paid);
        //printf("paid is %d", paid);
        while (paid--)
        {
            char ch; double val;
            scanf(" %c %lf", &ch, &val); //the beginning space skip the newline character
            //printf("%c: %d %.2lf\n", ch, ch, val);
            ascii[ch] = val / 100.0; //val are in cents
        }
        scanf("%d", &line);
        //printf("%d line\n", line);
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // remove the \n after the line number, preventing getline to get it
        while (line--)
        {
            cin.getline(text, 10000);
            //cout << "\nfirst character is " << text[0] << '\n';
            for (int i = 0; text[i] != '\0'; i++)
            {
                sum += ascii[text[i]];
                //cout << text[i];
            }
        }
        printf("%.2lf$\n", sum);
    }
}