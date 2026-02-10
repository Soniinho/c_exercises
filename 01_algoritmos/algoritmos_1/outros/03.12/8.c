#include <stdio.h>
#include <stdlib.h>

int main()
{
    char senha[12] = "batatafrita", senha_d[12];
    printf("Digite a senha:");
    scanf("%s", &senha_d);
    if(strcmp(senha,senha_d) == 0){
        printf("Acesso permitido.");
    } else {
        printf("Acesso negado.");
    }
    //coisa nova
    return 0;
}
