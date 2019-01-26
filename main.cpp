#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include "image.hpp"
#include "process.hpp"
int main(){

        engineering::image img("stanford.jpg");
	std::cout<<"Original image:"<<img.Sharpness()<<std::endl;
	//instantiate an object in image class and print out the original sharpness value
	int k_size = 3;
	while (k_size < 28) {
		img.BoxBlur(k_size);
		std::cout << "BoxBlur(" << std::setw(2) << k_size <<")";
		//compute the sharpness for the blurred image with different kernel size
		std::cout << std::setw(7) << img.Sharpness() << std::endl;
		std::stringstream ss;
		ss << std::setw(2) << std::setfill('0') << k_size;
		//set the width and print out format
		std::string s = "BoxBlur"; 
		s += ss.str();
		s += ".jpg";
		img.save(s);
		//save the blurred image with new name
		k_size += 4;
	}
	return 0;
}
