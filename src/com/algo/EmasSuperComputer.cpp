#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
Problem : https://www.hackerrank.com/challenges/two-pluses/problem
*/

bool inBounds(int r,int c,int n,int m){
    if( r < n && c < m && r >= 0 && c >= 0)
        return true;
    else
        return false;
}

int getMaxplus(vector<string>grid,vector<vector<bool>> blocked){
    int dir[4][2] = {{-1,0},{0,1},{0,-1},{1,0}};
    int max_area = 0;

    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]=='G' && !blocked[i][j]){
                int valid_steps=grid.size()+1;
                for(int k=0;k<4;k++){
                    int r = i + dir[k][0],c = j + dir[k][1];
                    int steps=0;
                    while(inBounds(r,c,grid.size(),grid[0].size()) && grid[r][c] !='B' && !blocked[r][c]){
                        steps++;
                        r+=dir[k][0];
                        c+=dir[k][1];
                    }
                    valid_steps = min(valid_steps,steps);
                }
                valid_steps = valid_steps*4;
                valid_steps++;
                max_area = max(max_area,valid_steps);
            }
        }
    }
    return max_area;
}
// Complete the twoPluses function below.
int twoPluses(vector<string> grid) {
    int res = 0;
    int first = 0,second=0;
    int dir[4][2] = {{-1,0},{0,1},{0,-1},{1,0}};

    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]=='G'){
                int valid_steps=grid.size()+1;
                for(int k=0;k<4;k++){
                    int r = i + dir[k][0],c = j + dir[k][1];
                    int steps=0;
                    while(inBounds(r,c,grid.size(),grid[0].size()) && grid[r][c] !='B'){
                        steps++;
                        r+=dir[k][0];
                        c+=dir[k][1];
                    }
                    valid_steps = min(valid_steps,steps);
                }
                vector<vector<bool>> blocked(grid.size(),vector<bool>(grid[0].size(),false));
                blocked[i][j]=true;
                int v = 0;

                while(v <= valid_steps){
                    for(int k=0;k<4;k++){
                        int r = i + dir[k][0],c = j + dir[k][1];
                        for(int l=0;l<v;l++){
                            blocked[r][c] = true;
                            r+=dir[k][0];
                            c+=dir[k][1];
                        }
                    }
                    res = max(res,(v*4 + 1) * getMaxplus(grid,blocked));
                    v++;
                }
            }
        }
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    int result = twoPluses(grid);

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
