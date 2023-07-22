class Solution {
public:
    bool isValid(string s) {
        stack<char>stack;
        if(s.size()<=1){
            return false;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[' ){
                stack.push(s[i]);
                continue;
            }
            if(!stack.empty()){
                 if(s[i]==')' && stack.top()=='('){
                     stack.pop();
                 }
                else  if(s[i]=='}' && stack.top()=='{'){
                     stack.pop();
                 }
                else  if(s[i]==']' && stack.top()=='['){
                     stack.pop();
                 }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
                 
        }
     return stack.empty();
    }
};