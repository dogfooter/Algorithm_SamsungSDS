#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

enum OPERATOR { PUSH, POP, SIZE, EMPTY, FRONT, BACK };

vector<int> intQueue;
int N;

void push(int X)
{
    intQueue.push_back(X);
}

int pop()
{
    int num;
    
    if (intQueue.empty())
        return -1;

    reverse(intQueue.begin(), intQueue.end());
    num = intQueue.back();
    intQueue.pop_back();
    reverse(intQueue.begin(), intQueue.end());

    return num;
}

int size()
{
    return intQueue.size();
}

int empty()
{
    if (intQueue.empty()) return 1;
    else return 0;
}

int front()
{
    if (intQueue.empty())
        return -1;
    
    return intQueue.front();
}

int back()
{
    if (intQueue.empty())
        return -1;
    
    return intQueue.back();
}

int getOperator(string str)
{
    if (str.compare("push") == 0) return PUSH;
    else if (str.compare("pop") == 0) return POP;
    else if (str.compare("size") == 0) return SIZE;
    else if (str.compare("empty") == 0) return EMPTY;
    else if (str.compare("front") == 0) return FRONT;
    else if (str.compare("back") == 0) return BACK;

    return -1;
}

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;
        
        switch (getOperator(input)) {
            case PUSH:
                int X;
                cin >> X;
                push(X);
                break;
            
            case POP:
                cout << pop() << endl;
                break;
            
            case SIZE:
                cout << size() << endl;
                break;
            
            case EMPTY:
                cout << empty() << endl;
                break;
            
            case FRONT:
                cout << front() << endl;
                break;

            case BACK:
                cout << back() << endl;
                break;

            default:
                cout << "명령어 오류" << endl;
        }
    }
    
    return 0;
}