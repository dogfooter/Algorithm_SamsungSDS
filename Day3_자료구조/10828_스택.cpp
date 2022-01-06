#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

enum OPERATOR { PUSH, POP, SIZE, EMPTY, TOP };

vector<int> intStack;
int N;

void push()
{   
    int X; cin >> X;
    intStack.push_back(X);
}

int pop()
{
    int num;
    
    if (intStack.empty())
        return -1;

    num = intStack.back() ;
    intStack.pop_back();
    return num;
}

int size()
{
    return intStack.size();
}

int empty()
{
    if (intStack.empty()) return 1;
    else return 0;
}

int top()
{
    if (intStack.empty())
        return -1;
    
    return intStack.back();
}

int getOperator(string str)
{
    if (str.compare("push") == 0) return PUSH;
    else if (str.compare("pop") == 0) return POP;
    else if (str.compare("size") == 0) return SIZE;
    else if (str.compare("empty") == 0) return EMPTY;
    else if (str.compare("top") == 0) return TOP;

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
                push();
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
            
            case TOP:
                cout << top() << endl;
                break;
            
            default:
                cout << "명령어 오류" << endl;
        }
    }
    return 0;
}