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
    unordered_map<ll, ll> visited;
    unordered_map<ll, ll> parent;
    unordered_map<ll, char> colour;
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
        for_loop(i, 0, n)
        {
            this->visited[i] = 0;
            this->parent[i] = -1;
            this->colour[i] = 'w';
            this->d[i] = llma;
        }
    }

    Graph(ll n, vector<pair<ll, ll>> edges, bool undirected = false)
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
            this->addEdge(p.first, p.second);
            if (undirected)
                this->addEdge(p.second, p.first);
        }
        for_loop(i, 0, n)
        {
            this->visited[i] = 0;
            this->parent[i] = -1;
            this->colour[i] = 'w';
            this->d[i] = llma;
        }
    }

    void reset_bfs()
    {
        for_loop(i, 0, this->num_vertices)
        {
            this->visited[i] = 0;
            this->parent[i] = -1;
            this->colour[i] = 'w';
            this->d[i] = llma;
        }
    }

    void bfs_cpp(ll source)
    {
        reset_bfs();
        this->colour[source] = 'g';
        this->d[source] = 0;
        this->parent[source] = -1;
        queue<ll> q;
        q.push(source);
        ll u;
        ll neighbour;
        while (q.size())
        {
            u = q.front();
            q.pop();
            head *h = this->adj_list[u];
            node *temp = h->adj_head;
            while (temp)
            {
                neighbour = temp->val;
                if (this->colour[neighbour] == 'w')
                {
                    this->colour[neighbour] = 'g';
                    this->d[neighbour] = this->d[u] + 1;
                    this->parent[neighbour] = u;
                    q.push(neighbour);
                }
                temp = temp->next;
            }
            this->colour[u] = 'b';
        }
    }

    bool print_path_rec(ll source, ll vertex)
    {
        if (source == vertex)
        {
            cval(source);
            return true;
        }
        else if (this->parent[vertex] == -1)
        {
            cval("NO PATH EXISTS");
            return false;
        }
        else
        {
            bool isPath = print_path_rec(source, this->parent[vertex]);
            if (isPath)
                cval(vertex);
            return isPath;
        }
    }

    void print_path(ll source, ll vertex)
    {
        print_path_rec(source, vertex);
        cout << new_line;
    }

    void print_single_source_shortest_path(ll source)
    {
        for_loop(i, 0, this->num_vertices)
        {
            co("Shortest path from " << source << " to " << i);
            if (this->d[i] != llma)
                co("The distance is " << this->d[i]);
            print_path(source, i);
        }
        return;
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

    void addEdge(ll x, ll y)
    {
        // adding edge from x to y
        head *vertex = this->adj_list[x];
        node *to_push = createNode(y);
        push(vertex, to_push);
    }

    void printGraph()
    {
        for_loop(i, 0, this->num_vertices)
        {
            co("Vertices adjacent to " << i);
            head *temp = this->adj_list[i];
            printSLL(temp);
            cout << new_line;
        }
    }
};

void cp()
{
    ll n, m;
    cin >> n >> m;
    Graph *g = new Graph(n, m);
    ll a, b;
    while (m--)
    {
        cin >> a >> b;
        g->addEdge(a, b);
        // g->addEdge(b, a);
    }
    g->printGraph();

    cout << new_line;
    ll source;
    cin >> source;
    g->bfs_cpp(source);
    g->print_single_source_shortest_path(source);

    // vector<pair<ll, ll>> edges;
    // ll a, b;
    // while (m--)
    // {
    //     cin >> a >> b;
    //     edges.push_back({a, b});
    // }
    // Graph *g = new Graph(n, edges);
    // g->printGraph();
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