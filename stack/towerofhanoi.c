#include <stdio.h>

void TOH(int n, int A, int B, int C) {
  if (n > 0) {
    TOH(n - 1, A, C, B); // Move n-1 discs from A to B using C
    printf("Move a disc from %d to %d\n", A, C); // Move the nth disc from A to C
    TOH(n - 1, B, A, C); // Move n-1 discs from B to C using A
  }
}

int main() {
  int n;
  printf("Enter the number of discs you want to pass: ");
  scanf("%d", &n);
  TOH(n, 1, 2, 3); // Passing 1 as source, 2 as auxiliary, and 3 as destination
  return 0;
}