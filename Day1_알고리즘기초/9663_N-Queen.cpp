#include <bits/stdc++.h>

#define endl '\n'
#define MAX 15
using namespace std;

int col[MAX];
int N, answer;

bool check(int row)
{
    for(int i = 0; i < row; i++)
    {   
        // 같은 열에 있는 경우 or 대각선에 있을 경우 => X
        if(col[i] == col[row] || abs(col[row] - col[i]) == row - i)
            return false;
    }
    return true;
}

void backTracking(int c)
{
    if (c == N)
    {
        answer++;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        col[c] = i;
        if (check(c))
            backTracking(c + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    backTracking(0);

    return 0;
}
