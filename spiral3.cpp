#include<iostream>
#include<vector>
using namespace std;

 bool is_out_or_occ(int n,int row,int col,vector<vector<int> >M)
 {
 	return row<0||row==n||col<0||col==n||M[row][col]!=0;
 }
 
 const int RIGHT=0,DOWN=1,LEFT=2,UP=3;

 vector<vector<int> >Spiral_Matrix(int n)
 {
 
 	vector<vector<int> > M(n,vector<int>(n));
 	int col=0,row=0;
 	int num=1;
 	int direction=RIGHT;
 	while(num<=n*n)
 	{
	 
 		M[row][col]=num;
 		num+=1;
 		if(direction==RIGHT)
 		{
 			col+=1;
			 if(is_out_or_occ(n,row,col,M))
			{
				col-=1;
				row+=1;
				direction=DOWN; 	
			}	
		}
		else if(direction==DOWN)
 		{
 			row+=1;
			if(is_out_or_occ(n,row,col,M))
			{
				row-=1;
				col-=1;
				direction=LEFT; 	
			}	
		}
		else if(direction==LEFT)
 		{
 			col-=1;
			 if(is_out_or_occ(n,row,col,M))
			{
				col+=1;
				row-=1;
				direction=UP; 	
			}	
		}
		else if(direction==UP)
 		{
 			row-=1;
			if(is_out_or_occ(n,row,col,M))
			{
				row+=1;
				col+=1;
				direction=RIGHT; 	
			}	
		}
		
    }
    return M;
 }
 
 int main() 
 {
    int n;
    cin >> n;
    vector<vector<int> > M = Spiral_Matrix(n);
    for(int i = 0; i < M.size(); i++) 
	{
        for(int j = 0; j < M[i].size(); j++) 
		{
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}
