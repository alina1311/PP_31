#include"MMatrix.h"

void write3(int i, int mode, bool complex) {
	std::string s = "matrix";
	char num[5];
	_itoa(i, num, 10);
	s += num;
	s += ".txt";
	std::ofstream fout;
	fout.open(s);
	Matrix a(3, 3);
	a[0] = { {2, 2}, {3, 3} , {4,4} };
	a[1] = { {2, 2}, {6,6} , {7, 7} };
	a[2] = { {2, 2}, {9, 9} , {10, 10} };
	Matrix b(a);
	if (!complex)
	{
		Complex c = a[mode][0];
		double dig = c.real();
		a[mode][0] += (dig * i * 0.001);
		b[mode][0] -= (dig * i * 0.001);
	}
	else {
		Complex c = a[mode][0];
		Complex dig(0, c.imag());
		a[mode][0] += (dig * i * 0.001);
		b[mode][0] -= (dig * i * 0.001);
	}

	fout << 3 << "\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (a[i][j] != b[i][j]) {
				Complex ca = a[i][j];
				Complex cb = b[i][j];
				if (ca.real() != cb.real())
				{
					fout << "(" << ca.real() << "-" << cb.real() << ", " << ca.imag() << ") ";
				}
				else {
					fout << "(" << ca.real() << ", " << ca.imag() << "-" << cb.imag() << ") ";
				}
			}
			else {
				Complex c = a[i][j];
				fout << "(" << c.real() << ", " << c.imag() << ") ";
			}
		}
		fout << "\n";
	}
}

void correct(int n, Matrix& a, Matrix& b, int i, int j) {
	Complex c = a[i][j];
	double dig = c.real();
	a[i][j] += (dig * n * 0.001);
	b[i][j] -= (dig * n * 0.001);
}

void correct_i(int n, Matrix& a, Matrix& b, int i, int j) {
	Complex c = a[i][j];
	double dig = c.imag();
	a[i][j] = { c.real(), dig + (dig * n * 0.001) };
	b[i][j] = { c.real(), dig - (dig * n * 0.001) };
}

void write3x(int i) {    //определитель
	std::string s = "matrix";
	char num[5];
	_itoa(i, num, 10);
	s += num;
	s += ".txt";
	std::ofstream fout;
	fout.open(s);
	Matrix a(3, 3);
	a[0] = { {2, 1}, {3, 5} , {4,1} };
	a[1] = { {4, 3}, {3,6} , {5, 7} };
	a[2] = { {2, 5}, {7, 9} , {11, 9} };
	Matrix b(a);

	//correct(i, a, b, 1, 2);
	//correct(i, a, b, 2, 1);

	fout << 3 << "\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (a[i][j] != b[i][j]) {
				Complex ca = a[i][j];
				Complex cb = b[i][j];
				if (ca.real() != cb.real())
				{
					fout << "(" << ca.real() << "-" << cb.real() << ", " << ca.imag() << ") ";
				}
				else {
					fout << "(" << ca.real() << ", " << ca.imag() << "-" << cb.imag() << ") ";
				}
			}
			else {
				Complex c = a[i][j];
				fout << "(" << c.real() << ", " << c.imag() << ") ";
			}
		}
		fout << "\n";
	}
}

void write34(int i, bool image) {
	std::string s = "matrix";
	char num[5];
	_itoa(i, num, 10);
	s += num;
	s += ".txt";
	std::ofstream fout;
	fout.open(s);
	Matrix a(3, 4);
	a[0] = { {2, 2}, {4, 3} , {5,4}, {9, 11} };
	a[1] = { {3, 1}, {4,6} , {7, 7} ,{11, 12} };
	a[2] = { {4, 3}, {6, 9} , {11, 10}, {11, 13} };
	Matrix b(a);


	if (!image)
	{
		correct(i, a, b,2, 3);
	}
	else {
		correct_i(i, a, b, 0, 0);
	}


	fout << 3 << "\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (a[i][j] != b[i][j]) {
				Complex ca = a[i][j];
				Complex cb = b[i][j];
				if (ca.real() != cb.real())
				{
					fout << "(" << ca.real() << "-" << cb.real() << ", " << ca.imag() << ") ";
				}
				else {
					fout << "(" << ca.real() << ", " << ca.imag() << "-" << cb.imag() << ") ";
				}
			}
			else {
				Complex c = a[i][j];
				fout << "(" << c.real() << ", " << c.imag() << ") ";
			}
		}
		fout << "\n";
	}
}  //метод гаусса для м и д

void write34x(int i) {
	std::string s = "matrix";
	char num[5];
	_itoa(i, num, 10);
	s += num;
	s += ".txt";
	std::ofstream fout;
	fout.open(s);
	Matrix a(3, 4);
	a[0] = { {2, 2}, {4, 3} , {5,4}, {9, 11} };
	a[1] = { {3, 1}, {4,6} , {7, 7} ,{11, 12} };
	a[2] = { {4, 3}, {6, 9} , {11, 10}, {11, 13} };
	Matrix b(a);

	correct(i, a, b, 0, 3);
	correct(i, a, b,2, 2);
	//correct(i, a, b, 2, 1);

	fout << 3 << "\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (a[i][j] != b[i][j]) {
				Complex ca = a[i][j];
				Complex cb = b[i][j];
				if (ca.real() != cb.real())
				{
					fout << "(" << ca.real() << "-" << cb.real() << ", " << ca.imag() << ") ";
				}
				else {
					fout << "(" << ca.real() << ", " << ca.imag() << "-" << cb.imag() << ") ";
				}
			}
			else {
				Complex c = a[i][j];
				fout << "(" << c.real() << ", " << c.imag() << ") ";
			}
		}
		fout << "\n";
	}
}//метод гаусса для действ

int main() {
	for (int i = 0; i < 100; i++)
	{
		//write3x(i); 
		write34x(i);
		//write34(i, false);
	}
	return 0;
}