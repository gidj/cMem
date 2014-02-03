#ifndef MEM_H_
#define MEM_H_ 

#include <stddef.h>

  /* Macros that make calling our encapsulated memory interface easier.*/ 

#define ALLOC(nbytes) \
    mem_alloc((nbytes), __FILE__, __LINE__)
#define CALLOC(count, nbytes) \
    mem_calloc((count), (nbytes), __FILE__, __LINE__)

/* These two macros implement the common C idiom of allocating an object via
 * its size. Example:
 *
 * int * p;
 * p = malloc(sizeof(*p));
 * */ 
#define NEW(p) ((p) = ALLOC((size_t)sizeof *(p)))
#define NEWO(p) ((p) = CALLOC(1, (size_t)sizeof *(p)))

/* FREE() takes a pointer to memory to be freed, tries to free it, and then
 * sets it to the NULL pointer. */ 
#define FREE(ptr) \
    ((void)(mem_free((ptr), __FILE__, __LINE__), (ptr) = 0))
 
#define RESIZE(ptr, nbytes) \
    ((ptr) = mem_resize((ptr), (nbytes), __FILE__, __LINE__))

extern void* mem_alloc(size_t nbytes, const char *file, int line);
extern void* mem_calloc(size_t count, size_t nbytes, const char *file, int line);

extern void mem_free(void *ptr, const char *file, int line);

extern void* mem_resize(void *ptr, size_t nbytes, const char *file, int line);
#endif
