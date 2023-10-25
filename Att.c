#include <stdio.h>
#include <stdlib.h>

// Função para ler e armazenar uma sequência de números em um arquivo
void lerEArmazenarSequencia(FILE *arquivo, int *sequencia, int tamanho) {
    printf("Digite a sequencia de numeros naturais:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &sequencia[i]);
        fprintf(arquivo, "%d ", sequencia[i]); // Armazena no arquivo
    }
    printf("Sequencia lida e armazenada com sucesso!\n");
}

// Função para ler as sequências de números de um arquivo
void lerSequenciasDeArquivo(FILE *arquivo, int *sequencia1, int *sequencia2, int tamanho1, int tamanho2) {
    printf("Lendo as sequencias do arquivo...\n");
    for (int i = 0; i < tamanho1; i++) {
        fscanf(arquivo, "%d", &sequencia1[i]);
    }
    for (int i = 0; i < tamanho2; i++) {
        fscanf(arquivo, "%d", &sequencia2[i]);
    }
    printf("Sequencias lidas do arquivo com sucesso!\n");
}

// Função para gerar e armazenar conjuntos A e B
void gerarConjuntos(FILE *arquivo, int *sequencia1, int *sequencia2, int tamanho1, int tamanho2) {
    int conjuntoA[tamanho1];
    int conjuntoB[tamanho2];
    int tamanhoA = 0;
    int tamanhoB = 0;

    for (int i = 0; i < tamanho1; i++) {
        int elemento = sequencia1[i];
        int pertenceA = 1;

        // Verifica se o elemento já está no conjunto A
        for (int j = 0; j < tamanhoA; j++) {
            if (conjuntoA[j] == elemento) {
                pertenceA = 0;
                break;
            }
        }

        // Se não pertencer a A, adiciona ao conjunto A
        if (pertenceA) {
            conjuntoA[tamanhoA] = elemento;
            tamanhoA++;
        }
    }

    for (int i = 0; i < tamanho2; i++) {
        int elemento = sequencia2[i];
        int pertenceB = 1;

        // Verifica se o elemento já está no conjunto B
        for (int j = 0; j < tamanhoB; j++) {
            if (conjuntoB[j] == elemento) {
                pertenceB = 0;
                break;
            }
        }

        // Se não pertencer a B, adiciona ao conjunto B
        if (pertenceB) {
            conjuntoB[tamanhoB] = elemento;
            tamanhoB++;
        }
    }

    printf("Conjunto A gerado: ");
    for (int i = 0; i < tamanhoA; i++) {
        fprintf(arquivo, "%d ", conjuntoA[i]);
        printf("%d ", conjuntoA[i]);
    }
    printf("\n");

    printf("Conjunto B gerado: ");
    for (int i = 0; i < tamanhoB; i++) {
        fprintf(arquivo, "%d ", conjuntoB[i]);
        printf("%d ", conjuntoB[i]);
    }
    printf("\n");

    printf("Conjuntos A e B armazenados no arquivo com sucesso!\n");
}

int main() {
    FILE *arquivo;
    int tamanho1, tamanho2;

    // Abre o arquivo para escrita (substitui se já existir)
    arquivo = fopen("sequencias.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    printf("Digite o tamanho da primeira sequencia: ");
    scanf("%d", &tamanho1);

    printf("Digite o tamanho da segunda sequencia: ");
    scanf("%d", &tamanho2);

    int sequencia1[tamanho1], sequencia2[tamanho2];

    // (a) Lê e armazena a primeira sequência no arquivo
    lerEArmazenarSequencia(arquivo, sequencia1, tamanho1);

    // (b) Lê a sequência do arquivo
    fclose(arquivo);
    arquivo = fopen("sequencias.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 1;
    }
    // (b) Lê as sequências do arquivo
    lerSequenciasDeArquivo(arquivo, sequencia1, sequencia2, tamanho1, tamanho2);
    
    // (c) Gera conjuntos A e B e armazena no arquivo
    fclose(arquivo);
    arquivo = fopen("sequencias.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }
    gerarConjuntos(arquivo, sequencia1, sequencia2, tamanho1, tamanho2);
    
    // Fecha o arquivo
    fclose(arquivo);

    return 0;
}