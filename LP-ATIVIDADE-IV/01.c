#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam_contatos 3

// dados do contato
struct contatos
{
    char nome[200], numero[20], email[200];
};
struct contatos contato[tam_contatos];

// função para encontrar o número
char *encontrarNumero(char *nome)
{
    for (int i = 0; i < tam_contatos; i++)
    {
        if (strcmp(nome, contato[i].nome) == 0)
        {
            return contato[i].numero;
        }
    }
    return "contato nao encontrado\n";
}

int main()
{
    // cadastrando contatos
    for (int i = 0; i < tam_contatos; i++)
    {
        printf("Informe o nome do contato:");
        fgets(contato[i].nome, 200, stdin);
        printf("Informe o numero de %s:", contato[i].nome);
        fgets(contato[i].numero, 20, stdin);
        printf("Informe o email de %s:", contato[i].nome);
        fgets(contato[i].email, 200, stdin);
        system("cls");
    }

    // buscar e imprimir o nmero
    char nomeBusca[200];
    printf("Informe o nome do contato que voce deseja encontrar:");
    fgets(nomeBusca, 200, stdin);

    char *numeroEncontrado = encontrarNumero(nomeBusca);
    printf("Nome: %s\n", nomeBusca);
    printf("Numero: %s\n", numeroEncontrado);

    return 0;
}
