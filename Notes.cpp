/*
Input type: 
TC
(blank line)
input1
(blank line)
input2
...
input n 
*/

/*
Output type:
output1
(blank line)
output2
(blank line)
...
outputn
*/

int main()
{
    cin >> TC; // cin or scanf will leave '\n' unconsumed
    getchar();//first '\n after TC
    getchar(); //second '\n' in blank line
    int ct = 1;
    while (TC--) //each TC start from the judging queue
    {
        if (ct > 1)
        {
            cout << '\n'; //preceeding blank line starts from output of TC2
            fill(ppls.begin(), ppls.end(), ppl{1000, 0, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, false}); //process preparation
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
            
            istringstream iss(line); //put the line into inputstringstream
            if (iss >> id >> q >> t >> state)
            {
                //processing input
            }
        }

        //processing 

        for (int i = 0; i <= 100; i++)
        {
            if (!ppls[i].joined) break;

            cout << ppls[i].id << ' ' << ppls[i].ct << ' ' << ppls[i].pen << '\n';
        }
    }
}

//-----------------------------------------------


/*Input type:
BLOCK1           
0
BLOCK2
0
BLOCK3
0
...
BLOCK n
0
0

Output type:
Output1.1
Output1.2
(blank line)
Output2.1
...
OutputN.M*/

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int T, tmp;
    while (cin >> T && T) // check whether T is 0
    {
        while (cin >> tmp && tmp)
        {
            stack<int> s;
            queue<int> q;
            q.push(tmp);
            for (int i = 1; i < T; ++i) cin >> tmp, q.push(tmp);
            for (int i = 1; i <= T; ++i)
            {
                //processing
            }
            cout << (s.empty() ? "Yes\n" : "No\n");
        }
        cout << '\n';
    }
}