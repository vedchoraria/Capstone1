#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class Queue{
    public:
    Node* front;
    Node* rear;
   Queue(){
    front = rear = NULL;
   }
    bool isEmpty(){
        if(front == NULL) return true;
        return false;
    }
    void enqueue(int x){
        Node* newNode = new Node(x);
        if(isEmpty()) front = rear = newNode;
        else{
            rear->next = newNode;
            rear = newNode;
        }
        cout<<x<<" is enqueued."<<endl;
        
    } 
    void dequeue(){
        if(isEmpty()){
            cout<<"Queue is Empty.\n";
            return;
        }
        cout<<front->data<<"is dequeued."<<endl;
        Node* temp = front;
        front = front->next;
        delete temp;
        if(front == NULL) rear = NULL; // If queue becomes empty

    }
    ~Queue(){
        
        while(front != NULL){
            Node* temp = front;
            front = front->next;
            delete temp;
        }  
    }

    void display(){
        Node* temp = front;
        cout<<"Elements of Queue are : ";
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
        delete temp;

    }

};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    q.enqueue(10);
    q.dequeue();
    q.dequeue();
    q.display();
    
    
    
    

}
