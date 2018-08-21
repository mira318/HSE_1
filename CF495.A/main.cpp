#include <iostream>

using namespace std;
const int N = 107;
long long A[N];
int main()
{
    int n, ans;
    long long d;
    cin >> n >> d;
    for(int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
    ans = 2;
    for(int i = 0; i < n - 1; ++i)
    {
        //cout << "i = " << i << endl;
        long long dist = A[i + 1] - A[i];
        if(dist == 2*d)
        {
            ans++;
        }
        if(dist > 2*d)
        {
            ans = ans + 2;
        }
        //cout << "ans = " << ans << endl;
    }
    cout << ans;
    return 0;
}
