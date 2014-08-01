#ifndef INTEGRAL_IMAGE_HXX_
# define INTEGRAL_IMAGE_HXX_

#include "integralImage.hh"

template<typename OUT, typename IN>
cv::Mat
computeIntegralImage(cv::Mat integral, const cv::Mat input)
{
	cv::Mat s (integral.size(), integral.type());

	for (int i = 0; i < integral.size().height; ++i)
		for (int j = 0; j < integral.size().width; ++j)
		{
			if (j > 0)
				s.at<OUT>(i,j) = s.at<OUT>(i, j - 1) + (OUT)input.at<IN>(i, j);
			else
				s.at<OUT>(i,j) = (OUT)input.at<IN>(i, j);

			if (i > 0)
				integral.at<OUT>(i, j) = integral.at<OUT>(i - 1, j) + s.at<OUT>(i,j);
			else
				integral.at<OUT>(i, j) = s.at<OUT>(i,j);

		}

	return integral;
}


template<typename T>
T getSum(cv::Mat image, unsigned i1, unsigned i2,
		 unsigned j1, unsigned j2)
{
	T A = image.at<T>(i1, j1);
	T B = image.at<T>(i1, j2);
	T C = image.at<T>(i2, j2);
	T D = image.at<T>(i2, j1);

	return A + C -B - D;
}


#endif /* !INTEGRAL_IMAGE_HXX_ */
