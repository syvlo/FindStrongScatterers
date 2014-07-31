#include <iostream>
#include <string>

#include <ImwHelper.hh>

#include <cv.h>
#include <highgui.h>

#include "utils.hh"


int main(int argc, char* argv[])
{
	if (argc < 7)
	{
		printHelp();
		return 1;
	}

	std::string inputFileName;
	std::string outputFileName;
	double thresh;
	unsigned s = 3;

	if (parseArgs(argc, argv, inputFileName, outputFileName, thresh, s))
	{
		printHelp();
		return 1;
	}

	std::cout << "Parameters:" << std::endl
			  << "- Input: " << inputFileName << std::endl
			  << "- Output: " << outputFileName << std::endl
			  << "- Threshold: " << thresh << std::endl
			  << "- Window size: " << s << std::endl;
}
