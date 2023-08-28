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

// Possible issues in Merging:

// 1. If current number is Integer.MAX then new encoded value which is usually greater than current element will cause integer overflow and data corruption (In python there is no limit to number size so this issue will not occur).

// 2. Doesn’t handle negative numbers (ie, when encoding a -ve number(current) with another -ve number(chosen smallest) the sign can’t be preserved since both numbers have -ve sign. Also absolute values must be used when computing dividend = divisor*quotient+remainder (divisor = maxele, quotient = smallest, remainder = original) and sign must be restored, still it might not work due to sign preservation issue.

// 3. Only applicable to Unsigned integers, like indexes which are usually non-negative.

// 4. AUX = O(n) in worst case, assuming in a language like python where there is no limit to word/integer size, when input array elements are almost at Integer.MAX, then encoded value will require possibly 2x bits space to represent new number, the 2x bit space on whole can become +1x array size, which is almost like creating an AUX array but in an indirect way.

// 5. mod and division operations are the costliest, hence reduces overall performance(upto some extent).

void inplace_merge(vl &v, ll p, ll q, ll r, ll max_ele)
{
    ll i = p, j = q + 1;
    ll k = i;

    while (i <= q && j <= r)
    {
        if (v[i] % max_ele <= v[j] % max_ele)
        {
            v[k] = v[k] + (v[i] % max_ele) * max_ele;
            k++;
            i++;
        }
        else
        {
            v[k] = v[k] + (v[j] % max_ele) * max_ele;
            k++;
            j++;
        }
    }
    while (i <= q)
    {
        v[k] = v[k] + (v[i] % max_ele) * max_ele;
        k++;
        i++;
    }
    while (j <= r)
    {
        v[k] = v[k] + (v[j] % max_ele) * max_ele;
        k++;
        j++;
    }

    for_loop(i, p, r + 1)
    {
        v[i] = v[i] / max_ele;
    }

    // print_all(L);
    // cout << '\n';
    // print_all(R);
    // cout << '\n';
    // for_loop(k, p, r + 1) cout << v[i] << ' ';
    // print_all(v);
    // cout << '\n';

    return;
}

void merge_sort(vl &v, ll start, ll end, ll max_ele)
{
    if (start < end)
    {
        ll q = (start + end) / 2;
        // co(start << ' ' << q << ' ' << end);
        merge_sort(v, start, q, max_ele);
        merge_sort(v, q + 1, end, max_ele);
        inplace_merge(v, start, q, end, max_ele);
    }
}

void merge_sort_cpp(vl &v)
{
    ll max_ele = *maxOf(v) + 1;
    merge_sort(v, 0, v.size() - 1, max_ele);
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
