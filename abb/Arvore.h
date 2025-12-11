#ifndef ARVORE_H
#define ARVORE_H

/* TAD Árvore binária como ponteiro opaco */
typedef struct No *Arvore;

/* Cria um nó com valor e filhos dados. Retorna NULL em falha. */
Arvore arv_cria(int valor, Arvore esq, Arvore dir);

/* Libera toda a árvore recursivamente. Aceita NULL. */
void arv_libera(Arvore r);

/* Retorna 1 se vazia, 0 caso contrário. */
int arv_vazia(Arvore r);

/* Retorna o número de nós. */
int arv_tamanho(Arvore r);

/* Retorna a altura. Convenção: vazia = -1, folha = 0. */
int arv_altura(Arvore r);

/* Percursos em profundidade com impressão em stdout. */
void arv_preordem(Arvore r); /* raiz, esquerda, direita */
void arv_inordem(Arvore r);  /* esquerda, raiz, direita */
void arv_posordem(Arvore r); /* esquerda, direita, raiz */

/* Percurso em largura com impressão em stdout. */
void arv_largura(Arvore r);

/* Insere um valor na ABB. Retorna a raiz (pode ser nova). */
Arvore arv_insere(Arvore r, int valor);

#endif /* ARVORE_H */
