#include <iostream>
#include <string>

#include <ImwHelper.hh>

#include <cv.h>
#include <highgui.h>


void printHelp()
{
	std::cout << "findStrongS -i input[.imw] -o output[.imw] -t|--threshold thresh"
			  << " [-s|--size s]" << std::endl << std::endl
			  << "Look for strong scatterers in the input image." << std::endl
			  << "A point p is considered as a strong scatterers if its value v"
			  << std::endl
			  << "compared to the mean value m of pixels in a square of size s*s"
			  << std::endl
			  << "is greater than thresh: v/m > thresh." << std::endl
			  << "s has to be an odd positive number greater than one."
			  << std::endl << std::endl
			  << "Default value:" << std::endl
			  << "- s = 3" << std::endl;
}

int parseArgs(int argc, char* argv[], std::string& input, std::string& output,
			  double& thresh, unsigned& s)
{
	for (int i = 1; i < argc; ++i)
	{
		if (!strcmp("-i", argv[i]))
		{
			input = argv[++i];
		}
		else if (!strcmp("-o", argv[i]))
		{
			output = argv[++i];
		}
		else if (!strcmp("-t", argv[i]) || !strcmp("--threshold", argv[i]))
		{
			thresh = atof(argv[++i]);
		}
		else if (!strcmp("-s", argv[i]) || !strcmp("--size", argv[i]))
		{
			s = atoi(argv[++i]);
		}
		else
		{
			std::cout << "Unknown argument " << argv[i] << std::endl;
			return 1;
		}
	}

	if (s % 2 == 0 || s < 3)
	{
		std::cout << "Error: s must be an odd number greater than 1." << std::endl;
		return 1;
	}
	if (input.length() > 4 && input.substr(input.length() - 4).compare(".imw") == 0)
		input.erase(input.length() - 4);
	if (output.length() > 4 && output.substr(output.length() - 4).compare(".imw") == 0)
		output.erase(output.length() - 4);

	return 0;
}

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
