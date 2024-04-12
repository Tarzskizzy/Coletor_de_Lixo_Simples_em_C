# Conclusão de Curso - Fundação Estudar (Havard)
- Aqui eu apresento um pequeno projetinho que fiz como projeto de conclusão de curso de havard feita pela instituição Fundação Estudar
- meu Tema foi focado na linguagem C, devido a menos conhecimento sobre frameworks e melhor aprimoramento nos conhecimentos de algoritmos
  - Thema -> Simples Garbage Colletor escrito em C
### O que é um Garbage collector ?
Uma das funções mais incríveis presentes na linguagem C se encontra na biblioteca `<stdlib.h>`, através das 2 principais funções, `malloc()` (alocar espaço na memória RAM) e `free()` (Liberar o espaço que foi alocado pela função anterior), entretanto, um dos maiores erros que programadores cometem é de esqueçer de dar `free()` em todos as variáveis em que você fez o `malloc()` gerando ao final do programa, diversos valores lixos espalhados pela memória RAM, gerando o que conhecemos como memory leak (vazamento de memória).
- **E para que eles servem ?** 
  - Ai é que entram os GC's, eles são responsáveis por lembrar e guardar na memória uma espécie de "lista" de supermercado, onde tem anotado todas as vezes que você fez um `malloc()`, onde, ao final do programa, ele só vai lá e cria um `free()` para todas as variáveis que foram alocadas.
- **porquê usar elas ?**
  - simples, ao contrário de diversas linguagem de alto nível como Python e Javascript, a linguagem C não possui muitas funcionalidades padrão da linguagem, ou seja, as limitações existentes nos computadores são encontrados em todas as linguagens de programação, mas, linguagem de alto nível apresentam soluções já prontas para essas limitações, como Estruturas de Dados intregradas, evitando o trabalho do programandor de entender o que acontece por debaixo do capô.
  - ao contrário das linguagens de alto nível, a linguagem C não se dá ao "luxo" de ter algumas funcionalidades que são consideradas básicas por diversas linguagens de programação, como é o caso do **Garbage Collector**, por isso, acaba sendo uma das melhores linguagens quando você quer estudar o que acontece por debaixo do capô, como, entender por exemplo o funcionamento de uma "Lista Encadeada" usadas em filas como seu `Ctrl+C` , ou pilhas que estão no seu `Ctrl+Z`.
 
# Como você construiu ele ?
- minha principal ideia foi construir uma lista-encadeada, onde se armazenava o endereço de todas as variáveis que foram allocadas pela função que criei chamada `gc_malloc()`, onde ao final do programa, você apenas precisaria digitar o `gc_free_all()` para liberar não somente as variáveis que foram criadas, mas também a lista encadeada responsável por armazenar o endereço de todas elas.

- Como bônus procurei algumas soluções na internet para integrar o `free()`, na biblioteca, pois chegará um momento que o programa ainda não encerrou, mas que precisaríamos liberar uma certa variável inútil, assim com ajuda da net, contruí o `gc_free()`, que, antes de liberar a variável em si, irá procurá-la na lista-encadeada, e consequentemente liberar o nó responsável por armazenar o endereço da variável que será posteriormente liberada

# Observações
- devido ao sua estrutura exageradamente simples, recomendo que não utilize de forma profissional, mas sim de forma educativa, a fim de entender o funcionamento das listas-encadeadas, e da alocação dinâmica na memória, para mais estudo você pode ver como [Uso da Biblioteca](files/Uso.md)

# Esquema
- para quem quiser uma representação mais visual do meu GC está ai.

![](files/Simple_GC.drawio.svg)
