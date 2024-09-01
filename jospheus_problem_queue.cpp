/*#include<iostream>
using namespace std;

struct node{

    int player_id;
    struct node *next;

};
struct node *start,*ptr,*new_node;

int main(){

int n,k,i,count;
cout<<"enter the number of players"<<endl;
cin>>n;
cout<<"enter the value of k(every kth player gets eliminated)"<<endl;
cin>>k;

start = new node;
start->player_id=1;
ptr=start;
for(int i=2;i<=n;i++){
    new_node = new node;
    ptr->next=new_node;
    new_node->player_id=i;
    new_node->next=start;
    ptr=new_node;
}
for(count=n;count>1;count--){
    for(i=0;i<k-1;++i)
        ptr=ptr->next;
    ptr->next=ptr->next->next;
}
cout<<"the winner is player: "<<ptr->player_id<<endl;


return 0;
}
*/

#include <iostream>
using namespace std;

class Node {
public:
    int player_id;
    Node* next;

    Node(int id) : player_id(id), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Function to enqueue (add) an element to the queue
    void enqueue(int player_id) {
        Node* new_node = new Node(player_id);
        if (rear == nullptr) {
            front = rear = new_node;
        } else {
            rear->next = new_node;
            rear = new_node;
        }
    }

    // Function to dequeue (remove) an element from the queue
    int dequeue() {
        if (front == nullptr) {
            cout << "Queue underflow, no players to remove." << endl;
            return -1;
        }
        Node* temp = front;
        int player_id = front->player_id;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr; // If the queue becomes empty
        }
        delete temp;
        return player_id;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to rotate the queue by moving the front element to the rear
    void rotateQueue() {
        if (!isEmpty()) {
            enqueue(dequeue());
        }
    }

    // Function to get the front element (used to determine the winner)
    int getFront() {
        if (!isEmpty()) {
            return front->player_id;
        }
        return -1;
    }
};

int main() {
    int n, k;
    cout << "Enter the number of players: ";
    cin >> n;
    cout << "Enter the value of k (every k-th player gets eliminated): ";
    cin >> k;

    Queue gameQueue;

    // Initialize the queue with player IDs
    for (int i = 1; i <= n; i++) {
        gameQueue.enqueue(i);
    }

    // Eliminate players until only one remains
    while (!gameQueue.isEmpty() && gameQueue.getFront() != gameQueue.dequeue()) {
        // Rotate the queue k-1 times
        for (int i = 1; i < k; i++) {
            gameQueue.rotateQueue();
        }
        // Eliminate the k-th player
        gameQueue.dequeue();
    }

    // The last remaining player is the winner
    cout << "The winner is player: " << gameQueue.getFront() << endl;

    return 0;
}
