#ifndef NOTAS_H
#define NOTAS_H
 
// Constantes gerais do sistema de notas
#define MAX_ALUNOS 30
#define NUM_AVALIACOES 4
 
// Protótipos das funções da "biblioteca" de notas
 
// Lê as 4 notas de cada aluno e preenche a matriz
void lerNotas(float notas[][NUM_AVALIACOES], int qtdAlunos);
 
// Calcula a média de cada aluno e armazena no vetor medias
void calcularMedias(float notas[][NUM_AVALIACOES], float medias[], int qtdAlunos);
 
// Mostra na tela a média de cada aluno
void exibirMedias(float medias[], int qtdAlunos);
 
// Encontra a maior e a menor nota da turma
void maiorMenorNota(float notas[][NUM_AVALIACOES], int qtdAlunos,
                    float *maior, float *menor);
 
// Lista alunos aprovados (média >= 6.0) e reprovados
void listarAprovadosReprovados(float medias[], int qtdAlunos);
 
#endif