#include <bits/stdc++.h>
using namespace std;

int bfs(map<int, vector<int>>& treeMap)
{
    map<int, int> check;

    // 들어오는 간선이 존재하는 경우 true
    for (auto t : treeMap)
        for (auto el : t.second)
            check[el] = 1;

    // 한번도 방문되지 않은 노드는 루트 노드
    int root = 0;
    for (auto t : treeMap)
        if (!check[t.first])
            root = t.first;
    
    check.clear();
    check[root] = 1;

    queue<int> q;
    q.push(root);

    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(int i = 0; i < treeMap[x].size(); i++){
            int nx = treeMap[x][i];
            if(check[nx] == 1)
                return 0;

            check[nx] = 1;
            q.push(nx);
        }
    }

    // 루트에서 방문하지 않는 노드가 있으면 트리가 아님
    for(auto t : treeMap)
        for(auto el : t.second)
            if(!check[el] || !check[t.first])
                return 0;

    return 1;
}

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testCase = 1;

    while (true)
    {
        map<int, vector<int>> treeMap;
        set<int> vertex;
        int edgeCnt = 0;
        int u, v;

        while (true)
        {
            cin >> u >> v;
            if (u < 0 && v < 0) return 0;
            if (u == 0 && v == 0) break;

            edgeCnt++;
            vertex.insert(u);
            vertex.insert(v);
            treeMap[u].push_back(v);     
        }
        
        // (u, v) = (0, 0)인 경우도 트리
        if (u && v && vertex.size() != edgeCnt + 1)
            cout << "Case " << testCase++ << " is not a tree." << '\n';
        else
        {
            if (bfs(treeMap))
                cout << "Case " << testCase++ << " is a tree." << '\n';
            else
                cout << "Case " << testCase++ << " is not a tree." << '\n';
        }
    }   
}