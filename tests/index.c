#define GDMALLOC_SOURCE
#include "../include/gd_malloc.h"

#define TEST_SOURCE
#include "test.h"

int* test_gd_malloc() {
  int* arr = gd_malloc(4 * sizeof(int));
  arr[0] = 6;
  arr[1] = 7;
  arr[2] = 8;
  arr[3] = 9;

  test(arr[0] == 6 && arr[1] == 7 && arr[2] == 8 && arr[3] == 9, "gd_malloc");
  return arr;
}

int* test_gd_calloc() {
  int* arr = gd_calloc(2, sizeof(int));
  arr[0] = 6;
  arr[1] = 7;

  test(arr[0] == 6 && arr[1] == 7, "gd_calloc");
  return arr;
}

int* test_gd_realloc(int* mem) {
  int* arr = gd_realloc(mem, 4 * sizeof(int));
  test(arr[0] == 6 && arr[1] == 7, "gd_realloc reuse");

  arr[2] = 8;
  arr[3] = 9;
  test(arr[0] == 6 && arr[1] == 7 && arr[2] == 8 && arr[3] == 9, "gd_realloc expand");

  return arr;
}

void test_gd_free(int* mem1, int* mem2) {
  gd_free(mem1);
  gd_free(mem2);
  test(1, "gd_free");
}

int main() {
  int* mem1 = test_gd_malloc();
  int* mem2 = test_gd_calloc();
  mem2 = test_gd_realloc(mem2);
  test_gd_free(mem1, mem2);

  return testStatus();
}
