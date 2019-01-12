#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
Problem : https://www.hackerrank.com/challenges/bomber-man/problem
*/
vector<string> fillUpGrid(vector<string> grid){
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            grid[i][j]='O';
        }
    }
    return grid;
}
vector<string> getBoardAfterTwoSeconds(vector<string> grid){
    vector<pair<int,int>> points;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j] =='O'){
                points.push_back({i,j});
            }
        }
    }
    grid = fillUpGrid(grid);

    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    for(auto p : points){
        grid[p.first][p.second] = '.';
        for(int i=0;i<4;i++){
            int x = p.first + dir[i][0];
            int y = p.second + dir[i][1];
            if( x>=0 && x < grid.size() && y>=0  && y < grid[0].size()){
                grid[x][y] = '.';
            }
        }
    }
    return grid;
}
// Complete the bomberMan function below.
vector<string> bomberMan(int n, vector<string> grid) {
    if( n < 2 )
        return grid;
    if(n%2==0){
        return fillUpGrid(grid);
    }
    else if( ( n + 1 ) % 4 == 0 ){// board at 3.
        return getBoardAfterTwoSeconds(grid);
    }
    else {// board at 5.
        grid = getBoardAfterTwoSeconds(grid);
        return getBoardAfterTwoSeconds(grid);
    }

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string rcn_temp;
    getline(cin, rcn_temp);

    vector<string> rcn = split_string(rcn_temp);

    int r = stoi(rcn[0]);

    int c = stoi(rcn[1]);

    int n = stoi(rcn[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
