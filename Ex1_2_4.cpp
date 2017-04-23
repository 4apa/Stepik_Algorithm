#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main()
{
    vector <int> stek;
    vector <int> max_stek;
    string command = "";
    int maximum = -1;
    int q;

    cin >> q;
    for (size_t i = 0; i < q; ++i)
    {
        cin >> command;
        if (command == "push")
        {
            int x;
            cin >> x;
            stek.push_back(x);
            if (x > maximum)
            {
                max_stek.push_back(x);
                maximum = x;
            }
            else max_stek.push_back(maximum);
        }
        else if (command == "pop")
        {
            stek.pop_back();
            max_stek.pop_back();
        }
        else if (command == "max" && max_stek.size() != 0)
            cout << max_stek.back() << '\n';
    }
    return 0;
}
