#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define loop(x) for (int i = 0;i < x;i++)
#define each(x, xs) for (auto& x : xs)
#define iter(a) a.begin(), a.end()

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef tuple<ll,ll,ll> ti;
typedef vector<ti> vti;
const double PI = acos(-1.0);

const int T = 1e5 + 5;
const ll INF = LLONG_MAX;

vector<int> g[T];
bool vis[T];
bool zorc[T];
int ori[T];
ll dist[T];
vti aresta;
priority_queue<ii, vii, greater<ii> >pq;
int n,k,l;
ll ans;

void dij() {
    while(!pq.empty()) {
	ii at = pq.top();
	pq.pop();

	if(vis[at.se]) continue;
	vis[at.se] = 1;

	int u = get<0>(aresta[at.se]);
	int v = get<1>(aresta[at.se]);
	ll d = get<2>(aresta[at.se]);


	if(!ori[u]) ori[u] = ori[v], dist[u] = dist[v] + d;
	else if(!ori[v]) ori[v] = ori[u], dist[v] = dist[u] + d;
	else if(ori[u] != ori[v]) ans = min(ans, (dist[u] + dist[v] + d));
	else if(ori[u] == ori[v]) continue;
	
	if(!zorc[u]) {
	    for(auto z : g[u]) 
		if(!vis[z]) pq.emplace(get<2>(aresta[z]) + dist[u],z);
	    zorc[u] = 1;
	}

	if(!zorc[v]) {
	    for(auto z : g[v]) 
		if(!vis[z]) pq.emplace(get<2>(aresta[z]) + dist[v],z);
	    zorc[v] = 1;
	}
    }
}

int main() {
    int x;
    ans = INF;
    scanf("%d %d %d", &n, &k, &l);

    for(int i = 0; i < n; i++) {
	scanf("%d", &x);
	if(ori[x] == x) {
	    cout << 0 << endl;
	    return 0;
	}
	ori[x] = x;
	zorc[x] = 1;
    }
    for(int i = 0; i < l; i++) {
	int a,b,c;
	scanf("%d %d %d", &a, &b, &c);
	if(ori[a] == a or ori[b] == b) pq.emplace(c,aresta.size());
	g[a].pb(aresta.size());
	g[b].pb(aresta.size());
	aresta.eb(a,b,c);
    }

    dij();
    printf("%lld\n", ans*3ll);
}
