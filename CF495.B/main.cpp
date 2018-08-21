#include <iostream>

using namespace std;
const int N = 100007;
int L[N];
int R[N];
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        cin >> L[i] >> R[i];
    }
    for(int i = 0; i < n; ++i)
    {
        cout << i % 2;
    }
    return 0;
}
