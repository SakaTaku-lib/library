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

//Mは素数
ll mod_inv(ll n, ll M){
    return power(n, M-2, M);
}