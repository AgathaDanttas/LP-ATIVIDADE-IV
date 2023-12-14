// Crie uma função chamada "calcularMedia" que recebe como parâmetro uma struct "Aluno", esta struct terá informações como: nome, data de nascimento, duas notas e média e retorna a média das notas. Em seguida, crie um programa que declare um array de 5 alunos e utilize a função "calcularMedia" para imprimir a média de cada aluno. Também crie uma função para verificar se um aluno está aprovado ou reprovado sendo necessário média maior ou igual a 7,0 para aprovação.

#include <stdio.h>
#include <stdlib.h>

#define tam 3
#define tam_notas 2

// dados dos alunos
struct dados_alunos {
   char nome [200],data_nascimento [9];
   float notas[tam_notas],media;
};
struct dados_alunos alunos[tam];

// Função para calcular a média de um aluno
float calcular_media (struct dados_alunos alunos) {
      return (alunos.notas[0] + alunos.notas[1])/tam_notas;
}

// Função para verificar se um aluno está aprovado
void verificar_aprovacao(struct dados_alunos aluno) {
    if (aluno.media >= 7.0) {
        printf("%s está aprovado!\n", aluno.nome);
    } else {
        printf("%s está reprovado.\n", aluno.nome);
    }
}

int main (){
    struct dados_alunos alunos [tam];

    // Preenchendo dados dos alunos
    for (int i = 0; i < tam; i++) {
        printf("Informe o nome do aluno %d: ", i + 1);
        scanf("%s", alunos[i].nome);

        printf("Informe a data de nascimento do aluno %d (DDMMYYYY): ", i + 1);
        scanf("%s", alunos[i].data_nascimento);

        printf("Informe a nota 1 do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].notas[0]);

        printf("Informe a nota 2 do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].notas[1]);

        // Calculando a média do aluno
        alunos[i].media = calcular_media(alunos[i]);
    }

     // Imprimindo a média de cada aluno e verificando aprovação
    for (int i = 0; i < tam; i++) {
        printf("Aluno %s:\n", alunos[i].nome);
        printf("  Média: %.2f\n", alunos[i].media);
        verificar_aprovacao(alunos[i]);
        printf("\n");
    }

    return 0;
}