//History.cpp

#include "globals.h"
#include "History.h"
#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>
using namespace std;

History::History(int nRows, int nCols):m_rows(nRows),m_cols(nCols)
{   
  	m_grid = new char*[m_rows];
	int i,j;
        for (i = 0;  i < m_rows; i++)
		m_grid[i] =  new char[m_cols];	
        for (i = 0; i < m_rows; i++)
       {	
		for (j = 0; j < m_cols; j++)
            		m_grid[i][j] = '.'; 
	}

}

History::~History()
{
   	for (int i=0; i< m_rows; ++i)
		delete [] m_grid[i];
	delete [] m_grid;
}

bool History::record(int r, int c)
{
    if (r < 1 || r > m_rows || c < 1 || c > m_cols)
       return false;
   
 //   if (m_grid == 0)
 //   {
 //   }
    char& gridChar = m_grid[r-1][c-1];
    //int shift = 'A'-'1';
    if (gridChar == '.')
    {
	gridChar ='A'-1;
        //gridChar += shift; 
    }
    gridChar++; 
    return true;
}

void History::display() const
{
   clearScreen();
   for (int r = 0; r < m_rows; r++)
   {   
      for (int c=0; c < m_cols; c++)
         cout << m_grid[r][c];
      cout<<endl;
   }
   cout<<endl;       
}

