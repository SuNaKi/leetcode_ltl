/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& s) {
        stack<long long> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == "+" || s[i] == "-" || s[i] == "*" || s[i] == "/" )
            {
                long long n1,n2;
                n1 = st.top();
                st.pop();
                n2 = st.top();
                st.pop();
                if (s[i] == "+") st.push(n2 + n1);
                if (s[i] == "-") st.push(n2-n1);
                if (s[i] == "*") st.push(n2*n1);
                if (s[i] == "/") st.push(n2/n1);
            }
            else
            st.push(stoll(s[i]));
            
        }
   
        return st.top();
    
    }
};
// @lc code=end

