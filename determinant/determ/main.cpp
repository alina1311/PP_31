#include "MMatrix.h"
#include <vector>
#include <algorithm>

bool operator !=(Complex a, Complex b) {
	if (a.imag() != b.imag() || a.real() != b.real()) return true;
	return false;
}

void x2array(std::vector<Matrix>& v, int i, int j, Complex c) {
	int size = v.size();
	for (int k = 0; k < size; k++)
	{
		Matrix a(v[k]);
		a[i][j] = c;
		v.push_back(a);
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
	std::vector<double> det_real;	// ����� �������������� ������ �������������
	std::vector<double> det_img;	// ����� ������ ������ �������������

	// ������� ������ � ����������� �� ����������
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((*f)[i][j] != (*t)[i][j]) {
				x2array(array, i, j, (*t)[i][j]);
			}
		}
	}

	// ������� �������������
	for (int i = 0; i < array.size(); i++)
	{
		auto c = array[i].det();
		det_real.push_back(c.real());
		det_img.push_back(c.imag());
	}

	// ����� ���������
	std::sort(det_real.begin(), det_real.end());
	std::sort(det_img.begin(), det_img.end());
	int s = det_img.size();
	s--;

	double r = sqrt((det_real[s] - det_real[0]) * (det_real[s] - det_real[0])
		+ (det_img[s] - det_img[0]) * (det_img[s] - det_img[0])) / 2;

	std::ofstream fout;
	fout.open("result_57.txt", std::ios_base::app);
	fout << r << "\n";
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
