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

// omega (n log n)
// theta (n log n)
// O ( n ^ 2) when partition is unbalanced, ie when partition produces one subproblem of length n-1 and another with 0

ll partition_quick_sort(vl &v, ll p, ll r)
{
    // end as pivot

    // ll pivot = v[r];
    // ll i = p - 1;
    // ll temp;
    // for_loop(j, p, r)
    // {
    //     if (v[j] <= pivot)
    //     // >= for non increasing order
    //     {
    //         i++;
    //         temp = v[i];
    //         v[i] = v[j];
    //         v[j] = temp;
    //     }
    // }
    // temp = v[i + 1];
    // v[i + 1] = v[r];
    // v[r] = temp;
    // return i + 1;

    // starting as pivot

    ll pivot = v[p];

    ll i = p;
    ll temp;
    for_loop(j, p + 1, r + 1)
    {
        if (v[j] <= pivot)
        // >= for non increasing order
        {
            i++;
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    temp = v[p];
    v[p] = v[i];
    v[i] = temp;
    return i;
}

void quick_sort_cpp(vl &v, ll p, ll r)
{
    if (p < r)
    {
        ll q = partition_quick_sort(v, p, r);
        quick_sort_cpp(v, p, q - 1);
        quick_sort_cpp(v, q + 1, r);
    }
    return;
}

void cp()
{

    ll n;
    cin >> n;
    vl_n(v, n);
    receive(v, n);
    quick_sort_cpp(v, 0, n - 1);
    print_all(v);
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
