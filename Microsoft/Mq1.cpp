/*
POSTFIX NOTATION = Reverse Polish Notation
Approach :
Start pushing into the stack until you get the valid operators(+,-,/,* ) , if at any point you get an operator just pop the top 2 elements from stack 
and push it again into the stack by doing the operation with the operator encountered.

Time complexity: O(n) - for traversing the whole string
Space complexity: O(n) - stack space
*/

class Solution {
public:
    
    int evalRPN(vector<string>& tokens) {
        
        stack<int>s;
        
        for(string &i:tokens){
            
            if(i == "+"){
                long a=s.top();
                s.pop();
                long b=s.top();
                s.pop();
                
                s.push(a+b);
            }
            else if(i == "*"){
                long a=s.top();
                s.pop();
                long b=s.top();
                s.pop();
                
                s.push(a*b);
            }
            else if(i == "-"){
                long a=s.top();
                s.pop();
                long b=s.top();
                s.pop();
                
                s.push(b-a);
            }
            else if(i == "/"){
                long a=s.top();
                s.pop();
                long b=s.top();
                s.pop();
                
                s.push(b/a);
            }
            else{
                s.push(stoi(i));
            }
        }
        return s.top();
    }
};

