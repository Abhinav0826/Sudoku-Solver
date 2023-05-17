#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int> >&v, int row, int col, int val){
    int maxi[] = {0,0,0,3,3,3,6,6,6};
    int mini[] = {2,2,2,5,5,5,8,8,8};
    for(int i=0; i<9; i++){
        if(v[i][col]==val){
            return false;
        }
        if(v[row][i]==val){
            return false;
        }
    }
    for(int i=mini[row]; i<=maxi[row]; i++){
        for(int j=mini[col]; j<=maxi[col]; j++){
            if(v[j][i]==val){
                return false;
            }
        }
    }
    return true;
}

bool SudokuSolver(vector<vector<int> >&v){
    for(int row=0; row<=8; row++){
        for(int col=0; col<=8; col++){
            if(v[row][col]==0){
                for(int val=1; val<=9; val++){
                    if(isSafe(v,row,col,val)){
                        v[row][col] = val;
                        if(SudokuSolver(v)){
                            return true;
                        }
                        v[row][col] = 0; //Backtracking
                    }
                }
                return false;
            }
        }
    }
    return true;  
}

int main(){
    vector<vector<int> > v; 
    int temp;
    for(int i=0; i<9; i++){
        vector<int> v1;
        for(int j=0; j<9; j++){
            cin>>temp;
            v1.push_back(temp);
        }
        v.push_back(v1);
    }
    cout<<endl;
    if(SudokuSolver(v)){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}

// 5 3 0 0 7 0 0 0 0
// 6 0 0 1 9 5 0 0 0
// 0 9 8 0 0 0 0 6 0
// 8 0 0 0 6 0 0 0 3
// 4 0 0 8 0 3 0 0 1
// 7 0 0 0 2 0 0 0 6
// 0 6 0 0 0 0 2 8 0
// 0 0 0 4 1 9 0 0 5
// 0 0 0 0 8 0 0 7 9