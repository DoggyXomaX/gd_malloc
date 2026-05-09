#define GDMALLOC_SOURCE
#include "../include/gd_malloc.h"

#define TEST_SOURCE
#include "test.h"

int* test_gd_malloc() {
  int* arr = gd_malloc(16);
  arr[0] = 6;
  arr[1] = 7;
  arr[2] = 8;
  arr[3] = 9;

  test(arr[0] == 6 && arr[1] == 7 && arr[2] == 8 && arr[3] == 9, "gd_malloc");
  return arr;
}

void test_gd_free(int* mem) {
  gd_free(mem);
  test(1, "gd_free");
}

int main() {
  int* mem = test_gd_malloc();
  test_gd_free(mem);

  return testStatus();
}
