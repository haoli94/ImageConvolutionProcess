
Appling namespace ‘engineering’ to hold the class image, abstracted and encapsulated the data attributes and methods as follows: 
Data attributes: string file, boost::multi_array input, boost::multi_array output, int sharp. 
Public methods: void save(string filename), and a default void save(), void Convolution(), void BoxBlur(int kernelSize), and unsigned int Sharpness().

Initialized the image class with data attributes file,input, output and sharp, and then write a new save method that takes in an argument, filename and a default one with no arguments and writes out the ‘blurred image’.

In Convolution method, first get the size, height and width of the input picture. Then compute each pixel in the range, check the boundary.Add up the weighted pixel values and clamped the values in the range of [0,255].

Compute Sharpness: use the kernel matrix for computing sharpness, find the max sharpness values.

![image](https://github.com/haoli94/ImageConvolutionProcess/blob/master/Blur.png)

![image](https://github.com/haoli94/ImageConvolutionProcess/blob/master/Convolution.png)

The kernel matrix for blurring, using the denominator(1/(k*k)).
