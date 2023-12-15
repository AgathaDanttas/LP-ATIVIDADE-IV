#include <stdio.h>

// Definição da estrutura Funcionario
struct Funcionario {
    char nome[50];
    char cargo[30];
    float salario;
};

// Função para calcular a média salarial dos funcionários com um cargo específico
float calcularMediaSalarial(struct Funcionario funcionarios[], int numFuncionarios, const char cargoBuscado[]) {
    float somaSalarios = 0;
    int contador = 0;

    for (int i = 0; i < numFuncionarios; i++) {
        if (strcmp(funcionarios[i].cargo, cargoBuscado) == 0) {
            somaSalarios += funcionarios[i].salario;
            contador++;
        }
    }

    // Evitar divisão por zero
    return (contador > 0) ? somaSalarios / contador : 0;
}

int main() {
    // Inicialização de um array de funcionários
    struct Funcionario funcionarios[] = {
        {"Alice", "Programador", 5000.0},
        {"Bob", "Analista", 6000.0},
        {"Charlie", "Programador", 5500.0},
        {"David", "Gerente", 8000.0},
        {"Eva", "Programador", 5200.0},
    };

    int numFuncionarios = sizeof(funcionarios) / sizeof(funcionarios[0]);

    // Calcular e imprimir a média salarial dos programadores
    const char cargoBuscado[] = "Programador";
    float mediaSalarial = calcularMediaSalarial(funcionarios, numFuncionarios, cargoBuscado);

    if (mediaSalarial > 0) {
        printf("A média salarial dos programadores é: R$ %.2f\n", mediaSalarial);
    } else {
        printf("Nenhum programador encontrado ou a média é zero.\n");
    }

    return 0;
}
