#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments

int main()
{
    setlocale(LC_ALL, "portuguese");
    float i, n1, n2, n3, n4;

    printf("Será pedido para digitar 5 grupos de 4 valores diferentes. Aperte \"enter\" para continuar...");
    getchar();
    system("cls");

    for (i = 1; i <= 5; i++)
    {
        printf("Digite o 1° número:");
        scanf("%f%*c", &n1);
        printf("Digite o 2° número:");
        scanf("%f%*c", &n2);
        printf("Digite o 3° número:");
        scanf("%f%*c", &n3);
        printf("Digite o 4° número:");
        scanf("%f%*c", &n4);

        printf("\nOrdem escrita:\n");
        printf("%.3f\n%.3f\n%.3f\n%.3f\n", n1, n2, n3, n4);

        printf("\nOrdem decrescente:\n");

        if (n1 > n2 && n1 > n3 && n1 > n4) //para n1<
        {
            printf("%.3f\n", n1);
            if (n2 > n3 && n2 > n4)
            {
                printf("%.3f\n", n2);
                if (n3 > n4)
                {
                    printf("%.3f\n", n3);
                    printf("%.3f\n", n4);
                }
                else if (n4 > n3)
                {
                    printf("%.3f\n", n4);
                    printf("%.3f\n", n3);
                }
            }
            else if (n3 > n2 && n3 > n4)
            {
                printf("%.3f\n", n3);
                if (n2 > n4)
                {
                    printf("%.3f\n", n2);
                    printf("%.3f\n", n4);
                }
                else if (n4 > n2)
                {
                    printf("%.3f\n", n4);
                    printf("%.3f\n", n2);
                }
            }
            else
            {
                printf("%.3f\n", n4);
                if (n2 > n3)
                {
                    printf("%.3f\n", n2);
                    printf("%.3f\n", n3);
                }
                else if (n3 > n2)
                {
                    printf("%.3f\n", n3);
                    printf("%.3f\n", n2);
                }
            }
        }
        else if (n2 > n1 && n2 > n3 && n2 > n4) //para n2<
        {
            printf("%.3f\n", n2);
            if (n1 > n3 && n1 > n4)
            {
                printf("%.3f\n", n1);
                if (n3 > n4)
                {
                    printf("%.3f\n", n3);
                    printf("%.3f\n", n4);
                }
                else if (n4 > n3)
                {
                    printf("%.3f\n", n4);
                    printf("%.3f\n", n3);
                }
            }
            else if (n3 > n1 && n3 > n4)
            {
                printf("%.3f\n", n3);
                if (n1 > n4)
                {
                    printf("%.3f\n", n1);
                    printf("%.3f\n", n4);
                }
                else if (n4 > n1)
                {
                    printf("%.3f\n", n4);
                    printf("%.3f\n", n1);
                }
            }
            else
            {
                printf("%.3f\n", n4);
                if (n1 > n3)
                {
                    printf("%.3f\n", n1);
                    printf("%.3f\n", n3);
                }
                else if (n3 > n2)
                {
                    printf("%.3f\n", n3);
                    printf("%.3f\n", n1);
                }
            }
        }
        else if (n3 > n1 && n3 > n2 && n3 > n4) //para n3<
        {
            printf("%.3f\n", n3);
            if (n1 > n2 && n1 > n4)
            {
                printf("%.3f\n", n1);
                if (n2 > n4)
                {
                    printf("%.3f\n", n2);
                    printf("%.3f\n", n4);
                }
                else if (n4 > n2)
                {
                    printf("%.3f\n", n4);
                    printf("%.3f\n", n2);
                }
            }
            else if (n2 > n1 && n2 > n4)
            {
                printf("%.3f\n", n2);
                if (n1 > n4)
                {
                    printf("%.3f\n", n1);
                    printf("%.3f\n", n4);
                }
                else if (n4 > n1)
                {
                    printf("%.3f\n", n4);
                    printf("%.3f\n", n1);
                }
            }
            else
            {
                printf("%.3f\n", n4);
                if (n2 > n1)
                {
                    printf("%.3f\n", n2);
                    printf("%.3f\n", n1);
                }
                else if (n1 > n2)
                {
                    printf("%.3f\n", n1);
                    printf("%.3f\n", n2);
                }
            }
        }
        else if (n4 > n1 && n4 > n2 && n4 > n3) //para n4<
        {
            printf("%.3f\n", n4);
            if (n1 > n2 && n1 > n3)
            {
                printf("%.3f\n", n1);
                if (n2 > n3)
                {
                    printf("%.3f\n", n2);
                    printf("%.3f\n", n3);
                }
                else if (n3 > n2)
                {
                    printf("%.3f\n", n3);
                    printf("%.3f\n", n2);
                }
            }
            else if (n2 > n1 && n2 > n3)
            {
                printf("%.3f\n", n2);
                if (n1 > n3)
                {
                    printf("%.3f\n", n1);
                    printf("%.3f\n", n3);
                }
                else if (n3 > n1)
                {
                    printf("%.3f\n", n3);
                    printf("%.3f\n", n1);
                }
            }
            else
            {
                printf("%.3f\n", n3);
                if (n1 > n2)
                {
                    printf("%.3f\n", n1);
                    printf("%.3f\n", n2);
                }
                else if (n2 > n1)
                {
                    printf("%.3f\n", n2);
                    printf("%.3f\n", n1);
                }
            }
        }

        printf("\nOrdem crescente:\n");

        if (n1 < n2 && n1 < n3 && n1 < n4) //para n1>
        {
            printf("%.3f\n", n1);
            if (n2 < n3 && n2 < n4)
            {
                printf("%.3f\n", n2);
                if (n3 < n4)
                {
                    printf("%.3f\n", n3);
                    printf("%.3f\n", n4);
                }
                else if (n4 < n3)
                {
                    printf("%.3f\n", n4);
                    printf("%.3f\n", n3);
                }
            }
            else if (n3 < n2 && n3 < n4)
            {
                printf("%.3f\n", n3);
                if (n2 < n4)
                {
                    printf("%.3f\n", n2);
                    printf("%.3f\n", n4);
                }
                else if (n4 < n2)
                {
                    printf("%.3f\n", n4);
                    printf("%.3f\n", n2);
                }
            }
            else
            {
                printf("%.3f\n", n4);
                if (n2 < n3)
                {
                    printf("%.3f\n", n2);
                    printf("%.3f\n", n3);
                }
                else if (n3 < n2)
                {
                    printf("%.3f\n", n3);
                    printf("%.3f\n", n2);
                }
            }
        }
        else if (n2 < n1 && n2 < n3 && n2 < n4) //para n2>
        {
            printf("%.3f\n", n2);
            if (n1 < n3 && n1 < n4)
            {
                printf("%.3f\n", n1);
                if (n3 < n4)
                {
                    printf("%.3f\n", n3);
                    printf("%.3f\n", n4);
                }
                else if (n4 < n3)
                {
                    printf("%.3f\n", n4);
                    printf("%.3f\n", n3);
                }
            }
            else if (n3 < n1 && n3 < n4)
            {
                printf("%.3f\n", n3);
                if (n1 < n4)
                {
                    printf("%.3f\n", n1);
                    printf("%.3f\n", n4);
                }
                else if (n4 < n1)
                {
                    printf("%.3f\n", n4);
                    printf("%.3f\n", n1);
                }
            }
            else
            {
                printf("%.3f\n", n4);
                if (n1 < n3)
                {
                    printf("%.3f\n", n1);
                    printf("%.3f\n", n3);
                }
                else if (n3 < n2)
                {
                    printf("%.3f\n", n3);
                    printf("%.3f\n", n1);
                }
            }
        }
        else if (n3 < n1 && n3 < n2 && n3 < n4) //para n3>
        {
            printf("%.3f\n", n3);
            if (n1 < n2 && n1 < n4)
            {
                printf("%.3f\n", n1);
                if (n2 < n4)
                {
                    printf("%.3f\n", n2);
                    printf("%.3f\n", n4);
                }
                else if (n4 < n2)
                {
                    printf("%.3f\n", n4);
                    printf("%.3f\n", n2);
                }
            }
            else if (n2 < n1 && n2 < n4)
            {
                printf("%.3f\n", n2);
                if (n1 < n4)
                {
                    printf("%.3f\n", n1);
                    printf("%.3f\n", n4);
                }
                else if (n4 < n1)
                {
                    printf("%.3f\n", n4);
                    printf("%.3f\n", n1);
                }
            }
            else
            {
                printf("%.3f\n", n4);
                if (n2 < n1)
                {
                    printf("%.3f\n", n2);
                    printf("%.3f\n", n1);
                }
                else if (n1 < n2)
                {
                    printf("%.3f\n", n1);
                    printf("%.3f\n", n2);
                }
            }
        }
        else if (n4 < n1 && n4 < n2 && n4 < n3) //para n4>
        {
            printf("%.3f\n", n4);
            if (n1 < n2 && n1 < n3)
            {
                printf("%.3f\n", n1);
                if (n2 < n3)
                {
                    printf("%.3f\n", n2);
                    printf("%.3f\n", n3);
                }
                else if (n3 < n2)
                {
                    printf("%.3f\n", n3);
                    printf("%.3f\n", n2);
                }
            }
            else if (n2 < n1 && n2 < n3)
            {
                printf("%.3f\n", n2);
                if (n1 < n3)
                {
                    printf("%.3f\n", n1);
                    printf("%.3f\n", n3);
                }
                else if (n3 < n1)
                {
                    printf("%.3f\n", n3);
                    printf("%.3f\n", n1);
                }
            }
            else
            {
                printf("%.3f\n", n3);
                if (n1 < n2)
                {
                    printf("%.3f\n", n1);
                    printf("%.3f\n", n2);
                }
                else if (n2 < n1)
                {
                    printf("%.3f\n", n2);
                    printf("%.3f\n", n1);
                }
            }
        }

        printf("\nGrupo %.0f\n", i + 1);
    }

    return 0;
}