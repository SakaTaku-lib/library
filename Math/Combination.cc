#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll power(ll x, ll n, ll M){
    ll res = 1;
    if(n > 0){
        res = power(x, n / 2, M);
        if(n%2 == 0)res = (res * res) % M;
        else res = (((res * res) % M) * x) % M;
    }
    return res;
}
ll mod_inv(ll n, ll M){
    return power(n, M-2, M);
}

struct Combination
{
    ll n, mod;
    vector<ll> factorial;
    Combination(ll n, ll mod):n(n),mod(mod){
        init();
    }
    void init(){
        factorial.push_back(1);
        for (int i=1; i<=n; i++){
            factorial.push_back(factorial[i-1] * i);
            factorial[i] %= mod;
        }
    }
    ll aCb(ll a, ll b){
        if (a < b)return 0;
        ll y = factorial[a] * mod_inv(factorial[b], mod);
        y %= mod;
        y *= mod_inv(factorial[a-b], mod);
        y %= mod;
        return y;
    }
};