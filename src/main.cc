#include <iostream>
#include <string>

#include <ImwHelper.hh>

#include <cv.h>
#include <highgui.h>

#include "utils.hh"
#include "integralImage.hh"


cv::Mat
findS(cv::Mat input, cv::Mat integral, double thresh, unsigned s)
{
	std::cout << "0, 0 " << input.at<unsigned short>(0,0) << std::endl
			  << "0, 1 " << input.at<unsigned short>(0,1) << std::endl
			  << "1, 0 " << input.at<unsigned short>(1,0) << std::endl
			  << "1, 1 " << input.at<unsigned short>(1,1) << std::endl;
	std::cout << integral.at<double>(1,1) << std::endl;
	cv::Mat result (input.size(), input.type());
	unsigned sSquaredMinus1 = s * s - 1;

	for (int i = 0; i < result.size().height; ++i)
		for (int j = 0; j < result.size().width; ++j)
		{
			int i1 = i - s / 2;
			int i2 = i + s / 2;
			int j1 = j - s / 2;
			int j2 = j + s / 2;

			if (i1 < 0)
				i1 = 0;
			if (i2 >= result.size().height)
				i2 = result.size().height;
			if (j1 < 0)
				j1 = 0;
			if (j2 >= result.size().width)
				j2 = result.size().width;

			unsigned short pixelVal = input.at<unsigned short> (i, j);
			double meanVal = (getSum<double>(integral, i1, i2, j1, j2) - pixelVal) / sSquaredMinus1;
			double ratio = pixelVal / meanVal;
			if (ratio > thresh)
				result.at<unsigned short>(i, j) = (unsigned short)pixelVal;
			else
				result.at<unsigned short>(i, j) = 0;
		}

	return result;
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

	cv::Mat SARImage = ReadImw(inputFileName.c_str());

	cv::Mat integralImage (SARImage.size(), CV_64F);
	integralImage = computeIntegralImage<double, unsigned short>(integralImage, SARImage);

	cv::Mat output = findS(SARImage, integralImage, thresh, s);

	WriteImw(output, outputFileName.c_str());

	return 0;
}
