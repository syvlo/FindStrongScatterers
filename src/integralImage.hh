#ifndef INTEGRAL_IMAGE_HH_
# define INTEGRAL_IMAGE_HH_

#include <cv.h>
#include <highgui.h>

/**
 * \brief compute the integral image.
 *
 * \param[in]	integral		The integral image (allocated)
 * \param[in]   input			The image on which we want the integral image.
 * \return						The integral image.
 */
template<typename OUT, typename IN>
cv::Mat
computeIntegralImage(cv::Mat integral, cv::Mat input);


/**
 * \brief Get the sum of the pixels in a rectangle.
 *
 * \param		integral		The integral image (previously computed using
 *								computeIntegralImage).
 * \param		i1				Starting row of the rectangle.
 * \param		i2				Ending row of the recangle (included).
 * \param		j1				Starting column of the rectangle.
 * \param		j2				Ending column of the recangle (included).
 */
template<typename T>
T getSum(cv::Mat image, unsigned i1, unsigned i2,
		 unsigned j1, unsigned j2);

#include "integralImage.hxx"

#endif /* INTEGRAL_IMAGE_HH_ */
