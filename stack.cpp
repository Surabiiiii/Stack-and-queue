#include <iostream>
#inlude <stack>
#include <queue>
using namespace std;
void reverseStack(stack<int> &input, stack<int> &extra) {
    //Write your code here
   while (!input.empty())
    {
        extra.push(input.top());
        input.pop();
    }
    input=extra;
    
}
void reverseQueue(queue<int> &input) {
	// Write your code here
    if(input.empty()==true)
        return;
	int x=input.front();
	input.pop();
	reverseQueue(input);
	input.push(x);
}
bool checkRedundantBrackets(string expression) {
	// Write your code here
    stack<char>s;
    string operators="+-*/";
    
    for(int i=0;i<expression.length();++i)
    {
        if(expression[i]=='('||operators.find(expression[i])!=string::npos)
        {
            s.push(expression[i]);
        } else if(expression[i]==')')
        {
            bool hasOperator =false;
            
            while(!s.empty()&&s.top()!='(')
            {
                s.pop();
                hasOperator=true;
            }
            if(!hasOperator)
            {
                return true;
            }
            
            if(!s.empty())
            {
                s.pop();
            }
        }
    }
    return false;
}
// Minimum Bracket Reversal
int countBracketReversals(string input) {
	// Write your code here
    int len=input.length();
    
    if(len==0){
        return 0;}
    
    if(len%2!=0){
        return -1;}
    
    
    stack<char>s;
    
    for(int i=0;i<len;i++)
    {
        char a=input[i];
        if(a=='{'){
            s.push(a);}
        else
        {
            
            if(!s.empty() && s.top()=='{'){
                s.pop();}
            else{
                s.push(a);}
        }
    }
    
    int count=0;
    while(!s.empty())
    {
        char c1=s.top();
        s.pop();
        char c2=s.top();
        s.pop();
        
        if(c1!=c2){
            count+=2;}
        else{
            count++;
        }
    }
    return count;
}
