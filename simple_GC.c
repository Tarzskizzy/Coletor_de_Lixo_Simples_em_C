#include <stdlib.h>
#include "simple_GC.h"
void *gc_malloc(size_t size)
{
  mem_t* Node;//criando um node temporário
  Node = malloc(sizeof(mem_t));//allocando um novo nó
  Node->Mem = malloc(size);//allocando novo espaço que foi requisitado na função
  //
  Node->prox = _HEAD;//var próx agr tem endereço contido na _HEAD
  _HEAD = Node;//_HEAD agr passa a ser o NODE atual;
  //
  //mem_t* _HEAD;
  return Node->Mem;//retornando a variável que foi criada
}
void gc_free(void* mem)
{
  mem_t* temp;
  mem_t* prev;
  if (_HEAD->Mem == mem)
  {
    temp = _HEAD->prox;
    free(_HEAD->Mem);
    free(_HEAD);
    _HEAD = temp;
  }
  else 
  {
    temp = _HEAD;
    prev = NULL;
    while (temp != NULL)   
    {
      if (temp->Mem == mem)
      {
        prev->prox = temp->prox;
        free(temp->Mem);
        free(temp);
      }
      prev = temp;
      temp = temp->prox;
    }
  }

}

void gc_free_all(mem_t *_head){

  while (_HEAD != NULL)
  {
    mem_t* tmp = _HEAD;
    _HEAD = _HEAD->prox;
    free(tmp->Mem);
    free(tmp);
  }
}
