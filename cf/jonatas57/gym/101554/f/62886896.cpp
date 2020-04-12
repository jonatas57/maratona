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

string mat[6];
int v[10] = {31599, 18724, 29671, 31207, 18925, 31183, 31695, 18727, 31727, 31215};

int pot(int b, int exp) {
	int ans = 1;
	while(exp-- > 0) ans *= b;
	return ans;
}

int calc() {
	int ans = 0;
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 3; j++) {
			ans += ((mat[i][j] == '*') * pot(2, i*3+j));
		}
	}
	for(int i = 0; i < 10; i++)
		if(v[i] == ans) return i;
	return -1;
}

void yes() {
	cout <<"BEER!!" <<endl;
	exit(0);
}

void no() {
	cout <<"BOOM!!" <<endl;
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);

	string in[6];
	for(int i = 0; i < 5; i++) 
		getline(cin, in[i]);
	
	int num = 0;
	for(int k = 0; k < in[0].size(); k += 4) {

		for(int i = 0; i < 5; i++) 
			for(int j = 0; j < 3; j++) 
				mat[i][j] = in[i][k+j];

		int at = calc();
		if(at == -1) no();
		num *= 10;
		num += at;
	}

	if(num%6 == 0) yes();
	else no();
	
	return 0;
}

