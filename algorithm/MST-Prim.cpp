#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
#include<map>

using namespace std;

const int MAX = 1000000000;

struct prim {
	int  a, node, weight;
};
struct cmp {
	bool operator()(prim n1, prim n2)
	{
		if (n1.weight > n2.weight)
			return true;
		else
			return false;
	}
};

int main() {
	int testCase;
	cin >> testCase;
	for (int t = 0; t < testCase; t++)
	{
		int sum = 0;
		int n, k, m;
		cin >> n;
		vector<bool> visited(n + 1);
		vector<vector<prim> > vr(n + 1);

		priority_queue<prim,vector<prim>,cmp> mini;
		for (int j = 1; j <= n; j++)
		{
			cin >> k >> m;
			for (int s = 1; s <= m; s++)
			{
				prim temp;
				temp.a = k;
				cin >> temp.node >> temp.weight;
				vr[k].push_back(temp);
			}
		}
		
		visited[1] = true;
		for (int i = 0; i < vr[1].size(); i++)
		{
			mini.push(vr[1][i]);
		}
		for (int i = 0; i < n-1; i++)
		{
			while (visited[mini.top().node])
			{
				mini.pop();
			}
			int current = mini.top().node;
			sum += mini.top().weight;
			mini.pop();
			visited[current] = true;
			for (int j = 0; j < vr[current].size(); j++)
			{
				if (!visited[vr[current][j].node])
				{
					mini.push(vr[current][j]);
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}