#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 1e6 + 5;
bool vis[T];
ll score[T];
int b,l,d;

const int nBuckets = 20;
const int alfa = 0.7;

struct lib {
    int n,t,m,id;
    vector<int> ids;
    vector<int> buckets;

    lib(int n, int t, int m, int id) :
        n(n), t(t), m(m), id(id), buckets(nBuckets) {}

    bool operator < (const lib &b) const {
        if(t != b.t) return t < b.t;
        return id < b.id;
    }
};

vector<lib> libs;
vector<lib> ans;
vector<vector<lib>> candidates;

void read() {
    cin >> b >> l >> d;
    for(int i = 0; i < b; i++) cin >> score[i];

    for(int i = 0; i < l; i++) {
        int n,t,m;
        cin >> n >> t >> m;
        lib tmp = lib(n,t,m,i);
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            tmp.ids.pb(x);
            
            int step = max(1, b / nBuckets); 
            tmp.buckets[(x + step - 1) / step]++;
        }
        
        for (int j = 0; j < tmp.buckets.size(); j++) {
            if (tmp.buckets[j] / n > alfa) {
                candidates[j].push_back(tmp);
            }
        }
        
        libs.pb(tmp);
    } 

    sort(libs.begin(), libs.end());
}

void solve() {
    int used = 0;

    for(int i = 0; i < l; i++) {
        bool f = 0; 
        for (int j = 0; j < libs[i].buckets[j]; j++)
            if (libs[i].buckets[j]/libs[i].n > alfa)
                f = 1;
            if(!f)
                continue; 

        if(used + libs[i].t > d) break;
        lib tmp(0,0,0,libs[i].id);
        used += libs[i].t;
        int lim = (d-used) * libs[i].m;

        for(auto livro : libs[i].ids) {
            if(tmp.n > lim) break;
            if(vis[livro]) continue;
            vis[livro] = 1;
            tmp.n++;
            tmp.ids.pb(livro);
        }

        if(tmp.n) ans.pb(tmp);
    }
} 
/*
void solve2() {
    int restantes = dia;
    for (int j = candidates.size() - 1; j >= 0; j--) {
        int max = 0;
        int sum = 0;

        for (int i = 0; i < candidates[j].size(); i++) {
            lib tmp = candidates[j][i];
            if (sum < tmp.buckets[j] * min(d, restantes - tmp.t)/tmp.m) {
                sum = tmp.buckets[j] * min(d, restantes - tmp.t)/tmp.m
                max = i;
            }
        }

        candidates.[j]
    }
}
*/
void output() {
    cout << ans.size() << endl;
    for(auto livr : ans) {
        cout << livr.id << " " << livr.n << endl;
        for(auto livro : livr.ids) cout << livro << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    read();
    solve();
    output();
    return 0;
}

