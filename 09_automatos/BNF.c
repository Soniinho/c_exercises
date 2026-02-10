// Matheus Henrique Daltroso RA: 202110059

/* prog.txt
int ypiz234 = 10;
int z12314 = x + y;

if (z + 15) {
    int x = z * 2;
} else {
    int yyy = z / 2;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

// Definindo tokens
typedef enum
{
    TK_ESPACO,
    TK_LETRAS,
    TK_INTEIRO,
    TK_SE,
    TK_SENAO,
    TK_NUMERO,
    TK_IGUAL,
    TK_PONTO_VIRGULA,
    TK_OPERADOR,
    TK_ABRE_PARENTESES,
    TK_FECHA_PARENTESES,
    TK_ABRE_CHAVES,
    TK_FECHA_CHAVES,
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

    if (isspace(caractere))
    {
        // caractere = proximoCaractere(arquivo); // Ignorar espaços em branco
        return criarToken(TK_ESPACO, "");
    }
    else if (isalpha(caractere)) // Verificar se o caractere é uma palavra-chave
    {
        char palavra_chave[5]; // 'int', 'if', 'else' + 0
        int i = 0;
        palavra_chave[i++] = caractere;
        long posicaoInicial = ftell(arquivo);
        while (i < 4 && isalpha(caractere = proximoCaractere(arquivo)))
        {
            palavra_chave[i++] = caractere;
        }
        palavra_chave[i] = '\0';

        if (strcmp(palavra_chave, "int") == 0)
        {
            return criarToken(TK_INTEIRO, "int");
        }
        else if (strcmp(palavra_chave, "if") == 0)
        {
            return criarToken(TK_SE, "if");
        }
        else if (strcmp(palavra_chave, "else") == 0)
        {
            return criarToken(TK_SENAO, "else");
        }
        else
        {
            // Voltar os caracteres não utilizados ao arquivo
            fseek(arquivo, posicaoInicial - 1, SEEK_SET); //-i-1 SEEK_CUR
            caractere = proximoCaractere(arquivo);
            char *lexema = (char *)malloc(sizeof(char) * 2);
            lexema[0] = caractere;
            lexema[1] = '\0';
            return criarToken(TK_LETRAS, lexema);
        }
    }
    else if (isdigit(caractere))
    {
        // Token é um número
        char *lexema = (char *)malloc(sizeof(char) * 2);
        lexema[0] = caractere;
        lexema[1] = '\0';
        return criarToken(TK_NUMERO, lexema);
    }
    else if (caractere == '=')
    {
        return criarToken(TK_IGUAL, "=");
    }
    else if (caractere == ';')
    {
        return criarToken(TK_PONTO_VIRGULA, ";");
    }
    else if (caractere == '+' || caractere == '-' || caractere == '*' || caractere == '/')
    {
        if (caractere == '+')
            return criarToken(TK_OPERADOR, "+");
        else if (caractere == '-')
            return criarToken(TK_OPERADOR, "-");
        else if (caractere == '*')
            return criarToken(TK_OPERADOR, "*");
        else if (caractere == '/')
            return criarToken(TK_OPERADOR, "/");
    }
    else if (caractere == '(')
    {
        return criarToken(TK_ABRE_PARENTESES, "(");
    }
    else if (caractere == ')')
    {
        return criarToken(TK_FECHA_PARENTESES, ")");
    }
    else if (caractere == '{')
    {
        return criarToken(TK_ABRE_CHAVES, "{");
    }
    else if (caractere == '}')
    {
        return criarToken(TK_FECHA_CHAVES, "}");
    }
    else if (caractere == EOF)
    {
        return criarToken(TK_FIM, "FIM");
    }

    return criarToken(TK_ERRO, "ERRO");
}

// Funções para análise sintática
void pularEspaco(FILE *arquivo, Token *token);
void programa(FILE *arquivo, Token *token);
void declaracao(FILE *arquivo, Token *token);
void variavel(FILE *arquivo, Token *token);
void identificador(FILE *arquivo, Token *token);
void expressao(FILE *arquivo, Token *token);
void condicional(FILE *arquivo, Token *token);

void pularEspaco(FILE *arquivo, Token *token)
{
    while (token->tipo == TK_ESPACO)
    {
        *token = analiseLexica(arquivo);
    }
}

//@<programa> ::= <declaracao> <programa> | <declaracao>
void programa(FILE *arquivo, Token *token)
{
    declaracao(arquivo, token);
    while (token->tipo != TK_FIM)
    {
        *token = analiseLexica(arquivo);
        programa(arquivo, token);
    }
}

//@<declaracao> ::= <variavel> "=" <expressao> ";" | <condicional>
void declaracao(FILE *arquivo, Token *token)
{
    pularEspaco(arquivo, token);
    if (token->tipo == TK_INTEIRO)
    {
        variavel(arquivo, token);
        pularEspaco(arquivo, token);
        if (token->tipo == TK_IGUAL)
        {
            pularEspaco(arquivo, token);
            *token = analiseLexica(arquivo);
            pularEspaco(arquivo, token);
            expressao(arquivo, token);
            pularEspaco(arquivo, token);
            if (token->tipo != TK_PONTO_VIRGULA)
            {
                printf("Erro na análise léxica, não há ponto e vírgula.\n");
                exit(1);
            }
        }
    }
    else if (token->tipo == TK_SE)
    {
        condicional(arquivo, token);
        pularEspaco(arquivo, token);
    }
    else
    {
        printf("Erro na análise léxica de declaração.\n");
        exit(1);
    }
}

//@<variavel> ::= "int" <identificador>
void variavel(FILE *arquivo, Token *token)
{
    *token = analiseLexica(arquivo);
    pularEspaco(arquivo, token);
    if (token->tipo == TK_LETRAS)
    {
        identificador(arquivo, token);
    }
    else if (token->tipo == TK_ERRO)
    {
        printf("Erro na análise léxica, não há nome de variável após int.");
        exit(1);
    }
}

//@<identificador> ::= <letra> | <identificador> <letra> | <identificador> <digito>
void identificador(FILE *arquivo, Token *token)
{
    *token = analiseLexica(arquivo);
    while (token->tipo == TK_LETRAS || token->tipo == TK_NUMERO)
    {
        *token = analiseLexica(arquivo);
    }
    pularEspaco(arquivo, token);
}

//@<expressao> ::= <digito> | <identificador> | <expressao> <operador> <expressao>
void expressao(FILE *arquivo, Token *token)
{
    if (token->tipo == TK_NUMERO)
    {
        while (token->tipo == TK_NUMERO)
        {
            *token = analiseLexica(arquivo);
        }
    }
    else if (token->tipo == TK_LETRAS)
    {
        identificador(arquivo, token);
    }

    pularEspaco(arquivo, token);
    if (token->tipo == TK_OPERADOR)
    {
        *token = analiseLexica(arquivo);
        pularEspaco(arquivo, token);
        expressao(arquivo, token);
    }
}

//@<condicional> ::= "if" "(" <expressao> ")" "{" <declaracao> "}" "else" "{" <declaracao> "}"
void condicional(FILE *arquivo, Token *token)
{
    *token = analiseLexica(arquivo);
    pularEspaco(arquivo, token);
    if (token->tipo == TK_ABRE_PARENTESES)
    {
        *token = analiseLexica(arquivo);
        pularEspaco(arquivo, token);
        expressao(arquivo, token);
        if (token->tipo == TK_FECHA_PARENTESES)
        {
            *token = analiseLexica(arquivo);
            pularEspaco(arquivo, token);
            if (token->tipo == TK_ABRE_CHAVES)
            {
                *token = analiseLexica(arquivo);
                pularEspaco(arquivo, token);
                declaracao(arquivo, token);
                *token = analiseLexica(arquivo);
                pularEspaco(arquivo, token);
                if (token->tipo == TK_FECHA_CHAVES)
                {
                    *token = analiseLexica(arquivo);
                    pularEspaco(arquivo, token);
                    if (token->tipo == TK_SENAO)
                    {
                        *token = analiseLexica(arquivo);
                        pularEspaco(arquivo, token);
                        if (token->tipo == TK_ABRE_CHAVES)
                        {
                            *token = analiseLexica(arquivo);
                            pularEspaco(arquivo, token);
                            declaracao(arquivo, token);
                            *token = analiseLexica(arquivo);
                            pularEspaco(arquivo, token);
                            if (token->tipo == TK_FECHA_CHAVES)
                            {
                                *token = analiseLexica(arquivo);
                                pularEspaco(arquivo, token);
                            }
                        }
                    }
                }
            }
        }
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

    // Expressao1(arquivo, &token);
    programa(arquivo, &token);

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
    arquivo = fopen("prog.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    analiseSintatica(arquivo);

    fclose(arquivo);
    return 0;
}
