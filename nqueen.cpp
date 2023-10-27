#include<iostream>
#include<vector>
using namespace std;



void printSolution(vector<vector<char> > board, int n){
        for(int i = 0;i<n;i++){
             for(int j = 0;j<n;j++)
             {
                 cout<<board[i][j]<< " ";
             }
          cout<<endl;
        }
 cout<<endl<<endl;
}

bool isSafe(vector<vector<char> > &board,int row,int col,int n)
{ // mai yaha ye check krunga ki , kya mera Q safe h ya nhi, agar safe nhi hai
 // to false return krunga, agar safe hai then automatic true return hoga

 int i = row;
 int j = col;
 
 //checking left row
 while(j>=0){
   
    if(board[i][j] == 'Q'){
         return false;
    }
         j--;
    }
 
 //checking upper left diagonal
 i = row;
 j = col;
 while(i>=0 && j>=0){
       if(board[i][j] == 'Q'){
         return false;
       }
     i--;
     j--;
 }
  // checking bottom left diagonal
  i = row;
  j = col;
  while( i<n && j>=0){
       if(board[i][j] == 'Q'){
         return false;
       }
     i++;
     j--;
  }
   
//kahi pe bhi queen nai mili
//iska mtlb position safe hai
  return true;
 }

void solve(vector<vector<char> > &board,int n,int col){
     //base case
      if(col>=n){
         printSolution(board,n);
      }

 //placing Q in every row
  
  for(int row = 0;row<n;row++){
       if (isSafe(board, row, col,n)){
         
       //1 case solve krna h baaki recursion sambhal lega
         board[row][col] = 'Q';
        solve(board,n,col+1);

        //backtracking
        board[row][col] = '-';
       
       }
  }

}

int main(){
     int n = 7;
    vector<vector<char> > board (n,vector<char>(n,'-'));
    int col = 0 ;
    //0-> empty cell
    //1 -> queen is there
    solve(board,n,col);
}