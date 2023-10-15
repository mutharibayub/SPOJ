#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>

using namespace std;

typedef long long ll;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            cin>>arr[i];
        vector<int> tarr = arr;
        map<int, int> acc;
        map<int, int> total;
        for(int i=0; i<n; i++)
        {
            for(int j=2; j*j <= arr[i]; j++)
            {
                if(arr[i]%j == 0)
                {
                    while(arr[i]%j == 0)
                    {
                        total[j]++;
                        arr[i] /= j;
                    }
                }
            }
            if(arr[i] > 1)
                total[arr[i]]++;
        }
        bool ok = true;
        for(auto [val, cnt]: total)
        {
            if(cnt%n != 0)
            {
                ok = false;
                break;
            }
        }
        cout << (ok?"YES":"NO") << '\n';
    }
    return 0;
}