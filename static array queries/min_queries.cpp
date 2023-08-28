#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> a({1, 3, 4, 8, 6, 1, 4, 2});

    // similar for max queries

    // there are errors
    // 3 4

    map<pair<int, int>, int> m;
    for (int i = 0; i < a.size(); i++)
    {
        int skip = 0;
        int j = i;
        while (j < a.size())
        {
            m[{i, j}] = *min_element(a.begin() + i, a.begin() + j);
            j += (int)pow(2, skip);
            skip++;
        }
    }
    // range queries
    int start, end;
    cin >> start >> end;
    // start end inclusive

    if (start == end)
    {
        cout << m[{start, end}] << '\n';
        return 0;
    }
    int diff = end - start + 1;
    double diff_log = log2(diff);
    if (diff_log == (int)diff_log)
    {
        cout << m[{start, end}] << '\n';
    }
    else
    {
        int power = log2(end - start + 1);
        int k = pow(2, power);
        cout << k << '\n';
        cout << start << '\n';
        cout << start + k - 1 << '\n';
        cout << end - k + 1 << '\n';
        cout << end << '\n';

        cout << min({m[{start, start + k - 1}], m[{end - k + 1, end}]}) << '\n';
    }
    return 0;
}