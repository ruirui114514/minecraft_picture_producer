#include <opencv2/opencv.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace cv;

struct rgb {
	int r, g, b;
};

string out;

int main(int argc,char**argv) {
	if (argc != 2) return -1;
	string filename = argv[1];
	ofstream fout("out.mcfunction");
	fout << "gamerule maxCommandChainLength ";
	int min = 114514, ji, s = 1, f = 0;
	rgb a[16] = {
		203,209,210,
		220,87,0,
		164,39,154,
		24,129,193,
		241,170,10,
		84,162,12,
		211,92,136,
		43,47,51,
		117,117,107,
		10,111,129,
		92,21,151,
		34,36,137,
		87,49,20,
		64,83,26,
		135,21,21,
		1,1,3
	};
	Mat src = imread(filename);
	int height = src.rows;
	int width = src.cols;
	fout << height * width + 1 << endl;
	for (int x = 0; x < height; x++) {
		for (int y = 0; y < width; y++) {
			min = 114514;
			Vec3b bgr = src.at<Vec3b>(x, y);
			int r = bgr[2];
			int g = bgr[1];
			int b = bgr[0];
			for (int i = 0; i < 16; i++) {
				int tmp = abs(r - a[i].r) + abs(g - a[i].g) + abs(b - a[i].b);
				if (tmp < min) {
					min = tmp;
					ji = i;
				}
			}
			stringstream temp;
			temp.clear();
			temp << "setblock " << y << " 10 " << x << " concrete " << ji;
			out = "";
			getline(temp, out);
			fout << out << endl;
		}
	}
	return 0;
}