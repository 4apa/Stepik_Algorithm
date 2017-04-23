//maximum in sliding window (Van Herk algorithm)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n;
    vector <int> v;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cin >> m;
    --m;
    if (m == 0)
    {
        for (auto now : v) cout << now << " ";
    }

    else
    {
        vector <int> fw_max (n);
        vector <int> bw_max (n);

        for (int i = 0; i < n; ++i)
        {
            if (i%m != 0)
                fw_max[i] = max (fw_max[i-1], v[i]);
            else fw_max[i] = v[i];
        }

        for (int i = n-1; i >= 0; --i)
        {
            if ((i+1)%m != 0)
                bw_max[i] = max (bw_max[i+1], v[i]);
            else bw_max[i] = v[i];
        }

        for (int i = 0; i < n-m; ++i)
            cout << max (bw_max[i], fw_max[m+i]) << " ";
    }
    return 0;
}

