class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        for(char ch :s){
            if(ch !=')'){
                st.push(ch);
            }else{
                string temp;
                while(st.top() != '(' ){
                    temp.push_back(st.top());
                    st.pop();
                }
         st.pop();
        for(char ch : temp){
            st.push(ch);
        }
            }
 

        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};