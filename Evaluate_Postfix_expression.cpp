#include<iostream>
#include<stack>
using namespace std;
#include<cmath>
bool isOperand(char ch){
    if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')) return true;
    return false;

}
int evaluatePostfix(string a){
    stack<int>arr;
    for(int i=0;i<a.length();i++){
        if(isOperand(a[i])){
            arr.push(a[i]-'0');
            //-'0' is used to convert char to int
        }
        else{
            int b = arr.top();
            arr.pop();
            int c = arr.top();
            arr.pop();
            switch(a[i]){
                case '+': arr.push(c+b); break;
                case '-': arr.push(c-b); break;
                case '*': arr.push(c*b); break;
                case '/': arr.push(c/b); break;
                case '^': arr.push(pow(c,b)); break;
                default : cout<<"INVALID OPERATOR"<<endl; break; 
            }
        }
    }
    int x = arr.top();
    arr.pop();
    return x;
}

int  main(){
    string a;
    cout<<"Enter the postfix expression: ";
    cin>>a;
    cout<<evaluatePostfix(a)<<endl;
    return 0;
}