#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <math.h>
#include <complex>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <valarray>

#define MAX_MATRIX_CACHE 100

#include "C:\PP_31\library\include\matrix2.hxx"<double> Complex;

typedef techsoft::matrix<Complex> Matrix;

Complex operator* (Complex& c, int i) {
	Complex res(c.real() * i, i * c.imag());
	return res;
}

bool operator !=(Complex a, Complex b) {
	if (a.imag() != b.imag() || a.real() != b.real()) return true;
	return false;
}

bool read(int& n, Matrix*& m_p, Matrix*& d_p);