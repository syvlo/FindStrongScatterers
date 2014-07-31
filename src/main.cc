#include <iostream>
#include <string>

#include <ImwHelper.hh>

#include <cv.h>
#include <highgui.h>


void printHelp()
{
	std::cout << "findStrongS input[.imw] -o output[.imw] -t|--threshold thresh"
			  << " [-s|--size s]" << std::endl << std::endl
			  << "Look for strong scatterers in the input image." << std::endl
			  << "A point p is considered as a strong scatterers if its value v"
			  << std::endl
			  << "compared to the mean value m of pixels in a square of size s*s"
			  << std::endl
			  << "is greater than thresh: v/m > thresh." << std::endl
			  << "s has to be odd." << std::endl
			  << std::endl
			  << "Default value:" << std::endl
			  << "- s = 3" << std::endl;
}


int main(int argc, char* argv[])
{
	if (argc < 6)
	{
		printHelp();
		return 1;
	}
}
