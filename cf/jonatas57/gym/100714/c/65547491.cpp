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

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >>n;
    vector<int> v;
    for(int i = 0; i < n; i++) {
	int a; cin >>a;
	v.pb(a);
    }

    for(int i = 1; i <= 100; i++) {
	vector<int> pos;
	pos.pb(0);
	for(int j = 1; j <= i; j++) 
	    pos.pb(round(j*(100.0/i)));
	bool ans = true;
	for(auto at:v) {
	    if(!binary_search(pos.begin(), pos.end(), at)) ans = false;
	}
	if(ans) {
	    cout <<i <<endl;
	    return 0;
	}
    }

}

