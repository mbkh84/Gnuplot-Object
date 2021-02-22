#include <iostream>
#include <unistd.h>
#include "..//include//Gnuplot.hpp"

using namespace std;

int main(void)
{
	CGNUPlot *m_a=new CGNUPlot;
	int k;
	int datax[128];
	float datay[128];
	cout<<"Creation of Object Successfull!"<<endl;
	for(k=0;k<10;k++)
	{
	    //m_a = new CGNUPlot;
		for(int i=0;i<128;i++)
		{
			datax[i]=i;
			datay[i]=k*i+k*100;			
		}
		m_a->plot(datax,datay,128,k);
		usleep(1000000);
		cout<<"Try"<<k<<endl<<std::flush;
		//(std:stdout).flush();
		//delete m_a;
	}
	delete m_a;
	return 0;
}
