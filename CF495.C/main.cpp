#include <iostream>

using namespace std;
const int N = (int)1e5 + 7;
int A[N];
bool Was[N];
long long Post[N];
int main()
{
    int n;
    long long ans = 0;
    cin >> n;
    if(n == 1)
    {
        cout << 0;
        return 0;
    }
    for(int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
    for(int i = 0; i < N; ++i)
    {
        Was[i] = false;
    }
    Post[n - 1] = 1;
    Was[A[n - 1]] = 1;
    for(int i = n - 2; i >= 0; --i)
    {
        Post[i] = Post[i + 1];
        if(!Was[A[i]])
        {
            Post[i]++;
            Was[A[i]] = true;
        }
    }
    for(int i = 0; i < N; ++i)
    {
        Was[i] = false;
    }
    for(int i = 0; i < n - 1; ++i)
    {
        if(!Was[A[i]])
        {
            ans = ans + Post[i + 1];
            Was[A[i]] = true;
        }
    }
    cout << ans;
    return 0;
}
