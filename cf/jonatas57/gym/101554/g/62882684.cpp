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

	string s, t;
	cin >>s >>t;
	
	bool change = n%2;
	for(int i = 0; i < s.size(); i++) {
		bool at = (s[i]-'0');
		bool at2 = (t[i]-'0');
		if(at^change != at2) {
			cout <<"Deletion failed" <<endl;
			return 0;
		}
	}

	cout <<"Deletion succeeded" <<endl;
	
	return 0;
}

