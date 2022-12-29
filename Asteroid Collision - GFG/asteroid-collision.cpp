//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        stack<int> st;
        for(auto i:asteroids) {
            if(i>0) st.push(i);
            else {
                bool need = true;
                while(!st.empty()) {
                    if(st.top()>0) {
                        if(i>0) {
                            break;
                        } else {
                            if(abs(st.top())>abs(i)) {
                                need = false;
                                break;
                            } else if(abs(st.top())<abs(i)) {
                                st.pop();
                            } else {
                                need = false;
                                st.pop();
                                break;
                            }
                        }
                    } else {
                        if(i<0) {
                            break;
                        } else {
                            if(abs(st.top())>abs(i)) {
                                need = false;
                                break;
                            } else if(abs(st.top())<abs(i)) {
                                st.pop();
                            } else {
                                need = false;
                                st.pop();
                                break;
                            }
                        }
                    }
                }
                if(need) {
                    st.push(i);
                }
            }
        }
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends