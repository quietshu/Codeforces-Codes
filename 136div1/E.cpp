#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#define MAXN 100010
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

map<int, int> rank;
int n, l, r, num[MAXN], tmp[MAXN];
long long k, tot, sum, tSum[MAXN];

int s[2][MAXN];

void add(int k, int p, int q){
	for(int i = p; i <= n; i += i & -i)
		s[k][i] += q;
}

int ask(int k, int p){
	int sum = 0;
	for(int i = p; i; i -= i & -i)
		sum += s[k][i];
	return sum;
}

int main(){
	scanf("%d", &n);
	cin >> k;
	rep(i, n)
		scanf("%d", &num[i]), tmp[i] = num[i];
	sort(tmp + 1, tmp + 1 + n);
	int rk = 0;
	for(int i = 1; i <= n; ++i)
		if(!rank[tmp[i]])
			rank[tmp[i]] = ++rk;
	for(int i = 1; i <= n; ++i)
		num[i] = rank[num[i]];
	for(int i = n; i > 1; --i){
		add(1, num[i], 1);
		sum += ask(1, num[i] - 1);
		tSum[i] = sum;
	}
	r = 2;
	sum = 0;
	for(l = 1; l <= n; ++l){
		add(0, num[l], 1);
		if(l == r){
			add(1, num[r], -1);
			sum -= ask(0, rk) - ask(0, num[r]);
			++r;
		}
		sum += ask(0, rk) - ask(0, num[l]) + ask(1, num[l] - 1);
		while(r <= n && sum + tSum[r] > k){
			add(1, num[r], -1);
			sum -= ask(0, rk) - ask(0, num[r]);
			++r;
		}
		tot += n - r + 1;
	}
	cout << tot << endl;
	return 0;
}