# Como usar a Biblioteca ?

antes de tudo deve-se importar a biblioteca com o nome `simple_GC.h` e começar a usar apenas 3 funções que foram criadas.

Código exemplo:
```C
#include "simple_GC.h"//importando a biblioteca
/* por debaixo dos panos, a biblioteca cria um ponteiro que irá apontar para o 
início de uma lista-encadeada, atualmente sem nenhum valor alocado no momento,
sendo chamada de _HEAD
POR FAVOR NÃO TENTE ADULTERAR ESTA VARIÁVEL, assim foi definida com "_"
*/

int main(){
  char *str;//definindo uma string sem tamanho

  for (int i = 0; i<100; i++)
  {
    str = gc_malloc(1);//alocando de forma descontrolada, incentivando a perda e posteriormente uma possível memory leak
  }
  gc_free(&(str[8]));//liberando um pedaço aleatório da memória, para testar se lista encadeada perde suas conexões
  gc_free_all();//liberando todo o espaço reversado para guardar os endereços e seus respectivos locais alocados
}
```

Teste usando o Valgrind:
```sh
==76945== Memcheck, a memory error detector
==76945== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==76945== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==76945== Command: ./Main
==76945==
==76945==
==76945== HEAP SUMMARY:
==76945==     in use at exit: 0 bytes in 0 blocks
==76945==   total heap usage: 200 allocs, 200 frees, 1,700 bytes allocated
==76945==
==76945== All heap blocks were freed -- no leaks are possible
==76945==
==76945== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
