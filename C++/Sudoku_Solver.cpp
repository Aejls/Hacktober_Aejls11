#include<bits/stdc++.h>
using namespace std;

void Helper(int r, int c, vector<vector<int>> &Suduku, map<pair<int,int>, map<int,int>> &mp,
vector<map<int,int>> &row, vector<map<int,int>> &col){
    if(r == 9){
        cout << endl;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout << Suduku[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }

    if(c == 9){
        Helper(r+1,0,Suduku,mp,row,col);
        return;
    }

    if(Suduku[r][c] != 0){
        Helper(r,c+1,Suduku,mp,row,col);
        return;
    }

    for(int i=1;i<=9;i++){
        int rw = r/3, cl = c/3;
        if(!mp[{rw,cl}][i] and !row[r][i] and !col[c][i]){
            mp[{rw,cl}][i] = 1;
            row[r][i] = 1;
            col[c][i] = 1;
            Suduku[r][c] = i;
            Helper(r,c+1,Suduku,mp,row,col);
            mp[{rw,cl}][i] = 0;
            row[r][i] = 0;
            col[c][i] = 0;
            Suduku[r][c] = 0;
        }
    }
}

void SolveSuduku(vector<vector<int>> &Suduku){
    map<pair<int,int>, map<int,int>> mp;
    vector<map<int,int>> row(9);
    vector<map<int,int>> col(9);

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(Suduku[i][j] != 0){
                mp[{i/3,j/3}][Suduku[i][j]] = 1;
                row[i][Suduku[i][j]] = 1;
                col[j][Suduku[i][j]] = 1;
            }
        }
    }

    Helper(0,0,Suduku,mp,row,col);
}

int main(){
    vector<vector<int>> Suduku(9, vector<int>(9));
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>Suduku[i][j];
        }
    }
    SolveSuduku(Suduku);
}
