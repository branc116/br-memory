#define BR_MEMORY_TRACER_IMPLEMENTATION
#include "../br_memory.h"

int main(void) {
  void* mem = BR_MALLOC(128);
  mem = BR_REALLOC(mem, 256);
  mem = BR_REALLOC(mem, 512);
  mem = BR_REALLOC(mem, 1024);
  BR_FREE(mem);
  br_memory_stack_print(0);
  br_memory_finish();
  return 1;
}
