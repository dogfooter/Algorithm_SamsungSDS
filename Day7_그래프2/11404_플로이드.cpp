#include <iostream>

#define INF 987654321
#define MAXN 101

using namespace std;

int N, M;
int a, b, c;
int floyd[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cin >> M;

    fill(&floyd[0][0], &floyd[MAXN-1][MAXN-1], INF);
    for (int i = 0; i <= N; i++)
        floyd[i][i] = 0;

    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        floyd[a][b] = min(floyd[a][b], c);  // 여러 경로가 있을 수 있기 때문에 최소 값만 취함
    }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << (floyd[i][j] == INF ? 0 : floyd[i][j]) << ' ';
        }
        cout << '\n';
    }

    return 0;
}