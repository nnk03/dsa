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

typedef struct Node node;
struct Node
{
    ll val;
    node *left;
    node *right;
};

node *createNode(ll val)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

class Binary_search_tree
{
private:
    node *root;

public:
    Binary_search_tree()
    {
        this->root = NULL;
    }

    void setRoot(node *head)
    {
        this->root = head;
    }

    void setRoot(ll val)
    {
        node *temp = createNode(val);
        root = temp;
    }

    node *getRoot()
    {
        return root;
    }

    node *tree_successor(node *x)
    {
        if (x->right)
        {
            return tree_minimum(x->right);
        }
        stack<node *> s;
        node *temp = this->root;

        while (temp && temp->val != x->val)
        {
            s.push(temp);
            if (x->val < temp->val)
                temp = temp->left;
            else
                temp = temp->right;
        }

        node *y = s.top();
        while (y && y->right == x)
        {
            x = y;
            s.pop();
            y = s.top();
        }
        // clearing the stack
        while (s.size())
            s.pop();

        return y;
    }

    void non_rec_tree_insert(node *z)
    {
        node *y = NULL;
        node *x = this->root;

        while (x)
        {
            y = x;
            if (z->val < x->val)
                x = x->left;
            else if (z->val > x->val)
                x = x->right;
            else
            {
                co("ERROR: VALUE ALREADY PRESENT");
                return;
            }
        }
        if (y == NULL)
            this->root = z;
        else if (z->val < y->val)
            y->left = z;
        else
            y->right = z;

        return;
    }

    // overloading the function
    void non_rec_tree_insert(ll value)
    {
        node *temp = createNode(value);
        non_rec_tree_insert(temp);
        return;
    }

    // subroutine for delete: Transplant
    void transplant(node *u, node *v)
    {
        if (u == this->root)
        {
            this->root = v;
            return;
        }
        node *parent = NULL;
        node *temp = this->root;
        while (temp && temp->val != u->val)
        {
            parent = temp;
            if (u->val < temp->val)
                temp = temp->left;
            else
                temp = temp->right;
        }
        if (parent->left == u)
            parent->left = v;
        else
            parent->right = v;
        return;
    }

    void non_rec_tree_delete(node *z)
    {
        if (z == NULL)
            return;
        if (z->left == NULL)
            transplant(z, z->right);
        else if (z->right == NULL)
            transplant(z, z->left);
        else
        {
            node *y = tree_minimum(z->right);
            if (z->right != y)
            {
                transplant(y, y->right);
                y->right = z->right;
            }
            transplant(z, y);
            y->left = z->left;
        }
    }

    node *recursive_tree_delete(node *head, ll value)
    {
        if (!head)
            return head;

        if (value < head->val)
        {
            head->left = recursive_tree_delete(head->left, value);
            return head;
        }
        else if (value > head->val)
        {
            head->right = recursive_tree_delete(head->right, value);
            return head;
        }
        else
        {
            if (head->left == NULL)
                return head->right;
            else if (head->right == NULL)
                return head->left;
            else
            {
                node *temp = tree_minimum(head->right);
                head->val = temp->val;
                head->right = recursive_tree_delete(head->right, temp->val);
                return head;
            }
        }
    }

    node *recursive_tree_insert(node *head, ll value)
    {
        if (!head)
            return createNode(value);

        if (value < head->val)
        {
            head->left = recursive_tree_insert(head->left, value);
            return head;
        }

        else if (value > head->val)
        {
            head->right = recursive_tree_insert(head->right, value);
            return head;
        }

        else
        {
            co("ERROR: VALUE ALREADY PRESENT");
            return head;
        }
    }

    node *tree_maximum(node *head)
    {
        node *temp = head;
        while (temp && temp->right)
        {
            temp = temp->right;
        }
        return temp;
    }

    node *tree_minimum(node *head)
    {
        node *temp = head;
        while (temp && temp->left)
        {
            temp = temp->left;
        }
        return temp;
    }

    node *iterative_tree_search(ll key)
    {
        node *temp = root;
        while (temp && temp->val != key)
        {
            if (key < temp->val)
                temp = temp->left;
            else
                temp = temp->right;
        }
        return temp;
    }

    node *treeSearch(node *head, ll key)
    {
        if (head == NULL || head->val == key)
        {
            return head;
        }
        if (key < head->val)
        {
            return treeSearch(head->left, key);
        }
        else
        {
            return treeSearch(head->right, key);
        }
    }

    void inOrderWalk(node *temp)
    {
        if (!temp)
            return;
        inOrderWalk(temp->left);
        cval(temp->val);
        inOrderWalk(temp->right);
    }
    void preOrderWalk(node *temp)
    {
        if (!temp)
            return;
        cval(temp->val);
        preOrderWalk(temp->left);
        preOrderWalk(temp->right);
    }
    void postOrderWalk(node *temp)
    {
        if (!temp)
            return;
        postOrderWalk(temp->left);
        postOrderWalk(temp->right);
        cval(temp->val);
    }

    void print_tree()
    {
        node *temp = root;
        inOrderWalk(temp);
        // if (!temp)
        cout << new_line;
        temp = root;
        preOrderWalk(temp);
        cout << new_line;
        if (!temp)
            free(temp);
    }
};

void cp()
{
    // Binary_search_tree t = Binary_search_tree();
    // Binary_search_tree *tree = &t;
    Binary_search_tree *tree = new Binary_search_tree();
    int option;
    while (true)
    {
        co("1 for non recursive insert");
        co("2 for recursive insert");
        co("3 for non recursive delete");
        co("4 for recursive delete");
        co("5 for inorder walk");
        co("6 for preorder walk");
        co("7 for postorder walk");
        co("8 for iterative tree search");
        co("9 for recursive tree search");
        co("10 for tree minimum");
        co("11 for tree maximum");
        co("12 for exit");
        cin >> option;

        switch (option)
        {
        case 1:
        {
            ll value;
            cin >> value;
            tree->non_rec_tree_insert(value);
            tree->print_tree();
            break;
        }
        case 2:
        {
            ll value;
            cin >> value;
            tree->setRoot(tree->recursive_tree_insert(tree->getRoot(), value));
            tree->print_tree();
            break;
        }

        case 3:
        {
            ll value;
            cin >> value;
            node *temp = tree->treeSearch(tree->getRoot(), value);
            if (temp)
                tree->non_rec_tree_delete(temp);
            if (!temp)
                free(temp);
            tree->print_tree();
            break;
        }

        case 4:
        {
            ll value;
            cin >> value;
            node *temp = tree->treeSearch(tree->getRoot(), value);
            if (temp)
                tree->setRoot(tree->recursive_tree_delete(tree->getRoot(), value));
            if (!temp)
                free(temp);
            tree->print_tree();
            break;
        }

        case 5:
        {
            tree->inOrderWalk(tree->getRoot());
            break;
        }

        case 6:
        {
            tree->preOrderWalk(tree->getRoot());
            break;
        }

        case 7:
        {
            tree->postOrderWalk(tree->getRoot());
            break;
        }

        case 8:
        {
            ll value;
            cin >> value;
            node *temp = tree->iterative_tree_search(value);
            if (temp)
            {
                co("FOUND");
                co(temp->val);
            }
            else
            {
                co("NOT FOUND");
            }
            if (!temp)
                free(temp);
            break;
        }

        case 9:
        {
            ll value;
            cin >> value;
            node *temp = tree->treeSearch(tree->getRoot(), value);
            if (temp)
            {
                co("FOUND");
                co(temp->val);
            }
            else
            {
                co("NOT FOUND");
            }
            if (!temp)
                free(temp);
            break;
        }

        case 10:
        {
            node *temp = tree->tree_minimum(tree->getRoot());
            if (temp)
                co(temp->val);
            else
                co("NO TREE");
            break;
        }

        case 11:
        {
            node *temp = tree->tree_maximum(tree->getRoot());
            if (temp)
                co(temp->val);
            else
                co("NO TREE");
            break;
        }

        case 12:
            return;

        default:
            break;
        }
        co(new_line);
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
