#include<iostream>
#include<stack>
using namespace std;
class Stack2Queue{
    stack<int>s1,s2;
public:
    void enqueue(int x){
        s1.push(x);
        cout<<x<<" is enqueued."<<endl;

    }
    void dequeue(){
        if(s2.empty()){
            if(!s1.empty()){
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }

            }
            else{
                cout<<"Queue is empty."<<endl;
                return;
            }
        }
        cout<<s2.top()<<" is dequeued."<<endl;
        s2.pop();

    }
    void display(){
        if(s1.empty() && s2.empty()){
            cout<<"Queue is empty."<<endl;
        }  
        else {cout<<"Queue elements are: ";
        if(!s2.empty()){
            while(!s2.empty()){
                cout<<s2.top()<<" ";
                s2.pop();
            }      
    }
        if(!s1.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            while(!s2.empty()){
                cout<<s2.top()<<" ";
                s2.pop();
            } 
        }
        cout<<endl;}
            
    }
};

int main(){
    Stack2Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.dequeue();
   
    q.enqueue(30);
    q.enqueue(40);
    
    q.display();
}