/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : B.cpp
*   Creation Time : 2013/07/24 23:41:00
*   Environment   : OS X 10.8 & Vim 7.3
*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#define rep(i, n) for(int i = 1; i <= n; ++i)
#define sqr(x) ((x) * (x))
#define pb push_back
#define mp make_pair
#define sign(x) (x < 0 ? -1 : (x > 0))
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

int n, k, a, b, A, B;
long long t[200010], ans, sum;

int main(){
    cin >> n >> k;
    rep(i, n){
        scanf("%lld", &t[i]);
        t[i] += t[i - 1];
    }
    ans = 0;
    b = n - k + 1;
    for(int i = n - k - k + 1; i; --i){
        a = i;
        sum = t[a + k - 1] - t[a - 1] + t[b + k - 1] - t[b - 1];
        if(sum >= ans)
            ans = sum, A = a, B = b;
        if(t[b + k - 2] - t[b - 2] >= t[b + k - 1] - t[b - 1])
            --b;
    }
    cout << A << " " << B << endl;
    return 0;
}
