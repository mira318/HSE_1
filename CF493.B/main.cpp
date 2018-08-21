#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 107;
vector<int> Cost;
int A[N];
int main()
{
    int n, B, balance = 0, ans = 0;
    cin >> n >> B;
    for(int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
    for(int i = 0; i < n - 1; ++i)
    {
        if(A[i] % 2 == 0)
        {
            balance++;
        }
        else
        {
            balance--;
        }
        if(balance == 0)
        {
            Cost.push_back(abs(A[i + 1] - A[i]));
        }
    }
    sort(Cost.begin(), Cost.end());
    int i = 0;
    while(B >= 0 && i < Cost.size())
    {
        if(B >= Cost[i])
        {
            B = B - Cost[i];
            i++;
            ans++;
        }
        else
        {
            cout << ans;
            return 0;
        }
    }
    cout << ans;
    return 0;
}
