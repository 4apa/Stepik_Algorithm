#include <iostream>
using namespace std;

struct point
{
    int value;
    int parent;
    int children {0};
};

int main()
{
    int n;
    int h_max = 1;
    cin >> n;
    point a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].parent;
        a[a[i].parent].children = 1;
    }
    for (int i = 0; i < n; ++i)
    {
        if (a[i].children == 0)
        {
            int h = 1;
            int l = i;
            while (a[l].parent != -1)
            {
                l = a[l].parent;
                ++h;
            }
            if (h > h_max) h_max = h;
        }
    }
    cout << h_max;
    return 0;
}
