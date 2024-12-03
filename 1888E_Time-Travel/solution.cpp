#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define all(x) x.begin(), x.end()

auto djikstra(int src, int n, vector<vii> &graph, vector<vi> &moment)
{
    vi dist(n, INT_MAX);
    dist[src] = 0;

    priority_queue<ii, vii, greater<>> pq;
    pq.emplace(dist[src], src);

    while(pq.size())
    {
        auto [dst, node] = pq.top();
        pq.pop();

        for(auto [v, i] : graph[node])
        {
            auto it = lower_bound(all(moment[i]), dst);

            if(it == moment[i].end() or dist[v] < *it + 1)
                continue;
            
            dist[v] = *it + 1;
            pq.emplace(dist[v], v);
        }
    }

    return dist;
}

auto solve()
{
    int n, t;
    cin >> n >> t;

    vector<vii> graph(n);
    for(int i = 0; i < t; i++)
    {
        int m;
        cin >> m;

        for(int j = 0; j < m; j++)
        {
            int a, b;
            cin >> a >> b;

            --a; --b;
            graph[a].emplace_back(b, i);
            graph[b].emplace_back(a, i);
        }
    }

    int m;
    cin >> m;

    vector<vi> moment(t);
    for(int i = 0; i < m; i++)
    {
        int v;
        cin >> v;

        moment[--v].emplace_back(i);
    }

    auto ans = djikstra(0, n, graph, moment);

    return ans[n - 1] == INT_MAX ? -1 : ans[n - 1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        cout << solve() << "\n";
    }

    return 0;
}
