#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    long long x, y, mincost;
    bool was = 0;
    string S;
    cin >> n >> x >> y >> S;
    int group = 0;
    for(int i = 0; i < n; ++i)
    {
        if(S[i] == '0' && !was)
        {
            group++;
            was = 1;
        }
        if(S[i] == '1')
        {
            was = 0;
        }
    }
    mincost = max(x * n, y * n);
    if(group == 0)
    {
        cout << "0";
        return 0;
    }
    for(int j = 1; j <= group; ++j)
    {
        if(mincost >= j * y + x * (group - j))
        {
            mincost = j * y + x * (group - j);
        }
    }
    cout << mincost;
    return 0;
}
