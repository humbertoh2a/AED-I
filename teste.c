#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>

// variavel global para contar operacoes
long long contadorOperacoes = 0;

// busca sequencial com contador de operacoes
// Formula: T(n) = 3n + 2
int buscaSequencial(int vetor[], int k, int alvo)
{
    contadorOperacoes = 0; // reseta o contador
    
    // Operações iniciais: i = 0, preparação do loop (2 operações)
    contadorOperacoes += 2;
    
    // busca sequencial do vetor
    for (int i = 0; i < k; i++)
    {
        // Para cada iteração: comparação i < k, comparação vetor[i] == alvo, incremento i++ (3 operações)
        contadorOperacoes += 3;
        if (vetor[i] == alvo)
        {
            return i;
        }
    }
    return -1;
}

// funcao para inverter numeros com contador
// Formula: T(n) = 5⌊n/2⌋ + 2
void inverteNumeros(int vetor[], int k)
{
    contadorOperacoes = 0; // reseta o contador
    
    // Operações iniciais: i = 0, cálculo de k/2 (2 operações)
    contadorOperacoes += 2;
    
    // inversao dos numeros
    for (int i = 0; i < k / 2; i++)
    {
        // Para cada iteração: comparação i < k/2, tmp = vetor[i], vetor[i] = vetor[k-1-i], 
        // vetor[k-1-i] = tmp, incremento i++ (5 operações)
        contadorOperacoes += 5;
        int tmp = vetor[i];
        vetor[i] = vetor[k - 1 - i];
        vetor[k - 1 - i] = tmp;
    }
}

// busca binaria iterativa com contador
// Formula: T(n) = 5⌊log₂(n)⌋ + 3
int buscaBinariaIterativa(int vetor[], int alvo, int tam)
{
    contadorOperacoes = 0; // reseta o contador
    int inicio = 0;
    int fim = tam - 1;
    
    // Operações iniciais: inicio = 0, fim = tam-1, preparação (2 operações)
    contadorOperacoes += 2;

    // comeco do laco para buscar por divisao e conquista
    while (inicio <= fim)
    {
        // Conta a comparação do while
        contadorOperacoes += 1;
        
        // sempre que o laco rodar ele atualiza o meio para ficar ciente onde ele esta
        int meio = inicio + (fim - inicio) / 2;

        // Conta: cálculo do meio, comparação alvo == vetor[meio], comparação para decidir lado, atualização (4 operações)
        contadorOperacoes += 4;
        
        // se o meio for o numero procurado, retorna o indice do meio
        if (alvo == vetor[meio])
        {
            return meio;
        }

        if (vetor[meio] < alvo)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }
    
    // Conta a última comparação do while que falha
    contadorOperacoes += 1;
    
    return -1;
}

// busca binaria recursiva com contador
// Formula: T(n) = 5⌊log₂(n)⌋ + 1
int buscaBinariaRecursivaAux(int vetor[], int alvo, int inicio, int fim)
{
    // Operação: comparação fim >= inicio (1 operação)
    contadorOperacoes += 1;
    
    if (fim >= inicio)
    {
        // sempre que o laco rodar ele atualiza o meio para ficar ciente onde ele esta
        int meio = inicio + (fim - inicio) / 2;

        // Operações: cálculo do meio, comparação vetor[meio] == alvo (2 operações)
        contadorOperacoes += 2;
        
        // se o meio for o numero procurado, retorna o indice do meio
        if (vetor[meio] == alvo)
        {
            return meio;
        }

        // Operações: comparação para decidir lado, preparação da chamada recursiva (2 operações)
        contadorOperacoes += 2;

        // se o valor presente no vetor no indice meio for maior que o valor procurado, quer dizer que o alvo esta a esquerda do meio, logo chama recursivamente a funcao alterando o valor do fim para meio-1
        if (vetor[meio] > alvo)
        {
            return buscaBinariaRecursivaAux(vetor, alvo, inicio, meio - 1);
        }
        // se o valor presente no vetor no indice meio for menor que o valor procurado, quer dizer que o alvo esta a direita do meio, logo chama recursivamente a funcao alterando o valor do inicio para meio+1
        else
        {
            return buscaBinariaRecursivaAux(vetor, alvo, meio + 1, fim);
        }
    } // retorna -1 pois ele ja varreu todo o vetor
    return -1;
}

// wrapper para busca binaria recursiva que reseta contador
int buscaBinariaRecursiva(int vetor[], int alvo, int inicio, int fim)
{
    contadorOperacoes = 0; // reseta o contador antes de iniciar
    
    return buscaBinariaRecursivaAux(vetor, alvo, inicio, fim);
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
    return segundos * 1000000 + microssegundos; // retorna tempo total em microssegundos
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

    printf("  tempo medio: %.2f microssegundos\n", tempoMedio);
    printf("  operacoes media: %.2f\n", operacoesMedio);
    
    // Mostra o valor esperado pela fórmula para verificação
    double valorEsperado = 0;
    if (tipoAlgoritmo == 1) { // Inversão: T(n) = 5⌊n/2⌋ + 2
        valorEsperado = 5 * floor(tamanho / 2.0) + 2;
    } else if (tipoAlgoritmo == 2) { // Busca Sequencial: T(n) = 3n + 2
        valorEsperado = 3 * tamanho + 2;
    } else if (tipoAlgoritmo == 3 || tipoAlgoritmo == 4) { // Busca Binária
        double logValue = floor(log2(tamanho));
        if (tipoAlgoritmo == 3) { // Iterativa: T(n) = 5⌊log₂(n)⌋ + 3
            valorEsperado = 5 * logValue + 3;
        } else { // Recursiva: T(n) = 5⌊log₂(n)⌋ + 1
            valorEsperado = 5 * logValue + 1;
        }
    }
    printf("  valor esperado pela formula: %.2f\n", valorEsperado);
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