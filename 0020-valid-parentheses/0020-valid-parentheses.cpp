class Solution {
public:
    bool isValid(string s) {
         stack<char> st;
        string x=s;
        for(int i=0; i<x.length(); i++){
            char a = x[i];
            if(a == '[' || a == '(' || a == '{'){
                st.push(a);
            }
            else{
                if(st.empty()){
                    return false;
                }
                else{
                    char t = st.top();        // for the top element of the stack
                    if(t == '(' && a == ')' || t == '[' && a == ']' || t == '{' && a == '}'){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return st.empty();
    }
};