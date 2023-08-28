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

ll parent(ll i, ll d_ary)
{
    return (i % d_ary != 0) ? i / d_ary : i / d_ary - 1;
}

vl children(ll i, ll d_ary)
{
    vl_n(v, d_ary);
    ll q = 1;
    for_loop(i, 0, d_ary)
    {
        v[i] = d_ary * i + q;
        q++;
    }
    return v;
}

void max_heapify_d_ary(vl &v, ll i, ll heapsize, ll d_ary)
{
    vl children_indices = children(i, d_ary);
    ll index_largest = i;
    for (auto index : children_indices)
    {
        if (index >= heapsize)
        {
            break;
        }
        if (index < heapsize && v[index] > v[index_largest])
        {
            index_largest = index;
        }
    }
    if (index_largest != i)
    {
        ll temp = v[i];
        v[i] = v[index_largest];
        v[index_largest] = temp;
        max_heapify_d_ary(v, index_largest, heapsize, d_ary);
    }
    return;
}

ll heap_extract_max_d_ary(vl &v, ll *heapsize_ptr, ll d_ary)
{
    if (v.size() == 0)
        return llmi;

    ll max = v[0];
    v[0] = *v.rbegin();
    v.pop_back();
    *heapsize_ptr = *heapsize_ptr - 1;
    max_heapify_d_ary(v, 0, *heapsize_ptr, d_ary);
    return max;
}

void heap_increase_key_d_ary(vl &v, ll index, ll key, ll d_ary)
{
    if (key < v[index])
    {
        co("ERROR: NEW VALUE IS LESS THAN OLD VALUE");
        return;
    }
    v[index] = key;

    // ll temp;
    // while (index > 0 && v[parent(index)] < v[index])
    // {
    //     temp = v[index];
    //     v[index] = v[parent(index)];
    //     v[parent(index)] = temp;
    //     index = parent(index);
    // }

    // another way of implementing: find the topmost parent with value less than key

    while (index > 0 && v[parent(index, d_ary)] < key)
    {
        v[index] = v[parent(index, d_ary)];
        index = parent(index, d_ary);
    }
    v[index] = key;
    return;
}

void max_heap_insert_d_ary(vl &v, ll key, ll *heap_size_ptr, ll d_ary)
{
    *heap_size_ptr = *heap_size_ptr + 1;
    if (v.size() >= *heap_size_ptr)
    {
        v[*heap_size_ptr - 1] = llmi;
    }
    else
    {
        v.pb(llmi);
    }
    heap_increase_key_d_ary(v, *heap_size_ptr - 1, key, d_ary);
    return;
}

ll heap_maximum(vl &v)
{
    return v[0];
}

void cp()
{
    vl v;
    int option;
    ll d_ary;
    co(" Value for d for d_ary heap: ");
    cin >> d_ary;
    ll heapsize = 0;
    while (true)
    {
        co("1 for heapmax");
        co("2 for heap extract max");
        co("3 for heap insert");
        co("4 for heap increase key");
        co("5 to exit");
        cin >> option;
        switch (option)
        {
        case 1:
            co(heap_maximum(v));
            co("The heap is");
            print_all(v);
            cout << new_line;
            break;

        case 2:
            co(heap_extract_max_d_ary(v, &heapsize, d_ary));
            co("The heap is");
            print_all(v);
            cout << new_line;
            break;

        case 3:
            ll value;
            cin >> value;
            max_heap_insert_d_ary(v, value, &heapsize, d_ary);
            co("The heap is");
            print_all(v);
            cout << new_line;
            break;

        case 4:
            ll index, key;
            cin >> index >> key;
            heap_increase_key_d_ary(v, index, key, d_ary);
            co("The heap is");
            print_all(v);
            cout << new_line;
            break;

        case 5:
            return;

        default:
            break;
        }
        cout << new_line;
        cout << new_line;
    }
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
