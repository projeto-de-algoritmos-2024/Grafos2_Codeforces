#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef tuple<ll, ll, ll> tp;

const int MAX_SLOWNESS_FACTOR = 1000;
const ll INF = LLONG_MAX;

auto djikstra_2d(int src, int n, vl &vs, vector<vector<pll>> &graph)
{
    vector<vl> dist(n + 1, vl(MAX_SLOWNESS_FACTOR + 1, INF));
    priority_queue<tp, vector<tp>, greater<>> pq;

    dist[src][vs[src]] = 0; 
    pq.emplace(0, src, vs[src]);

    while(pq.size())
    {
        auto [dst, node, slowness] = pq.top();
        pq.pop(); 

        for(auto [v, w] : graph[node])
        {
            ll new_dist = dst + (w * slowness);
            ll new_slns = min(slowness, vs[v]);

            if(new_dist >= dist[v][new_slns])
                continue;

            dist[v][new_slns] = new_dist;
            pq.emplace(new_dist, v, new_slns);
        }
    }

    return dist;
}

auto solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pll>> graph(n + 1);
    for(int i = 0; i < m; i++)
    {
        ll a, b, w;
        cin >> a >> b >> w;

        graph[a].emplace_back(b, w);
        graph[b].emplace_back(a, w);
    }

    vl vs(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> vs[i];

    auto dist = djikstra_2d(1, n, vs, graph);

    ll ans = INF;
    for(ll i = 1; i <= MAX_SLOWNESS_FACTOR; i++)
        ans = min(ans, dist[n][i]);

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    cin >> t;

    while (t--)
    {
        cout << solve() << "\n";
    }

    return 0;
}
