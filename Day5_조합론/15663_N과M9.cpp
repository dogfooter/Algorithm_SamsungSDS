#include <bits/stdc++.h>

using namespace std;

set<vector<int>> answerList; // 중복 제거
vector<int> selectList;
vector<int> numList;
vector<bool> visited;
int N, M;

void backtracking(int depth)
{
    if (depth == M) {
        answerList.insert(selectList);
        return;
    }

    for (int i=0; i<N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            selectList.push_back(numList[i]);
            backtracking(depth+1);
            visited[i] = false;
            selectList.pop_back();
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> N >> M;    
    for (int i=0; i<N; i++) {
        int num; cin >> num;
        numList.push_back(num);
        visited.push_back(false);
    }

    sort(numList.begin(), numList.end());
    backtracking(0);
    
    for (auto answer : answerList) {
        for (auto n : answer)
            cout << n << ' ';
        cout << '\n';
    }
    return 0;
}