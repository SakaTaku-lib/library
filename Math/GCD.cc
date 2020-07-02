//gcd(x, y) -> xとyの最大公約数
ll gcd(ll x, ll y){
    return y ? gcd(y, x % y) : x;
}
