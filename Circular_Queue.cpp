#include<iostream>
using namespace std;
#define MAX 100
class Circular_Queue{
    public:
    int front,rear;
    int arr[MAX];
    Circular_Queue(){
        front = -1;
        rear = -1;
    }
    bool isEmpty(){
        if(front == -1) return true;
        return false;
    }
    bool isFull(){
        if((rear+1)%MAX==front) return true;
        return false;
    }
    void enqueue(int x){
        if(isFull()){
            cout<<"Queue is full."<<endl;
        }
        else{
            if(front ==-1) front++;
            rear=(rear+1)%MAX;
            arr[rear] = x;
            cout<<x<<" is enqueued."<<endl;
        }
    }    
    void dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty."<<endl;
        }
        else{
            cout<<arr[front]<<" is dequeued."<<endl;
            front = (front+1)%MAX;
        }
    }
    // int frontElement(){
    //     if(isEmpty()){
    //         cout<<"Queue is empty."<<endl;
    //         return -1;
    //     }
    //     else{
    //         return arr[front];
    //     }
    // }
    // int rearElement(){
    //     if(isEmpty()){
    //         cout<<"Queue is empty."<<endl;
    //         return -1;
    //     }
    //     else{
    //         return arr[rear];
    //     }
    // }
    void display(){
        if(isEmpty()){
            cout<<"Queue is empty."<<endl;
        }
        else{
            cout<<"Queue elements are: ";
            for(int i=front;i!=rear;i=(i+1)%MAX){
                cout<<arr[i]<<" ";
                //cout<<i<<endl;
            }
            cout<<arr[rear]<<endl;
        }
    }
};

int main(){
    Circular_Queue q;
    q.dequeue();
    q.enqueue(10);
    
    q.enqueue(50);
    q.display();
   
    q.dequeue();
    q.enqueue(20);
    q.enqueue(30);
    q.display();
     
    
}