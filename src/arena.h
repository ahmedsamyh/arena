#ifndef _ARENA_H_
#define _ARENA_H_

#include <assert.h>
#include <stdlib.h>

#define KB ((size_t)1000)
#define MB (KB * KB)
#define GB (MB * KB)

typedef struct {
  void *arena;
  size_t size;
  size_t used;
} Arena;

Arena *Arena_make(size_t size);
void *Arena_alloc(Arena *ar, size_t size);
void Arena_free(Arena *ar);

//////////////////////////////////////////////////
#ifdef ARENA_IMPLEMENTATION

Arena *Arena_make(size_t size) {
  Arena *arena = (Arena *)calloc(1, sizeof(Arena));
  arena->size = size;
  arena->used = 0;
  arena->arena = malloc(size);
  return arena;
}
void *Arena_alloc(Arena *ar, size_t size) {
  if (ar->used + size > ar->size) {
    // out of memory in arena
    return NULL;
  }

  void *ptr = (char *)ar->arena + ar->used;
  ar->used += size;
  return ptr;
}
void Arena_free(Arena *ar) {
  free(ar->arena);
  free(ar);
}
#endif /* ARENA_IMPLEMENTATION */
#endif /* _ARENA_H_ */
