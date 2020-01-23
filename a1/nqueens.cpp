#include<bits/stdc++.h>
using namespace std;
#define N 4




bool is_safe(int board[N][N], int row, int col){
	int i, j;
	for(i=0; i<col; i++){
		//cout<<i<<" for 1\n";
		if(board[row][i]){
			//cout<<row<<" "<<i<<" "<<board[row][i]<<" is_row_left\n";
			return false;
			}
		}
			
	for(i=row, j=col; i>=0 && j>=0; i--, j--){
		//cout<<i<<j<<" for 2\n";
		if(board[i][j]){
		//	cout<<i<<" "<<j<<" "<<board[row][i]<<" is_diag_upper\n";
			return false;
			}
		}
	for(i=row, j=col; i<N && j>=0; i++, j--){
		//cout<<i<<j<<" for 3\n";
		if(board[i][j]){
		//	cout<<i<<" "<<j<<" "<<board[row][i]<<" is_diag_lower \n";
			return false;
		}
	}
	return true;

}


bool solveNQ(int board[N][N], int col){

	if(col >= N)
		return false;
		
	for(int i = 0;i<N;i++){
		if(is_safe(board, i, col)){
			board[i][col] = 1;
		
			
			if(solveNQ(board, col+1))
				return true;
			
			board[i][col] = 0;
		}
		
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			cout<<board[i][j]<<" ";
		cout<<"\n";
	}
	cout<<"\n";
	
	return false;
	

}

int main(){
	int board[N][N];
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			board[i][j] = 0;
			
	
	if(solveNQ(board, 0)==false){
		cout<<"no solution found\n";
		return 0; 
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			cout<<board[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}
