#include <bits/stdc++.h>

using namespace std;

#define int long long int

const int MAX = 5000000;
const int oo = 9e15;

int32_t main(){
        int n,m,k;
        cin >> n >> m >> k;
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<m;i++){
                int a,b,c;
                cin >> a >> b >> c;
                adj[a].push_back(make_pair(b,c));       
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push(make_pair(0,1));
        vector<vector<int>> dist(n+1);
        for(int i=1;i<=n;i++){
                dist[i].resize(k);
                for(int j=0;j<k;++j) dist[i][j] = oo;
        }
        dist[1][0]=0; 

        while(!pq.empty()){
                auto [d,u] = pq.top();
                pq.pop();

                if(dist[u][k-1] < d) continue;
                
                for(auto e : adj[u]){
                        auto [v,c] = e;
                        if(dist[v][k-1] > c+d){
                                dist[v][k-1] = c+d;
                                pq.push(make_pair(dist[v][k-1],v));
                                sort(dist[v].begin(),dist[v].end());
                        }
                }
        }
        for(int i=0;i<k;i++){
                cout << dist[n][i] << " ";
        }


}
