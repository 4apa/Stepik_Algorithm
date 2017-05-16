//Алгоритм Рабина-Карпа. Найти все вхождения строки pattern в строку text
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string pattern, text;
    cin >> pattern >> text;//считываем исходные данные
    constexpr int p = 29;
    vector <long long> p_pow (text.length());
    //считаем степени p
    p_pow[0] = 1;
    for (size_t i=1; i<p_pow.size(); ++i)
        p_pow[i] = p_pow[i-1]*p;

// хэши строки text
    vector<long long> h (text.length());
    for (size_t i=0; i<text.length(); ++i)
    {
        h[i] = (text[i] - 'a' + 1) * p_pow[i];
        if (i!=0)  h[i] += h[i-1];
    }

// хэш строки pattern
    long long h_p = 0;
    for (size_t i=0; i<pattern.length(); ++i)
        h_p += (pattern[i] - 'a' + 1) * p_pow[i];

// перебираем все подстроки text длины |pattern| и сравниваем их
    for (size_t i = 0; i + pattern.length() - 1 < text.length(); ++i)
    {
        long long cur_h = h[i+pattern.length()-1];
        if (i!=0)  cur_h -= h[i-1];
// приводим хэши к одной степени и сравниваем
        if (cur_h == h_p * p_pow[i])
            cout << i << ' '; //выводим индекс вхождения
    }
}
