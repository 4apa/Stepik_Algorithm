#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue <pair <long int, long int>> a;
    long int p {0}, n {0}, t {0}; //число процессоров, число процессов, время на выполнение процесса

    cin >> p >> n;

    if (p >= n) //если процессоров больше, чем процессов
    {
        for (long int i = 0; i < n; ++i)
        {
            cin >> t;
            cout << i << " " << 0 << '\n';
        }
    }

    else
    {
        for (long int i = 0; i < p; ++i)
        {
            cin >> t;
            a.push(make_pair(-t, -i));//записываем отрицательные значения, чтобы top() мог вывести минимум 
            cout << i << " " << 0 << '\n';
        }


        for (long int i = p; i < n; ++i)
        {
            pair <long int,long int> buf;
            cin >> t;
            buf = a.top();//вытаскиваем процесс, который завершится раньше всех
            a.pop();
            a.push(make_pair(buf.first-t, buf.second));
            cout << -buf.second << " " << -buf.first << '\n'; //восстанавливаем знак
        }
    }
    return 0;
}
