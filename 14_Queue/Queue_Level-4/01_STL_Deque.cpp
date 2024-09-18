#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    dq.push_front(10);
    dq.push_front(20);

    dq.push_back(15);
    dq.push_back(25);

    cout << "Front element of dqueue: " << dq.front() << endl;
    cout << "Rear element of dqueue: " << dq.back() << endl;
    cout << "Size of dqueue: " << dq.size() << endl;
    cout << endl;

    dq.push_front(30);
    dq.push_back(45);
    dq.push_front(40);
    dq.push_back(35);

    dq.pop_front();
    dq.pop_back();

    cout << "Front element of dqueue: " << dq.front() << endl;
    cout << "Rear element of dqueue: " << dq.back() << endl;
    cout << "Size of dqueue: " << dq.size() << endl;

    return 0;
}