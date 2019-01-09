#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
Problem : https://www.hackerrank.com/challenges/almost-sorted/problem
*/

void almostSorted(vector<int> arr) {
    vector<int> sorted = arr;
    sort(sorted.begin(),sorted.end());
    if(arr==sorted){
        cout<<"yes"<<endl;
        return;
    }
    int srt_ind[1000000] = {0};
    for(int i = 0 ; i< sorted.size();i++){
        int el = sorted[i];
        srt_ind[el] = i;
    }
    vector<int> inds;
    for(int i=0;i < arr.size() ;i++){
        if( i != srt_ind[arr[i]])
            inds.push_back(i+1);
    }

    if(inds.size()>2){
        int l = inds[0]-1,r = inds[inds.size()-1]-1;
        reverse(arr.begin()+l,arr.begin()+r+1);
        if(arr == sorted){
            cout<<"yes"<<endl;
            cout<<"reverse "<<(l+1)<<" "<<(r+1)<<endl;
            return;
        }
        cout<<"no"<<endl;
        return;
    }
    else {
        cout<<"yes"<<endl;
        cout<<"swap "<<inds[0]<<" "<<inds[1]<<endl;
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    almostSorted(arr);

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
