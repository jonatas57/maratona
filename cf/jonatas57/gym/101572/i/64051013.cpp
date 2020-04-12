#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mk make_pair
#define cc(x) cout <<#x <<" = " <<x <<endl
#define loop(x)  for (int i = 0;i < x;i++)

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 505;

int n;
map<string,int> id;
vector<int> adj[T];
vector<string> vs(T);
int vis[T];
int pai[T];
int tmp[T];
int vez;
int ans = INF;
int ori = 0;

void addEdge(int a, int b) {
	adj[a].push_back(b);
}

void bfs(int at) {
	int fdp = at;
	vez++;
	vis[at] = vez;
	queue<int> fila;
	fila.push(at);
	tmp[at] = 0;

	while(!fila.empty()) {
		at = fila.front();
		fila.pop();
		for(auto v : adj[at]) {
			if(vis[v] != vez) {
				fila.push(v);
				vis[v] = vez;
				pai[v] = at;
				tmp[v] = tmp[at] + 1;
			} 
			else if(v == fdp) {
				pai[v] = at;
				if(tmp[at]+1 < ans) {
					ans = tmp[at]+1;
					ori = fdp;
				}
				return;
			}
		}
	}
}

void build(int at) {
	int fdp = pai[at];
	vector<string> nok;
	nok.pb(vs[at]);
	while(fdp != at) nok.pb(vs[fdp]), fdp = pai[fdp];
	for(int i = nok.size()-1; i >= 0; i--) cout << nok[i] << " ";
	cout << endl;
}

int main() {
	cin >> n;
	loop(n) {
		cin >> vs[i];
		id[vs[i]] = i;
	}
	string x, viz;
	int m;
	loop(n) {
		cin >> x >> m;
		string y;
		getchar();
		loop(m) {
			getline(cin, y);
			string s = "";
			bool skip = true;
			for (char c : y) {
				if (c == ' ') skip = false;
				else if (skip) continue;
				else if (c == ',') {
					addEdge(id[x],id[s]);
					s = "";
				}
				else s += c;
			}
			if (s.length()) addEdge(id[x],id[s]);
		}
	}

	//for(int i = 0; i < n; i++) {
	//	cout << vs[i] << ": ";
	//	for(auto v : adj[i]) cout << vs[v] << ", "; 
	//	cout << endl;
	//}

	for(int i = 0; i < n; i++) bfs(i);
	if(ans == INF) cout << "SHIP IT" << endl;
	else bfs(ori), build(ori);

	return 0;
}


