//History.h
#ifndef	HISTORY_INCLUDED
#define	HISTORY_INCLUDED
//#include "globals.h"

class History
{
 public:
    History(int nRows, int nCols);
    ~History();
    bool record(int r, int c); 	//false when r/c is out of bond
    void display() const;	//clear the screan and display the gistory grid

 private:
//    char m_grid[MAXROWS][MAXCOLS]; /////////whatif no headfile???
//    char m_grid[30][40];
    char** m_grid;
    int m_rows;
    int m_cols;
};

#endif //HISTORY_INCLUDED
