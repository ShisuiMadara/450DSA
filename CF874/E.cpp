#include <bits/stdc++.h>

using namespace std;

vector<int> read_vec(int n) {
	vector<int> v(n);
	for (int& i : v) {
		cin >> i;
		--i;
	}
	return v;
}

void dfs(int v, vector<vector<int>> const& g, vector<bool>& vis) {
	if (vis[v])
		return;
	vis[v] = true;
	for (int u : g[v])
		dfs(u, g, vis);
}

void solve() {
	int n;
	cin >> n;
	auto p = read_vec(n);

	set<array<int, 2>> edges;
	for (int i = 0; i < n; ++i) {
		int u = min(i, p[i]), v = max(i, p[i]);
		edges.insert(array<int, 2> {u, v});
	}

	vector<vector<int>> g(n);
	vector<int> deg(n);
	for (auto const& e : edges) {
		for (int i = 0; i < 2; ++i) {
			++deg[e[i]];
			g[e[i]].push_back(e[1 - i]);
		}
	}

	int l, c;
	l = c = 0;

	vector<bool> vis(n, false);
	for (int i = 0; i < n; ++i) {
		if (vis[i] or deg[i] != 1)
			continue;
		// deg[i] == 1 and not vis[i]
		dfs(i, g, vis);
		++l;
	}

	for (int i = 0; i < n; ++i) {
		if (vis[i])
			continue;
		// i is in a cycle
		dfs(i, g, vis);
		++c;
	}

	cout << c + (l > 0 ? 1 : 0) << ' ' << c + l << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--)
		solve();

	return 0;
}