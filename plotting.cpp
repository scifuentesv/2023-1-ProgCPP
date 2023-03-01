// Beyla Darassia Martinez Perez
// Nicolas Acero Vargas
// Sergio Andres Cifuentes Vasquez
// Juan Manuel Gonzalez
// Sebastian Prieto Cruz

#include <iostream>
#include <fstream>
#include <cmath>

double mysin(double x, int nterms);
int factorial(int m);
double extension(double x, int terminos);
double pade(double x);

int main(int argc, char **argv)
{
  double x{0.0};

  if(argc != 2) {
    std::cerr << "ERROR.\nUsage:\n" << argv[0] << " x \n";
    return 1;
  }

  x = std::stod(argv[1]);
  std::ofstream fout("datos.txt");
  for (int ite = 1; ite <= 10 ; ite++)
  {
    double exact = std::sin(x);
    double myval = mysin(x, ite);
    double otherval = extension(x, ite);
    double padeval = pade(x);
    fout << ite << "\t" << myval << "\t" << otherval << "\t" << padeval << "\t" << exact << "\t" << std::fabs(1.0 - myval/exact) << "\t" << std::fabs(1.0 - otherval/exact) << "\t" << std::fabs(1.0 - padeval/exact)
         << "\n";
  }
  fout.close();
  return 0;
}

double mysin(double x, int nterms)
{
  double total = 0.0;
  for(int k = 0; k <= nterms; ++k) {
    total += std::pow(-1, k)*std::pow(x, 2*k+1)/factorial(2*k+1);
  }
  if(nterms>5){
    total = 0;
  }
  return total;
}


double extension(double x, int terminos)
{
  double total = 0.0;
  double k1 = 0 ;
  k1 = mysin(x, 0);
  total = mysin(x, 0);
  for (int k = 1; k<=terminos; k++)
  {
  k1 *= (-1*((std::pow(x,2))/((2*k)*(2*k+1))));
  total += k1;
  }
  
  return total;
}

// factorial(int m)
//   result = 1
//   for k <= m
//     result *= k
//   return result
int factorial(int m)
{
  int result = 1;
  for (int k = 2; k <= m; ++k) {
    result *= k;
  }
  return result;
}

double pade(double x)
{
    double k=((12671.0/4363920.0)*std::pow(x,5.0)-(2363.0/18183.0)*std::pow(x,3.0)+x)/(1.0+(445.0/12122.0)*std::pow(x,2)+(601.0/872784.0)*std::pow(x,4.0)+(121.0/16662240.0)*std::pow(x,6.0));

    return k;
}
