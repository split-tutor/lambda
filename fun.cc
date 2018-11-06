#include <iostream>

int add(int x, int y)
{
  return x + y;
}

// Create a function class, overloading `operator()`
class Less_than {
  int z;

public:
  Less_than() = delete;
  Less_than(int z) : z {z} {}

  bool operator()(int x) {
    return x < z;
  };
};

int main()
{
  // C++11 type aliases
  using f_ptr = int(*)(int, int);

  // C-style function pointers
  int (*fp)(int, int);
  fp = add;

  f_ptr fp2 {add};

  std::cout << "fp(3, 4) = " << fp(3, 4)
            << "\nfp2(4,5) = " << fp2(4, 5) << '\n';

  // Function class with overloaded `operator()`
  Less_than lt42 = Less_than(42);
  std::cout << "lt42(17) = " << lt42(17)
            << "\nlt42(48) = " << lt42(48) << '\n';

  // C++ lambda
  int x = 3;
  auto lambda = [x](int y){ return x + y; };

  std::cout << "lambda(7) = " << lambda(7) << '\n';

  return 0;
}
