#ifndef GDMALLOC_HEADER
#define GDMALLOC_HEADER

#include <stddef.h>

void* gd_malloc(size_t size);
void gd_free(void* memory);

#endif
/* =============================== */
#ifdef GDMALLOC_SOURCE

#include <malloc.h>

void* gd_malloc(size_t size) {
  return malloc(size);
}

void gd_free(void* memory) {
  free(memory);
}

#undef GDMALLOC_SOURCE
#endif
