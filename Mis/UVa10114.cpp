#include <bits/stdc++.h>
#include <cstdio>

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

int main()
{
    using namespace std;
    //payment in double
    //duration(months) downPayment(monthly) loanAmount no.of Dep
    //Month dep%
    //if a month is not listed, prev % applies

    int dur, nodep, time;
    double pay, owe, val, monthPay;
    while (true)
    {
        scanf("%d %lf %lf %d", &dur, &pay, &owe, &nodep);
        if (dur < 0) return 0;
        val = owe + pay; time = 0; monthPay = owe / dur;
        vector<double> depMonth(101, 0.0);
        while (nodep--)
        {
            int month; double dep;
            scanf("%d %lf", &month, &dep);
            depMonth[month] = dep;
        }
        for (int i = 0; i < (int)depMonth.size(); i++)
            if (depMonth[i] == 0.0)
                depMonth[i] = depMonth[i - 1];
        
        val *= (1.0 - depMonth[0]);
        while (owe >= val)
        {
            time++;
            owe -= monthPay;
            val *= (1.0 - depMonth[time]);
        }

        if (time != 1) printf("%d months\n", time);
        else printf("%d month\n", time);
    }
}