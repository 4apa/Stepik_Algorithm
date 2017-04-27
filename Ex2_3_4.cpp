//Реализация системы непересекающихся множеств - disjoint set union (DSU)
//Проверить можно ли присвоить переменным целые значения, чтобы
//выполнялись здаданные равенства и неравенства

#include <iostream>

unsigned *p = new unsigned [100000];

void make_set (unsigned i, unsigned *p)
{
    p[i] = i;
}

unsigned find_set (unsigned i, unsigned *p)
{
    if (i == p[i])
        return i;
    return p[i] = find_set (p[i], p);
}

void union_sets (unsigned a, unsigned b, unsigned *parent)
{
    if (a != b)
    {
        parent[b] = a;
    }
}

int main()
{
    unsigned n, e, d;
    bool check = true;
    std::cin >> n >> e >> d;

    for (unsigned i = 0; i < n; ++i)
        make_set(i, p);

    for (unsigned i = 0; i < e; ++i)
    {
        unsigned x, y;
        std::cin >> x >> y;
        union_sets(x, y, p);
    }

    for (unsigned i = 0; i < d; ++i)
    {
        unsigned x, y;
        std::cin >> x >> y;
        if (x == y)
        {
            check = false;
            break;
        }
        else if (find_set(x, p) == find_set(y, p))
        {
            check = false;
            break;
        }
    }   
    delete [] p;
    std::cout << check;
    return 0;
}
