ll gcd(ll x, ll y){
    return y ? gcd(y, x % y) : x;
}
pair<ll,ll> fl2fr(string fl){
   string bunbo, bunshi;
   for (int i=0; i<fl.size(); i++){
      if (fl[i] == '.'){
         bunbo.push_back('1');
         continue;
      }
      bunshi.push_back(fl[i]);
      bunbo.push_back('0');
   }
   ll bunbo_ll = stoi(bunbo);
   ll bunshi_ll = stoi(bunshi);
   ll GCD = gcd(bunbo_ll, bunshi_ll);
   bunbo_ll /= GCD;
   bunshi_ll /= GCD;
   return {bunshi_ll, bunbo_ll};
}
