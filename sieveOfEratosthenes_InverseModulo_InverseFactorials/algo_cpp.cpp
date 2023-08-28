#include <bits/stdc++.h>
using namespace std;

vector<bool> Sieve(int n)
{
    vector<bool> Prime(max((int)3, n + 1), 1);
    Prime[0] = Prime[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (Prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                Prime[j] = false;
            }
        }
    }
    return Prime;
};
vector<bool> Sieve(long long n)
{
    vector<bool> Prime(max((long long)3, n + 1), 1);
    Prime[0] = Prime[1] = false;

    for (long long i = 2; i * i <= n; i++)
    {
        if (Prime[i])
        {
            for (long long j = i * i; j <= n; j += i)
            {
                Prime[j] = false;
            }
        }
    }
    return Prime;
};
vector<int> inverse_modulo(int n, int prime)
{
    vector<int> inv(max(3, n + 1));
    inv[0] = 1;
    inv[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        inv[i] = (1ll * ((prime - prime / i) % prime) * (inv[prime % i] % prime)) % prime;
    }
    return inv;
};
vector<long long> inverse_modulo(long long n, long long prime)
{
    vector<long long> inv(max(3ll, n + 1));
    inv[0] = 1;
    inv[1] = 1;
    for (long long i = 2; i <= n; ++i)
    {
        inv[i] = (1ll * ((prime - prime / i) % prime) * (inv[prime % i] % prime)) % prime;
    }
    return inv;
};
vector<int> inverse_factorial(int n, int prime)
{
    vector<int> inv_fact(max(3, n + 1));
    vector<int> inv = inverse_modulo(n, prime);
    inv_fact[0] = inv_fact[1] = 1;
    for (int i = 2; i <= n; ++i)
        inv_fact[i] = (inv[i] * inv_fact[i - 1]) % prime;
    return inv_fact;
}
vector<long long> inverse_factorial(long long n, long long prime)
{
    vector<long long> inv_fact(max(3ll, n + 1));
    vector<long long> inv = inverse_modulo(n, prime);
    inv_fact[0] = inv_fact[1] = 1;
    for (long long i = 2; i <= n; ++i)
        inv_fact[i] = (inv[i] * inv_fact[i - 1]) % prime;
    return inv_fact;
}

int main()
{
    return 0;
}