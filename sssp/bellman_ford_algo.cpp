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
typedef struct Node node;
struct Node
{
    ll val;
    node *next;
};

typedef struct Head head;
struct Head
{
    ll vertex;
    node *adj_head;
};

node *createNode(ll val)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->val = val;
    temp->next = NULL;
    return temp;
}

head *createHead(ll val)
{
    head *temp = (head *)malloc(sizeof(head));
    temp->vertex = val;
    temp->adj_head = NULL;
    return temp;
}

class Graph
{
private:
    ll num_vertices;
    ll num_edges;
    vector<head *> adj_list;
    set<pair<ll, ll>> edge_set;
    map<pl, ll> weight;
    unordered_map<ll, ll> parent;
    unordered_map<ll, ll> d;

public:
    Graph(ll n, ll m)
    {
        this->num_vertices = n;
        this->num_edges = m;
        for_loop(i, 0, n)
        {
            head *temp = createHead(i);
            this->adj_list.push_back(temp);
        }
        for_loop(i, 0, this->num_vertices)
        {
            parent[i] = -1;
            d[i] = llma;
        }
        // vpl v = this->getEdgeSet();

        // set<pl> s;
        // for (auto p : v)
        // {
        //     s.insert(p);
        // }
        // edge_set = s;
    }

    Graph(ll n, vector<pair<ll, pair<ll, ll>>> edges, bool undirected = false)
    {
        ll m = edges.size();
        this->num_vertices = n;
        this->num_edges = m;
        for_loop(i, 0, n)
        {
            head *temp = createHead(i);
            this->adj_list.push_back(temp);
        }

        for (auto p : edges)
        {
            this->addEdge(p.second.first, p.second.second, p.first);
            if (undirected)
                this->addEdge(p.second.second, p.second.first, p.first);
        }
        for_loop(i, 0, this->num_vertices)
        {
            parent[i] = -1;
            d[i] = llma;
        }
        // vpl v = this->getEdgeSet();

        // set<pl> s;
        // for (auto p : v)
        // {
        //     s.insert(p);
        // }
        // edge_set = s;
    }

    void initialize_single_source(ll source)
    {
        for_loop(i, 0, this->num_vertices)
        {
            parent[i] = -1;
            d[i] = llma;
        }
        d[source] = 0;
    }

    void relax(ll u, ll v)
    {
        if (this->edge_set.count({u, v}) == 0)
            return;
        if (this->d[v] > this->d[u] + this->weight[{u, v}])
        {
            this->d[v] = this->d[u] + this->weight[{u, v}];
            this->parent[v] = u;
        }
        // since it is undirected
        // if (d[u] > d[v] + weight[{v, u}])
        // {
        //     d[u] = d[v] + weight[{v, u}];
        //     parent[u] = v;
        // }
        // if (this->d[v] > this->)
    }

    bool bellman_ford(ll source)
    {
        initialize_single_source(source);
        co("here");
        for_loop(i, 0, this->num_vertices - 1)
        {
            for (auto e : this->edge_set)
            {
                relax(e.first, e.second);
                // relax(e.second, e.first);
            }
        }
        for (auto e : this->edge_set)
        {
            ll u = e.first;
            ll v = e.second;
            if (d[v] > d[u] + weight[{u, v}])
            {
                // co(v << ' ' << u);
                return false;
            }
        }
        return true;
    }

    bool print_path_rec(ll source, ll vertex)
    {
        if (source == vertex)
        {
            // co("HERE");
            cval(source);
            return true;
        }
        else if (parent[vertex] == -1)
        {
            // co("HERE");

            cval("NO PATH EXISTS");
            return false;
        }
        else
        {
            cval(parent[vertex]);
            bool x = print_path_rec(source, parent[vertex]);
            // co("HERE");
            // cout<<
            if (x)
                cval(vertex);
            return x;
        }
    }

    void print_path(ll source, ll vertex)
    {
        print_path_rec(source, vertex);
        cout << new_line;
    }

    bool getPath(ll source, ll vertex, vl &v)
    {
        if (source == vertex)
        {
            v.push_back(source);
            return true;
        }
        else if (parent[vertex] == -1)
        {
            return false;
        }
        else
        {
            bool isPath = getPath(source, parent[vertex], v);
            if (isPath)
            {
                v.push_back(vertex);
            }
            return isPath;
        }
    }

    vl getPath(ll source, ll vertex)
    {
        vl v = {};
        bool isPath = getPath(source, vertex, v);
        if (isPath)
            return v;
        else
            return {};
    }

    ll get_weight_of_path(vl v)
    {
        ll sum = 0;
        for_loop(i, 0, v.size())
        {
            sum += weight[{v[i - 1], v[i]}];
        }
        return sum;
    }

    void print_single_source_shortest_paths(ll source)
    {
        for_loop(i, 0, this->num_vertices)
        {
            co("Shortest Path from " << source << " to " << i);
            this->print_path(source, i);

            vl path = getPath(source, i);
            if (path.size())
                co("Weight of Path is " << this->get_weight_of_path(path));
        }
    }

    void printParents()
    {
        for_loop(i, 0, this->num_vertices)
        {
            co(this->parent[i]);
        }
    }

    vpl getEdgeSet()
    {
        vpl v = {};
        for (auto h : this->adj_list)
        {
            if (h)
            {
                node *temp = h->adj_head;
                while (temp)
                {
                    v.pb({h->vertex, temp->val});
                    temp = temp->next;
                }
            }
        }
        return v;
    }

    void printSLL(head *h)
    {
        printSLL(h->adj_head);
    }

    void printSLL(node *start)
    {
        node *temp = start;
        while (temp)
        {
            cval(temp->val);
            temp = temp->next;
        }
        cout << new_line;
    }
    void push(head *h, node *val_node)
    {
        if (h->adj_head == NULL)
        {
            h->adj_head = val_node;
            return;
        }
        // place it in correct sorted position
        node *parent = NULL;
        node *temp = h->adj_head;
        while (temp && temp->val < val_node->val)
        {
            parent = temp;
            temp = temp->next;
        }
        if (!parent)
        {
            val_node->next = h->adj_head;
            h->adj_head = val_node;
            return;
        }
        val_node->next = parent->next;
        parent->next = val_node;
        return;
    }

    void addEdge(ll x, ll y, ll weight)
    {
        // adding edge from x to y
        head *vertex = this->adj_list[x];

        node *to_push = createNode(y);
        this->weight[{x, y}] = weight;
        push(vertex, to_push);
        // if (this->edge_set.count({x, y}) == 0 && this->edge_set.count({y, x}) == 0)
        // {
        this->edge_set.insert({x, y});
        // }
    }

    void printGraph()
    {
        for_loop(i, 0, this->num_vertices)
        {
            co("Vertices adjacent to " << i);
            head *temp = this->adj_list[i];
            printSLL(temp);
            node *tempnode = temp->adj_head;
            while (tempnode)
            {
                cval((this->weight[{i, tempnode->val}]));
                tempnode = tempnode->next;
            }
            cout << new_line;
        }
    }
};

void cp()
{
    ll n, m;
    cin >> n >> m;
    Graph *g = new Graph(n, m);
    while (m--)
    {
        ll a, b, weight;
        cin >> a >> b >> weight;
        g->addEdge(a, b, weight);
        // g->addEdge(b, a, weight);
    }
    g->printGraph();
    cout << new_line;

    ll source;
    cin >> source;
    bool isNoCycle = g->bellman_ford(source);

    if (isNoCycle == false)
    {
        co("NEGATIVE WEIGHT CYCLE FOUND");
    }
    else
    {
        // g->printParents();
        g->print_single_source_shortest_paths(source);
    }
    // not working for source other than 4
    // parent keeping on repeating between 0 and 1
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

// sample input

// 9 14
// 0 1 4
// 0 7 8
// 1 7 11
// 1 2 8
// 7 8 7
// 8 6 6
// 7 6 1
// 2 8 2
// 6 5 2
// 2 5 4
// 2 3 7
// 3 5 14
// 3 4 9
// 4 5 10
