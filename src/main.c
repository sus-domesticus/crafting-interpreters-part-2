#include "chunk.h"
#include "common.h"
#include "debug.h"

// TODO: this is an attempt at challenge 1 from
// [here](https://craftinginterpreters.com/chunks-of-bytecode.html#challenges)
int main(int argc, const char *argv[]) {
  Chunk chunk;
  initChunk(&chunk);

  int constant = addConstant(&chunk, 1.2);
  writeChunk(&chunk, OP_CONSTANT, 123);
  writeChunk(&chunk, constant, 123);

  writeChunk(&chunk, OP_RETURN, 123);

  disassembleChunk(&chunk, "test chunk");
  freeChunk(&chunk);
  return 0;
}
