#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
//
//
#ifndef ONLINE_JUDGE
#include "../DEBUG.h"
#endif
//
//

using namespace std;

#define ll long long
#define llll long long
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
#ifndef ll
#define ll int
#define llma INT_MAX
#define llmi INT_MIN
#define ull unsigned int
#define ullma UINT_MAX
#else
#define llma __LONG_LONG_MAX__
#define llmi LLONG_MIN
#define ull unsigned long long
#define ullma ULLONG_MAX
#endif
#define vl vector<ll>
#define vi vector<int>
#define vvl vector<vl>
#define vvi vector<vi>
#define vpl vector<pair<ll, ll>>
#define vpi vector<pair<int, int>>
#define new_line '\n'
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ef emplace_front
#define pl pair<ll, ll>
#define pii pair<int, int>
#define full(v) v.begin(), v.end()
#define rfull(v) v.rbegin(), v.rend()
#define vln(v, n) vector<ll> v(n, 0)
#define vin(v, n) vector<int> v(n, 0)
#define minof(v) min_element(full(v))
#define maxof(v) max_element(full(v))
// #define maxPQ priority_queue<ll>
// #define minPQ priority_queue<ll, vector<ll>, greater<int>>
#define lb(v, x) lower_bound(full(v), x)
#define ub(v, x) upper_bound(full(v), x)
#define co(val) cout << val << '\n'
#define cval(val) cout << val << ' '
#define for_loop(i, a, b) for (llll i = a; i < b; i++)
#define for_loop_reverse(i, a, b) for (llll i = a; i > b; i--)
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
// #define Y "YES"
// #define N "NO"
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

template <typename T>
llll find_gcd(T &v)
{
    llll ans = v[0];
    for (auto val : v)
    {
        if (val > 0)
        {
            ans = gcd(ans, val);
        }
    }
    return ans;
};

template <typename T>
llll find_sum(T &v)
{
    llll ans = 0;
    for (auto val : v)
    {
        ans += val;
    }
    return ans;
};

template <typename T>
unordered_map<llll, llll> Counter(T &v)
{
    unordered_map<llll, llll> m;
    for (auto val : v)
    {
        m[val]++;
    }
    return m;
};
template <typename T>
map<llll, llll> Counter_map(T &v)
{
    map<llll, llll> m;
    for (auto val : v)
    {
        m[val]++;
    }
    return m;
};

ll find_pow(ll a, ll b, ll prime)
{
    if (b == 0)
        return 1;
    ll temp = find_pow(a, b / 2, prime);
    if (b % 2)
        return ((temp % prime) * (((temp % prime) * (a % prime)) % prime)) % prime;
    else
        return ((temp % prime) * (temp % prime)) % prime;
}
#ifndef llll
llll find_pow(llll a, llll b, llll prime)
{
    if (b == 0)
        return 1;
    llll temp = find_pow(a, b / 2, prime);
    if (b % 2)
        return ((temp % prime) * (((temp % prime) * (a % prime)) % prime)) % prime;
    else
        return ((temp % prime) * (temp % prime)) % prime;
}
#endif
// #define MOD 1e9 + 7
const int MOD = (int)(1e9 + 7);
#define INF 1e18
template <typename T>
// for vector
using V = vector<T>;
// vector of bool
using vb = V<bool>;
// vector of long double
using vd = V<long double>;
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

vector<bool> Sieve(llll n)
{
    vector<bool> Prime(max((llll)3, n + 1), 1);
    Prime[0] = Prime[1] = false;

    for (llll i = 2; i * i <= n; i++)
    {
        if (Prime[i])
        {
            for (llll j = i * i; j <= n; j += i)
            {
                Prime[j] = false;
            }
        }
    }
    return Prime;
}

void preCalculate()
{
}

class BinaryIndexedTree
{
public:
    int n;
    vector<int> v;
    vector<int> tree;
    vector<int> diff;
    BinaryIndexedTree *diff_tree;

    BinaryIndexedTree(vector<int> &arr)
    {
        n = arr.size();
        v = vector<int>(n + 1);
        tree = vector<int>(n + 1);
        for_loop(i, 0, n)
        {
            v[i + 1] = arr[i];
            // add(i + 1, v[i + 1]);
            int k = i + 1;
            // tree[k] = sum_query(k - (k & -k) + 1, k);
            add(i + 1, v[i + 1]);
        }
    }
    int sum(int k)
    {
        int ans = 0;
        while (k >= 1)
        {
            ans += tree[k];
            k -= k & -k;
        }
        return ans;
    }
    void add(int pos, int x)
    {
        // increase v[pos] by x;
        // x can be positive or negative
        while (pos <= n)
        {
            tree[pos] += x;
            pos += pos & -pos;
        }
    }

    int sum_query(int a, int b)
    {
        // a and b are 1 - indexed
        // sum from a to b, both inclusive;
        // if (a == 1)
        //     return sum(b);
        // else
        //     return sum(b) - sum(a - 1);
        return sum(b) - sum(a - 1);
    }

    void update(int pos, int val)
    {
        // update v[pos] to val
        int diff = val - v[pos];
        add(pos, diff);
    }
};

void cp()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    receive(arr);
    BinaryIndexedTree *tree = new BinaryIndexedTree(arr);

    for (auto val : tree->tree)
    {
        cval(val);
    }
    cout << new_line;

    while (q--)
    {
        co("Option 1 for sum query");
        co("Option 2 to update");
        int op;
        cin >> op;
        if (op == 2)
        {
            int a, b;
            cin >> a >> b;
            int ans = tree->sum_query(a, b);
            co(ans);
        }
        else
        {
            int pos, val;
            cin >> pos >> val;
            tree->update(pos, val);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    //     freopen("./input_file_check.txt", "r", stdin);
    //     freopen("./output_file_check.txt", "w", stdout);
    freopen("../error_file_check.txt", "w", stderr);
#endif
    bool interactive_question = true;
    if (!interactive_question)
    {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
    }
    bool multi_test_case = false;
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
