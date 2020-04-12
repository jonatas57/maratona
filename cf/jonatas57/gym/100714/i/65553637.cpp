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
typedef pair<int,int> ii;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

struct mane { 
    int user, cat, cre, heu;

    mane(int user, int cat, int cre, int heu) :
	    user(user), cat(cat), cre(cre), heu(heu) {}

    bool operator < (const mane &b) const {
	if(cre != b.cre) return cre < b.cre;
	return false;
    }
};

struct malandro {
    int user, cat, cre, heu, adv, show, click;

    malandro(int user, int cat, int cre, int heu, int adv, int show, int click) :
     user(user), cat(cat), cre(cre), heu(heu), adv(adv), show(show), click(click) {}

    bool operator < (const malandro &b) const {
	if(heu != b.heu) return heu < b.heu;
	if(user != b.user) return user < b.user;
	if(cat != b.cat) return cat < b.cat;
	if(cre != b.cre) return cre < b.cre;
	if(adv != b.adv) return adv < b.adv;
	if(show != b.show) return show < b.show;
	return false;
    }

    void print() {
	cout << user << " " << cat << " " << cre << " " << heu << " " << adv << " " << show << " " << click << endl;
    }
};

map<ii,vector<mane>> bag;
vector<malandro> ans;

int main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	bag[mk(a,b)].eb(a,b,c,d);
    }

    for(auto ok : bag) sort(bag[ok.fi].begin(), bag[ok.fi].end());

    while(m--) {
	int a,b,c,d,e;
	cin >> a >> b >> c >> d >> e;
	if(bag.count(mk(a,b))) {
	    mane x = mane(0,0,d,0);
	    int y = lower_bound(bag[mk(a,b)].begin(), bag[mk(a,b)].end(), x) - bag[mk(a,b)].begin();
	    if(y > 0) {
		x = bag[mk(a,b)][y-1];
		ans.pb(malandro(a,b,x.cre,x.heu,c,d,e));
	    }
	}
    }
    
    if(ans.size()) sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto x : ans) x.print();


}

