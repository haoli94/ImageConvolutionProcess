
Appling namespace ‘engineering’ to hold the class image, abstracted and encapsulated the data attributes and methods as follows: 
string file, boost::multi_array input, boost::multi_array output, int sharp.
public methods: void save(string filename), and a default void save(), void Convolution(), void BoxBlur(int kernelSize), and unsigned int Sharpness().


Initialized the image class with data attributes file,input, output and sharp, and then wrote a new save method that takes in an argument,
filename and a default one with no arguments and writes out the ‘blurred image’.

In Convolution method, first get the size, height and width of the input picture. Then compute each pixel in the range, checke the boundary.
Added up the weighted pixel values and clamped the values in the range of [0,255].

Compute Sharpness: max sharpness values.



And in the Sharpness method, I initialize the max sharpness value to be zero, I constructed the kernel matrix for computing sharpness, and then computed the sharpness.

In the main, I instantiated an object in image class and print out the original sharpness value, and then computed the sharpness for the blurred image with different kernel size, set the print out format and saved the blurred image with new name.

And also I think we can deﬁne certain methods that we are going to use repeatedly as base class which would be helpful to create an easy-to-maintain and performant-minded program

![image](https://github.com/haoli94/ImageConvolutionProcess/blob/master/Blur.png)


![image](https://github.com/haoli94/ImageConvolutionProcess/blob/master/Convolution.png)

![image](https://github.com/haoli94/Android-apps/blob/master/UI1.png)

The kernel matrix for blurring, using the denominator(1/(k*k)).