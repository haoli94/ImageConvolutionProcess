#include <iostream>
#include <string>
#include <boost/multi_array.hpp>

#include "image.hpp"
#include "process.hpp"


namespace engineering{
//using namespace engineering to hold the class image
image::image(std::string file){
	this->file = file;
	ReadGrayscaleJPEG(file,this->input);
	this->output.resize(boost::extents[this->input.shape()[0]][this->input.shape()[1]]);
	this->output = this->input;
	this->sharp = 0;
	//initialize the image class with data attributes file,input, output and sharp
}

void image::save(std::string filename){
        WriteGrayscaleJPEG(filename, output);
//write a new save method that takes in an argument,filename
}

void image::save(){
	WriteGrayscaleJPEG(this->file,output);
//wtite a default save method that write the original picture
}

void image::Convolution(boost::multi_array <unsigned char ,2>& input,
boost::multi_array <unsigned char ,2>& output,boost::multi_array <float ,2>& kernel,int& kernelSize){
	unsigned int height = (unsigned int)input.shape()[0];
        unsigned int width = (unsigned int)input.shape()[1];
	//get the height and width of the input picture
	int k = kernelSize;
        for(unsigned int i=0;i<height;i++){
                for(unsigned int j=0;j<width;j++){
                        float values = 0.f;
                        for (int r = -k/2 ; r <= (int)k/2 ; r++){
                                int row_range_number = r + i;
                                if (row_range_number < 0) row_range_number = 0;
                                if (row_range_number >= (int)height) row_range_number = height-1;
				//check if the row_range gets out of the height boundary 
                                for (int c = -k/2;c<= (int)k/2;c++){
                                        int col_range_number = c + j;
                                        if (col_range_number < 0) col_range_number = 0;
                                        if (col_range_number >= (int)width) col_range_number = width-1;
					 //check if the col_range gets out of the width boundary
                                        values += (float)input[row_range_number][col_range_number]*kernel[r+k/2][c+k/2];
					//accumulate the weighted pixel values
				}
			}
                        //clamping the values if the values is larger than 255 or less than 0
			if (values > 255) values = 255;
			if (values < 0) values = 0;
                        output[i][j] = (unsigned char)round(values);
			//put the newly computed pixel value into the output boost multi-array
			if ((int)round(values) > this->sharp){
				this->sharp = (int)round(values);
				//store the maximum sharpness value
			}
                }
        }
}

void image::BoxBlur(int kernelSize){
	boost::multi_array <float ,2> kernel(boost::extents[kernelSize][kernelSize]);
        float denominator = 1.f/((float(kernelSize))*(float(kernelSize)));
	//get the denominator
        for (int i = 0; i < kernelSize; i++) {
                for (int j = 0; j < kernelSize; j++) {
                        kernel[i][j] = denominator;
			//construct the kernel matrix for blurring
                }
	}
	image::Convolution(this->input,this->output,kernel,kernelSize);
	//blur the image with the kernel
}

unsigned int image::Sharpness(){
	this->sharp = 0;
	//initialize the max sharpness value to be 0
	boost::multi_array<float,2> kernel(boost::extents[3][3]);
	int size = 3;
	kernel[0][0] = 0.f;
	kernel[0][1] = 1.f;
	kernel[0][2] = 0.f;
	kernel[1][0] = 1.f;
	kernel[1][1] = -4.f;
	kernel[1][2] = 1.f;
	kernel[2][0] = 0.f;
	kernel[2][1] = 1.f;
	kernel[2][2] = 0.f;
	//construct the kernel matrix for computing the sharpness
	boost::multi_array<unsigned char,2> sharp(boost::extents[this->input.shape()[0]][this->input.shape()[1]]);
	image::Convolution(this->output,sharp,kernel,size);
	//compute the sharpness value
	if(this->sharp > 255){
		this->sharp = 255;
		//clamping
	}
	return (unsigned int)this->sharp;

}

}





