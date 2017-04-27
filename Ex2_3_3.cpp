//Реализация системы непересекающихся множеств - disjoint set union (DSU)
//задано n - таблиц, в каждой из которых r_i элементов. Производится m объединений
//вывести максимальной число элементов среди получившихся таблиц
#include <iostream>
#include <algorithm>
#include <vector>

int *parent = new int [100000];//массив индексов родителей

void make_set (int i)//создать множество
{
    parent[i] = i;
}

int find_set (int i)//вывод индекса множества, которому принадлежит элемент
                    //(индекс элемента без родителей)
{
    if (i == parent[i])
        return i;
    return parent[i] = find_set (parent[i]);
}

void union_sets (int a, int b)//объединение множеств
{
    a = find_set(a);
    b = find_set(b);
    if (a != b) parent[b] = a;
}

int main()
{
    int n, m, max = 0;
    std::vector <int> records;//для хранения числа строк в i+1 таблице
    std::cin >> n >> m; //n - число таблиц, m - число слияний

    for (int i = 0; i < n; ++i) //считываем и записиваем число строк в n - таблицах
    {
        int rec;
        std::cin >> rec;
        records.push_back(rec);
        if (rec > max) max = rec;
        make_set(i+1); //потому что разная индексация (0...n-1) и (1...n)
    }

    for (int i = 1; i <= m; ++i)
    {
        int d, s;
        std::cin >> d >> s;
        if (find_set(d) != find_set(s))//если таблицы в разных множествах
        {
            records[find_set(d)-1] += records[find_set(s)-1];
            union_sets (d, s);
            if (records[find_set(d)-1] > max) max = records[find_set(d)-1];
        }

        std::cout << max << '\n';//выводим максимальный размер таблицы
    }

    delete [] parent;//удаляем массив индексов родителей
    return 0;
}

