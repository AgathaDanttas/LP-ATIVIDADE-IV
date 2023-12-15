#include <stdio.h>

// Definição da estrutura ContaBancaria
struct ContaBancaria {
    int numeroConta;
    char titular[50];
    float saldo;
    char tipoConta[20]; // Poupança ou Corrente
};

// Função para realizar um depósito
void depositar(struct ContaBancaria *conta, float valor) {
    conta->saldo += valor;
    printf("Depósito realizado com sucesso. Saldo atual: R$ %.2f\n", conta->saldo);
}

// Função para realizar um saque
void sacar(struct ContaBancaria *conta, float valor) {
    if (valor > conta->saldo) {
        printf("Saldo insuficiente. Operação cancelada.\n");
    } else {
        conta->saldo -= valor;
        printf("Saque realizado com sucesso. Saldo atual: R$ %.2f\n", conta->saldo);
    }
}

// Função para imprimir o saldo atual
void imprimirSaldo(struct ContaBancaria *conta) {
    printf("Saldo atual da conta: R$ %.2f\n", conta->saldo);
}

int main() {
    // Inicialização de uma conta bancária
    struct ContaBancaria minhaConta = {12345, "Fulano de Tal", 1000.0, "Corrente"};

    int opcao;
    float valor;

    do {
        // Menu de operações
        printf("\n1. Depositar\n");
        printf("2. Sacar\n");
        printf("3. Imprimir Saldo\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a depositar: ");
                scanf("%f", &valor);
                depositar(&minhaConta, valor);
                break;
            case 2:
                printf("Digite o valor a sacar: ");
                scanf("%f", &valor);
                sacar(&minhaConta, valor);
                break;
            case 3:
                imprimirSaldo(&minhaConta);
                break;
            case 4:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 4);

    return 0;
}
