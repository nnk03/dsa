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

pair<pair<ll, ll>, ll> kadane_algo(vl &v)
{
    ll n = v.size();
    vector<pair<ll, pair<ll, ll>>> dp(n + 1);
    dp[0] = {0, {llma, llmi}};
    ll temp;
    for_loop(i, 0, n)
    {
        temp = dp[i].first + v[i];
        if (temp > v[i])
        {
            dp[i + 1].first = temp;
            dp[i + 1].second = {dp[i].second.first, i};
        }
        else
        {
            dp[i + 1].first = v[i];
            dp[i + 1].second = {i, i};
        }
    }
    pair<ll, pair<ll, ll>> ans = *max_element(dp.begin() + 1, dp.end());
    return {ans.second, ans.first};
}

// O(N)

void cp()
{
    ll n;
    cin >> n;
    vl_n(v, n);
    receive(v, n);
    pair<pair<ll, ll>, ll> ans = kadane_algo(v);
    co(ans.first.first << ' ' << ans.first.second);
    co(ans.second);
    return;
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
