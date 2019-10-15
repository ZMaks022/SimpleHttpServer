#include "header.h"

void ReadFile (const char* name) {
  FILE* file;
  file = fopen(name, "r");
  char temp;

  while((temp = getc(file)) != EOF) {
    putchar_unlocked(temp);
  }
}
