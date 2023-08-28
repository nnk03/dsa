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

// 0-indexed arrays

ll parent(ll i)
{
    return (i % 2) ? i / 2 : i / 2 - 1;
}
ll left(ll i)
{
    return (2 * i + 1);
}
ll right(ll i)
{
    return 2 * (i + 1);
}

// max-heapify O(lg n)
// build-max-heap O(n)
// max-heap-insert, heap-extract-max, heap-increase-key, heap-maximum -> O(lg n)
void max_heapify(vl &v, ll i, ll heap_size)
{
    ll l = left(i);
    ll r = right(i);
    ll index_largest = i;
    if (l < heap_size && v[l] > v[index_largest])
    {
        index_largest = l;
    }
    if (r < heap_size && v[r] > v[index_largest])
    {
        index_largest = r;
    }
    if (index_largest != i)
    {
        ll temp = v[index_largest];
        v[index_largest] = v[i];
        v[i] = temp;
        max_heapify(v, index_largest, heap_size);
    }
}

void build_max_heap(vl &v)
{
    ll heap_size = v.size();
    for_loop_reverse(i, (ll)(v.size() / 2), -1)
    {
        max_heapify(v, i, heap_size);
    }
    // print_all(v);
    // cout << new_line;
}

// worst case, best case, average case time complexity all are O(n log n)
// space complexity O(1)

void heap_sort_cpp(vl &v)
{
    ll heap_size = v.size();
    build_max_heap(v);
    ll temp;
    // heap_size--;
    for_loop_reverse(i, v.size() - 1, 0)
    {
        temp = v[i];
        v[i] = v[0];
        v[0] = temp;
        heap_size--;
        max_heapify(v, 0, heap_size);
        // print_all(v);
        // cout << new_line;
    }
}

void cp()
{
    ll n;
    cin >> n;
    vl_n(v, n);
    receive(v, n);
    heap_sort_cpp(v);
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
