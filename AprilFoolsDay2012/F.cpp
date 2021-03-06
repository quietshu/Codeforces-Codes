#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int p[1000000];

bool check(int n){
	int _n = n;
	if(p[n] == 1) return 1;
	if(p[n] == 2) return 0;
	for(int i = 2; i * i <= n; ++i)
		if(n % i == 0) return 0;
	int m = 0;
	while(n){
		m = m * 10 + n % 10;
		n /= 10;
	}
	if(_n == m) return 0;
	for(int i = 2; i * i <= m; ++i)
		if(m % i == 0) return 0;
	return 1;
}

int main(){
	int n, p = 2, tot = 0;
	cin >> n;
	while(tot < n){
		if(check(p))
			tot++;
		p++;
	}
	cout << p - 1;
}