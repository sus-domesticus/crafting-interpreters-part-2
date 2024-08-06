#include "chunk.h"
#include "common.h"
#include "debug.h"

void writeConstant(Chunk *chunk, Value value, int line) {
  int index = addConstant(chunk, value);
  if ((index >> 8) == 0) {
    writeChunk(chunk, OP_CONSTANT, line);
  } else {
    writeChunk(chunk, OP_CONSTANT_LONG, line);
  }
  writeChunk(chunk, index, line);
  if ((index >> 8) != 0) {
    writeChunk(chunk, index >> 8, line);
  }
}

// TODO: this is an attempt at challenge 2 from
// [here](https://craftinginterpreters.com/chunks-of-bytecode.html#challenges)
int main(int argc, const char *argv[]) {
  Chunk chunk;
  initChunk(&chunk);

  for (int i = 0; i < (1 << 8) + 10; i++) {
    writeConstant(&chunk, (i * 3 + 5) % 7, 123);
  }

  writeChunk(&chunk, OP_RETURN, 123);

  disassembleChunk(&chunk, "test chunk");
  freeChunk(&chunk);
  return 0;
}
