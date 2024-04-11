#include <stdlib.h>

int main(){
  char *str;

  for (int i = 0; i<100; i++)
  {
    str = malloc(1);
  }
  free(str);
}
