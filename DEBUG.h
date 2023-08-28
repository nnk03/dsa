#include <bits/stdc++.h>

using namespace std;

// #define ll long long
// #define vl vector<ll>
// #define vvl vector<vl>
#define new_line '\n'
// #define mp make_pair
// #define pb push_back
// #define eb emplace_back
// #define pf push_front
// #define pl pair<ll, ll>
// #define ld long double
// #ifndef ld
// #define ld double
// #endif
// #ifndef ll
// #define ll int
// #define llma INT_MAX
// #define llmi INT_MIN
// #else
// #define llma __LONG_LONG_MAX__
// #define llmi LLONG_MIN
// #endif
// #define full(v) v.begin(), v.end()
// #define rfull(v) v.rbegin(), v.rend()
// #define vl vector<ll>
// #define vpl vector<pair<ll, ll>>
// #define vi vector<int>
// #define vi_n(v, n) vector<int> v(n, 0)
// #define vln(v, n) vector<ll> v(n, 0)
// #define vpl vector<pair<ll, ll>>
// #define minof(v) min_element(full(v))
// #define maxof(v) max_element(full(v))
// #define maxPQ priority_queue<ll>
// #define minPQ priority_queue<ll, vector<ll>, greater<int>>
// #define lb(v, x) lower_bound(full(v), x)
// #define ub(v, x) upper_bound(full(v), x)
// #define co(val) cout << val << '\n'
// #define cval(val) cout << val << ' '
// #define for_loop(i, a, b) for (ll i = a; i < b; i++)
// #define for_loop_reverse(i, a, b) for (ll i = a; i > b; i--)
// #define receive(arr, n) \
//     for_loop(asdfasdf, 0, n) { cin >> arr[asdfasdf]; }
#ifndef ONLINE_JUDGE
#define debug(asdfasdf)         \
    cerr << #asdfasdf << " = "; \
    _print(asdfasdf, false);    \
    cerr << "\n";
#else
#define debug(asdfasdf) ;
#endif

// void _print(long long x, bool NEWLINE = true);
// void _print(int x, bool NEWLINE = true);
// void _print(char ch, bool NEWLINE = true);
// void _print(string s, bool NEWLINE = true);

// void _print(bool b, bool NEWLINE = true);

// template <class T1, class T2>
// void _print(pair<T1, T2> p, bool NEWLINE = true);

// template <typename T>
// void _print(vector<T> &v, bool NEWLINE = true);

// template <typename T>
// void _print(set<T> &v, bool NEWLINE = true);

// template <typename T>
// void _print(unordered_set<T> &v, bool NEWLINE = true);

// template <typename T>
// void _print(multiset<T> &v, bool NEWLINE = true);

// template <typename T1, typename T2>
// void _print(map<T1, T2> &v, bool NEWLINE = true);

// template <typename T1, typename T2>
// void _print(unordered_map<T1, T2> &v, bool NEWLINE = true);

//
//
//

void _print(long int x, bool NEWLINE = true)
{
    cerr << x;
    if (NEWLINE)
        cerr << new_line;
};
void _print(long long x, bool NEWLINE = true)
{
    cerr << x;
    if (NEWLINE)
        cerr << new_line;
};
void _print(int x, bool NEWLINE = true)
{
    cerr << x;
    if (NEWLINE)
        cerr << new_line;
};
void _print(char ch, bool NEWLINE = true)
{
    cerr << ch;
    if (NEWLINE)
        cerr << new_line;
};
void _print(string s, bool NEWLINE = true)
{
    cerr << s;
    if (NEWLINE)
        cerr << new_line;
};

void _print(bool b, bool NEWLINE = true)
{
    cerr << b;
    if (NEWLINE)
        cerr << new_line;
};

template <class T1, class T2>
void _print(pair<T1, T2> p, bool NEWLINE = true)
{
    cerr << "{ ";
    _print(p.first, NEWLINE = false);
    cerr << " , ";
    _print(p.second, NEWLINE = false);
    cerr << " }";
    if (NEWLINE)
        cerr << new_line;
};

template <typename T>
void _print(vector<T> &v, bool NEWLINE = true)
{
    cerr << "VECTOR [ ";
    for (T val : v)
    {
        _print(val, false);
        cerr << " ";
    }
    cerr << "]";
    if (NEWLINE)
        cerr << new_line;
};

template <typename T>
void _print(set<T> &v, bool NEWLINE = true)
{
    cerr << "SET [ ";
    for (T val : v)
    {
        _print(val, false);
        cerr << " ";
    }
    cerr << "]";
    if (NEWLINE)
        cerr << new_line;
};

template <typename T>
void _print(unordered_set<T> &v, bool NEWLINE = true)
{
    cerr << "UNORDERED_SET [ ";
    for (T val : v)
    {
        _print(val, false);
        cerr << " ";
    }
    cerr << "]";
    if (NEWLINE)
        cerr << new_line;
};

template <typename T>
void _print(multiset<T> &v, bool NEWLINE = true)
{
    cerr << "MULTISET [ ";
    for (T val : v)
    {
        _print(val, false);
        cerr << " ";
    }
    cerr << "]";
    if (NEWLINE)
        cerr << new_line;
};

template <typename T1, typename T2>
void _print(map<T1, T2> &v, bool NEWLINE = true)
{
    cerr << "MAP [ ";
    for (auto val : v)
    {
        _print(val, false);
        cerr << " ";
    }
    cerr << "]";
    if (NEWLINE)
        cerr << new_line;
};

template <typename T1, typename T2>
void _print(unordered_map<T1, T2> &v, bool NEWLINE = true)
{
    cerr << "UNORDERED_MAP [ ";
    for (auto val : v)
    {
        _print(val, false);
        cerr << " ";
    }
    cerr << "]";
    if (NEWLINE)
        cerr << new_line;
};
