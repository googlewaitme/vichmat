#include <iostream>
#include <cmath>
#include <cassert>
#define 	EPS		0.0005
#define assertm(exp, msg) assert(((void)msg, exp))


double func(double x);
double func1(double x);
double func2(double x);
double dihotomii_method(double start, double end);
double hord_method(double start, double end);
double newton_method(double x0);


int main() {
	// x^3 + x + 3 = 0;
	double start = -2, end = -1;

	double newton_method_answer = newton_method(start);
	std::cout << "newton_method_answer: "<< newton_method_answer << std::endl;


	double dihotomii_method_answer = dihotomii_method(start, end);
	std::cout << "dihotomii_method_answer: "<< dihotomii_method_answer << std::endl;

	double hord_method_answer = hord_method(start, end);
	std::cout << "hord_method_answer: "<< hord_method_answer << std::endl;

	return 0;
}

double func(double x) { return x*x*x + x + 3; }

double func1(double x) { return 3*x*x + 1; } // производная первого порядка

double func2(double x) { return 6*x; }	// производная второго порядка

double newton_method(double x0) {
	assertm(fabs(func(x0)*func2(x0)/(func1(x0)*func1(x0))) < 1, "Процесс расходится x0 выбран не правильно.");
	double xi = x0;
	while (fabs(func(xi)) > EPS) {
		xi = xi - func(xi)/func1(xi);
	}
	return xi;
}

double hord_method(double start, double end) {
	// [start, end] - где мы ищем 
	assertm(func(start) * func(end) < 0, "Интервал [a, b] выбран не правильно");
	double a = start, b = end, c;
	while (fabs(b - a) > EPS) {
		c = a - (b-a) * func(a) / (func(b) - func(a));
		if (func(c) * func(a) > 0) {
			b = c;
		} else {
			a = c;
		}
	}
	return c; 
}

double dihotomii_method(double start, double end) {
	// По сути это метод бинарного поиска,
	assertm(func(start) * func(end) < 0, "Интервал [a, b] выбран не правильно");
	double middle;
	while (fabs(start-end) > EPS) {
		middle = (start + end) / 2;
		if (func(start)*func(middle) < 0) {
			end = middle;
		} else {
			start = middle;
		}
	}
	middle = (start+end) / 2;
	return middle;
}
