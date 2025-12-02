#include <stdio.h>
#include "notas.h"
 
// Lê as notas de todos os alunos
void lerNotas(float notas[][NUM_AVALIACOES], int qtdAlunos) {
    int i, j;
 
    for (i = 0; i < qtdAlunos; i++) {
        printf("\nAluno %d:\n", i + 1);
        for (j = 0; j < NUM_AVALIACOES; j++) {
            do {
                printf("  Informe a nota %d (0 a 10): ", j + 1);
                scanf("%f", &notas[i][j]);
 
                if (notas[i][j] < 0.0f || notas[i][j] > 10.0f) {
                    printf("  Valor invalido! A nota deve estar entre 0 e 10.\n");
                }
            } while (notas[i][j] < 0.0f || notas[i][j] > 10.0f);
        }
    }
}
 
// Calcula média de cada aluno
void calcularMedias(float notas[][NUM_AVALIACOES], float medias[], int qtdAlunos) {
    int i, j;
    float soma;
 
    for (i = 0; i < qtdAlunos; i++) {
        soma = 0.0f;
        for (j = 0; j < NUM_AVALIACOES; j++) {
            soma += notas[i][j];
        }
        medias[i] = soma / NUM_AVALIACOES;
    }
}
 
// Exibe as médias
void exibirMedias(float medias[], int qtdAlunos) {
    int i;
 
    printf("\n=== Medias dos alunos ===\n");
    for (i = 0; i < qtdAlunos; i++) {
        printf("Aluno %d: media = %.2f\n", i + 1, medias[i]);
    }
}
 
// Encontra a maior e menor nota da turma
void maiorMenorNota(float notas[][NUM_AVALIACOES], int qtdAlunos,
                    float *maior, float *menor) {
 
    int i, j;
 
    if (qtdAlunos <= 0) {
        return; // só pra segurança do código
    }
 
    *maior = notas[0][0];
    *menor = notas[0][0];
 
    for (i = 0; i < qtdAlunos; i++) {
        for (j = 0; j < NUM_AVALIACOES; j++) {
            if (notas[i][j] > *maior) {
                *maior = notas[i][j];
            }
            if (notas[i][j] < *menor) {
                *menor = notas[i][j];
            }
        }
    }
}
 
// Lista aprovados e reprovados com base na média
void listarAprovadosReprovados(float medias[], int qtdAlunos) {
    int i;
 
    printf("\n=== Situacao dos alunos ===\n");
    for (i = 0; i < qtdAlunos; i++) {
        printf("Aluno %d: media = %.2f - ", i + 1, medias[i]);
        if (medias[i] >= 6.0f) {
            printf("APROVADO\n");
        } else {
            printf("REPROVADO\n");
        }
    }
}