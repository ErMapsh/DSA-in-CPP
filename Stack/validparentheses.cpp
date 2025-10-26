class Solution {
public:
    bool isValid(string s) {
      stack<char> st;
      if(s.length()==1 && (s[0]=='(' || s[0]=='[' ||s[0]=='{' || s[0]==')' || s[0]==']' ||s[0]=='}')){
        return false;
      }
      for(int i=0;i<s.length();i++){
       
           if(s[i]=='(' || s[i]=='[' ||s[i]=='{'  ){
            st.push(s[i]);
           }
            if(st.empty()){
            return false;
        }
           if((s[i]==')' && st.top()=='(') || (s[i]==']' && st.top()=='[') || (s[i]=='}' && st.top()=='{')){
            st.pop();
           }
           else if(s[i]==')' || s[i]==']' || s[i]=='}'){
            return false;
           }
         
 


      }
      if(st.empty())
      {
        return true;
      }
      return false;
    }
};