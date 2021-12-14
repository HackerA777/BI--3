#include <iostream>
#include "Bimage.h"
#include <cstdio>
using namespace std;

enum class cardinaldirection { NORTH, EAST, SOUTH, WEST };
ostream& operator <<(ostream& os, const cardinaldirection& a_p) {
	if ((int)a_p > 0)
		os << "\t1";
	else
		os << "\t.";
	return os;
}

int main() {

	binaryimage<int, 7, 3> bimage(5, 5);
	bimage(0, 0) = true;
	bimage(1, 1) = 7;
	bimage(1, 2) = true;
	bimage(3, 3) = 3;
	bimage(3, 0) = 3;
	bimage(1, 4) = 3;
	bimage(4, 2) = 3;
	std::cout << bimage << endl;	// 1..
							// .1.
							// ...
	bimage = !bimage;
	std::cout << bimage <<endl;	// .11
							// 1.1
							// 111

	//bimage(1, 1) = 5; // FAIL: Should throw
	//if (bimage == bimage)
		//std::cout << "True";
	binaryimage<cardinaldirection,
		cardinaldirection::SOUTH,
		cardinaldirection::NORTH> image(2, 2);
	std::cout << image << endl; // ..
	 // ..
	image(0, 0) = cardinaldirection::SOUTH;
	std::cout << image << endl; // 1.
	// ..
	//image(0, 0) = CardinalDirection::EAST; // FAIL: Should throw
	std::cout << bimage << "\n";
	std::cout << bimage(1, 1) << " pixel (1, 1) = True" << "\n";
	std::cout << bimage(2, 2) << " pixel (2, 2) = False" << "\n";
	std::cout << image(0, 0);
	std::cout << "\n" << image;
	std::cout << endl << bimage.ratio();
}