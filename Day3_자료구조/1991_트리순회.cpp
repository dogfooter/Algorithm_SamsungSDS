#include <bits/stdc++.h>
using namespace std;

pair<int, int> tree[26];

void preOrderTraversal(char cur)
{
    if (cur == '.')
        return;
    
    cout << cur;
    preOrderTraversal(tree[cur - 'A'].first);
    preOrderTraversal(tree[cur - 'A'].second);
}

void inOrderTraversal(char cur)
{
    if (cur == '.')
        return;
    
    inOrderTraversal(tree[cur - 'A'].first);
    cout << cur;
    inOrderTraversal(tree[cur - 'A'].second);
}

void postOrderTraversal(char cur)
{
    if (cur == '.')
        return;
    
    postOrderTraversal(tree[cur - 'A'].first);
    postOrderTraversal(tree[cur - 'A'].second);
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
    
    preOrderTraversal('A');
    cout << '\n';
    inOrderTraversal('A');
    cout << '\n';
    postOrderTraversal('A');
    cout << '\n';

    return 0;
}