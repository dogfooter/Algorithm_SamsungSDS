#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

const int MAX = 51;
vector<string> mapInfo;
vector<int> mapHeight[MAX];
vector<int> v;  // two pointer algorithm
bool visited[MAX][MAX];

int N;
int houseCnt;       // 배달해야하는 집 갯수
int sr, sc;         // 우체국의 위치(시작점)
int answer = 1e9;   // 정답

int dr[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dc[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void dfs(int r, int c, int& minH, int& maxH, int& visitCnt)
{
    // 지도 바깥을 방문하였을 경우
    if (r < 0 || r >= N || c < 0 || c >= N)
        return;

    // 범위 내가 아닌 경우
    if (mapHeight[r][c] < minH || mapHeight[r][c] > maxH)
        return;

    // 이미 방문한 경우
    if (visited[r][c])
        return;

    visited[r][c] = true;
    if (mapInfo[r][c] == 'K')
        visitCnt++;
        
    for (int i = 0; i < 8; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        dfs(nr, nc, minH, maxH, visitCnt);
    }        

    return;
}

bool canGo(int minH, int maxH)
{
    // visit 초기화
    memset(visited, 0, sizeof(visited));
    
    int visitCnt = 0;
    dfs(sr, sc, minH, maxH, visitCnt);
    
    if (visitCnt == houseCnt)
        return true;
    
    return false;
}

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string temp = "";
        for (int j = 0; j < N; j++)
        {
            char input;
            cin >> input;
            if (input == 'P')
            {
                sr = i;
                sc = j;
            }
            
            if (input == 'K')
                houseCnt++;

            temp.push_back(input);
        }
        mapInfo.push_back(temp);
    }

    int minH = 1e9;
    int maxH = 0;
    int minHIdx, maxHIdx;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int input;
            cin >> input;

            if (mapInfo[i][j] == 'P' || mapInfo[i][j] == 'K')
            {
                maxH = max(maxH, input);
                minH = min(minH, input);
            }
            mapHeight[i].push_back(input);
            v.push_back(input);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == minH) minHIdx = i;
        if (v[i] == maxH) maxHIdx = i;
    }

    // two-pointer
    int lp = 0;
    int rp = maxHIdx;
    while (rp < v.size())
    {
        while (lp <= minHIdx)
        {
            if (!canGo(v[lp], v[rp]))
                break;

            // 만족하면 lp를 더해 범위를 좁힌다 
            answer = min(answer, v[rp] - v[lp]);
            lp++;
        }
        
        // 만족할 수 없으면 rp를 더해 범위를 늘린다
        rp++;
    }
    
    cout << answer << endl;

    return 0;
}