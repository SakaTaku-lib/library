//gcd(x, y) -> xとyの最大公約数
int gcd(int x, int y){
    return y ? gcd(y, x % y) : x;
}
