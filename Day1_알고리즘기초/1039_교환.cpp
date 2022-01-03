#include <bits/stdc++.h>
 
#define endl "\n"
#define MAX 1000000 + 1
using namespace std;
 
string answer = "0";
string N;
int K, M;

void BFS(string start) 
{
    queue<string> q;
    q.push(start);
    
    // layer를 늘려가면서 K번까지 진행
    for (int i = 0; i < K; i++)
    {
        // 각 layer에서 숫자가 중복된 것을 연산할 필요가 없음
        // 중복 계산을 막기 위해 set 활용
        set<string> s;
        int qSize = q.size();

        // 하나의 layer씩 처리
        for (int j = 0; j < qSize; j++)
        {
            string cur = q.front();
            q.pop();
            
            // 이미 Queue에 존재하면 진행할 필요 없음
            if (s.count(cur) == 1) 
                continue;  
            
            s.insert(cur);
            for (int k = 0; k < M - 1; k++) 
            {
                for (int l = k + 1; l < M; l++) 
                {
                    // 첫 번째 문자가 0이면 시작하면 안되는 예외 조건
                    if (k == 0 && cur[l] == '0')
                        continue;

                    // k, l 교환
                    char temp = cur[k];
                    cur[k] = cur[l];
                    cur[l] = temp;

                    q.push(cur);

                    // 다시 복구
                    temp = cur[k];
                    cur[k] = cur[l];
                    cur[l] = temp;
                }
            }
        }
    }

    // Queue에 남아 있는 것 중에서 가장 큰 값을 선택
    while (!q.empty()) 
    {
        answer = max(answer, q.front());
        q.pop();
    }
}

void Input()
{
    cin >> N >> K;
    M = N.length();
}

void Solution()
{
    BFS(N);
    
    if (answer.compare("0") == 0)
        cout << -1;
    else
        cout << answer;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Solve();
    return 0;
}