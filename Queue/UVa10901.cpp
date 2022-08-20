//From https://www.pinghenotes.com/UVa-10901-Ferry-Loading-III/
//All rights reserved for PingHe


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef tuple<int, int, int> tp;
typedef pair<int, int> p;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	
	while (T--)
	{
		int n, t, m;
		queue<p> Q[2];

		cin >> n >> t >> m;

		for (int i = 0; i < m; ++i)
		{
			int time;
			string side;

			cin >> time >> side;
			side == "left" ? Q[0].push({ time, i }) : Q[1].push({ time, i });
		}

		int cur = 0, time = 0;
		vector<int> ret(m);
		while (!Q[0].empty() || !Q[1].empty())
		{
			int close, cnt = 0;

			if (Q[0].empty()) close = Q[1].front().first;
			else if (Q[1].empty()) close = Q[0].front().first;
			else close = min(Q[1].front().first, Q[0].front().first);
			time = max(time, close);

			while (!Q[cur].empty() && cnt < n && Q[cur].front().first <= time)
			{
				ret[Q[cur].front().second] = time + t;
				Q[cur].pop();
				++cnt;
			}

			cur ^= 1;
			time += t;
		}

		for (auto& i : ret) cout << i << "\n";
		if (T) cout << "\n";
	}
}