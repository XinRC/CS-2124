// queue
#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);

    cout << "FRONT: " << queue.front() << ", BACK: " << queue.back() << endl;
    queue.pop();
    cout << "FRONT: " << queue.front() << ", BACK: " << queue.back() << endl;
}