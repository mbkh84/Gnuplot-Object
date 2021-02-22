#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;
class CGNUPlot
{
    private:
		FILE     *m_strmGnuPlotPipe;
		ofstream m_strmFileWriter;

		string gen_random_string(const int len);
    public:
		string m_strFileName;
		string m_strXLabel,m_strYLabel;
		int    m_intXRange, m_intYRange;
		CGNUPlot();
		~CGNUPlot();
		void plot(int*,float*,int,int);
	
};
