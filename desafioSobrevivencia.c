// Nível: Novato
// Simulação de um jogo que envolve sobrevivência em um ambiente hostil.
// Simlar uma mochila que pode carregar itens limitados: 10 itens no máximo.
//  1 - Precisamos de forma para representar um item no código, com características
//  Nome, tipo e quantidade, usando scruct, como ficha cadastral do item.
// Criamos lista linear, vetor para guardar uma ficha de cada item.
// Vetor com capacidade para 10 itens.
// Precisamos saber quantos itens estão cadastrados na mochila, contador de itens, aumentando quando um item é adicionado.
//  E reduzindo quando um item é removido.
// Programa terá um menu principal com as seguintes opções:
//  1 - Adicionar item na mochila
//  2 - Remover item da mochila, perguntando o nome do item a ser removido, usar strcmp para comparar strings.
//  3 - Listar itens da mochila, mostrando todas as informações de cada item cadastrado
//  4 - Sair do programa
// Todas as vezes que um item for adicionado ou removido, printar uma lista com todos os itens atuais na mochila.
// Manter o código organizado, com funções para cada funcionalidade do menu.
// Manter a saída do programa amigável, com mensagens claras para o usuário e boa formatação.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Contante para definir o máximo de itens na mochila, o tamanho máximo do nome e do tipo do item
#define MAX_ITENS 10
#define MAX_NOME 50
#define MAX_TIPO 30

// Definição da struct para representar um item
typedef struct
{
    char nome[MAX_NOME];
    char tipo[MAX_TIPO];
    int quantidade;
} Item;

// Função para adicionar um item na mochila
void adicionarItem(Item mochila[], int *contador)
{
    if (*contador >= MAX_ITENS)
    {
        printf("Mochila cheia! Nao e possivel adicionar mais itens.\n");
        return;
    }
    Item novoItem;
    printf("Digite o nome do item: ");
    scanf(" %[^\n]", novoItem.nome);
    printf("Digite o tipo do item: ");
    scanf(" %[^\n]", novoItem.tipo);
    printf("Digite a quantidade do item: ");
    scanf("%d", &novoItem.quantidade);
    mochila[*contador] = novoItem;
    (*contador)++;
}

// Função para remover um item da mochila
void removerItem(Item mochila[], int *contador)
{
    if (*contador == 0)
    {
        printf("Mochila vazia! Nao ha itens para remover.\n");
        return;
    }
    char nomeRemover[MAX_NOME];
    printf("Digite o nome do item a ser removido: ");
    scanf(" %[^\n]", nomeRemover);
    for (int i = 0; i < *contador; i++)
    {
        if (strcmp(mochila[i].nome, nomeRemover) == 0)
        {
            for (int j = i; j < *contador - 1; j++)
            {
                mochila[j] = mochila[j + 1];
            }
            (*contador)--;
            printf("Item removido com sucesso!\n");
            return;
        }
    }
    printf("Item nao encontrado na mochila.\n");
}

// Função para listar os itens na mochila
void listarItens(Item mochila[], int contador)
{
    if (contador == 0)
    {
        printf("Mochila vazia! Nao ha itens para listar.\n");
        return;
    }
    printf("Itens na mochila:\n");
    printf("+------------------+----------------+---------------\n");
    printf("| Nome.            | Tipo           | Quantidade    |\n");
    printf("+------------------+----------------+---------------\n");
    for (int i = 0; i < contador; i++)
    {
        printf("| %-16.16s | %-14.14s | %-12d |\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
    printf("+------------------+----------------+---------------\n");
}

// Função principal com o menu do programa
int main()
{
    Item mochila[MAX_ITENS];
    int contador = 0;
    int opcao;
    do
    {
        printf("\nMenu:\n");
        printf("-------------------------\n");
        printf("Mochila: %d/%d itens\n", contador, MAX_ITENS);
        printf("-------------------------\n");
        printf("1 - Adicionar item na mochila\n");
        printf("2 - Remover item da mochila\n");
        printf("3 - Listar itens da mochila\n");
        printf("4 - Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            adicionarItem(mochila, &contador);
            listarItens(mochila, contador);
            break;
        case 2:
            removerItem(mochila, &contador);
            listarItens(mochila, contador);
            break;
        case 3:
            listarItens(mochila, contador);
            break;
        case 4:
            printf("Saindo do programa. Ate mais!\n");
            break;
        default:
            printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 4);
    return 0;
}