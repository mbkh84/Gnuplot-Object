#include <iostream>
#include <unistd.h>
#include "..//include//Gnuplot.hpp"

using namespace std;

int main(void)
{
	CGNUPlot *m_a=new CGNUPlot;
	int k=0;
	int datax[128];
	float datay[128];
	
	m_a->setXRange(0,128);
	m_a->setYRange(0,1280);
	
	for(k=0;k<20;k++)
	{
	    //m_a = new CGNUPlot;
		for(int i=0;i<128;i++)
		{
			datax[i]=i;
			datay[i]=k*i;		
		}
		m_a->plot(datax,datay,128,k);
		usleep(300000);
		cout<<"Try"<<k<<endl<<std::flush;
		//delete m_a;
	}
	
	delete m_a;
	return 0;
}
