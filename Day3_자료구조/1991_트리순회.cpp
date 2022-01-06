#include <bits/stdc++.h>
using namespace std;

pair<int, int> tree[26];

void preOrder(char cur)
{
    if (cur == '.')
        return;
    
    cout << cur;
    preOrder(tree[cur - 'A'].first);
    preOrder(tree[cur - 'A'].second);
}

void inOrder(char cur)
{
    if (cur == '.')
        return;
    
    inOrder(tree[cur - 'A'].first);
    cout << cur;
    inOrder(tree[cur - 'A'].second);
}

void postOrder(char cur)
{
    if (cur == '.')
        return;
    
    postOrder(tree[cur - 'A'].first);
    postOrder(tree[cur - 'A'].second);
    cout << cur;
}

int main(void)
{
    ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);
    int N;
    char parent, leftChild, rightChild;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> parent >> leftChild >> rightChild;
        tree[parent - 'A'] = { leftChild, rightChild };
    }
    
    preOrder('A');
    cout << '\n';
    inOrder('A');
    cout << '\n';
    postOrder('A');
    cout << '\n';

    return 0;
}