#include <queue>
#include <iostream>
using namespace std;
int main()
{
	int max_size, n, time {0};
	cin >> max_size >> n; //максимальный размер буфера и число пакетов
    queue <pair<int, int>> buffer; 
	for(int i = 0; i < n; ++i)
        {
		int arrive, duration; //время прибытия пакета и время на обработку
		cin >> arrive >> duration;
        while(!buffer.empty() && buffer.front().first <= arrive) //выводим из буфера все, что обработано к моменту прихода пакета
            {
			cout << buffer.front().first - buffer.front().second << '\n'; //время начала обработки
			if (buffer.front().first >= 0) max_size += 1; //освобождаем место в буфере
            buffer.pop();
		    }

		if(max_size <= 0) //если места в буфере нет
        {
			buffer.push({-1, 0});
        }
        else
        {
			if(time <= arrive)
				time = arrive + duration;
			else
				time += duration;
			buffer.push({time, duration});
			--max_size; //занимаем место в буфере
		}
	}
	while(!buffer.empty()) // выводим то, что осталось в буфере
        {
		cout << buffer.front().first - buffer.front().second << '\n';
		buffer.pop();
	}
	return 0;
}
