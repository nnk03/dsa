#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vl vector<ll>
#define new_line '\n'
#define mp make_pair
#define pb push_back
#define pf push_front
#define pl pair<ll, ll>
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
    }                     \
    cout << new_line;
#define print_all_in_separate_lines(arr) \
    for (auto x : arr)                   \
    {                                    \
        co(x);                           \
    }

// int c = 1;

typedef struct Set s;
typedef struct Node node;
struct Node
{
    ll val;
    s *representative;
    node *next;
};

struct Set
{
    node *head;
    node *tail;
};

node *createNode(ll val)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->next = NULL;
    temp->val = val;
    temp->representative = NULL;
    return temp;
}
s *createSet(ll val)
{
    node *temp = createNode(val);
    s *tempset = (s *)malloc(sizeof(s));
    tempset->head = temp;
    tempset->tail = temp;
    temp->representative = tempset;
    return tempset;
}
s *createSet(node *valNode)
{
    s *tempset = (s *)malloc(sizeof(s));
    tempset->head = valNode;
    tempset->tail = valNode;
    return tempset;
}

class DisjointSet
{
private:
    vector<Set *> v;

public:
    DisjointSet()
    {
    }

    DisjointSet(vl &set_of_nums)
    {
        // vl temp;
        for (auto val : set_of_nums)
        {
            makeSet(val);
        }
    }

    s *findRepresentative(node *x)
    {
        return x->representative;
    }

    void makeSet(ll val)
    {
        // (this->v).push_back()
        s *tempset = createSet(val);
        this->v.push_back(tempset);
        return;
    }

    void set_union(node *x, node *y)
    {
        s *rep_x = findRepresentative(x);
        s *rep_y = findRepresentative(y);

        // if (!x || !y)
        //     return;

        if (!rep_x || !rep_y)
        {
            co("HERE");
            return;
        }

        if (rep_x == rep_y)
            return;

        node *tail1 = rep_x->tail;
        node *temp = rep_y->head;

        tail1->next = temp;
        rep_x->tail = rep_y->tail;
        while (temp)
        {
            temp->representative = rep_x;
            temp = temp->next;
        }
        rep_y->head = NULL;
        rep_y->tail = NULL;
        return;
    }

    void set_union(s *x, s *y)
    {
        // if (!x || !y)
        // {
        //     co("HERE");
        //     return;
        // }
        set_union(x->head, y->head);
    }

    void printSet(s *x)
    {
        node *head = x->head;
        while (head)
        {
            cval(head->val);
            head = head->next;
        }
        cout << new_line;
        return;
    }
    void printSet(node *x)
    {
        s *rep_x = findRepresentative(x);
        if (!rep_x)
            return;

        printSet(rep_x);
        return;
    }

    vector<s *> getSets()
    {
        return this->v;
    }
};

void cp()
{
    ll n = 10;
    // cin >> n;
    vl v(n, 0);
    for_loop(i, 0, n)
    {
        v[i] = i + 1;
    }

    DisjointSet *x = new DisjointSet(v);

    for (auto val_set : x->getSets())
    {
        x->printSet(val_set);
    }
    vector<s *> vset = x->getSets();
    x->set_union(vset[0], vset[1]);
    x->set_union(vset[2], vset[3]);
    x->set_union(vset[0], vset[2]);
    x->set_union(vset[4], vset[5]);
    x->set_union(vset[6], vset[7]);
    x->set_union(vset[8], vset[9]);
    x->set_union(vset[4], vset[6]);
    x->set_union(vset[4], vset[8]);
    x->set_union(vset[0], vset[4]);

    for (auto val_set : x->getSets())
    {
        x->printSet(val_set);
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
