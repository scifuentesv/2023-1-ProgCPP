#include <cmath>
#include <iostream>
#include <string>

bool isodd(int n);

int main(void) {
  long N = 0;
  std::cout << "Hello! Enter a random positive integer: "
            << "\n";
  std::cin >> N;
  long a = 0;
  long b = 1;
  long c = 0;
  long sum = 0;
  std::cout << "Your automatically generated Fibonacci sequence with a maximun "
               "value of "
            << N << " is:\n";
  for (a <= N; c = a + b;) {
    if (N < c) {
      std::cout << "...";
      break;
    }
    std::cout << c << ", ";
    if (isodd(c)) {
      sum += c;
    }
    a = b;
    b = c;
  }
  std::cout << "\nGiven the previous Fibonacci sequence bounded in " << N
            << ", the sum of the odd terms is equal to:  " << sum << ".\n";

  return 0;
}

bool isodd(int n) {
  if (n % 2 == 0) {
    return false;
  }
  return true;
}
