#include <bits/stdc++.h>

using namespace std;

#define int long long int

const int MAX = 5000000;
const int oo = 9e17;

int32_t main(){
        int n,m;
        cin >> n >> m;
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<m;i++){
                int a,b,c;
                cin >> a >> b >> c;
                adj[a].push_back(make_pair(b,c));
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<int> distc(n+1, oo);
        vector<int> dist(n+1,oo);
        distc[0] = 0;
        dist[0]=0;
        pq.push({0,{1,0}});

        while(!pq.empty()){
                auto d = pq.top().first, u = pq.top().second.first, f = pq.top().second.second;
                pq.pop();
                if(f and distc[u]<d) continue;
                if(!f and dist[u]<d) continue;
                for (auto e : adj[u]){
                        int v = e.first, c = e.second;
                        if(!f){
                                if(dist[v] > c+d){
                                        dist[v] = c+d;
                                        pq.push({dist[v],{v,0}});
                                }
                                if(distc[v] > d + c/2){   
                                        distc[v] = d+c/2;
                                        pq.push({distc[v],{v,1}});
                                }
                        }else{ 
                                if(distc[v] > d+c){
                                        distc[v] = d+c;
                                        pq.push({distc[v],{v,1}});
                                }                                
                        }
                }
        }
        cout << distc[n] << "\n";
}       


                


