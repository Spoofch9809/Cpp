#include <iostream>
#include <queue>

using namespace std;

int main() 
{
    queue<int> myQueue;
    // Adding elements to the queue
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    // Now the queue is {10, 20, 30}, with 10 at the front
    myQueue.pop(); // Removing the front element

    // Accessing the front element
    cout << "Front element: " << myQueue.front() << endl; // Output: 10
}