#include <iostream>
#include <map>
#include <cstdlib>
#include <algorithm>

using namespace std;

int height (const multimap <int, int> &m, int x)
{
    typedef multimap <int, int>::const_iterator I;
    int h = 0;
    pair <I, I> b = m.equal_range(x);
    for (I i = b.first; i != b.second; ++i)
        h = max (h, height(m,i->second)+1);
    return h;
}

int main()
{
    int n;
    cin >> n;
    multimap <int, int> tree;
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        tree.insert (make_pair(k, i));
    }
cout << height(tree, -1);
    return 0;
}
