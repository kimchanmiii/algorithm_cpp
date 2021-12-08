#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
#include<map>

using namespace std;

const int MAX = 1000000000;

int least(int n,vector<vector<int> > &v,vector<int> &dis,vector<bool> &b)
{
	int min = MAX+1;
	int idx = 1;
	for (int i = 1; i <= n; i++)
	{
		if (dis[i] < min && !b[i])
		{
			min = dis[i];
			idx = i;
		}
	}
	return idx;
}

int main() {
	int testCase;
	cin >> testCase;
	for (int t = 0; t < testCase; t++)
	{
		int n, k, m;
		cin >> n;
		vector<int> dis(n + 1);
		vector<bool> b(n + 1);
		vector<vector<int> > v(n + 1, vector<int>(n + 1));
		vector<int> used(n + 1);
		int sum = 0;
		for (int j = 1; j <= n; j++)
		{
			for (int s = 1; s <= n; s++)
			{
				if (j == s)
					v[j][s] = 0;
				else
					v[j][s] = MAX;
			}
		}

		for (int j = 1; j <= n; j++)
		{
			cin >> k >> m;
			for (int s = 1; s <= m; s++)
			{
				int temp, weight;
				cin >> temp >> weight;
				v[k][temp] = weight;
			}
		}
		
		for (int j = 1; j <= n; j++)
		{
			dis[j] = v[1][j];
			if (dis[j] < 1000000000)
				used[j] = dis[j];
		}

		b[1] = true;
		for (int j = 0; j < n - 2; j++)
		{
			int current = least(n, v, dis, b);
			b[current] = true;
			for (int p = 1; p <= n; p++)
			{
				if (!b[p])
				{
					if (dis[p] > dis[current] + v[current][p])
					{
						dis[p] = dis[current] + v[current][p];
						used[p] = v[current][p];	
					}
				}
			}
		}

		int p = 0;
		for (int j = 1; j <= n; j++)
		{
			p += used[j];
		}
		cout << p << endl;
	}
	return 0;
}