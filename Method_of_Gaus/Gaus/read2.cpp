#include "MMatrix.h"

bool read_digital(double& di, std::ifstream& fin, bool first) {
	fin >> di;
	char c;
	fin >> c;
	if (c == ')') {
		return true;
	}
	if (c == '-') {
		if (first) {
			double n;
			fin >> n;
		}
		else {
			fin >> di;
		}
		fin.ignore(1);
		return true;
	}
	return false;
}

bool read_element(Complex& c, std::ifstream& fin, bool first) {
	char a;
	fin >> a;
	if (a != '(') {
		std::cout << "File is incorrect" << std::endl;
		return false;
	}
	double r;
	double i;
	double n;	// nothing
	fin >> r;
	fin >> a;
	bool flag;
	if (a == ',') {
		fin.ignore(1);
		flag = read_digital(i, fin, first);
	}
	else
		if (a == '-') {
			if (first) {
				fin >> n;
				fin.ignore(2);
				flag = read_digital(i, fin, first);
			}
			else {
				fin >> r;
				fin.ignore(2);
				flag = read_digital(i, fin, first);
			}
		}
		else
			if (a == ')') {
				i = 0;
				flag = true;
			}
			else {
				std::cout << "File is incorrect" << std::endl;
				return false;
			}
	if (!flag) {
		std::cout << "File is incorrect" << std::endl;
		return false;
	}
	c = Complex(r, i);
	return true;
}

bool read(int& n, Matrix*& m_p, Matrix*& d_p, std::string path) {
	std::ifstream fin(path, std::ios_base::in);
	if (!fin.is_open()) {
		std::cout << "File is not open" << std::endl;
		return false;
	}

	fin >> n;
	if (!fin.good()) {
		std::cout << "File is incorrect" << std::endl;
		return false;
	}
	fin.ignore(1);

	static Matrix m(n, n+1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n+1; j++)
		{
			Complex c = 0;
			if (!read_element(c, fin, true)) {
				std::cout << "File is incorrect" << std::endl;
				return false;
			}
			m[i][j] = c;
			fin.ignore(1);
		}
		fin.ignore(1);
	}
	m_p = &m;
	
	fin.seekg(0, std::ios::beg);
	fin >> n;
	fin.ignore();
	static Matrix d(n, n+1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n+1; j++)
		{
			Complex c = d[i][j];
			if (!read_element(c, fin, false)) {
				std::cout << "File is incorrect" << std::endl;
				return false;
			}
			d[i][j] = c;
			fin.ignore(1);
		}
		fin.ignore(1);
	}
	d_p = &d;
	return true;
}