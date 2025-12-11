#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

// variavel global para contar operacoes
long long contadorOperacoes = 0;

// busca sequencial CORRIGIDA - T(n) = 3n + 2
int buscaSequencial(int vetor[], int k, int alvo)
{
  contadorOperacoes = 0;

  for (int i = 0; i < k; i++)
  {
    contadorOperacoes++; // comparação i < k
    contadorOperacoes++; // comparação vetor[i] == alvo

    if (vetor[i] == alvo)
    {
      return i;
    }
    // i++ é automático no for, não conta como operação explícita
  }

  contadorOperacoes++; // comparação final do for (i < k falha)
  return -1;
}

// funcao para inverter numeros com contador CORRIGIDO - T(n) = 5 * floor(n/2) + 2
void inverteNumeros(int vetor[], int k)
{
  contadorOperacoes = 0;

  for (int i = 0; i < k / 2; i++)
  {
    contadorOperacoes++; // comparação i < k/2

    int tmp = vetor[i];
    contadorOperacoes++; // atribuição tmp

    vetor[i] = vetor[k - 1 - i];
    contadorOperacoes++; // atribuição vetor[i] = vetor[k-1-i]

    vetor[k - 1 - i] = tmp;
    contadorOperacoes++; // atribuição vetor[k-1-i] = tmp

    // i++ é automático no for, não conta
  }

  contadorOperacoes++; // comparação final do for
}

// busca binaria iterativa CORRIGIDA - T(n) = 5*floor(log2(n)) + 3
int buscaBinariaIterativa(int vetor[], int alvo, int tam)
{
  contadorOperacoes = 0;

  int inicio = 0;
  int fim = tam - 1;
  contadorOperacoes += 2; // duas atribuições iniciais

  while (inicio <= fim)
  {
    contadorOperacoes++; // comparação inicio <= fim

    int meio = inicio + (fim - inicio) / 2;
    contadorOperacoes++; // atribuição meio

    if (alvo == vetor[meio])
    {
      contadorOperacoes++; // comparação alvo == vetor[meio]
      return meio;
    }
    contadorOperacoes++; // comparação alvo == vetor[meio] (falsa)

    if (vetor[meio] < alvo)
    {
      contadorOperacoes++; // comparação vetor[meio] < alvo
      inicio = meio + 1;
      // contadorOperacoes++; // REMOVIDO - atribuição inicio
    }
    else
    {
      // não precisa contar comparação novamente
      fim = meio - 1;
      // contadorOperacoes++; // REMOVIDO - atribuição fim
    }
  }

  contadorOperacoes++; // comparação final do while
  return -1;
}

// busca binaria recursiva CORRIGIDA - T(n) = 4*floor(log2(n)) + 1
int buscaBinariaRecursivaAux(int vetor[], int alvo, int inicio, int fim, long long *contador)
{
  (*contador)++; // comparação fim >= inicio

  if (fim >= inicio)
  {
    int meio = inicio + (fim - inicio) / 2;
    (*contador)++; // atribuição meio

    if (vetor[meio] == alvo)
    {
      (*contador)++; // comparação vetor[meio] == alvo
      return meio;
    }
    (*contador)++; // comparação vetor[meio] == alvo (falsa)

    if (vetor[meio] > alvo)
    {
      // (*contador)++; // REMOVIDO - comparação vetor[meio] > alvo
      return buscaBinariaRecursivaAux(vetor, alvo, inicio, meio - 1, contador);
    }
    else
    {
      // não precisa contar comparação novamente
      return buscaBinariaRecursivaAux(vetor, alvo, meio + 1, fim, contador);
    }
  }

  return -1;
}

// wrapper para busca binaria recursiva que reseta contador
int buscaBinariaRecursiva(int vetor[], int alvo, int inicio, int fim)
{
  contadorOperacoes = 0;
  return buscaBinariaRecursivaAux(vetor, alvo, inicio, fim, &contadorOperacoes);
}

// funcao para gerar numeros aleatorios ordenados
void geraVetorOrdenado(int vetor[], int tamanho)
{
  for (int i = 0; i < tamanho; i++)
  {
    vetor[i] = i + 1; // gera numeros de 1 a tamanho
  }
}

// funcao para copiar vetor (necessario para resetar apos inversao)
void copiaVetor(int origem[], int destino[], int tamanho)
{
  for (int i = 0; i < tamanho; i++)
  {
    destino[i] = origem[i];
  }
}

// funcao para calcular tempo em microssegundos
long calcularTempo(struct timeval inicio, struct timeval fim)
{
  long segundos = fim.tv_sec - inicio.tv_sec;
  long microssegundos = fim.tv_usec - inicio.tv_usec;
  if (microssegundos < 0)
  {
    segundos -= 1;
    microssegundos += 1000000;
  }
  return segundos * 1000000 + microssegundos;
}

// funcao para testar um algoritmo especifico
void testaAlgoritmo(FILE *arquivo, const char *nomeAlgoritmo, int tipoAlgoritmo,
                    int vetor[], int vetorBackup[], int tamanho, int numeroTestes)
{
  struct timeval inicio, fim;
  long tempoTotal = 0;
  long long operacoesTotal = 0;

  printf("testando %s com tamanho %d...\n", nomeAlgoritmo, tamanho);

  // realiza os testes
  for (int teste = 0; teste < numeroTestes; teste++)
  {
    // define o alvo para o pior caso de cada algoritmo
    int alvo;
    if (tipoAlgoritmo == 1) // inversao nao precisa de alvo
    {
      alvo = 0;
      copiaVetor(vetorBackup, vetor, tamanho); // reseta o vetor
    }
    else if (tipoAlgoritmo == 2) // busca sequencial - pior caso: elemento nao existe
    {
      alvo = tamanho + 1; // numero que nao esta no vetor (vetor vai de 1 a tamanho)
    }
    else // busca binaria (iterativa e recursiva) - pior caso: elemento nao existe
    {
      alvo = tamanho + 1; // numero que nao esta no vetor e força divisões máximas
    }

    gettimeofday(&inicio, NULL);

    switch (tipoAlgoritmo)
    {
    case 1:
      inverteNumeros(vetor, tamanho);
      break;
    case 2:
      buscaSequencial(vetor, tamanho, alvo);
      break;
    case 3:
      buscaBinariaIterativa(vetor, alvo, tamanho);
      break;
    case 4:
      buscaBinariaRecursiva(vetor, alvo, 0, tamanho - 1);
      break;
    }

    gettimeofday(&fim, NULL);

    tempoTotal += calcularTempo(inicio, fim);
    operacoesTotal += contadorOperacoes;
  }

  // calcula as medias
  double tempoMedio = (double)tempoTotal / numeroTestes;
  double operacoesMedio = (double)operacoesTotal / numeroTestes;

  fprintf(arquivo, "%s,%d,%.2f,%.2f\n", nomeAlgoritmo, tamanho, tempoMedio, operacoesMedio);

  printf("   tempo medio: %.2f microssegundos\n", tempoMedio);
  printf("   operacoes media: %.2f\n", operacoesMedio);
  
  // Verificação das fórmulas teóricas
  printf("   verificacao teorica: ");
  if (tipoAlgoritmo == 1) {
    int esperado = 5 * (tamanho / 2) + 2;
    printf("T(%d) = 5*%d + 2 = %d", tamanho, tamanho/2, esperado);
  }
  else if (tipoAlgoritmo == 2) {
    int esperado = 3 * tamanho + 2;
    printf("T(%d) = 3*%d + 2 = %d", tamanho, tamanho, esperado);
  }
  else if (tipoAlgoritmo == 3) {
    int log_val = 0;
    int temp = tamanho;
    while (temp > 1) {
      temp /= 2;
      log_val++;
    }
    int esperado = 5 * log_val + 3;
    printf("T(%d) = 5*%d + 3 = %d", tamanho, log_val, esperado);
  }
  else if (tipoAlgoritmo == 4) {
    int log_val = 0;
    int temp = tamanho;
    while (temp > 1) {
      temp /= 2;
      log_val++;
    }
    int esperado = 4 * log_val + 1;
    printf("T(%d) = 4*%d + 1 = %d", tamanho, log_val, esperado);
  }
  printf("\n");
}

int main()
{
  int tamanhos[] = {10, 100, 1000, 5000};
  int numTamanhos = 4;
  int numeroTestes = 100;

  FILE *arquivo = fopen("resultados_testes.csv", "w");
  if (arquivo == NULL)
  {
    printf("erro ao criar arquivo csv\n");
    return 1;
  }

  fprintf(arquivo, "algoritmo,tamanho_entrada,tempo_medio_us,operacoes_medio\n");

  printf("iniciando testes dos algoritmos...\n");
  printf("cada teste sera executado %d vezes para calcular a media\n\n", numeroTestes);

  // seed para numeros aleatorios
  srand(time(NULL));

  // testa cada tamanho
  for (int i = 0; i < numTamanhos; i++)
  {
    int tamanho = tamanhos[i];
    printf("=== testando com entrada de tamanho %d ===\n", tamanho);

    // aloca memoria para os vetores
    int *vetor = (int *)malloc(tamanho * sizeof(int));
    int *vetorBackup = (int *)malloc(tamanho * sizeof(int));

    if (vetor == NULL || vetorBackup == NULL)
    {
      printf("erro ao alocar memoria\n");
      return 1;
    }

    // gera vetor ordenado
    geraVetorOrdenado(vetor, tamanho);
    copiaVetor(vetor, vetorBackup, tamanho);

    // testa cada algoritmo
    testaAlgoritmo(arquivo, "inversao", 1, vetor, vetorBackup, tamanho, numeroTestes);

    // para os algoritmos de busca, sempre reseta o vetor para manter ordenacao
    copiaVetor(vetorBackup, vetor, tamanho);
    testaAlgoritmo(arquivo, "busca_sequencial", 2, vetor, vetorBackup, tamanho, numeroTestes);

    copiaVetor(vetorBackup, vetor, tamanho);
    testaAlgoritmo(arquivo, "busca_binaria_iterativa", 3, vetor, vetorBackup, tamanho, numeroTestes);

    copiaVetor(vetorBackup, vetor, tamanho);
    testaAlgoritmo(arquivo, "busca_binaria_recursiva", 4, vetor, vetorBackup, tamanho, numeroTestes);

    printf("\n");

    // libera memoria
    free(vetor);
    free(vetorBackup);
  }

  fclose(arquivo);

  printf("testes concluidos! resultados salvos em 'resultados_testes.csv'\n");
  printf("voce pode abrir o arquivo no excel ou qualquer editor de planilhas\n");

  return 0;
}