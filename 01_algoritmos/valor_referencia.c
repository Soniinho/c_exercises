#include <stdio.h>

// Função para passagem por valor
void passagemPorValor(int x) {
    x = x * 2;
    printf("Dentro da função (passagem por valor): %d\n", x);
}

// Função para passagem por referência
void passagemPorReferencia(int *x) {
    *x = *x * 2;
    printf("Dentro da função (passagem por referência): %d\n", *x);
}

int main() {
    int valor = 5;

    // Passagem por valor
    printf("Antes da função (passagem por valor): %d\n", valor);
    passagemPorValor(valor);
    printf("Depois da função (passagem por valor): %d\n", valor);

    // Passagem por referência
    printf("Antes da função (passagem por referência): %d\n", valor);
    passagemPorReferencia(&valor);
    printf("Depois da função (passagem por referência): %d\n", valor);

    return 0;
}
