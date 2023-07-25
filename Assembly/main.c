#include <stdio.h>

int main(void) {
  int a = 0;
  // option 1
  __asm__("movl %1, %0\n"
          : "=g"(a)  // salida, %0 = a
          : "g"(5)   // entrada, %1 = 5
          :          // clobbers
  );
  printf("a: %d\n", a);

  // option 2
  __asm__("movl %[value_of_a], %[variable_a]\n"
          : [variable_a] "=g"(a)
          : [value_of_a] "g"(7)
          :);
  printf("a: %d\n", a);

  // option 3
  __asm__(
      "movl %1,%%eax\n"
      "movl %%eax,%0\n"
      : "=g"(a)
      : "g"(15)
      : "%eax");
  printf("a: %d\n", a);

  // task several variables, opt 1
  a = 0;
  int b = 0;
  int c = 0;
  int d = 0;
  int e = 0;
  __asm__(
      "movl %[value_a], %[a]\n"
      "movl %[value_b], %[b]\n"
      "movl %[value_c], %[c]\n"
      "movl %[value_d], %[d]\n"
      "movl %[value_e], %[e]\n"
      : [a] "=g"(a), [b] "=g"(b), [c] "=g"(c), [d] "=g"(d), [e] "=g"(e)
      : [value_a] "g"(1), [value_b] "g"(2), [value_c] "g"(3), [value_d] "g"(4),
        [value_e] "g"(5)
      :);
  printf("a = %d\n", a);
  printf("b = %d\n", b);
  printf("c = %d\n", c);
  printf("d = %d\n", d);
  printf("e = %d\n", e);

  // task several variables, opt 2
  a = 0;
  b = 0;
  c = 0;
  d = 0;
  e = 0;
  __asm__("movl %5, %0\n"
          "movl %6, %1\n"
          "movl %7, %2\n"
          "movl %8, %3\n"
          "movl %9, %4\n"
          : "=g"(a), "=g"(b), "=g"(c), "=g"(d), "=g"(e)
          : "g"(1), "g"(2), "g"(3), "g"(4), "g"(5)
          :);
  printf("a = %d\n", a);
  printf("b = %d\n", b);
  printf("c = %d\n", c);
  printf("d = %d\n", d);
  printf("e = %d\n", e);

  return 0;
}
