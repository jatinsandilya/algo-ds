#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
/*
    Problem : https://www.hackerrank.com/challenges/3d-surface-area/problem
*/
// Complete the surfaceArea function below.
int surfaceArea(vector<vector<int>> A) {
    int result = 0;
    int n = A.size();
    int m = A[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=1;k<=A[i][j];k++){
                if(j==0){
                    result++; // edge on left
                }
                else{
                    if(A[i][j-1] < k )
                        result++;
                }
                if(j==m-1){
                    result++; // edge on right
                }
                else{
                    if(A[i][j+1] < k )
                        result++;
                }
                if(k==1){
                    result++; // edge on bottom
                }
                if(k==A[i][j]){
                    result++; // edge on top
                }
                if(i==0){
                    result++; // edge in front
                }
                else{
                    if(A[i-1][j] < k )
                        result++;
                }
                if(i==n-1){
                    result++; // edge in back
                }
                else{
                    if(A[i+1][j] < k )
                        result++;
                }
            }
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string HW_temp;
    getline(cin, HW_temp);

    vector<string> HW = split_string(HW_temp);

    int H = stoi(HW[0]);

    int W = stoi(HW[1]);

    vector<vector<int>> A(H);
    for (int i = 0; i < H; i++) {
        A[i].resize(W);

        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = surfaceArea(A);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
