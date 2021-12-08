#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
#include<map>

using namespace std;

class Edge {
public:
	int distance;
	int node[2];

	Edge(int a, int b, int distance)
	{
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	bool operator <(Edge& edge)
	{
		return this->distance < edge.distance;
	}
};

bool cmp(Edge &edge_1,Edge &edge_2 )
{
	return edge_1.distance < edge_2.distance;

}

int getParent(int Parent[],int x)
{
	if (Parent[x] == x) return x;
	else return getParent(Parent, Parent[x]);
}
bool findParent(int Parent[], int a, int b)
{
	a = getParent(Parent, a);
	b = getParent(Parent, b);
	if (a == b)return true;
	else return false;
}
void unionParent(int Parent[], int a, int b)
{
	a = getParent(Parent, a);
	b = getParent(Parent, b);
	if (a < b) Parent[b] = a;
	else Parent[a] = b;
	
}


int main() {
	int testCase;
	cin >> testCase;
	for (int t = 0; t < testCase; t++)
	{	
		int n, k, m;
		cin >> n;
		vector<Edge> e;
		for (int i = 1; i <=n; i++)
		{
			cin >> k >> m;
			for (int j = 1; j <= m; j++)
			{
				int temp1, temp2;
				cin >> temp1>> temp2;
				e.push_back(Edge(k, temp1, temp2));
			}	
		}
		sort(e.begin(), e.end(), cmp);

		int Parent[1001];
		for (int i = 1; i <= n; i++) Parent[i] = i;

		int sum=0;
		for (int i = 0; i < e.size(); i++)
		{
			if (findParent(Parent, e[i].node[0], e[i].node[1])) continue;
			else
			{
				sum += e[i].distance;
				unionParent(Parent, e[i].node[0], e[i].node[1]);
			}
		}
		cout << sum << endl;

	}
	return 0;
}