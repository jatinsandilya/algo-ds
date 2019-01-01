#include <bits/stdc++.h>

using namespace std;

/*
    Problem : https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem
*/
// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> container) {

    int n = container.size();
    vector<int> sum_row,sum_col;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=0;j<n;j++){
            sum += container[i][j];
        }
        sum_row.push_back(sum);
    }
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=0;j<n;j++){
            sum += container[j][i];
        }
        sum_col.push_back(sum);
    }
    sort(sum_row.begin(),sum_row.end());
    sort(sum_col.begin(),sum_col.end());

    if(sum_col == sum_row)
        return "Possible";
    else
        return "Impossible";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
