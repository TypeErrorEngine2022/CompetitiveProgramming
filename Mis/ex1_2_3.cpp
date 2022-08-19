#include "convention.h"
#include <cmath>
#include <cstdio>
#include <regex>
#include <cstring>

using namespace std;

void q2()
{
    int N;
    scanf("%d", &N);
    printf("%.*lf", N , PI);
}

/*void q3()
{
    map<string, int> months
        {
            "January": 1, "February": 2, "March": 3, "April": 4, "May": 5, "June": 6,
            "July": 7, "August": 8, "September": 9, "October": 10, "November": 11, "December": 12
        }
    
    vector<int> monthDay {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int date, year, numday;
    string month;
    scanf("%2d %s %4d", &date, &month, &year);

    if (year % 4 == 0 && year % 100 != 0)
        numday = 366;
    else if ( (year % 4 == 0 && year % 100 == 0) && year % 400 == 0)
        numday = 366;
    else  
        numday = 365;

    if numday == 366 
    {
        monthDay[2] = 29;
    }

    int prevDay = 0;
    for (int i = 1; i < months[month]; i++)
    {
        prevDay += vector[i];
    }

    //incorrect
}*/

void q4()
{
    vi a{1, 2, -1, 34, 34, 66, 10};
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    int c = 1;
    for (auto& n: a)
    {
        if (c > 1) printf(" ");
        c++;
        printf("%d", n);
    }
}

int binarySearch(vi& a, int l, int r, int num)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (a[mid] == num) return mid;

        if (num < mid)
            return binarySearch(a, l, mid - 1, num);
        else
            return binarySearch(a, mid + 1, r, num);
    }

    return -1;
}

bool q6()
{
    freopen("sortedInt.txt", "r", stdin);

    vi a;
    int b;
    while (scanf("%d", &b))
        a.push_back(b);
    
    int N;
    scanf("%d", &N);
    
    return binarySearch(a, 0, a.size() - 1, N) != -1;
}

void q10()
{
    string s{"line: a70 and z72 will be replaced, aa24 and a872 will not"};
    regex e("(^| )+[a-z][0-9][0-9](^| )+");
    cout << regex_replace(s, e, " *** ");
}

void q11()
{
    string s{"3 + (8 - 7.5) * 10 / 5 - (2 * 5 - 7)"};
    stack<int> num;
    stack<char> op;
    for (auto& c: s)
    {
        if (isalnum(c))
            num.push(c - '0');
        if (isblank(c)) continue;
        if (c == "+" || c == "-" || c == "*" || c == "\\" || c == "(")
            op.push(c);
        if (c == ")")
        {
            int n1 = num.top(); num.pop();
            int n2 = num.top(); num.pop();
            
        }
        
    }
}

int main()
{
    q10();

    return 0;
}