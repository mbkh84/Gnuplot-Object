#include "..//include//Gnuplot.hpp"
#include <stdio.h>
#include <unistd.h>


CGNUPlot::CGNUPlot()
{
	string tmp_filename;
	string tmp_address="tmp/";
	tmp_filename=gen_random_string(8);
	tmp_filename=tmp_address+tmp_filename;
	m_strmFileWriter.open(tmp_filename,ios::out);
	m_strmGnuPlotPipe=popen("gnuplot -p","w");
	m_strFileName=tmp_filename;
}

CGNUPlot::~CGNUPlot()
{
	m_strmFileWriter.close();
	pclose(m_strmGnuPlotPipe);
}

string CGNUPlot::gen_random_string(const int len)
{
	string tmp_s;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    
    srand( (unsigned) time(NULL) * getpid());

    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) 
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
       
    return tmp_s;
}
void CGNUPlot::plot(int *xval,float *yval,int length,int flag)
{
	for(int i=0;i<length;i++)
	{
		m_strmFileWriter<<xval[i]<<","<<yval[i]<<std::endl;
	}
	m_strmFileWriter.flush();
	if(flag==0)
		std::fprintf(m_strmGnuPlotPipe,"plot \"%s\" with lines\n",m_strFileName.c_str());
	else
		std::fprintf(m_strmGnuPlotPipe,"replot \"%s\" with lines\n",m_strFileName.c_str());
	//std::fprintf(m_strmGnuPlotPipe,"quit \n");
    std::fflush(m_strmGnuPlotPipe);
}
