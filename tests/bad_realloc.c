#define BR_MEMORY_TRACER_IMPLEMENTATION
#include "../br_memory.h"

int main(void) {
  void* mem = BR_MALLOC(128);
  BR_REALLOC(mem, 256);
  BR_FREE(mem);
  return 0;
}

