#include<iostream>
using namespace std;
#include<stack>
int precedence(char ch){
    if(ch=='^') return 3;
    else if(ch=='*' || ch=='/') return 2;
    else if(ch=='+' || ch=='-') return 1;
    return 0;
}
bool isOperand(char ch){
    if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')) return true;
    return false;

}
string infixtoPostfix(string s){
    stack<char>a;
    string p="";
    for(int i=0;i<s.length();i++){
        if(isOperand(s[i])) p += s[i];
        else if(s[i]=='(') a.push(s[i]);
        else if(s[i]==')'){
            while(a.top()!='('){
                p += a.top();
                a.pop();
            }
            a.pop();
        }
        else{
            while(!a.empty() && precedence(a.top())>=precedence(s[i])){
                p += a.top();
                a.pop();
            }
            a.push(s[i]);
        }
    }
    while(!a.empty()){
        p+=a.top();
        a.pop();
    }
    return p;
}
int main(){
    string s;
    cout<<"Enter the infix expression: "<<endl;
    cin>>s;
    cout<<infixtoPostfix(s)<<endl;
    return 0;
}