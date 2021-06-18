#include "PS.h"
#include <iostream>
using namespace std;

int main() {
	PS A, B, C;
	cout << "Nhap phan so A:\n";
	cin >> A;
	cout << "Phan so A: " << A << "\n";
	cout << "(A) ++: " << A++ << "\n";
	cout << "++ (A): " << ++A;
	return(0);
}