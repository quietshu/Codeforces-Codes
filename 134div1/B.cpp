#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, r, ans = ~0U >> 1;
bool ch[1000010], ansch[1000010];

int gcd(int a, int b){
	return !b ? a : gcd(b, a % b);
}

void solve(int x, int y){
	int tot = n;
	while(x != y){
		if(x > y){
			ch[tot] = 0;
			x -= y;
		}
		else{
			ch[tot] = 1;
			y -= x;
		}
		--tot;
	}
	if(x != y || x != 1 || tot != 1)
		return;
	ch[1] = 0;
	tot = 0;
	for(int i = 1; i < n; ++i)
		if(ch[i] == ch[i + 1])
			++tot;
	if(tot >= ans) return;
	ans = tot;
	for(int i = 1; i <= n; ++i)
		ansch[i] = ch[i];
}

int main(){
	scanf("%d%d", &n, &r);
	for(int i = 1; i <= r; ++i)
		solve(i, r), solve(r, i);
	if(ans > n)
		puts("IMPOSSIBLE");
	else{
		printf("%d\n", ans);
		for(int i = 1; i <= n; ++i)
			printf("%c", ansch[i] ? 'B' : 'T');
		puts("");
	}
	return 0;
}