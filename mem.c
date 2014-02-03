#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "mem.h"


extern void* mem_alloc(size_t nbytes, const char *file, int line)
{
  assert(nbytes > 0);
  void *ptr;

  ptr = malloc(nbytes);
  if (!ptr)
  {
    printf("Memory was not allocated. Exiting...\n");
    exit(EXIT_FAILURE);
  }

  return ptr;
}

extern void* mem_calloc(size_t count, size_t nbytes, const char *file, int line)
{
  assert(count > 0 && nbytes > 0);
  void *ptr;

  ptr = calloc(count, nbytes);
  if (!ptr)
  {
    printf("Memory was not allocated. Exiting...\n");
    exit(EXIT_FAILURE);
  }

  return ptr;
}

extern void mem_free(void *ptr, const char *file, int line)
{
  if (ptr)
  {
    free(ptr);
  }
}

extern void* mem_resize(void *ptr, size_t nbytes, const char *file, int line)
{
  assert(ptr);
  assert(nbytes > 0);

  ptr = realloc(ptr, nbytes);
  if (!ptr)
  {
    printf("Memory was not allocated. Exiting...\n");
    exit(EXIT_FAILURE);
  }

  return ptr;
}

