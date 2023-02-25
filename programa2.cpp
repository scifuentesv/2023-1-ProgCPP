#include <cmath>
#include <iostream>
#include <string>

bool isprime(int n);

int main(void) {
  long N = 0;
  std::cout << "Hello! Enter a random positive integer: "
            << "\n";
  std::cin >> N;
  std::string str = std::to_string(N);
  long n = 0;
  long N2 = std::stol(str);
  std::cout << "The the highest prime factor of " << N << " is: ";
  for (n = 2; n <= N2;) {
    if (N2 % n == 0 && isprime(n)) {
      N2 /= n;
    } else {
      n++;
    }
  }
  std::cout << n << ".\n";

  return 0;
}

bool isprime(int n) {
  for (long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
