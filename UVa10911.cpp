/* Forming Quiz Teams. This DP solution will be explained in Section 3.4 */
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int N, target;
double dist[20][20], memo[1 << 16]; // 1 << 16 is 2 ^16, recall that max N = 8

double matching(int bitmask)
{
    if (memo[bitmask] > -0.5) //see that we intialize the array with -1 in the main function
        return memo[bitmask];
    if (bitmask == (( 1 << 2 * N) - 1)) // all are matched
        return memo[bitmask] = 0;

    double ans = 2000000000.0; //intialize with large value
    int p1, p2;
    for (p1 = 0; p1 < 2 * N; p1++)
        if (!(bitmask & ( 1 << p1))) 
            break; //find the first bit that is off
    for (p2 = p1 + 1; p2 < 2 * N; p2++) //then, try to match p1
        if (!(bitmask & (1 << p2))) //with another bit p2 that is also off
            ans = min(ans,
                dist[p1][p2] + matching(bitmask | (1 << p1) | (1 << p2)));

    return memo[bitmask] = ans; //store results in a memo table and return
}

int main()
{
    int i, j, caseNo = 1, x[20], y[20];
    // freopen("10911.txt", "r", stdin); //redirect input file to stdin
    while (scanf("%d", &N), N) //check comma operator, eval the first operand and discard the value, eval the second and return
    {
        for (i = 0; i < 2 * N; i++)
            scanf("%s %d %d", &x[i], &y[i]); //"%s" skips names in file
        for (i = 0; i < 2 * N; i++) //build pairwise distance table
            for (j = 0; j < 2 * N; j++)
                dist[i][j] = dist[j][i] = hypot(x[i] - x[j], y[i] - y[j]); //Compute hypotenuse

        // using DP to solve min weighted perfect matching on small general graph
        for (i = 0; i < (1 << 16); i++) memo[i] = -1.0; //set -1 to all cells
        target = (1 << (2 * N)) - 1;
        printf("Case %d: %.2lf\n", caseNo++, matching(0));
    }

    return 0;
}