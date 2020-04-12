    #include <bits/stdc++.h>
     
    using namespace std;
     
    typedef long long          ll;
    typedef unsigned long long ull;
    typedef vector<int>	       vi;
    typedef vector<bool>       vb;
    typedef map<int, int>      mii;
    typedef pair<int, int>     ii;
     
    #define INF                0x3f3f3f3f
    #define MAX                100000
    #define N                  4 * MAX + 10
    #define MOD                1000000007
    #define each(x, s)         for(auto& x : s)
    #define ceach(x, s)        for(auto const& x : s)
    #define rep(x, y, z)       for(int i = x;i < y;i+=z)
    #define loop(x)	           for(int i = 0;i < x;i++)
    #define vloop(v, x)        for(int v = 0;v < x;v++)
    #define avg(l, r)          l + (r - l) / 2
     
    int main() {
    	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
     
    	ll n, m, q;
    	cin >> n >> m >> q;
    	ll mdc = __gcd(n, m);
    	ll n2 = n / mdc, m2 = m / mdc;
    	ll s1, s2, e1, e2;
    	loop(q) {
    		cin >> s1 >> s2 >> e1 >> e2;
    		ll s, e;
    		s = (s2 - 1) / (s1 == 1 ? n2 : m2);
    		e = (e2 - 1) / (e1 == 1 ? n2 : m2);
    		cout << (e == s ? "YES" : "NO") << endl;
    	}
    	return 0;
    }