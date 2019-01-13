#include <bits/stdc++.h>

using namespace std;


/*
    Problem : https://leetcode.com/discuss/interview-question/124720/tickets-needed-to-get-minimum-cost
    & hackerearth.
*/

int solution(vector<int> arr,int n ) {
    int expense[32] = {0};
    expense[0] = 0;
    int j = 0;
    for(int i=1;i<=30;i++){
        if(arr[j]==i){
            j++;
            int c = 0;
            if(i-7<0){
                c = 699;
            }
            else{
                c = expense[i-7]+699;
            }
            if(i-1<0){
                c = min(c,199);
            }else{
                c = min(c,199 + expense[i-1]);
            }
            if(i-30 < 0){
                c = min(c,2499);
            }else{
                c = min(c,2499 + expense[i-30]);
            }
            expense[i] = c;
        }
        else{
            expense[i]=expense[i-1];
        }
    }
    return expense[arr[n-1]];
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin>>arr_item;
        arr[i] = arr_item;
    }

    cout<<solution(arr,n)<<endl;

    return 0;
}

