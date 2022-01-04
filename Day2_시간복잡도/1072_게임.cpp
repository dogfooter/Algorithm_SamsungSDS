#include <bits/stdc++.h>

#define MAX 100001
using namespace std;

long long X, Y, Z;

bool checking(long long game)
{
    long long winRate = (Y + game) * 100 / (X + game);

    if (winRate == Z)
        return true;

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> X >> Y;
    
    Z = Y * 100 / X;

    // Z가 절대 변하지 않는 경우
    if (Z == 99 || Z == 100)
    {
        cout << -1 << '\n';
        return 0;
    }
    
    long long lo = 1;
    long long hi = 1e9;
    long long answer = 1e9;

    while (lo <= hi)
    {
        long long mid = lo + (hi - lo) / 2;

        // checking() == true이면, 승률 변동 없음
        if (checking(mid))
        {
            lo = mid + 1;
        }
        else
        {
            answer = min(answer, mid);
            hi = mid - 1;
        }
    }
    cout << answer << '\n';
    
    return 0;
}