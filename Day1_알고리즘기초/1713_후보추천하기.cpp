#include <bits/stdc++.h>

#define endl '\n'
#define MAX 21
using namespace std;

struct info
{
    int thumb;      // 추천 수
    int order;      // 사진의 오래된 정도

    bool operator<(const info& rhs) const
    {
        if (thumb == rhs.thumb)
            return order < rhs.order;
        else
            return thumb < rhs.thumb;
    }
};

map<int, info> candidate;
int N, M;
int cnt;

bool compareToDelete(const pair<int, info> &A, const pair<int, info> &B)
{
    if (A.second.thumb == B.second.thumb)
        return A.second.order < B.second.order;
    
    return A.second.thumb < B.second.thumb;
}

void solve(int r)
{
    // 현재 사진이 게시된 학생이 추천받은 경우
    if (candidate.count(r) > 0) 
    {
        candidate[r].thumb++;
        return;
    }

    // 비어있는 사진틀이 없는 경우
    if (candidate.size() == N)
    {
        vector<pair<int, info>> v(candidate.begin(), candidate.end());
        sort(v.begin(), v.end(), compareToDelete);
        candidate.erase(v.front().first);
    }
    
    candidate.insert({r, {1, cnt++}});
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int r;
        cin >> r;
        solve(r);
    }

    vector<pair<int, info>>::iterator it;
    vector<pair<int, info>> v(candidate.begin(), candidate.end());
    sort(v.begin(), v.end());
    for (it = v.begin(); it != v.end(); it++)
        cout << it->first << ' ';

    return 0;
}
