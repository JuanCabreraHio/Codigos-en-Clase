#include <iostream>
#include <cmath>
#include <functional>
#include <fstream>
#include <iomanip>

double potencial(double x);
using fptr = std::function<double(double)>;
double central_diff(double x, double h, fptr f);
using algptr = std::function<double(double, double, fptr)>;
double richardson(double x, double h, fptr f, algptr alg, int alpha);
double electricfield(double x, double h);

int main(int argc, char **argv) {
    const double h = 0.02;

    std::ofstream file("campo.txt");
    file << std::scientific << std::setprecision(16);

    for(double x = 0; x <= 2.5; x += h) {
        double exact_result = 2 * std::sin(x) + 2 * x * std::cos(x); // derivada de 2x*sin(x)
        double richardson_result = richardson(x, h, potencial, central_diff, 2);

        file << x << " "
             << exact_result << " "
             << richardson_result 
             << std::endl;
    }

    file.close();
    return 0;
}

double potencial(double x) {
    return 2 * x * std::sin(x);
}

double central_diff(double x, double h, fptr f) {
    return (f(x + h) - f(x - h)) / (2 * h);
}

double richardson(double x, double h, fptr f, algptr alg, int alpha) {
    double aux = std::pow(2.0, alpha);
    double val1 = alg(x, h, f);
    double val2 = alg(x, h / 2.0, f);
    return (aux * val2 - val1) / (aux - 1.0);
}
