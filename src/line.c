#include <stdio.h>

#include "line.h"
#include "memory.h"

void initLineArray(LineArray *array) {
  array->lines = NULL;
  array->capacity = 0;
  array->count = 0;
}

void writeLineArray(LineArray *array, int line) {
  if (array->count > 0) {
    if (array->lines[array->count - 1].line == line) {
      array->lines[array->count - 1].count++;
      return;
    }
  }

  if (array->capacity < array->count + 1) {
    int oldCapacity = array->capacity;
    array->capacity = GROW_CAPACITY(oldCapacity);
    array->lines = GROW_ARRAY(Line, array->lines, oldCapacity, array->capacity);
  }

  array->lines[array->count] = (Line){line, 1};
  array->count++;
}

void freeLineArray(LineArray *array) {
  FREE_ARRAY(Line, array->lines, array->capacity);
  initLineArray(array);
}

int getLine(LineArray *array, int index) {
  for (int i = 0; i < array->count; i++) {
    if (index <= 0) {
      return array->lines[i].line;
    }
    index -= array->lines[i].count;
  }
  return -1;
}
