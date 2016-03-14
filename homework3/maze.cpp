//////////////////////////////////////////////////////////////////////////
//mazequeue.cpp								//	
//CS32 homework2 							//
//problem 3. using queue to find if path exists 				//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <queue>
using namespace std;

bool pathExists(string maze[],int nRows, int nCols, int sr, int sc, int er, int ec);
	//return true if there is a path from (sr,sc) to (er,ec) through the maze; return false otherwise
void printAndClean(string maze[], int nRows, int nCols);

class Coord
	//the convension: the upper left is (0,0)
{
 public:
	Coord(int rr, int cc): m_r(rr), m_c(cc){}
	int r() const {return m_r;}
	int c() const {return m_c;}
 private:
	int m_r;
	int m_c;
};

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
	//maze is string[nRows][nCols] that contains either 'X' or '.', which represent wall and walkway 
	//sr, er are numbers between 0 ~ nRows-1
	//sc, ec are numbers between 0 ~ nCols-1
{
	// check if (sr,sc) (er,ec) are walls
	if (maze[sr][sc]=='X' || maze[er][ec]=='X')
		cerr<<"not a valid input"<<endl;
	Coord s(sr,sc);
	Coord e(er,ec);
	if (s.r()==e.r() && s.c()==e.c())
		return true;
	int r=s.r(),c=s.c();
	//explore next steps of different direction
	if (r>0 && maze[r-1][c] == '.')
	{	
		maze[r-1][c]='#';	
		if(pathExists(maze,nRows,nCols,sr-1,sc,er,ec))
			return true;
	}
	if (r<nRows-1 && maze[r+1][c] == '.')
	{	
		maze[r+1][c]='#';	
		if(pathExists(maze,nRows,nCols,sr+1,sc,er,ec))
			return true;
	}
	if (c>0 && maze[r][c-1] == '.')
	{	
		maze[r][c-1]='#';	
		if(pathExists(maze,nRows,nCols,sr,sc-1,er,ec))
			return true;
	}
	if (c<nCols-1 && maze[r][c+1] == '.')
	{	
		maze[r][c+1]='#';	
		if(pathExists(maze,nRows,nCols,sr,sc+1,er,ec))
			return true;
	}
	
	return false;
}

void printAndClean(string maze[],int nRows,int nCols)
{	//output result
	for (int j=0; j<nRows;j++)
	{	for (int k=0; k <nCols; k++)
			cerr<<maze[j][k];
		cerr<<endl;
	}
	cerr<<endl;
	//change back to original maze for multiple test

	for (int j=0; j<nRows;j++)
	{	for (int k=0; k <nCols; k++)
		{	
			if (maze[j][k]=='#')
				maze[j][k]='.';
		}
	}
}

int main()
{
        string maze[10] = {
             "XXXXXXXXXX",
             "X........X",
             "XX.X.XXXXX",
             "X..X.X...X",
             "X..X...X.X",
             "XXXX.XXX.X",
             "X.X....XXX",
             "X..XX.XX.X",
             "X...X....X",
             "XXXXXXXXXX"
	};
      if (pathExists(maze, 10,10, 6,4, 1,1))
                cerr << "Solvable!" << endl;
      else
                cerr << "Out of luck!" << endl;
      printAndClean(maze,10,10);
/*      if (pathExists(maze, 10,10, 8,8, 1,1))
                cerr << "Solvable!" << endl;
      else
                cerr << "Out of luck!" << endl;
      printAndClean(maze,10,10);
*/
}
