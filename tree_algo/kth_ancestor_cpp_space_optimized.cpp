#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_set_reverse = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

//
//
#ifndef ONLINE_JUDGE
#include "../DEBUG.h"
#else
#define debug(x) ;
#endif
//
//

#define ll long long
// #define llll long long
#ifndef llll
#define llll int
#endif
#define ld long double
#ifndef ld
#define ld double
#endif
#define ima INT_MAX
#define imi INT_MIN
#define uima UINT_MAX
#define llma __LONG_LONG_MAX__
#define llmi LLONG_MIN
#define ull unsigned long long
#define ullma ULLONG_MAX
#define vl vector<long long>
#define vi vector<int>
#define vvl vector<vector<long long>>
#define vvi vector<vector<int>>
#define vpl vector<pair<long long, long long>>
#define vpii vector<pair<int, int>>
#define new_line '\n'
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ef emplace_front
#define sz(arr) (int)arr.size()
#define pl pair<long long, long long>
#define pii pair<int, int>
#define full(v) v.begin(), v.end()
#define rfull(v) v.rbegin(), v.rend()
#define vln(v, n) vector<long long> v(n, 0)
#define vin(v, n) vector<int> v(n, 0)
#define minof min_element
#define maxof max_element
#define lb lower_bound
#define ub upper_bound
#define co(val) cout << val << '\n'
#define cval(val) cout << val << ' '
#define for_loop(i, a, b) for (llll i = a; i < b; i++)
#define for_loop_reverse(i, a, b) for (llll i = a; i > b; i--)
#define forint(i, a, b) for (int i = a; i < b; ++i)
#define forint_r(i, a, b) for (int i = a; i > b; --i)
#define forl(i, a, b) for (long long i = a; i < b; ++i)
#define forl_r(i, a, b) for (long long i = a; i > b; --i)
// #define receive(arr, n) \
//     for_loop(asdfasdf, 0, n) { cin >> arr[asdfasdf]; }
//
//
#define receive(arr)           \
    for (auto &asdfasdf : arr) \
    {                          \
        cin >> asdfasdf;       \
    }

#define print_all(arr)           \
    for (auto asdfasdf : arr)    \
    {                            \
        cout << asdfasdf << ' '; \
    }                            \
    cout << new_line;
#define print_all_in_separate_lines(arr) \
    for (auto asdfasdf : arr)            \
    {                                    \
        co(asdfasdf);                    \
    }
#define YY "YES"
#define NN "NO"
//
//
//
//
const int MOD = (int)(1e9 + 7);
#define INF 1e18
template <typename T>
// for vector
using V = vector<T>;
// vector of bool
using vb = V<bool>;
// vector of double
using vd = V<double>;
// vector of long double
using vld = V<long double>;
// vector of string
using vstr = V<string>;
//
//
//
//
//
//
//
//
// max priority queue
template <typename T>
using maxPQ = priority_queue<T>;
// default priority queue
template <typename T>
using PQ = priority_queue<T>;
// min priority queue
template <typename T>
using minPQ = priority_queue<T, vector<T>, greater<T>>;

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

// PROTOTYPING FUNCTIONS

// to find gcd of a vector
template <typename T, typename T_return>
T_return find_gcd(T &v, T_return x);

// to find sum of a vector
template <typename T, typename T_return>
T_return find_sum(T &v, T_return x);

// unordered map of frequencies
template <typename T, typename T_key, typename T_value>
unordered_map<T_key, T_value> Counter(T &v, T_key x, T_value y);

// ordered map of frequencies
template <typename T, typename T_key, typename T_value>
map<T_key, T_value> Counter_map(T &v, T_key x, T_value y);

// to find a power b mod prime with return type long long
long long find_pow(long long a, long long b, long long prime);

// to find a power b mod prime with return type int
int find_pow(int a, int b, int prime);

// Sieve of Eratosthenes upto int n
vector<bool> Sieve(int n);

// Sieve of Eratosthenes upto long long n
vector<bool> Sieve(long long n);

// Inverse of a number x modulo prime upto int n
vector<int> inverse_modulo(int n, int prime);

// Inverse of a number x modulo prime upto long long n
vector<long long> inverse_modulo(long long n, long long prime);

// Inverse factorial modulo prime upto int n, returns pair of inverse factorials and inverse modulo
pair<vector<int>, vector<int>> inverse_factorial(int n, int prime);

// Inverse factorial modulo prime upto long long n, returns pair of inverse factorials and inverse modulo
pair<vector<long long>, vector<long long>> inverse_factorial(long long n, long long prime);

void preCalculate();

void cp();

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

template <typename T, typename T_return>
T_return find_gcd(T &v, T_return x)
{
    T_return ans = v[0];
    for (auto val : v)
    {
        if (val > 0)
        {
            ans = gcd(ans, val);
        }
    }
    return ans;
};

template <typename T, typename T_return>
T_return find_sum(T &v, T_return x)
{
    T_return ans = 0;
    for (auto val : v)
    {
        ans += val;
    }
    return ans;
};

template <typename T, typename T_key, typename T_value>
unordered_map<T_key, T_value> Counter(T &v, T_key x, T_value y)
{
    unordered_map<T_key, T_value> m;
    for (auto val : v)
    {
        m[val]++;
    }
    return m;
};

template <typename T, typename T_key, typename T_value>
map<T_key, T_value> Counter_map(T &v, T_key x, T_value y)
{
    map<T_key, T_value> m;
    for (auto val : v)
    {
        m[val]++;
    }
    return m;
};

long long find_pow(long long a, long long b, long long prime = 0)
{
    if (prime != 0)
    {
        if (b == 0)
            return 1;
        long long temp = find_pow(a, b / 2, prime);
        if (b % 2)
            return ((temp % prime) * (((temp % prime) * (a % prime)) % prime)) % prime;
        else
            return ((temp % prime) * (temp % prime)) % prime;
    }
    else
    {
        if (b == 0)
            return 1;
        long long temp = find_pow(a, b / 2);
        if (b % 2)
            return ((temp) * (((temp) * (a))));
        else
            return ((temp) * (temp));
    }
};

int find_pow(int a, int b, int prime = 0)
{
    if (prime != 0)
    {
        if (b == 0)
            return 1;
        int temp = find_pow(a, b / 2, prime);
        if (b % 2)
            return ((temp % prime) * (((temp % prime) * (a % prime)) % prime)) % prime;
        else
            return ((temp % prime) * (temp % prime)) % prime;
    }
    else
    {
        if (b == 0)
            return 1;
        int temp = find_pow(a, b / 2);
        if (b % 2)
            return ((temp) * (((temp) * (a))));
        else
            return ((temp) * (temp));
    }
};

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

pair<vector<int>, vector<int>> inverse_factorial(int n, int prime)
{
    vector<int> inv_fact(max(3, n + 1));
    vector<int> inv = inverse_modulo(n, prime);
    inv_fact[0] = inv_fact[1] = 1;
    for (int i = 2; i <= n; ++i)
        inv_fact[i] = (inv[i] * inv_fact[i - 1]) % prime;
    return mp(inv_fact, inv);
}

pair<vector<long long>, vector<long long>> inverse_factorial(long long n, long long prime)
{
    vector<long long> inv_fact(max(3ll, n + 1));
    vector<long long> inv = inverse_modulo(n, prime);
    inv_fact[0] = inv_fact[1] = 1;
    for (long long i = 2; i <= n; ++i)
        inv_fact[i] = (inv[i] * inv_fact[i - 1]) % prime;
    return mp(inv_fact, inv);
}

//
//
//
//
//

// ll C = 0;

/***************************************************************************/
/////////////////////////////////////////////////////////////////////////////
/***************************************************************************/

void preCalculate()
{
}

/***************************************************************************/
/////////////////////////////////////////////////////////////////////////////
/***************************************************************************/
bool multi_test_case = false;
bool interactive_question = false;

// directed graph
class Tree
{
    int n;
    vvi adj;
    vi parent;
    vvi anc;

public:
    Tree(int n)
    {
        this->n = n;
        adj = vvi(n + 1);
        parent = vi(n + 1);
        for (int i = 0; i < n - 1; ++i)
        {
            int x, y;
            cin >> x >> y;
            parent[y] = x;
            addEdge(x, y);
        }
        anc = vvi(n + 1, vi(LOG2(n) + 1));
        precalculate();
    }
    void addEdge(int x, int y, bool undirected = false)
    {
        adj[x].eb(y);
        if (undirected)
            adj[y].eb(x);
    }
    void precalculate()
    {
        forint(i, 1, n + 1)
        {
            anc[i][0] = parent[i];
        }
        for (int lg = 1; lg < LOG2(n) + 1; ++lg)
        {
            forint(v, 1, n + 1)
            {
                // anc[v][i] = anc[anc[v][i / 2]][i / 2];
                anc[v][lg] = anc[anc[v][lg - 1]][lg - 1];
            }
        }
        for (auto &row : anc)
        {
            debug(row);
        }
        // space complexity of anc -> O(n * LOG(n))
    }

    int LOG2(int num)
    {
        int ans = 0;
        while ((1 << ans) <= num)
            ++ans;
        return ans ? ans - 1 : 1e9;
    }

    int findAncestor(int x, int k)
    {
        // kth ancestor of x;
        // for (int bit = 0; bit < 31; ++bit)
        // {
        //     if (k >> bit & 1)
        //     {
        //         x = anc[x][bit];
        //     }
        // }
        // return x;
        if (k > LOG2(n))
            return 0;
        while (k >= 1)
        {
            int lg = LOG2(k);
            x = anc[x][lg];
            k -= 1 << lg;
        }
        return x;
    }
};

void cp()
{
    int n;
    cin >> n;
    Tree *g = new Tree(n);
    int x, k;
    cin >> x >> k;
    co(g->findAncestor(x, k));
}

/***************************************************************************/
/////////////////////////////////////////////////////////////////////////////
/***************************************************************************/

int main()
{
#ifndef ONLINE_JUDGE
    // freopen("./input_file_check.txt", "r", stdin);
    // freopen("./output_file_check.txt", "w", stdout);
    freopen("../error_file_check.txt", "w", stderr);
#endif
    if (!interactive_question)
    {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
    }

    bool single_test_case = !multi_test_case;
    //
    //
    //
    //
    //
    bool pre_calculate = true;

    //
    //
    //
    //
    bool check_time = true;
#ifndef ONLINE_JUDGE
    check_time = true;
#else
    check_time = false;
#endif
    if (check_time)
    {
        auto start_time_of_program = chrono::high_resolution_clock::now();
        int t;
        if (pre_calculate)
            preCalculate();
        if (single_test_case)
            t = 1;
        else
            cin >> t;
        // cin >> t;
        // t = 1;
        while (t--)
        {
            cp();
        }

        auto end_time_of_program = chrono::high_resolution_clock::now();

        double time_taken_for_program = chrono::duration_cast<chrono::nanoseconds>(end_time_of_program - start_time_of_program).count();
        time_taken_for_program *= 1e-9;
        cerr << "\nTIME TAKEN FOR THE PROGRAM\n";
        cerr << fixed << time_taken_for_program << setprecision(9) << endl;
    }

    //
    //
    //
    //
    else
    {
        int t;
        if (pre_calculate)
            preCalculate();
        if (single_test_case)
            t = 1;
        else
            cin >> t;
        // cin >> t;
        // t = 1;
        while (t--)
        {
            cp();
        }
    }

    return 0;
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////