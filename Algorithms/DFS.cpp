/*
dfs on graph having root node at 0
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> G[], vector<bool> &visited, int x)
{
    cout << x << " ";
    visited[x] = true;

    for (auto edge : G[x])
    {
        if (!visited[edge])
        {
            dfs(G, visited, edge);
        }
    }
}

int main()
{
    int n; //Number of nodes in graph
    int m; //number of edges in graph
    cin >> n >> m;

    vector<int> G[n];
    vector<bool> visited(n, false);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(G, visited, 0); //dfs on root node
    return 0;
}

/*
3 3
0 1
1 2
2 0

Output : 0 1 2
*/