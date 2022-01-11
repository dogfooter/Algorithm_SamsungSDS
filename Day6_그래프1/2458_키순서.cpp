#include <iostream>

#define INF 987654321
#define MAXN 501

using namespace std;

int N, M;
int a, b;

int floyd[MAXN][MAXN];
int check[MAXN];
int answer;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    // 그래프 연결관계 표현 (floyd[a][b] > 0 이면, a와 b 사이에 간선 존재)
    for (int i = 0; i < M; i++) {
        int a, b;  cin >> a >> b;
        floyd[a][b] = 1;
    }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++) {
                if (floyd[i][k] > 0 && floyd[k][j] > 0) {
                    floyd[i][j] = 1;
                }
            }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (floyd[i][j] > 0) check[i]++; // i가 j보다 작다는 것을 알 수 있음
            if (floyd[j][i] > 0) check[i]++; // i가 j보다 크다는 것을 알 수 있음
        }
    }

    for (int i = 1; i <= N; i++) {
        if (check[i] == N-1) answer++;
    }
    cout << answer;

    return 0;
}