#include "MMatrix.h"
#include <vector>
#include <algorithm>

void x2array(std::vector<Matrix>& v, int n, int i, int j, Complex c) {
	int size = v.size();
	for (int k = 0; k < size; k++)
	{
		Matrix a(v[k]);
		a[i][j] = c;
		v.push_back(a);
	}
}

bool operator !=(Complex a, Complex b) {
	if (a.imag() != b.imag() || a.real() != b.real()) return true;
	return false;
}

void Triangular(Matrix& m, int n) {
	
	for (int i = 0; i < n; i++)
	{
		auto a = m[i][i];
		for (int j = 0; j < n + 1; j++)
		{
			m[i][j] = m[i][j] / a;
		}
		for (int j = i + 1; j < n; j++)
		{
			auto b = m[j][i];
			for (int k = 0; k < n + 1; k++)
			{
				m[j][k] = m[j][k] - m[i][k] * b;
			}
		}
	}

	for (int i = n-2; i >= 0; i--)
	{
		for (int j = i+1; j < n+1; j++)
		{			
			for (int k = i; k >= 0; k--)
			{
				m[k][j] = m[k][j] - m[i+1][j] * m[k][j];
			}
		}
	}
}

int not_main(std::string path) {
	int n;							// ������ �������
	// �� � �� - 2 ������� � ������ � ������� ���������� ����������
	Matrix* f = nullptr, * t = nullptr;
	if (!read(n, f, t, path)) return 0;	// ������ ������� �� ����� "matrix.txt"

	std::vector<Matrix> array;		// ����� ������ �� ����� ���������� ����������
	Matrix p = *f;
	array.push_back(p);				// ��������� �������

	// ������� ������ � ����������� �� ����������
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			if ((*f)[i][j] != (*t)[i][j]) {
				x2array(array, n, i, j, (*t)[i][j]);
			}
		}
	}

	// ���������� ������ � ������������ ����
	for (int i = 0; i < array.size(); i++)
	{
		Triangular(array[i], n);
	}

	// ���� �������
	std::vector<std::vector<double>> dig;	// �������� � ������ �����

	for (int i = 0; i < n; i++)
	{
		std::vector<double> r;
		std::vector<double> im;

		for (int k = 0; k < array.size(); k++)
		{
			r.push_back(array[k][i][n].real());
			im.push_back(array[k][i][n].imag());
		}

		std::sort(r.begin(), r.end());
		std::sort(im.begin(), im.end());
		dig.push_back(r);
		dig.push_back(im);
	}

	// �����
	int s = array.size();
	s--;
	double min = 0;
	double max = 0;
	for (int i = 0; i < 6; i+=2)
	{
		min += dig[i][0] * dig[i][0];
		max += dig[i][s] * dig[i][s];
		min += dig[i+1][0] * dig[i+1][0];
		max += dig[i+1][s] * dig[i+1][s];
	}
	double rad = 0;
	rad = abs((sqrt(max) - sqrt(min))) / 2;

	std::ofstream fout;
	fout.open("result_8.txt", std::ios_base::app);
	fout << rad << "\n";
	return 0;
}

int main() {
	char* path;
	for (int i = 0; i < 100; i++)
	{
		std::string s = "matrix";
		char num[5];
		_itoa(i, num, 10);
		s += num;
		s += ".txt";
		not_main(s);
	}
}