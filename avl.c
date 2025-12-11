#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

struct No {
	int valor;
	struct No *esq;
	struct No *dir;
};

// FUNÇÕES AUXILIARES PARA AVL
static Arvore RSD(Arvore r) {
	// vamos definir os nós a terem os filhos alterados
	Arvore p = r->esq;
	Arvore T2 = p->dir;

	// efetivar a rotação
	p->dir = r;
	r->esq = T2;

	// retornamos a nova raiz
	return p;
}

static Arvore RSE(Arvore r) {
	// vamos definir os nós a terem os filhos alterados
	Arvore p = r->dir;
	Arvore T2 = p->esq;

	// efetivar a rotação
	p->esq = r;
	r->dir = T2;

	// retornamos a nova raiz
	return p;
}

static int fb(Arvore r) {
	if (r == NULL) {
		return 0;
	}
	return arv_altura(r->esq) - arv_altura(r->dir);
}

static Arvore balancear(Arvore r) {
	// em nó nulo, nada a fazer
	if (r == NULL) {
		return NULL;
	}
	// calculamos o fator de balanceamento da raiz
	int fator_r = fb(r);
	// vamos tratar casos fora do intervalo [-1, 1]
	if (fator_r > +1) {
		// POSITIVO: peso da árvore está para a esquerda
		// olho para o filho a esquerda
		int fator_filho = fb(r->esq);
		if (fator_filho >= 0) { // POSITIVO
			// CASO EE
			return RSD(r);
		} else { // NEGATIVO
			 // CASO ED
			// rotaciona o pivô
			r->esq = RSE(r->esq);
			// rotaciona a raiz
			return RSD(r);
		}
	} else if (fator_r < -1) {	
		// NEGATIVO: peso da árvore está para a direita
		// olho para o filho a direita
		int fator_filho = fb(r->dir);
		if (fator_filho >= 0) { // POSITIVO
			// CASO DE
			r->dir = RSD(r->dir);
			return RSE(r);
		} else { // NEGATIVO
			 // CASO DD
			 return RSE(r);
		}
	}

	// caso não haja desbalanceamento, apenas retorno
	return r;
}

// lá no .h
// typedef struct No* Arvore;

Arvore arv_cria(int valor, Arvore esq, Arvore dir) {
	Arvore r = malloc(sizeof(struct No));
	if (!r) {
		return NULL;
	}
	r->valor = valor;
	r->esq = esq;
	r->dir = dir;
	return r;
}


/* Libera toda a árvore recursivamente. Aceita NULL. */
void arv_libera(Arvore r) {
	if (!r) {
		// não há nada a fazer
		return;
	}
	arv_libera(r->esq);
	arv_libera(r->dir);
	free(r);
}

/* Retorna 1 se vazia, 0 caso contrário. */
int arv_vazia(Arvore r) {
	if (r == NULL) {
		return 1; // vazia
	}
	return 0;
}

/* Retorna o número de nós. */
int arv_tamanho(Arvore r) {
	// caso base
	if (r == NULL) {
		return 0;
	}
	// caso geral
	return 1 + // conta raiz
		arv_tamanho(r->esq) +
		arv_tamanho(r->dir);
}

/* Retorna a altura. Convenção: vazia = -1, folha = 0. */
int arv_altura(Arvore r) {
	// caso base
	if (r == NULL) {
		return -1;
	}
	// caso geral
	int alt_esq = 1 + arv_altura(r->esq);
	int alt_dir = 1 + arv_altura(r->dir);
	// a altura exige pegar o maior
	if (alt_esq > alt_dir) {
		return alt_esq;
	}
	return alt_dir;
}

/* Percursos em profundidade com impressão em stdout. */
void arv_preordem(Arvore r) {
	if (r == NULL) {
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

void arv_inordem(Arvore r) {
	if (r == NULL) {
		return;
	}
	arv_inordem(r->esq);
	printf("%d ", r->valor);
	arv_inordem(r->dir);
}   /* esquerda, raiz, direita */

void arv_posordem(Arvore r) {
	if (r == NULL) {
		return;
	}
	arv_posordem(r->esq);
	arv_posordem(r->dir);
	printf("%d ", r->valor);
}  /* esquerda, direita, raiz */

/* Percurso em largura com impressão em stdout. */
void arv_largura(Arvore r) {
	if (!r) {
		return; //nada a fazer
	}

	// num. nós na árvore
	int n = arv_tamanho(r);

	// crio fila que pode armazenar n nós
	Arvore* fila = malloc(sizeof(Arvore) * n);

	// contadores de inicio e fim da fila
	int fim = 0;
	int ini = 0;

	// coloco a raiz na fila
	fila[fim] = r;
	fim++; // sempre que eu adicionar na fila, inc. fim.

	while (ini < fim) {
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

/* Vamos adicionar novas funções de ABB */
Arvore arv_busca(Arvore r, int x) {
	// casos base
	// 1. árvore vazia
	if (!r) {
		return NULL;
	}
	// 2. verifico se o valor do nó atual é o que eu procuro
	if (r->valor == x) {
		return r;
	}
	// casos gerais: esquerda e direita
	if (x < r->valor) {
		return arv_busca(r->esq, x);
	} else if (x > r->valor) {
		return arv_busca(r->dir, x);	
	}
}

int arv_contem(Arvore r, int x) {
	if (arv_busca(r, x) != NULL) {
		// achou
		return 1;
	}
	// não achou
	return 0;
}

Arvore arv_insere(Arvore r, int x) {
	/* CASOS BASE */
	// 1. quando nulo, crio um novo nó
	if (!r) {
		return arv_cria(x, NULL, NULL);
	}
	// 2. se o elemento já está lá, não vou inserir
	if (r->valor == x) {
		return r; //deixa como está
	}
	/* CASO GERAL */
	// chamar recursivo para esquerda e direita
	if (x < r->valor) {
		r->esq = arv_insere(r->esq, x);
	} else if (x > r->valor) {
		r->dir = arv_insere(r->dir, x);
	}
	return balancear(r);
}

Arvore arv_max_node(Arvore r) {
	if (!r) {
		return NULL;
	}
	// avança para a direita até chegar em NULL
	while (r->dir != NULL) {
		r = r->dir;
	}
	return r;
}

Arvore arv_min_node(Arvore r) {
	if (!r) {
		return NULL;
	}
	// avança para a esquerda até chegar em NULL
	while (r->esq != NULL) {
		r = r->esq;
	}
	return r;
}

Arvore arv_remove(Arvore r, int x) {
	if (!r) {
		// não remove nó em árvore vazia
		return NULL;
	}
	// verifico esquerda
	if (x < r->valor) {
		r->esq = arv_remove(r->esq, x);
		return balancear(r);
	}
	// verifico direira
	if (x > r->valor) {
		r->dir = arv_remove(r->dir, x);
		return balancear(r);
	}

	// se chegamos até aqui sem retornar
	// é porque r->valor (valor do nó atual)
	// é igual ao x que estamos procurando
	// para remover
	// CASO 1. Sem filhos (folha)
	if ((r->dir == NULL) && (r->esq == NULL)) {
		free(r);
		return NULL;
	}
	// CASO 2. Um único filho
	// só possui filho à esquerda
	if ((r->esq != NULL) && (r->dir == NULL)) {
		Arvore t = r->esq;
		free(r);
		return t;
	}
	// só possui filho à direita
	if ((r->esq == NULL) && (r->dir != NULL)) {
		Arvore t = r->dir;
		free(r);
		return t;
	}
	// CASO 3. Dois filhos
	// pegamos o sucessor em ordem
	// que é o menor elemento da subárvore direta
	Arvore s = arv_min_node(r->dir);
	r->valor = s->valor;
	r->dir = arv_remove(r->dir, s->valor); // recursão p/ remover
	return balancear(r);					       //
}
