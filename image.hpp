#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <string>
#include <boost/multi_array.hpp>

#include "process.hpp"

namespace engineering{
class image{
	std::string file;
	boost::multi_array<unsigned char, 2> input;
        boost::multi_array<unsigned char, 2> output;
	int sharp;
	//encapsulation and abstraction
public:
	image(std::string file);
	void save(std::string filename);
	void save();
	void Convolution(boost::multi_array <unsigned char ,2>& input,
	boost::multi_array <unsigned char ,2>& output,boost::multi_array <float ,2>& kernel,int &kernelSize);
	void BoxBlur(int kernelSize);
	unsigned int Sharpness();
};
}



#endif /* IMAGE_HPP */


