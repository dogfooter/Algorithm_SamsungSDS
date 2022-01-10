#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;
long long arr[MAX];
long long tree[MAX*4];

long long makeTree(int node, int start, int end)
{
    if (start == end)
        return tree[node] = arr[start];
    
    long long mid = (start + end) / 2;

    // 구간을 두 부분으로 재귀적으로 나눈 후, 그 합을 리턴
    return tree[node] = makeTree(node * 2, start, mid) + makeTree(node * 2 + 1, mid + 1, end);
}

long long sectionSum(int node, int start, int end, int left, int right)
{
    // 범위 내에 없는 경우
    if (left > end || right < start)
        return 0;
    
    // 범위 내에 있는 경우 노드의 값 리턴
    if (left <= start && end <= right)
        return tree[node];

    // 범위에 걸친 경우 나누어 합을 구하기
    long long mid = (start + end) / 2;
    return sectionSum(node * 2, start, mid, left, right) + sectionSum(node * 2 + 1, mid + 1, end, left, right);
}

void updateTree(int node, int start, int end, int idx, int val)
{
    if (idx < start || idx > end)
        return;
    
    if (start == end)
    {
        tree[node] = val;
        return;
    }

    long long mid = (start + end) / 2;
    updateTree(node * 2, start, mid, idx, val);
    updateTree(node * 2 + 1, mid + 1, end, idx, val);
    
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
    
    return;
}

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    makeTree(1, 1, N);

    for (int i = 1; i <= Q; i++)
    {
        int X, Y, A, B;
        cin >> X >> Y >> A >> B;

        // X ~ Y의 합을 출력
        if (X <= Y)
            cout << sectionSum(1, 1, N, X, Y) << '\n';
        else if (X > Y)
            cout << sectionSum(1, 1, N, Y, X) << '\n';

        // A 번째 수를 B로 변경
        updateTree(1, 1, N, A, B);
    }

    return 0;
}