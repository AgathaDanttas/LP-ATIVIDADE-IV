#include <stdio.h>

// Definição da estrutura Produto
struct Produto {
    char nome[200];
    float preco;
    int quantidade_estoque;
};

// Função para realizar uma compra
void realizar_compra(struct Produto *produto) {
    char temp_nome[200];  // Variável temporária para armazenar o nome temporariamente

    printf("Informe o nome do produto: ");
    scanf("%s", temp_nome);

    // Copia o conteúdo de temp_nome para o campo nome da estrutura Produto
    snprintf(produto->nome, sizeof(produto->nome), "%s", temp_nome);

    printf("Informe o preço do produto: ");
    scanf("%f", &(produto->preco));

    printf("Informe a quantidade em estoque: ");
    scanf("%d", &(produto->quantidade_estoque));

    printf("Compra realizada com sucesso!\n\n");
}

// Função para consultar o estoque
void consultar_estoque(struct Produto *produto) {
    printf("Nome: %s\n", produto->nome);
    printf("Preço: %.2f\n", produto->preco);
    printf("Quantidade em estoque: %d\n\n", produto->quantidade_estoque);
}

int main() {
    struct Produto produto;
    struct Produto *ptr_produto = &produto; // Ponteiro para a estrutura Produto
    int opcao;

    do {
        // Menu de opções
        printf("Menu:\n");
        printf("1 - Realizar uma compra\n");
        printf("2 - Consultar estoque\n");
        printf("3 - Sair do programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                realizar_compra(ptr_produto);
                break;
            case 2:
                consultar_estoque(ptr_produto);
                break;
            case 3:
                printf("Saindo do programa. Até logo!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}
