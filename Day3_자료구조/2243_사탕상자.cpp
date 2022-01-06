#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001; // 사탕의 맛 개수
int tree[MAX * 4];
int answer;

int findCandy(int node, int start, int end, int k)
{ 
    if (start == end)
        return end;
    
    int mid = (start + end) / 2;
    if (tree[node * 2] >= k)
        return findCandy(node * 2, start, mid, k);
    else
        return findCandy(node * 2 + 1, mid + 1, end, k - tree[node * 2]);
} 

void updateTree(int node, int start, int end, int idx, long long diff)
{
    if (idx < start || idx > end)
        return;

    tree[node] += diff;
    
    if (start != end)
    {
        int mid = (start + end) / 2;
        updateTree(node * 2, start, mid, idx, diff);
        updateTree(node * 2 + 1, mid + 1, end, idx, diff);
    }
}

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;  cin >> N;

    for (int i = 0; i < N; i++)
    {
        int A, B, C;
        cin >> A;
        switch (A)
        {
            // 사탕을 꺼내는 경우
            case 1:
                cin >> B;
                answer = findCandy(1, 1, MAX, B);
                cout << answer << '\n';
                updateTree(1, 1, MAX, answer, -1);
                break;

            // 사탕을 넣는 경우
            case 2:
                cin >> B >> C;
                updateTree(1, 1, MAX, B, C);
                break;
        }
    }

    return 0;
}