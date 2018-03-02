#include <iostream>
#include <queue>
#include <stack>

using namespace std;


int main() {
    stack<int> s;
    queue<int> q;
    priority_queue<int> p;
    for (int i = 0; i < 5; i++) {
        s.push(i); q.push(i); p.push(i);
    }
    cout << "s | q | p" << endl << "---------" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << s.top() << " | " << q.front() << " | " << p.top() << endl;
        s.pop(); q.pop(); p.pop();
    }
    
    return 0;
}
