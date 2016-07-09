#include "Leetcode.h"


int Solution::TotalN_Queens(int n){
    int cnt = 0;
    vector<bool> col(n, true);
    vector<bool> diag(n, true);
    vector<bool> offDiag(n, true);
    N_QueensDFS(0, cnt, col, diag, offDiag);
    return cnt;
}


void Solution::N_QueensDFS(unsigned i, int &cnt, vector<bool> &col, vector<bool> &diag, vector<bool> &offDiag){
    // i denotes the row index, if i reaches the last row, current DFS is completed
    if(i == col.size()){
        cnt++;
        return;
    }
    for(unsigned j = 0; j < col.size(); j++){
        if(col[j] && diag[i+j] && offDiag[i+col.size()-1-j]){
            col[j] = diag[i+j] = offDiag[i+col.size()-1-j] = false;
            N_QueensDFS(i+1, cnt, col, diag, offDiag);
            // reset each position to empty status, i.e. true, for next DFS search with j+1
            col[j] = diag[i+j] = offDiag[i+col.size()-1-j] = true;
        }
    }
}
