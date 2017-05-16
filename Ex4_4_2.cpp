//Проверка выполнения свойства бинарного дерева поиска
#include <iostream>
using namespace std;

struct Node
{
    long int key;
    int left;
    int right;
};

constexpr long int I_MAX = 2147483647;
constexpr long int I_MIN = -2147483648;

bool is_bst (Node *tree, int i, long int minim, long int maxim)
{
if (tree[i].key < minim || tree[i].key > maxim) return false;
if (tree[i].left == -1 && tree[i].right == -1) return true;
if (tree[i].left == -1 && tree[i].right != -1) return
   is_bst (tree, tree[i].right, tree[i].key + 1, maxim);
if (tree[i].right == -1 && tree[i].left != -1) return
   is_bst (tree, tree[i].left, minim, tree[i].key - 1);
return
 is_bst (tree, tree[i].left, minim, tree[i].key - 1)&&
 is_bst (tree, tree[i].right, tree[i].key + 1, maxim);
}



int main()
{
    int n;
    cin >> n;
    if (n == 0) cout << "CORRECT";
    else
    {
        Node *tree = new Node [n];
        for (int i = 0; i < n; ++i)
            cin >> tree[i].key >> tree[i].left >> tree[i].right;

    if (is_bst(tree, 0, I_MIN, I_MAX)) cout << "CORRECT";
    else cout << "INCORRECT";
        delete [] tree;
    }
    return 0;
}
