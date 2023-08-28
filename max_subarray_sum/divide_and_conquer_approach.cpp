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

pair<pair<ll, ll>, ll> find_max_crossing_sub_array(vl &v, ll low, ll mid, ll high)
{
    ll left_sum = llmi;
    ll right_sum = llmi;
    ll max_left, max_right;
    max_left = max_right = mid;
    ll sum = 0;
    for_loop_reverse(i, mid, low - 1)
    {
        sum += v[i];
        if (sum > left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }
    sum = 0;
    for_loop(i, mid + 1, high + 1)
    {
        sum += v[i];
        if (sum > right_sum)
        {
            right_sum = sum;
            max_right = i;
        }
    }
    return {{max_left, max_right}, left_sum + right_sum};
}

pair<pair<ll, ll>, ll> find_maximum_subarray(vl &v, ll low, ll high)
{
    if (low == high)
        return {{low, high}, v[low]};
    ll mid = (low + high) / 2;
    ll left_low, left_high, left_sum;
    ll right_low, right_high, right_sum;
    ll cross_low, cross_high, cross_sum;
    pair<pair<ll, ll>, ll> left = find_maximum_subarray(v, low, mid);
    pair<pair<ll, ll>, ll> right = find_maximum_subarray(v, mid + 1, high);
    pair<pair<ll, ll>, ll> cross = find_max_crossing_sub_array(v, low, mid, high);

    if (left.second > right.second && left.second > cross.second)
    {
        return left;
    }
    else if (right.second > left.second && right.second > cross.second)
    {
        return right;
    }
    else
    {
        return cross;
    }
}

// O(N log N)

void cp()
{
    ll n;
    cin >> n;
    vl_n(v, n);
    receive(v, n);
    pair<pair<ll, ll>, ll> ans = find_maximum_subarray(v, 0, n - 1);
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
