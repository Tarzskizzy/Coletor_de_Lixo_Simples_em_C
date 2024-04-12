#ifndef GARBAGE_SIMPLES
#define GARBAGE_SIMPLES
#include <stdlib.h>
typedef struct Node_memoria//lista encadeada que tem armazenado todos os ponteiros
{
    void *Mem; //ponteiro para a memória que foi alocada pelo meu malloc customizado
    struct Node_memoria *prox;//ponteiro para o próximo nó da lista encadeada
}mem_t;
//inicializando a cabeça
static mem_t* _HEAD;

void *gc_malloc(size_t size);
void gc_free(void* ptr);
void gc_free_all();

#endif
