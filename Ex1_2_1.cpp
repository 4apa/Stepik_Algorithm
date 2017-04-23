#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main()
{
    string s {""};
    bool check {true};
    vector <char> v;
    vector <size_t> index;
    getline(cin, s);
    for (size_t i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            v.push_back(s[i]);
            index.push_back(i);
        }
        if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            if (v.size() == 0)
            {
                check = false;
                cout << i+1;
                break;
            }
            else if ((v.back() == '(' && s[i] != ')') || (v.back() == '{' && s[i] != '}') || (v.back() == '[' && s[i] != ']'))
            {
                check = false;
                cout << i+1;
                break;
            }
            else
            {
                v.pop_back();
                index.pop_back();
            }
        }
    }
    if (check && v.size() == 0) cout << "Success";
    if (check && v.size() != 0) cout << index.back()+1;
    return 0;
}
