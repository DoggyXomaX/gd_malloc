# GameDev malloc

## Description
Custom header-only GameDev malloc library for study purposes.

## Usage
```c
#define GDMALLOC_SOURCE
#include "gd_malloc.h"
```

## Methods
```c
void* gd_malloc(size_t size);
void* gd_calloc(size_t count, size_t size);
void* gd_realloc(void* memory, size_t size);
void gd_free(void* memory);
```
