#include "stdc++.h"
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

long n, pos;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n >> pos, n + pos != 0)
    {
        if (n == 1){
             cout << "Line = 1, column = 1.\n";
             continue;
        }
        
        int mid = n / 2; //if n = 5 => mid = 2;

        if (pos == 1) 
        {
            cout << "Line = " << mid + 1 <<  ", column = " << mid + 1 << ".\n";
            continue;
        }

        if (pos == n * n)
        {
            cout << "Line = " << n <<  ", column = " << n << ".\n";
            continue;
        }

        int linesign[4] = {1, 0, -1, 0};
        int colsign[4] = {0, -1, 0 ,1}; 

        /*long sq = sqrtl((long double)pos); 
        if (sq % 2 != 1) sq--; //nearest perfect square from odd number
        long steps = sq;

        long cur = sq * sq; long line = sq + 1; long col = sq + 1;

        long route[] = {1, steps, steps + 1, steps + 1, steps + 2};
        
        int ct = 0;

        while (cur < pos)
        {
            steps = route[ct];
            cout << "pos: (" << line << ", " << col << ")\n";
            cout << "ct: " << ct << " steps: " << steps << '\n';
            if (cur + steps > pos) steps = pos - cur;
            cur += steps;
            line += steps * linesign[ct % 4];
            col += steps * colsign[ct % 4];
            ct++;
        }*/

        long circle = sqrt(pos + 1) / 2;
        cout << "circle is " << circle << '\n';
        long center = (n + 1) / 2;
        cout << "center is " << center << '\n';
        // 2 * circle - 1 is the odd square
        long left = pos - (2 * circle - 1) * (2 * circle - 1);
        cout << "left is " << left << '\n';

        long line, col;

        if (left <= circle * 2)
        {
            line = center + circle; col = center + circle - left;
        }
        else if (left <= circle * 4)
        {
            left = left - 2 * circle;
            line = center + circle - left; col = center - circle;
        }
        else if (left <= circle * 6)
        {
            left = left - 4 * circle;
            line = center - circle; col = center - circle + left;  
        }
        else
        {
            left = left - 6 * circle;
            line = center - circle + left; col = center + circle;
        }
        cout << "Line = " << line << ", column = " << col <<".\n";


        /*long long root = sqrt(pos);
        if(root * root == pos && root % 2 == 1) {
        } else if(root % 2 == 1) root += 2;
        else root++;
 
        long long i = root / 2, j = root / 2;
        if(root * root != 1) {  
            long group = (root * root - pos) / (root - 1);
            switch(group) {
                case 0:
                    i -= root * root - pos;
                    break;
                case 1:
                    i -= root - 1;
                    j -= (root * root - pos - (root - 1));
                    break;
                case 2:
                    cout << "i: " << i << '\n';
                    cout << "j: " << j << '\n';
                    cout << "root: " << root << '\n';
                    cout << "i - " << (root - 1) - (root * root - pos - (root - 1) * 2) << '\n';
                    cout << "j - " << (root - 1) << '\n';
                    i -= (root - 1) - (root * root - pos - (root - 1) * 2);
                    j -= root - 1;
                    break;
                case 3:
                    j -= (root - 1) - (root * root - pos - (root - 1) * 3);
                    break;
            }
        }
        cout << "Line = " << i + n / 2 + 1 << ", column = " << j + n / 2 + 1 <<".\n";*/
    

    //dur:       1    1    2     2  3   3     4     4  4
            //  up left down right up left down right up
        // line: 1     0  -1     0  1    0    -1    0  1
        // col:  0    -1   0     1  0   -1    0     1  0

        // up left down down right right up up up left left left
        // down down down down right right right right up up up up

        

        /*long cur = 1;
        long steps = 0;
        long line = mid + 1, col = mid + 1;
        long ct = 0;
        
        while (cur < pos)
        {
            if (ct % 2 == 0) steps++; //after 2 steps, increase the magnitude for steps
            if (cur + steps > pos) //not to go beyone pos
            {
                steps = pos - cur;
            }
            cur += steps;
            cout << "pos: (" << line << ", " << col << ")\n";
            cout << "ct: " << ct << " steps: " << steps << '\n';
            line += steps * linesign[ct % 4];
            col += steps * colsign[ct % 4];
            ct++;
        }*/
        //cout << "(" << line << ", " << col << ") ";
        //cout << "Line = " << line <<  ", column = " << col << ".\n";
    }
}