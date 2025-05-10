#include <iostream>
using namespace std;
#define MAX 100

class Queue{
    public:
    int front =-1; int rear =-1;
    int arr[MAX];
    
     bool isEmpty(){
        if(rear == -1 || front>rear) return true;
        return false;
    }
    bool isFull(){
        if(rear==MAX-1) return true;
        return false;
    }
    void enqueue(int x){
        if(isFull()){
            cout<<"Queue is full."<<endl;
        }
        else{
            if(front == -1) {front++;}
            rear++;
            arr[rear] = x;
            cout<<x<<"is enqueued."<<endl;
        }
    }
    void dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty."<<endl;
        }
        else{
            cout<<arr[front]<<" is dequeued."<<endl;
            front++;
        }
    }
    int frontElement(){
        if(isEmpty()){
            cout<<"Queue is empty."<<endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }
    int rearElement(){
        if(isEmpty()){
            cout<<"Queue is empty."<<endl;
            return -1;
        }
        else{
            return arr[rear];
        }
    }
};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.enqueue(10);
    cout<<"THE QUEUE IS: "<<endl;
    while(!q.isEmpty()){
        cout<<q.arr[q.front]<<" ";
        q.front++;
    }

}


