#include "simple_GC.h"

int main(){
  char *str;

  for (int i = 0; i<100; i++)
  {
    str = gc_malloc(1);
  }
  gc_free(&(str[8]));
  gc_free_all(_HEAD);
}
