#include <bits/stdc++.h>

using namespace std;

#define ll long
#define vl vector<ll>
#define new_line '\n'
#define mp make_pair
#define pb push_back
#define pf push_front
#define pob pob_back
#define llma __LONG_LONG_MAX__
#define llmi LLONG_MIN
#define full(v) v.begin(), v.end()
#define rfull(v) v.rbegin(), v.rend()
#define vl vector<ll>
#define vpl vector<pair<ll, ll>>
#define vi vector<int>
#define vi_n(v, n) vector<int> v(n, 0)
#define vl_n(v, n) vector<ll> v(n, 0)
#define vpl vector<pair<ll, ll>>
#define minOf(v) min_element(full(v))
#define maxOf(v) max_element(full(v))
#define maxPQ priority_queue<ll>
#define minPQ priority_queue<ll, vector<ll>, greater<int>>
#define lb(v, x) lower_bound(full(v), x)
#define ub(v, x) upper_bound(full(v), x)
#define co(val) cout << val << '\n'
#define cval(val) cout << val << ' '
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

// counting sort assumes that the elements are in the range 0 to k for some k

// stability of counting sort ??????

void counting_sort_cpp(vl &a, vl &b, ll k)
{
    vl_n(c, k + 1);
    for_loop(i, 0, k + 1)
    {
        c[i] = 0;
    }
    for_loop(j, 0, a.size())
    {
        c[a[j]]++;
    }
    for_loop(i, 1, k + 1)
    {
        c[i] += c[i - 1];
    }
    // c[i] containg number of elements less than or equal to i

    for_loop_reverse(j, a.size() - 1, -1)
    {
        b[c[a[j]] - 1] = a[j];
        c[a[j]]--;
    }
}

void cp()
{

    ll n;
    cin >> n;
    vl_n(v, n);
    receive(v, n);
    vl_n(ans, n);

    counting_sort_cpp(v, ans, *maxOf(v));
    print_all(ans);
    cout << new_line;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    bool single_test_case = true;
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
    return 0;
}
