#include <iostream>
#include "BmpStructures.h"
#include "ImgFunctions.h"
#include <algorithm>

void testBmpIo()
{
	printImgInfo("masterpiece.bmp");
	RgbImg img = readRgbImg("masterpiece.bmp");
	for (size_t row = 0; row < 50; ++row)
		for (size_t col = 0; col < 50; ++col)
		{
			img.pixels[row][col].Blue = 255;
			img.pixels[row][col].Green = 128;
			img.pixels[row][col].Red = 0;
			//img.pixels[row][col] = {255, 255, 255}; //same as above
		}
	writeRgbImg("out\\ugly_copy.bmp", img);
	deleteRgbImg(img);
}

//Generate dummy image example
void genImgWithSquare()
{
	RGB background = { 255, 128, 0 };
	RgbImg img = createRgbImg(600, 600, background);
	for (size_t row = 50; row < 200; ++row)
		for (size_t col = 100; col < 400; ++col)
			img.pixels[row][col] = { 128, 255, 0 };

	writeRgbImg("out\\ai_masterpiece.bmp", img);
	deleteRgbImg(img);
}

//Autobalancing example
void testAutolevels()
{
	RgbImg img = readRgbImg("data\\Lenna.bmp");
	RgbImg balanced = autolevels(img);
	writeRgbImg("out\\Lenna_avtolevels.bmp", img);
	deleteRgbImg(img);
}

//Another autobalancing example
void testGrayworld()
{
	RgbImg img = readRgbImg("data\\sinichka.bmp");
	RgbImg balanced = grayworld(img);
	writeRgbImg("out\\grayworld.bmp", balanced);
	deleteRgbImg(img);
}

//Box filter example
void testBoxFilter()
{
	RgbImg img = readRgbImg("data\\kidsnoise.bmp");
	RgbImg filtered = convolution(img, 5);
	writeRgbImg("out\\kids_filtered.bmp", img);
	deleteRgbImg(img);
	deleteRgbImg(filtered);
}

void testKernelFilter()
{
	size_t const kern_sz = 3;
	double** kernel = new double* [kern_sz];
	for (size_t row = 0; row < kern_sz; ++row)
	{
		kernel[row] = new double[kern_sz];
		for (size_t col = 0; col < kern_sz; ++col)
			kernel[row][col] = 1. / 9;
	}
	RgbImg img = readRgbImg("data\\kidsnoise.bmp");
	RgbImg filtered = convolution(img, 5, kernel);
	writeRgbImg("out\\kids_filtered_kernel.bmp", img);
	deleteRgbImg(img);
	deleteRgbImg(filtered);
}

void testContours()
{
	RgbImg img = readRgbImg("data\\sinichka.bmp");
	RgbImg contour_img = contours(img);
	writeRgbImg("out\\contours.bmp", contour_img);
	deleteRgbImg(img);
	deleteRgbImg(contour_img);
}


void generate_rainbow(const char* out_file = (char*)"out\\noname.bmp") {
	RgbImg img = createRgbImg(100, 700, { 0, 0, 0 });
	RGB colors[7] = { {0, 0, 255}, {0, 128, 255}, {0, 255, 255}, {0, 255, 0}, {255, 255, 0}, {255, 0, 0}, {102, 0, 52} };
	for (int c = 0; c < 7; ++c) {
		for (int i = c * 100; i < (c + 1) * 100; ++i){  //because the size is 100*100
			for (int j = 0; j < 100; ++j){
				img.pixels[j][i] = colors[c];
			}
		}
	}
	writeRgbImg(out_file, img);
	deleteRgbImg(img);
}


void rotate_img(const char* source = (char*)"data\\sinichka.bmp", const char* destination = (char*)"data\\sinichka1.bmp", int rotate = 90) {
	rotate %= 360;
	if (rotate % 90 != 0)
		return;

	RgbImg src_img = readRgbImg(source);
	int h = src_img.height, w = src_img.width;

	if (rotate == 0) {
		writeRgbImg(destination, src_img);
		deleteRgbImg(src_img);
		return;
	}
	else if (rotate == 90) {
		RgbImg des_img = createRgbImg(w, h, { 0, 0, 0 });
		for (int x = 0; x < w; ++x){
			for (int y = 0; y < h; ++y) {
				des_img.pixels[w - 1 - x][y] = src_img.pixels[y][x];
			}
		}
		writeRgbImg(destination, des_img);
		deleteRgbImg(src_img);
		deleteRgbImg(des_img);
	}
	else if (rotate == 180) {
		RgbImg des_img = createRgbImg(h, w, { 0, 0, 0 });
		for (int x = 0; x < w; ++x){
			for (int y = 0; y < h; ++y){
				des_img.pixels[y][x] = src_img.pixels[h - y - 1][w - x - 1];
			}
		}
		writeRgbImg(destination, des_img);
		deleteRgbImg(src_img);
		deleteRgbImg(des_img);
	}
	else if (rotate == 270) {
		RgbImg des_img = createRgbImg(w, h, { 0, 0, 0 });
		for (int x = 0; x < w; ++x){
			for (int y = 0; y < h; ++y){
				des_img.pixels[x][h - 1 - y] = src_img.pixels[y][x];
			}
		}
		writeRgbImg(destination, des_img);
		deleteRgbImg(src_img);
		deleteRgbImg(des_img);
	}
}


void to_grayscale(const char* source = (char*)"data\\sinichka.bmp",const char* destination = (char*)"data\\sinichka_gray.bmp") {
	RgbImg src = readRgbImg(source);
	int h = src.height, w = src.width;

	RgbImg des = createRgbImg(h, w, { 0, 0, 0 });

	for (int x = 0; x < w; ++x) {
		for (int y = 0; y < h; ++y)	{
			unsigned char avg = (src.pixels[y][x].Red + src.pixels[y][x].Green + src.pixels[y][x].Blue) / 3;
			des.pixels[y][x].Red = avg;
			des.pixels[y][x].Green = avg;
			des.pixels[y][x].Blue = avg;

		}
	}
	writeRgbImg(destination, des);
	deleteRgbImg(src);
	deleteRgbImg(des);
}


void sharpen(const char* source = (char*)"data\\kidsnoise.bmp",const char* destination = (char*)"data\\kidsnoise_shar.bmp") {
	RgbImg src = readRgbImg(source);

	RgbImg des = convolution(src, 5);

	double** sharpening = new double* [3];
	sharpening[0] = new double[3] { 0., -1., 0. };
	sharpening[1] = new double[3] { -1., 5., -1. };
	sharpening[2] = new double[3] { 0., -1., 0. };

	des = convolution(des, 3, sharpening);

	writeRgbImg(destination, des);


	for (int i = 0; i < 3; ++i)
		delete[] sharpening[i];
	delete[] sharpening;

	deleteRgbImg(src);
	deleteRgbImg(des);
}

void BubbleSort(int*& M, int n) {

	for (int j = 0; j < n - 1; ++j) {
		bool isSorted = true;
		for (int i = n - 1; i > j; --i) {
			if (M[i] < M[i - 1]) {
				std::swap(M[i], M[i - 1]); 
				isSorted = false;
			}
		}
		if (isSorted) break;
	}
}

void mediana(const char* source = (char*)"data\\kidsnoise.bmp", const char* destination = (char*)"data\\kidsnoise_med.bmp", int n = 3) {
	RgbImg src = readRgbImg(source);
	int h = src.height, w = src.width;
	int* red = new int [n * n];
	int* green = new int [n * n];
	int* blue = new int [n * n];
	int middle = n / 2;

	for (size_t rows = middle; rows < h; ++rows) {
		for (size_t cols = middle; cols < w; ++cols) {
			for (size_t i = 0; i < n; ++i) {
				for (size_t j = 0; j < n; ++j) {
					size_t i_m = rows + i - middle;
					size_t j_m = cols + j - middle;
					red[i * n + j] = src.pixels[i_m][j_m].Red;
					green[i * n + j] = src.pixels[i_m][j_m].Green;
					blue[i * n + j] = src.pixels[i_m][j_m].Blue;
				}
			}
			BubbleSort(red, n * n);
			BubbleSort(green, n * n);
			BubbleSort(blue, n * n);
		
			src.pixels[rows][cols].Red = red[n * n / 2 + 1];
			src.pixels[rows][cols].Green = green[n * n / 2 + 1];
			src.pixels[rows][cols].Blue = blue[n * n / 2 + 1];
		}
	}
	writeRgbImg(destination, src);

	delete[]red;
	delete[]green;
	delete[]blue;
	deleteRgbImg(src);
}

int main(int argc, char* argv[]) {
	try	{
		/*const char* test = argv[1];  //sinichka
		const char* test1 = argv[2];
		rotate_img(test, test1, 90);*/
		/*const char* test = argv[1];  //sinichka_grey
		const char* test1 = argv[2];
		to_grayscale(test, test1);*/
		/*const char* test = argv[1];  //sharpening and bluring
		const char* test1 = argv[2];
		sharpen(test, test1);
		const char* test = argv[1];  //last
		const char* test1 = argv[2];
		mediana(test, test1, 3);*/
	}
	catch (std::exception const& e)	{
		std::cout << "Error: " << e.what() << "\n";
		return -1;
	}
	return 0;
}