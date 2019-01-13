#include <bits/stdc++.h>

using namespace std;

bool dp[10001][1001] = {false}; // dp[i][j] is true if possible to sum any collection of j elems to i

string solution(vector<int> chocs,int n,int m){
    string ans="NO"; // if m can be formed using sum of any nums in chocs;

    for(int i=1;i<=m;i++){
        dp[i][0] = false;
    }
    for(int i=0;i<=n;i++){
        dp[0][i] = true;
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            bool x=false,y=false;
            x = dp[i][j-1];
            if(i-chocs[j-1]>=0){
                y = dp[i-chocs[j-1]][j-1];
            }
            dp[i][j] = x || y;
        }
    }
    if(dp[m][n]){
        ans = "YES";

    }
    return ans;
}

int main() {
    int t;
    cin >> t;

    while(t--){
        int n;
        cin>>n;
        vector<int> chocs(n);
        for (int i = 0; i < n; i++) {
            int arr_item;
            cin>>arr_item;
            chocs[i] = arr_item;
        }
        int m;
        cin>>m;
        cout<<solution(chocs,n,m)<<endl;
    }

    return 0;
}

