// we use monotonic stack as a greedy approach
#include <bits/stdc++.h>
using namespace std;
 string smallestSubsequence(string s) {
        int n = s.size();
        int count[26] = {0};
        for( int i = 0 ; i < n ; i++){
            count[s[i] - 'a']++;
        }
        vector<char>st;
        bool inStack[26] = {false};
        for( int i = 0 ; i < n ; i++){
            count[s[i] - 'a']--;
            if(inStack[s[i] - 'a'])continue;

            while(!st.empty() && st.back() > s[i] && count[st.back() - 'a'] > 0){
                 inStack[st.back()-'a'] = false;  
                st.pop_back();
            }
              st.push_back(s[i]);
                 inStack[st.back()-'a'] = true;
        }
           string ans = "";
        for(char ch : st)
            ans += ch;

        return ans;
    }
    // time complexity = O(n);
    // space complexity = O(1) no extra space use 
    int main()
    {
          
    string s;
    cin >> s;
    cout << smallestSubsequence(s) << endl;
    return 0;
    }