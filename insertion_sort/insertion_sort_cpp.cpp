#include <bits/stdc++.h>

using namespace std;

#define ll long
#define vl vector<ll>
#define new_line '\n'
#define mp make_pair
#define pb push_back
#define pf push_front
// #define llma LONG_LONG_MAX
// #define llmi LONG_LONG_MIN

#define full(v) v.begin(), v.end()
#define vl vector<ll>
#define vpl vector<pair<ll, ll>>
#define vi vector<int>
#define vi_n(v) vector<int> v(n, 0)
#define vl_n(v) vector<ll> v(n, 0)
#define vpl vector<pair<ll, ll>>
#define minOf(v) min_element(full(v))
#define maxOf(v) max_element(full(v))
#define maxPQ priority_queue<ll>
#define minPQ priority_queue<ll, vector<ll>, greater<int>>
#define lb(v, x) lower_bound(full(v), x)
#define ub(v, x) upper_bound(full(v), x)
#define co(val) cout << val << '\n'
#define for_loop(i, a, b) for (ll i = a; i < b; i++)
#define for_loop_reverse(i, a, b) for (ll i = a; i > b; i--)
#define receive(arr, n) \
    for_loop(i, 0, n) { cin >> arr[i]; }
#define print_all(arr)    \
    for (auto x : arr)    \
    {                     \
        cout << x << ' '; \
    }
#define print_all_in_separate_lines(arr) \
    for (auto x : arr)                   \
    {                                    \
        co(x);                           \
    }

// int c = 1;

// Best case omega(n)
// Worst case O(n^2)
// Average case theta(n^2)
void insertion_sort_cpp(vl &v)
{
    ll len = v.size();
    ll key;
    for (ll j = 1; j < len; j++)
    {
        key = v[j];
        ll i = j - 1;
        while (i > -1 && v[i] > key)
        {
            v[i + 1] = v[i];
            // for non increasing order, replace v[i] > key with v[i] < key above

            i--;
        }
        v[i + 1] = key;
    }
    return;
}

void cp()
{
    ll n;
    cin >> n;
    vl_n(v);
    receive(v, n);
    insertion_sort_cpp(v);
    print_all(v);
    cout << new_line;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        cp();
    }
    return 0;
}
