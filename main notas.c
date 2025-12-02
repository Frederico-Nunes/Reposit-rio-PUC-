#include <stdio.h>
#include <stdlib.h>
#include "notas.h"
 
int main() {
    int qtdAlunos,i,j,opcao,notasPreenchidas = 0; //flag para saber se já cadastrou notas 
    float notas[MAX_ALUNOS][NUM_AVALIACOES],medias[MAX_ALUNOS];
 
    // Leitura e validação da quantidade de alunos
    do {
        printf("Informe a quantidade de alunos da turma: ", MAX_ALUNOS);
        scanf("%d", &qtdAlunos);
 
        if (qtdAlunos < 1 || qtdAlunos > MAX_ALUNOS) {
            printf("Valor invalido! Tente novamente.\n\n");
        }
    } while (qtdAlunos < 1 || qtdAlunos > MAX_ALUNOS);
 
    // Inicializa notas e medias com 0
    for (i = 0; i < qtdAlunos; i++) {
        for (j = 0; j < NUM_AVALIACOES; j++) {
            notas[i][j] = 0.0f;
        }
        medias[i] = 0.0f;
    }
 
    // Menu principal
    do {
        printf("\n==============================\n");
        printf("       MENU PRINCIPAL\n");
        printf("==============================\n");
        printf("1 - Cadastrar/alterar notas dos alunos\n");
        printf("2 - Calcular e exibir a media de cada aluno\n");
        printf("3 - Exibir a maior e a menor nota da turma\n");
        printf("4 - Listar alunos aprovados e reprovados\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
 
        switch (opcao) {
            case 1:
                // Cadastrar ou alterar notas
                lerNotas(notas, qtdAlunos);
                calcularMedias(notas, medias, qtdAlunos);
                notasPreenchidas = 1;
                break;
 
            case 2:
                // Calcular e exibir médias
                if (!notasPreenchidas) {
                    printf("Nenhuma nota cadastrada ainda. Use a opcao 1 primeiro.\n");
                } else {
                    calcularMedias(notas, medias, qtdAlunos); // garante que estão atualizadas
                    exibirMedias(medias, qtdAlunos);
                }
                break;
 
            case 3: {
                // Maior e menor nota da turma
                if (!notasPreenchidas) {
                    printf("Nenhuma nota cadastrada ainda. Use a opcao 1 primeiro.\n");
                } else {
                    float maior, menor;
                    maiorMenorNota(notas, qtdAlunos, &maior, &menor);
                    printf("\nMaior nota da turma: %.2f\n", maior);
                    printf("Menor nota da turma: %.2f\n", menor);
                }
                break;
            }
 
            case 4:
                // Lista de aprovados e reprovados
                if (!notasPreenchidas) {
                    printf("Nenhuma nota cadastrada ainda. Use a opcao 1 primeiro.\n");
                } else {
                    calcularMedias(notas, medias, qtdAlunos); // por garantia
                    listarAprovadosReprovados(medias, qtdAlunos);
                }
                break;
 
            case 5:
                printf("Saindo do programa...\n");
                break;
 
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
 
    } while (opcao != 5);
 
    return 0;
}