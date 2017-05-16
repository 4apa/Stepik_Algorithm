//обход элементов дерева в различном порядке
#include <iostream>
#include <vector>
using namespace std;

struct Leaf
{
    unsigned key;
    int left;
    int right;
};

void preOrder (Leaf v[], int i)
{
    cout << v[i].key << " ";
    if (v[i].left != -1) preOrder(v, v[i].left);
    if (v[i].right != -1) preOrder(v, v[i].right);
    return;
}

void inOrder (Leaf v[], int i)
{
    if (v[i].left != -1) inOrder(v, v[i].left);
    cout << v[i].key << " ";
    if (v[i].right != -1) inOrder(v, v[i].right);
    return;
}

void postOrder (Leaf v[], int i)
{
    if (v[i].left != -1) postOrder(v, v[i].left);
    if (v[i].right != -1) postOrder(v, v[i].right);
    cout << v[i].key << " ";
    return;
}

int main()
{
    int n;
    cin >> n;
    Leaf tree [n];

    for (int i = 0; i < n; ++i)
        cin >> tree[i].key >> tree[i].left >> tree[i].right;

    inOrder(tree, 0);
    cout << '\n';
    preOrder(tree, 0);
    cout << '\n';
    postOrder(tree, 0);
    return 0;
}
