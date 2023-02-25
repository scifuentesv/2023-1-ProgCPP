#include <cmath>
#include <iostream>

bool isprime(int n);

int main(void) {
  int N = 0;
  long sum = 0;
  int n = 0;
  int i = 0;
  std::cout << "Hello! Enter a random positive integer: "
            << "\n";
  std::cin >> N;
  std::cout << "The sum of the primes numbers that are equal or less than " << N
            << " is: ";
  for (n = 2; i != N, n <= N; n++, i++) {
    if (isprime(n)) {
      sum += n;
      if (i == N) {
        break;
      }
    }
  }
  std::cout << sum << ".\n";

  return 0;
}

bool isprime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
