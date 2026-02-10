#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

/* entrada.txt
(3 + 5) * 2 - 4 / 2
*/

// Definindo tokens
typedef enum
{
    TK_NUMERO,
    TK_MAIS,
    TK_MENOS,
    TK_MULTIPLICACAO,
    TK_DIVISAO,
    TK_ABRE_PARENTESES,
    TK_FECHA_PARENTESES,
    TK_FIM,
    TK_ERRO
} TipoToken;

// Estrutura de token
typedef struct
{
    TipoToken tipo;
    char *lexema;
} Token;

// Função para ler próximo caractere do arquivo
char proximoCaractere(FILE *arquivo)
{
    return fgetc(arquivo);
}

// Função para criar token
Token criarToken(TipoToken tipo, char *lexema)
{
    Token token;
    token.tipo = tipo;
    token.lexema = lexema;
    return token;
}

// Função para realizar a análise léxica
Token analiseLexica(FILE *arquivo)
{
    char caractere;
    caractere = proximoCaractere(arquivo);

    while (isspace(caractere))
    {
        caractere = proximoCaractere(arquivo); // Ignorar espaços em branco
    }

    if (isdigit(caractere))
    {
        // Token é um número
        char *lexema = (char *)malloc(sizeof(char) * 2);
        lexema[0] = caractere;
        lexema[1] = '\0';
        return criarToken(TK_NUMERO, lexema);
    }
    else if (caractere == '+')
    {
        return criarToken(TK_MAIS, "+");
    }
    else if (caractere == '-')
    {
        return criarToken(TK_MENOS, "-");
    }
    else if (caractere == '*')
    {
        return criarToken(TK_MULTIPLICACAO, "*");
    }
    else if (caractere == '/')
    {
        return criarToken(TK_DIVISAO, "/");
    }
    else if (caractere == '(')
    {
        return criarToken(TK_ABRE_PARENTESES, "(");
    }
    else if (caractere == ')')
    {
        return criarToken(TK_FECHA_PARENTESES, ")");
    }
    else if (caractere == EOF)
    {
        return criarToken(TK_FIM, "FIM");
    }
    else
    {
        return criarToken(TK_ERRO, "ERRO");
    }
}

// Gramática:
// Expressão ::= Termo '+' Termo | Termo '-' Termo | Termo
// Termo ::= Fator '*' Fator | Fator '/' Fator | Fator
// Fator ::= '(' Expressão ')' | Número
// Número ::= [0-9]+

// Funções para análise sintática
void expressao(FILE *arquivo, Token *token);
void Termo(FILE *arquivo, Token *token);
void Fator(FILE *arquivo, Token *token);

void Fator(FILE *arquivo, Token *token)
{
    if (token->tipo == TK_NUMERO)
    {
        printf("Fator: Número %s\n", token->lexema);
        *token = analiseLexica(arquivo);
    }
    else if (token->tipo == TK_ABRE_PARENTESES)
    {
        printf("Fator: Abrir parênteses\n");
        *token = analiseLexica(arquivo);
        expressao(arquivo, token);
        if (token->tipo != TK_FECHA_PARENTESES)
        {
            printf("Erro: Esperado fechar parênteses.\n");
            exit(1);
        }
        printf("Fator: Fechar parênteses\n");
        *token = analiseLexica(arquivo);
    }
    else
    {
        printf("Erro: Esperado número ou abrir parênteses.\n");
        exit(1);
    }
}

void Termo(FILE *arquivo, Token *token)
{
    Fator(arquivo, token);
    while (token->tipo == TK_MULTIPLICACAO || token->tipo == TK_DIVISAO)
    {
        if (token->tipo == TK_MULTIPLICACAO)
        {
            printf("Termo: Multiplicação\n");
        }
        else
        {
            printf("Termo: Divisão\n");
        }
        *token = analiseLexica(arquivo);
        Fator(arquivo, token);
    }
}

void expressao(FILE *arquivo, Token *token)
{
    Termo(arquivo, token);
    while (token->tipo == TK_MAIS || token->tipo == TK_MENOS)
    {
        if (token->tipo == TK_MAIS)
        {
            printf("Expressão: Adição\n");
        }
        else
        {
            printf("Expressão: Subtração\n");
        }
        *token = analiseLexica(arquivo);
        Termo(arquivo, token);
    }
}

void analiseSintatica(FILE *arquivo)
{
    Token token;
    token = analiseLexica(arquivo);

    if (token.tipo == TK_ERRO)
    {
        printf("Erro de análise léxica.\n");
        exit(1);
    }

    expressao(arquivo, &token);

    if (token.tipo != TK_FIM)
    {
        printf("Erro: Token inesperado no final do arquivo.\n");
        exit(1);
    }

    printf("Análise sintática concluída.\n");
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    FILE *arquivo;
    arquivo = fopen("../entrada.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    analiseSintatica(arquivo);

    fclose(arquivo);
    return 0;
}
