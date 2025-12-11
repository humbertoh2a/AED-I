#include <stdio.h>
#include <stdlib.h>
#include "LSE.h"

LSE *lse_cria() {
	LSE *l = malloc(sizeof(LSE));

	if (!l) {
		return NULL;
	}
	l->qtd = 0;

	return l;
}

int lse_destroi(LSE **l) {
	if (!l) {
		return -1;
	}
	free(*l);

	*l = NULL;

	return 1;
}

int lse_vazia(const LSE *l) {

	if (!l) {
		return -1;
	}

	if (l->qtd == 0) {
		return 1;
	}
	return 0;
}

int lse_cheia(const LSE *l) {
	if (!l) {
		return -1;
	}
	if (l->qtd == LSE_MAX) {
		return 1;
	}
	return 0;
}

int lse_tamanho(const LSE *l) {
	if (!l) {
		return -1;
	}
	return l->qtd;
}

int lse_insere_final(LSE *l, LSE_Tipo elem) {
	if (!l) {
		return -1;
	}
	if (lse_cheia(l)) {
		return -1;
	}
	l->dados[l->qtd] = elem;
	l->qtd++;
	return 1;
}

int lse_insere_pos(LSE *l, int pos, LSE_Tipo elem) {
	if (!l) {
		return -1;
	}
	if (lse_cheia(l)) {
		return -1;
	}
	if (pos < 0 || pos > l->qtd) {
		return -1;
	}


	for (int i = l->qtd; i > pos; i--) {
		l->dados[i] = l->dados[i-1];
	}

	l->qtd++;
	l->dados[pos] = elem;

	return 1;
}

int lse_remove_pos(LSE *l, int pos, LSE_Tipo *removido) {
	if (!l) {
		return -1;
	}
	if (pos < 0 || pos >= l->qtd) { 
		return -1;
	}
	if (!removido) {
		return -1;
	}

	*removido = l->dados[pos];


	for (int i = pos; i < l->qtd-1; i++) {
		l->dados[i] = l->dados[i+1];
	}

	l->qtd--;

	return 1;
}

int lse_consulta_pos(const LSE *l, int pos, LSE_Tipo *elem) {
	if (!l) {
		return -1;
	}
	if (pos < 0 || pos >= l->qtd) {
		return -1;
	}
	if (!elem) {
		return -1;
	}
	*elem = l->dados[pos];
	return 1;
}

int lse_busca(const LSE *l, LSE_Tipo elem, int *pos) {
	if (!l) {
		return -1;
	}
	if (!pos) {
		return -1;
	}

	*pos = -1;

	for (int i = 0; i < l->qtd; i++) {
		if (l->dados[i] == elem) {
			*pos = i;
			return 1;
		}
	}

	return 0;
}

int lse_limpa(LSE *l) {
	if (!l) {
		return -1;
	}
	l->qtd = 0;
	return 1;
}


int lse_imprime(const LSE *l) {
	if (!l) {
		return -1;
	}
	printf("[");
	if (l->qtd > 0) {
		for (int i = 0; i < l->qtd - 1; i++) {
			printf("%d, ", l->dados[i]); 
		}
		printf("%d", l->dados[l->qtd-1]);
	}
	printf("]\n");
	return 1;
}