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

int N, n, ct = 0, prevPos = -1;
vector<string> big, small;
vector<vector<string>> res;

/*bool place(int x ,int y, int line2)
{
    int lenforbig = N - y;
    string subforbig = big[x].substr(y, lenforbig);
    const char* one = subforbig.c_str();
    const char* two = small[line2].c_str();
    char* pos = strstr(one, two);
    if (pos)
    {
        if (prevPos == -1 || y == prevPos)
        {
            prevPos = y;
            return true;
        }
    }
    
    return false;
}

void backtrack1(int line)
{
    //candidate sol
    if (line == small.size() + 1)
    {
        ct++; 
        return;
    }

    //if size = 4, line = 1 => need to match 2 more lines 
    int left = small.size() - 1 - line; 

    for (int i = 0; i < N; i++) //try all possible row in big
    {
        if (line + left > N - 1) continue;

        /*if (place(i, line)) // if can place small[line] in big[i] in same pos
        {
            backtrack(line + 1); // try small[line + 1]
        }
    }
}*/

bool isValid(vector<string>& sq, int row, int col)
{
    cout << "row: " << row << " col: " << col << '\n';
    if (row + n - 1 > N || col + n - 1 > N) return false;

    for (int i = 0; i < n; i++)
    {
        cout << "test " << col << '\n';
        string subforbig = big[row + i].substr(col, n);
        if (!(subforbig == small[i]))
        {
            return false;
        }
    }
}

void backtrack(vector<string>& sq, int row)
{
    if (row == N)
    {
        ct++;
        res.push_back(sq);
        return;
    }

    for (int col = 0; col < N; col++)
    {
        //early pruning
        if (!isValid(sq, row, col))
            continue;
        
        sq[row][col] = 'y';

        backtrack(sq, row + 1);
        
        sq[row][col] = '.';
    }
}

void solve()
{
    ct = 0;
    for (int i = 0; i <= N - n; i++)
    {
        for (int j = 0; j <= N - n; j++)
        {
            bool can = false;
            if (big[i][j] == small[0][0]) can = true;
            if (can)
            {
                for (int k = 0; k < n && can; k++)
                    for (int l = 0; l < n; l++)
                        if (big[i + k][j + l] != small[k][l]) can = false;

                if (can) ct++;
            }
        }
    }
}

// rotate 90 degrees clockwisely
void rotate()
{
    //(0,0) -> (0,1)
    //(0,1) -> (1,1)
    //(1,0) -> (0,0)
    //(1,1) -> (0,1)

    //new row = col; new col = size - row;

    //inplace
    // O(n * n) time, O(1) space
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++) //start after diagonal
        {
            swap(small[i][j], small[j][i]); //transpose
        }
    }

    for (int i = 0; i < n; i++)
        reverse(small[i].begin(), small[i].end());


    // O(n) time, O(n) space
    /*vector<string> tmp(n, string(n, ' '));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tmp[j][n - 1 - i] = small[i][j]; // (0, 0) to (0, 2)
        }
    }

    std::swap(tmp, small);*/
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N >> n, N != 0 && n != 0)
    {
        //cout << N << " " << n << "\n";
        big.clear(); small.clear();
        big.reserve(N); small.reserve(n);
        cin.ignore();
        string line; line.reserve(N);
        for (int i = 0; i < N; i++)
        {
            getline(cin, line);
            big.push_back(line);
        }
        for (int i = 0; i < n; i++)
        {
            getline(cin, line);
            small.push_back(line);
        }

        solve();
        cout << ct << ' ';
        
        rotate(); //90
        solve(); cout << ct << ' ';
        
        rotate(); //180
        solve(); cout << ct << ' ';

        rotate(); //270
        solve(); cout << ct << '\n';
    }
}