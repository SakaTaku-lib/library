const int SIZE = 1e6+1;
bool isprime[SIZE];
vector<ll> primes;
map<ll, int> factors;
vector<ll> divisor;
void make_primes(){
   for (int i = 0; i < SIZE; ++i) isprime[i] = true;
   isprime[0] = isprime[1] = false;
   for (int i = 2; i*i <= SIZE; ++i){
      if (isprime[i]){
         int j = i+i;
         while (j < SIZE){
            isprime[j] = false;
             j += i;
         }
      }
   }
   for (int i = 0; i < SIZE; i++)
      if (isprime[i]) primes.push_back(i);
}

void prime_factorize(ll x){
   for (ll i : primes){
      while (x % i == 0){
         ++factors[i];
         x /= i;
      }
   }
   if (x != 1) ++factors[x];
}
void make_divisor(ll x){
   divisor.emplace_back(1);
   for (auto &&i : factors){
      int size = divisor.size();
      for (int j = 0; j < i.second; j++)
         for (int k = 0; k < size; k++)
            divisor.emplace_back(divisor[j*size+k]*i.first);
   }
}
