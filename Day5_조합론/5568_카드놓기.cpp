#include <bits/stdc++.h>

using namespace std;

unordered_set<string> mySet;
vector<int> cards;
vector<int> selects;
vector<bool> visited;
int n, k;

void permutation(int depth)
{
    if (depth == k) {
        string makeStr;
        string temp;
        
        for (auto it : selects) {
            temp = to_string(it);
            makeStr += temp;
        }
        mySet.insert(makeStr);
        
        return;
    }

    for (int i = 0; i < n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            selects.push_back(cards[i]);
            permutation(depth + 1);
            visited[i] = false;
            selects.pop_back();
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        cards.push_back(num);
        visited.push_back(false);
    }

    permutation(0);
    cout << mySet.size();
    
    return 0;
}