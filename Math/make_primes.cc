#include<bits/stdc++.h>
using namespace std;

const int SIZE = 1e6;
bool isprime[SIZE];
vector<int> primes;

void make_primes(){
    for (int i = 0; i < SIZE; ++i)
        isprime[i] = true;
    isprime[0] = isprime[1] = false;
    for (int i = 2; i*i <= SIZE; ++i)
    {
        if (isprime[i]){
            int j = i+i;
            while (j < SIZE)
            {
                isprime[j] = false;
                j += i;
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
        if (isprime[i])
            primes.push_back(i);
}
