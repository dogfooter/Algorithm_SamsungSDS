#include <bits/stdc++.h>

#define MAXN 1001
using namespace std;

struct Data {
    int n, w;
    Data() {};
    Data(int n, int w) : n(n), w(w) {};
    bool operator<(const Data d) const {
        return w > d.w;
    }
};

int N, M;
int a, b, c;
bool isVisited[MAXN];
vector<Data> v[MAXN];
priority_queue<Data> pq;
int answer;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        v[i].clear();
        isVisited[i] = false;
    }

    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        v[a].push_back(Data(b, c));
        v[b].push_back(Data(a, c));
    }

    pq.push(Data(1, 0));
    answer = 0;

    for (int i = 0; i < N; i++) {
        Data d;
        while (true) {
            if (pq.empty()) break;
            d = pq.top();
            if (isVisited[d.n]) {
                pq.pop();
            }
            else {
                break;
            }
        }
        answer += d.w;
        isVisited[d.n] = true;
        for (int j = 0; j < v[d.n].size(); j++) {
            pq.push(v[d.n].at(j));
        }
    }

    cout << answer << endl;

    return 0;
}