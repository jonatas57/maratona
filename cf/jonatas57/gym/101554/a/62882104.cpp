#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define eb emplace_back
#define cc(x) cout <<#x <<" = " <<x <<endl;
#define loop(i, r) for(int i = 0; i < r; i++)
#define each(x, xs) for(auto &x:xs)

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	cin >>n;
	
	vector<int> v;
	for(int i = 0; i < n; i++) {
		int a; cin >>a;
		v.pb(a);
	}

	sort(v.begin(), v.end(), greater<int>());
	
	int maior = -1;
	for(int i = 0; i < n; i++) {
		maior = max(maior, v[i]+i+2);
	}
	cout <<maior <<endl;
	
	return 0;
}

