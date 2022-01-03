#include <bits/stdc++.h>

#define endl '\n'
#define MAX 51
using namespace std;

vector<string> V;
bool visited[MAX][MAX];
int DP[MAX][MAX];
int N, M;
int answer;

// 4가지 방향(오른쪽, 왼쪽, 아래쪽, 위쪽)
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

bool DFS(int r, int c, int count) 
{
    // 무한으로 움직이는 경우(cycle)
    if (answer == -1)
        return true;

    answer = max(answer, count);
    visited[r][c] = true;
    DP[r][c] = count;

    for (int i = 0; i < 4; i++) 
    {
        int nr = r + dr[i] * (V[r][c] - '0');
        int nc = c + dc[i] * (V[r][c] - '0');

        if (nr < 0 || nr >= N || nc < 0 || nc >= M || V[nr][nc] == 'H')
            continue;
        
        // 방문한 곳에 또 방문하려 한다면 무한으로 움직일 수 있음(cycle)
        if (visited[nr][nc])
        {
            answer = -1;
            return true;
        }

        // 이미 계산된 것은 DP테이블에 기록되있음
        // DP의 값이 count보다 크다면 진행할 필요 없음
        if (DP[nr][nc] > 0 && DP[nr][nc] > count)
            continue;
        
        // 무한으로 움직이는 경우 true 리턴
        if (DFS(nr, nc, count + 1))
            return true;
    }

    // 방문했던 기록을 초기화
    visited[r][c] = false;
    return false;
}

void Input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;
        V.push_back(input);
    }
}

void Solution()
{   
    // (0, 0) 에서 출발
    DFS(0, 0, 1);
    cout << answer << endl;
}

void Solve()
{
    Input();
    Solution();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Solve();    
    return 0;
}
