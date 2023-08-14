#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<pair<pair<int, int>, int>> graph;
long long arr[501];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph.push_back({ {a, b}, c });
	}

	fill_n(arr, 501, INT32_MAX);
	arr[1] = 0;
	bool answer = false;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int snode = graph[j].first.first;
			int enode = graph[j].first.second;
			int w = graph[j].second;

			if (arr[snode] == INT32_MAX) continue;
			if (arr[enode] > arr[snode] + w)
			{
				arr[enode] = arr[snode] + w;
				if (n == i) answer = true;
			}
		}
	}
	if (answer == true)
	{
		cout << "-1\n";
		return 0;
	}

	for (int i = 2; i <= n; i++)
	{
		if (arr[i] == INT32_MAX) cout << "-1\n";
		else cout << arr[i] << "\n";
	}
	return 0;
}