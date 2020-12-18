#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <math.h>
#include <complex>
#include <iostream>
#include <fstream>
#include <iomanip>

typedef std::complex<double> Complex;

class Matrix {
public:
	Matrix() {
		sizeh = 0;
		sizev = 0;
		a = nullptr;
	}
	Matrix(const int n, const int k) {
		a = new Complex * [n];
		for (int i = 0; i < n; i++)
		{
			a[i] = new Complex[k];
		}
		sizev = n;
		sizeh = k;
	}
	Matrix(const int n) :Matrix(n, n) {};
	Complex* operator[] (const int n) const {
		return a[n];
	};
	Matrix(const Matrix& b) {
		sizeh = b.sizeh;
		sizev = b.sizev;
		this->a = new Complex * [sizev];
		for (int i = 0; i < sizev; i++)
		{
			this->a[i] = new Complex[sizeh];
		}

		for (int i = 0; i < sizev; i++)
		{
			for (int j = 0; j < sizeh; j++)
			{
				a[i][j] = b[i][j];
			}
		}
	}

	~Matrix() {
		for (int i = 0; i < sizev; i++)
		{
			delete[] this->a[i];
		}
		delete[] a;
	};

	int size1() { return this->sizev; }
	int size2() { return this->sizeh; }

private:
	Complex** a;
	int sizeh;
	int sizev;
};

bool read(int& n, Matrix*& m_p, Matrix*& d_p, std::string path);