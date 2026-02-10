#include <stdio.h>
#include <locale.h>

#define letras 26

int minuscula(char carac) {
    return (carac >= 'a' && carac <= 'z');
}

int maiuscula(char carac) {
    return (carac >= 'A' && carac <= 'Z');
}

void cifra_cesar(char mensagem[], int troca, int inverso) {
    int i = 0;

    if (inverso)
        troca = -troca;

    while (mensagem[i] != 0) {
        if (minuscula(mensagem[i])) {
            mensagem[i] = ((mensagem[i] - 'a' + troca + letras) % letras) + 'a';
        } else if (maiuscula(mensagem[i])) {
            mensagem[i] = ((mensagem[i] - 'A' + troca + letras) % letras) + 'A';
        }
        i++;
    }
}

int main() {
    char mensagem[100];
    int troca;
    int inverso;

    setlocale(LC_ALL, "portuguese");

    printf("Digite a mensagem: ");
    fgets(mensagem, sizeof(mensagem), stdin);
    printf("Digite o valor do deslocamento (número inteiro): ");
    scanf("%d", &troca);
    printf("Digite 1 para descriptografar ou 0 para criptografar: ");
    scanf("%d", &inverso);

    cifra_cesar(mensagem, troca, inverso);

    if (inverso)
        printf("Mensagem descriptografada: %s\n", mensagem);
    else
        printf("Mensagem criptografada: %s\n", mensagem);

    system("pause");

    return 0;
}