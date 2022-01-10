#include <bits/stdc++.h>

#define MAXN 1000001
using namespace std;

int n, m;
int parent[MAXN];
int cmd, a, b;

void init()
{
    // 자기 자신을 부모로 초기화
    for (int i = 0; i <= n; i++)
        parent[i] = i;
}

int find(int x)
{   
    // 부모 노드를 반환
    if (x == parent[x])
        return x;
    
    // 경로 압축 및 부모 탐색
    return parent[x] = find(parent[x]);
}

void unite(int x, int y)
{
    // 1. x의 부모를 y의 부모로 연결 
    // 2. 경로 압축
    parent[find(x)] = find(y);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    init();
    for (int i = 0; i < m; i++) {
        cin >> cmd >> a >> b;
        switch (cmd) {
            case 0:
                unite(a, b);
                break;
            
            case 1:
                if (find(a) == find(b)) {
                    cout << "YES" << '\n';
                }
                else if (find(a) != find(b)) {
                    cout << "NO" << '\n';
                }
                break;
        }
    }
    return 0;
}