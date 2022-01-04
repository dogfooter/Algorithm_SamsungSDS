#include <bits/stdc++.h>

#define MAX 1000001
using namespace std;

int N, M;
long long answer;
long long tree[MAX];

bool checking(long long height)
{
    long long sum = 0;
    for (int i = 1; i <= N; i++)
    {   
        if (tree[i] - height > 0)
            sum += (tree[i] - height);
    }

    // 합이 M보다 크면 절단기 높이 올리고, 작으면 절단기 높이 낮춤
    if (sum >= M)
        return true;
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++)
        cin >> tree[i];

    sort(tree, tree + N);

    int lo = 0;
    int hi = 1e9;

    while (lo <= hi)
    {
        long long mid = lo + (hi - lo) / 2;
        if (checking(mid))
        {
            answer = max(answer, mid);
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    cout << answer;

    return 0;
}