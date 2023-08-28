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
// #ifndef ONLINE_JUDGE
// #include "DEBUG.h"
// #endif
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
// #ifndef ll
// #define ll int
// #define llma INT_MAX
// #define llmi INT_MIN
// #define ull unsigned int
// #define ullma UINT_MAX
// #else
#define llma __LONG_LONG_MAX__
#define llmi LLONG_MIN
#define ull unsigned long long
#define ullma ULLONG_MAX
// #endif
#define vl vector<long long>
#define vi vector<int>
#define vvl vector<vl>
#define vvi vector<vi>
#define vpl vector<pair<long, long>>
#define vpi vector<pair<int, int>>
#define new_line '\n'
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ef emplace_front
#define pl pair<long long, long long>
#define pii pair<int, int>
#define full(v) v.begin(), v.end()
#define rfull(v) v.rbegin(), v.rend()
#define vln(v, n) vector<long long> v(n, 0)
#define vin(v, n) vector<int> v(n, 0)
#define minof min_element
#define maxof max_element
// #define maxPQ priority_queue<ll>
// #define minPQ priority_queue<ll, vector<ll>, greater<int>>
#define lb lower_bound
#define ub upper_bound
#define co(val) cout << val << '\n'
#define cval(val) cout << val << ' '
#define for_loop(i, a, b) for (llll i = a; i < b; i++)
#define for_loop_reverse(i, a, b) for (llll i = a; i > b; i--)
#define forint(i, a, b) for (int i = a; i < b; i++)
#define forint_r(i, a, b) for (int i = a; i > b; i--)
#define forl(i, a, b) for (long long i = a; i < b; i++)
#define forl_r(i, a, b) for (long long i = a; i > b; i--)
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
#ifdef ONLINE_JUDGE
#define debug(x) ;
#endif
//

template <typename T>
using maxPQ = priority_queue<T>;
template <typename T>
using PQ = priority_queue<T>;
template <typename T>
using minPQ = priority_queue<T, vector<T>, greater<T>>;

// template <typename T>
// int find_gcd_int(T &v)
// {
//     int ans = v[0];
//     for (auto val : v)
//     {
//         if (val > 0)
//         {
//             ans = gcd(ans, val);
//         }
//     }
//     return ans;
// };
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

// template <typename T>
// int find_sum_int(T &v)
// {
//     int ans = 0;
//     for (auto val : v)
//     {
//         ans += val;
//     }
//     return ans;
// };
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

// template <typename T>
// unordered_map<int, int> Counter(T &v, int x)
// {
//     unordered_map<int, int> m;
//     for (auto val : v)
//     {
//         m[val]++;
//     }
//     return m;
// };
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
// template <typename T>
// map<long long, long long> Counter_map(T &v, long long x)
// {
//     map<long long, long long> m;
//     for (auto val : v)
//     {
//         m[val]++;
//     }
//     return m;
// };

long long find_pow(long long a, long long b, long long prime)
{
    if (b == 0)
        return 1;
    long long temp = find_pow(a, b / 2, prime);
    if (b % 2)
        return ((temp % prime) * (((temp % prime) * (a % prime)) % prime)) % prime;
    else
        return ((temp % prime) * (temp % prime)) % prime;
}
int find_pow(int a, int b, int prime)
{
    if (b == 0)
        return 1;
    int temp = find_pow(a, b / 2, prime);
    if (b % 2)
        return ((temp % prime) * (((temp % prime) * (a % prime)) % prime)) % prime;
    else
        return ((temp % prime) * (temp % prime)) % prime;
}
// #define MOD 1e9 + 7
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

void preCalculate();
void cp();
//
//
//
//
//

// ll C = 0;

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
void preCalculate()
{
}
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

// array of 2n elements where n is the size of the array
// both implementation for n being a power of 2 and n not being a power of 2
// segment tree for sum queries
class Segment_Tree
{
    vector<int> seg_tree;
    vector<int> v;
    int n;

public:
    Segment_Tree(vector<int> &arr)
    {
        v = arr;
        n = arr.size();
        seg_tree = vector<int>(2 * n + 1);
        for (int i = 1; i < n + 1; ++i)
        {
            add(i, arr[i - 1]);
        }
    }
    int parent(int i) { return i / 2; };

    int left(int i) { return 2 * i; }
    int right(int i) { return 2 * i + 1; };

    int sum_query(int a, int b)
    {
        a += n, b += n;
        int res = 0;
        while (a <= b)
        {
            // if(a % 2 == 1) if n is assumed to be a power of 2
            if (a < 2 * n + 1 && a % 2 == 1)
                res += seg_tree[a++];
            if (b < 2 * n + 1 && b % 2 == 0)
                res += seg_tree[b--];
            a /= 2, b /= 2;
        }
        return res;
    }
    // the following function increases the array value at position k by x
    void add(int k, int x)
    {
        k += n;
        seg_tree[k] += x;
        for (k /= 2; k >= 1; k /= 2)
        {
            // seg_tree[k] = seg_tree[2 * k] + seg_tree[2 * k + 1];
            int res = 0;
            if (2 * k < 2 * n)
                res += seg_tree[2 * k];
            if (2 * k + 1 < 2 * n)
                res += seg_tree[2 * k + 1];
            seg_tree[k] = res;
        }
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
bool multi_test_case = false;

void cp()
{
    int n;
    cin >> n;
    // power of 2
    vector<int> arr(n);
    receive(arr);
    Segment_Tree *g = new Segment_Tree(arr);

    int q;
    cin >> q;
    while (q--)
    {
        int op;
        co("1 for sum query and 2 for update");
        cin >> op;
        if (op == 1)
        {
            int a, b;
            cin >> a >> b;
            int res = g->sum_query(a, b);
            co(res);
        }
        else
        {
            int pos, x;
            cin >> pos >> x;
            g->add(pos, x);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("./input_file_check.txt", "r", stdin);
    //     freopen("./output_file_check.txt", "w", stdout);
    freopen("../error_file_check.txt", "w", stderr);
    // #endif
    bool interactive_question = true;
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
