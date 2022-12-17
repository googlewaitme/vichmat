#include <iostream>
#include <cmath>
#include <fstream>
#include <iostream>
#include <cassert>
#include <vector>

#define Matrix(n, m)		std::vector<std::vector<double>> (n, std::vector<double>(m)) 
#define MatrixType          std::vector<std::vector<double>>


void swap_rows(MatrixType&, int, int);
void forward_gauss(MatrixType&);
void reverse_gauss(MatrixType, std::vector<double>&);
void print_matrix(MatrixType);


int main() {

	std::ifstream fin("input.txt");
	int n;
	fin >> n;
	MatrixType matrix=Matrix(n, n+1);

	double temp;
	for (int i=0; i<n; i++) {
		for (int j=0; j<(n+1); j++) {
			fin >> temp;
			matrix[i][j] = temp;
			std::cout << temp << " ";
		}
		std::cout << std::endl;
	}

	swap_rows(matrix, 0, 1);

	std::cout << "Matrix\n";
	for (int i=0; i<n; i++) {
		for (int j=0; j<(n+1); j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::vector<double> answer(n);

	forward_gauss(matrix);


	for (int i=0; i<n; i++) {
		for (int j=0; j<(n+1); j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}


	reverse_gauss(matrix, answer);

	std::cout << "Answer\n";
	for (int i=0; i<n; i++) {
		std::cout << answer[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}


void swap_rows(MatrixType &matrix, int i, int j)
{
	int n = matrix.size();
	for (int k=0; k<=n; k++)
		std::swap(matrix[i][k], matrix[j][k]);
}


void forward_gauss(MatrixType &matrix) {
	std::cout << "forward Gauss" << std::endl;
	int n = matrix.size();
	double koef, max_value;
	int max_value_index;
	for (int k=0; k<n; k++) {
		max_value=abs(matrix[k][k]);
		max_value_index=k;

		for (int i=k+1; i<n; i++)
			if (abs(matrix[i][k]) > max_value) {
				max_value = abs(matrix[i][k]);
				max_value_index = i;
			}

		assert(matrix[max_value_index][k] != 0);

		if (k != max_value_index) {
			swap_rows(matrix, k, max_value_index);
		}

		std::cout << "\n ***\n"; print_matrix(matrix);
		for (int i=n; i>=k; i--) {
			matrix[k][i] /= matrix[k][k];
		}
		for (int i=k+1; i<n; i++) {
			koef = matrix[i][k]/matrix[k][k];
			for (int j=k+1; j <= n; j++) {
				matrix[i][j] -= matrix[k][j] * koef;
			}
			matrix[i][k] = 0;
		}
	}
}


void reverse_gauss(MatrixType matrix, std::vector<double> &answer)
{
	std::cout << "reverse gauss" << std::endl;
	int n = matrix.size();
	for (int k=n - 1; k >= 0; k--) {
		for (int i=k+1; i < n; i++) {
			matrix[k][n] -= matrix[k][i] * answer[i];
		}	
		answer[k] = matrix[k][n];
	}
}


void print_matrix(MatrixType matrix)
{
	int n = matrix.size();
	for (int i=0; i<n; i++) {
		for (int j=0; j<=n; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
