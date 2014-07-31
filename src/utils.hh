#ifndef UTILS_HH_
# define UTILS_HH_

# include <string>

/**
 * \brief display usage string.
 */
void printHelp();

/**
 * \brief Parse argument list.
 *
 * \param[in]	argc	Number of arguments.
 * \param[in]   argv	Argument list.
 * \param[out]  input	string to store the input image name.
 * \param[out]  output  string to store the output image name.
 * \param[out]  thresh  double to store the thresh.
 * \param[out]  s		unsigned to store the window's size.
 * \return		1 if an argument has not been defined, or if s is not odd.
 *				0 otherwise.
 */
int parseArgs(int argc, char* argv[], std::string& input, std::string& output,
			  double& thresh, unsigned& s);

#endif /* !UTILS_HH_ */
