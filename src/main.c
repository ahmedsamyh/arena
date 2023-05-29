#include <stdio.h>
#define ARENA_IMPLEMENTATION
#include "arena.h"

int main(int argc, char *argv[]) {
  Arena *arena = Arena_make(1 * KB);

  size_t array_size;

  do {
    printf("Enter size of bytes to allocate: ");
    scanf("%zd", &array_size);
  } while (array_size == 0);

  size_t bytes = sizeof(char) * array_size;
  char *array = (char *)Arena_alloc(arena, bytes);

  if (array == NULL) {
    fprintf(stderr,
            "ERROR: Could not allocate %zd bytes! (arena have only %zd bytes "
            "allocated)\n",
            array_size, arena->size);
    goto pause;
  }

  for (size_t i = 0; i < array_size; ++i) {
    array[i] = (char)i;
  }

  printf("Allocated %zd bytes!\n", bytes);
pause:
  system("pause");

  Arena_free(arena);

  return 0;
}
