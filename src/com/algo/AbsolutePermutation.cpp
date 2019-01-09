#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
Problem : https://www.hackerrank.com/challenges/absolute-permutation/problem
*/
vector<int> absolutePermutation(int n, int k) {
    vector<int> result;
    if(k!=0 && (n%(2*k))!=0 ){
        return vector<int>(1,-1);
    }
    else if(k==0){
        for(int i=1;i<=n;i++)
            result.push_back(i);
        return result;
    }
    else{
        bool add = true;
        for(int i=1;i<=n;i++){
            int t1 = i+k;
            int t2 = i-k;
            if(add)
                result.push_back(t1);
            else
                result.push_back(t2);
            if((i%k)==0)
                add = !add;
        }
        return result;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nk_temp;
        getline(cin, nk_temp);

        vector<string> nk = split_string(nk_temp);

        int n = stoi(nk[0]);

        int k = stoi(nk[1]);

        vector<int> result = absolutePermutation(n, k);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

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
