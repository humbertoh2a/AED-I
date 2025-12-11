#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"

struct No
{
	int valor;
	struct No *esq;
	struct No *dir;
};

// lá no .h
// typedef struct No* Arvore;

Arvore arv_cria(int valor, Arvore esq, Arvore dir)
{
	Arvore r = malloc(sizeof(struct No));
	if (!r)
	{
		return NULL;
	}
	r->valor = valor;
	r->esq = esq;
	r->dir = dir;
	return r;
}

/* Libera toda a árvore recursivamente. Aceita NULL. */
void arv_libera(Arvore r)
{
	if (!r)
	{
		// não há nada a fazer
		return;
	}
	arv_libera(r->esq);
	arv_libera(r->dir);
	free(r);
}

/* Retorna 1 se vazia, 0 caso contrário. */
int arv_vazia(Arvore r)
{
	if (r == NULL)
	{
		return 1; // vazia
	}
	return 0;
}

/* Retorna o número de nós. */
int arv_tamanho(Arvore r)
{
	// caso base
	if (r == NULL)
	{
		return 0;
	}
	// caso geral
	return 1 + // conta raiz
				 arv_tamanho(r->esq) +
				 arv_tamanho(r->dir);
}

/* Retorna a altura. Convenção: vazia = -1, folha = 0. */
int arv_altura(Arvore r)
{
	// caso base
	if (r == NULL)
	{
		return -1;
	}
	// caso geral
	int alt_esq = 1 + arv_altura(r->esq);
	int alt_dir = 1 + arv_altura(r->dir);
	// a altura exige pegar o maior
	if (alt_esq > alt_dir)
	{
		return alt_esq;
	}
	return alt_dir;
}

/* Percursos em profundidade com impressão em stdout. */
void arv_preordem(Arvore r)
{
	if (r == NULL)
	{
		// não tem o que imprimir
		return;
	}
	// raiz
	printf("%d ", r->valor);
	// esquerda
	arv_preordem(r->esq);
	// direita
	arv_preordem(r->dir);
} /* raiz, esquerda, direita */

void arv_inordem(Arvore r)
{
	if (r == NULL)
	{
		return;
	}
	arv_inordem(r->esq);
	printf("%d ", r->valor);
	arv_inordem(r->dir);
} /* esquerda, raiz, direita */

void arv_posordem(Arvore r)
{
	if (r == NULL)
	{
		return;
	}
	arv_posordem(r->esq);
	arv_posordem(r->dir);
	printf("%d ", r->valor);
} /* esquerda, direita, raiz */

/* Percurso em largura com impressão em stdout. */
void arv_largura(Arvore r)
{
	if (!r)
	{
		return; // nada a fazer
	}

	// num. nós na árvore
	int n = arv_tamanho(r);

	// crio fila que pode armazenar n nós
	Arvore *fila = malloc(sizeof(Arvore) * n);

	// contadores de inicio e fim da fila
	int fim = 0;
	int ini = 0;

	// coloco a raiz na fila
	fila[fim] = r;
	fim++; // sempre que eu adicionar na fila, inc. fim.

	while (ini < fim)
	{
		// exibe o próximo da fila
		Arvore u = fila[ini];
		// sempre que eu leio da fila,
		// removo o valor, inc. ini.
		ini++;

		// imprime elemento atual
		printf("%d ", u->valor);

		// coloca os filhos na fila
		if (u->esq)
			fila[fim++] = u->esq;
		if (u->dir)
			fila[fim++] = u->dir;
	}

	// limpa a fila
	free(fila);
}

Arvore arv_insere(Arvore r, int valor)
{
	if (r == NULL)
	{
		return arv_cria(valor, NULL, NULL);
	}

	if (valor < r->valor)
	{
		r->esq = arv_insere(r->esq, valor);
	}
	else
	{
		r->dir = arv_insere(r->dir, valor);
	}

	return r;
}