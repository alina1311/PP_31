#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <math.h>
#include <complex>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <valarray>

#define MAX_MATRIX_CACHE 100

// надо указать свой путь
#include "/PP_31/library/include/matrix2.hxx"

typedef std::complex<double> Complex;

typedef techsoft::matrix<Complex> Matrix;

bool read(int& n, Matrix*& m_p, Matrix*& d_p, std::string path);