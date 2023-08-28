#include <bits/stdc++.h>

using namespace std;

#define ll long
#define vl vector<ll>
#define new_line '\n'
#define mp make_pair
#define pb push_back
#define pf push_front
#define llma __LONG_LONG_MAX__
#define llmi LLONG_MIN

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

void merge(vl &v, ll p, ll q, ll r)
{
    // co(p << ' ' << q << ' ' << r);
    ll n1 = q - p + 1;
    ll n2 = r - q;
    vl L(n1 + 1, 0), R(n2 + 1, 0);
    for_loop(i, 0, n1)
    {
        L[i] = v[p + i];
    }
    for_loop(i, 0, n2)
    {
        R[i] = v[q + i + 1];
    }
    L[n1] = llma;
    R[n2] = llma;
    ll i = 0, j = 0;
    for_loop(k, p, r + 1)
    {
        if (L[i] <= R[j])
        {
            v[k] = L[i];
            i++;
        }
        else
        {
            v[k] = R[j];
            j++;
        }
    }

    // for non increasing order

    // L[n1] = llmi;
    // R[n2] = llmi;
    // ll i = 0, j = 0;
    // for_loop(k, p, r + 1)
    // {
    //     if (L[i] >= R[j])
    //     {
    //         v[k] = L[i];
    //         i++;
    //     }
    //     else
    //     {
    //         v[k] = R[j];
    //         j++;
    //     }
    // }

    // print_all(L);
    // cout << '\n';
    // print_all(R);
    // cout << '\n';
    // for_loop(k, p, r + 1) cout << v[i] << ' ';
    // print_all(v);
    // cout << '\n';

    return;
}

void merge_sort(vl &v, ll start, ll end)
{
    // if (start < end)
    // {
    //     ll q = (start + end) / 2;
    //     // co(start << ' ' << q << ' ' << end);
    //     merge_sort(v, start, q);
    //     merge_sort(v, q + 1, end);
    //     merge(v, start, q, end);
    // }
    ll current_size;
    ll left_start;
    for (current_size = 1; current_size <= v.size() - 1; current_size *= 2)
    {
        for (left_start = 0; left_start < v.size() - 1; left_start += 2 * current_size)
        {
            ll mid = min((ll)(left_start + current_size - 1), (ll)(v.size() - 1));
            ll right_end = min((ll)(left_start + 2 * current_size - 1), (ll)(v.size() - 1));
            merge(v, left_start, mid, right_end);
        }
    }
}

void merge_sort_cpp(vl &v)
{
    merge_sort(v, 0, v.size() - 1);
}

void cp()
{
    ll n;
    cin >> n;
    vl_n(v);
    receive(v, n);
    merge_sort_cpp(v);
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
