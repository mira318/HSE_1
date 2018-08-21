#include <iostream>

using namespace std;
const int N = 11;
int A[N];
int main()
{
    int n, sum = 0, sum2 = 0;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> A[i];
        sum = sum + A[i];
    }
    if(n == 1)
    {
        cout << "-1";
        return 0;
    }
    if(n == 2 && A[0] == A[1])
    {
        cout << "-1";
        return 0;
    }
    int am = -1;
    while(am < n - 1)
    {
        am++;
        sum2 = A[am] + sum2;
        if(sum - sum2 != sum2)
        {
            cout << am + 1 << endl;
            for(int i = 0; i <= am; ++i)
            {
                cout << i + 1 << " ";
            }
            return 0;
        }
    }
    return 0;
}
