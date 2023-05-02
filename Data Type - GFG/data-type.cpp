//{ Driver Code Starts
// Initial Template for C++

// {Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dataTypeSize(string str) {
        int a;
        if(str[0] == 'c' || str[0] == 'C'){
            a = sizeof(char);
        }
        else if(str[0] == 'I' || str[0] == 'i'){
            a = sizeof(int);
        }
        else if(str[0] == 'L' || str[0] == 'l'){
            a = sizeof(long);
        }
        else if(str[0] == 'F' || str[0] == 'f'){
            a = sizeof(float);
        }
        else if(str[0] == 'D' || str[0] == 'd'){
            a = sizeof(double);
        }
        return a;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.dataTypeSize(str);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends