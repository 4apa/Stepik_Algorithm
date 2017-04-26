#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cnt{0};
vector <pair <int, int>> v;

int Parent(int i)
{
    return (i-1)/2;
}

int LeftChild(int i)
{
    return 2*i+1;
}

int RightChild(int i)
{
    return 2*i+2;
}

void SiftDown (int *p, int n, int i)
{
    int MinIndex = i;
    int l = LeftChild(i);
    int r = RightChild(i);
    if (l < n && p[l] < p[MinIndex]) MinIndex = l;
    if (r < n && p[r] < p[MinIndex]) MinIndex = r;
    if (i != MinIndex)
    {
        ++cnt;
        v.push_back(make_pair(i, MinIndex));
        swap(p[i], p[MinIndex]);
        SiftDown(p, n, MinIndex);
    }
}

void MakeHeap (int *p, int n)
{
for (int i = n/2; i >= 0 ; --i)
SiftDown(p, n, i);
}

int main()
{
    int n;
    cin >> n;
    int *a = new int [n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    MakeHeap(a, n);
    cout << cnt << '\n';
    for (auto now : v)
        cout << now.first << " " << now.second << '\n';
    delete [] a;
    return 0;
}
