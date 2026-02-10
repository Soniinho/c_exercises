#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments

int main()
{
    setlocale(LC_ALL, "portuguese");
    int opcao_inicio;
    printf("1- Verificar se um número é primo ou não"
           "\n2- programa 2"
           "\n3- programa 3"
           "\n4- programa 4"
           "\n5- programa 5"
           "\n6- programa 6"
           "\n7- programa 7"
           "\n8- programa 8"
           "\n9- programa 9"
           "\n10- Sair");
    printf("\nSelecione uma das opções para continuar: ");
    scanf("%d%*c", &opcao_inicio);

    while (opcao_inicio < 1 || opcao_inicio > 10)
    {
        printf("Opção inválida, digite umas das opções da lista para continuar: ");
        scanf("%d%*c", &opcao_inicio);
    }

    if (opcao_inicio >= 1 && opcao_inicio < 10)
    {
        system("cls");
    }

    switch (opcao_inicio)
    {
    case 1:
    {
        main1();
        break;
    }
    case 2:
    {
        main2();
        break;
    }
    case 3:
    {
        main3();
        break;
    }
    case 4:
    {
        main4();
        break;
    }
    case 5:
    {
        main5();
        break;
    }
    case 6:
    {
        main6();
        break;
    }
    case 7:
    {
        main7();
        break;
    }
    case 8:
    {
        main8();
        break;
    }
    case 9:
    {
        main9();
        break;
    }
    default:
    {
        printf("\nSaindo...");
        system("pause");
        exit(main);
    }
    }
}

int main1()
{
    int i, numero, verificacao;
    char opc, primo;
    printf("Digite um número inteiro maior do que 1:  ");
    scanf("%d%*c", &numero);

    if (numero < 1)
    {
        printf("Número inválido, aperte \"enter\" para reiniciar o programa.");
        getchar();
        system("cls");
        main1();
    }
    else if (numero == 1)
    {
        printf("O número digitado é primo.");
    }
    else
    {
        primo = 'v';

        for (i = 2; i < numero; i++)
        {
            verificacao = numero % i;

            if (verificacao == 0)
            {
                printf("O número digitado não é primo.");
                primo = 'f';
                break;
            }
        }
        
        if (primo == 'v')
        {
            printf("O número digitado é primo.");
        }
    }

    printf("\nDeseja reiniciar o programa? \'s\' ou \'n\'\n");
    scanf("%c%*c", &opc);
    if (opc == 's')
    {
        system("cls");
        main1();
    }
    else
    {
        printf("Voltando para a lista de programas...Aperte Enter para continuar");
        getchar();
        system("cls");
        main();
    }
}

int main2()
{
    return 0;
}

int main3()
{
    return 0;
}

int main4()
{
    return 0;
}

int main5()
{
    return 0;
}

int main6()
{
    return 0;
}

int main7()
{
    return 0;
}

int main8()
{
    return 0;
}

int main9()
{
    return 0;
}