#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de uma venda
typedef struct {
    char data[11]; // formato dd/mm/yyyy
    int codigo;
    char nome[50];
    char marca[30];
    int quantidade;
    float precoUnitario;
    float valorTotal;
} Venda;

// Função para calcular valor total da venda (com desconto se aplicável)
float calcularValorTotal(int quantidade, float precoUnitario) {
    float total = quantidade * precoUnitario;
    if (quantidade >= 3) {
        total *= 0.9; // desconto de 10%
    }
    return total;
}

// Função para gravar a venda no TXT e CSV
void gravarVendaArquivo(Venda v) {
    // TXT
    FILE *arquivoTxt = fopen("loja_roupa.txt", "a");
    if (arquivoTxt == NULL) {
        printf("Erro ao abrir o arquivo TXT.\n");
        exit(1);
    }
    fprintf(arquivoTxt, "%s;%d;%s;%s;%d;%.2f;%.2f\n",
            v.data,
            v.codigo,
            v.nome,
            v.marca,
            v.quantidade,
            v.precoUnitario,
            v.valorTotal);
    fclose(arquivoTxt);

    // CSV
    FILE *arquivoCsv = fopen("loja_roupa.csv", "a");
    if (arquivoCsv == NULL) {
        printf("Erro ao abrir o arquivo CSV.\n");
        exit(1);
    }

    // Opcional: se o CSV não existe, criar cabeçalho (somente se o arquivo for novo)
    static int cabecalhoEscrito = 0;
    if (!cabecalhoEscrito) {
        fseek(arquivoCsv, 0, SEEK_END);
        long tamanho = ftell(arquivoCsv);
        if (tamanho == 0) {
            fprintf(arquivoCsv, "Data,Codigo,Nome,Marca,Quantidade,PrecoUnitario,ValorTotal\n");
        }
        cabecalhoEscrito = 1;
    }

    fprintf(arquivoCsv, "%s,%d,%s,%s,%d,%.2f,%.2f\n",
            v.data,
            v.codigo,
            v.nome,
            v.marca,
            v.quantidade,
            v.precoUnitario,
            v.valorTotal);
    fclose(arquivoCsv);
}

// Função para ler todas as vendas do TXT e retornar quantidade lida
int carregarVendasArquivo(Venda vendas[], int max) {
    FILE *arquivo = fopen("loja_roupa.txt", "r");
    if (arquivo == NULL) {
        return 0; // Nenhum dado
    }
    int count = 0;
    while (fscanf(arquivo, "%[^;];%d;%[^;];%[^;];%d;%f;%f\n",
                  vendas[count].data,
                  &vendas[count].codigo,
                  vendas[count].nome,
                  vendas[count].marca,
                  &vendas[count].quantidade,
                  &vendas[count].precoUnitario,
                  &vendas[count].valorTotal) == 7) {
        count++;
        if (count >= max) break;
    }
    fclose(arquivo);
    return count;
}

// Função para ordenar vendas em ordem decrescente de valor total
// Função para trocar duas vendas
void trocar(Venda *a, Venda *b) {
    Venda temp = *a;
    *a = *b;
    *b = temp;
}

// Função de particionamento (para ordenar em ordem decrescente)
int particionar(Venda vendas[], int inicio, int fim) {
    float pivo = vendas[fim].valorTotal;
    int i = inicio - 1;
    for (int j = inicio; j < fim; j++) {
        if (vendas[j].valorTotal >= pivo) { // Maior primeiro
            i++;
            trocar(&vendas[i], &vendas[j]);
        }
    }
    trocar(&vendas[i + 1], &vendas[fim]);
    return i + 1;
}

// Função recursiva do QuickSort
void quickSort(Venda vendas[], int inicio, int fim) {
    if (inicio < fim) {
        int indicePivo = particionar(vendas, inicio, fim);
        quickSort(vendas, inicio, indicePivo - 1);
        quickSort(vendas, indicePivo + 1, fim);
    }
}

// Função principal que chama o QuickSort
void ordenarVendasPorValorDecrescente(Venda vendas[], int n) {
    quickSort(vendas, 0, n - 1);
}


// Função para gerar relatórios de uma data específica
void gerarRelatoriosPorData(char data[]) {
    Venda vendas[500];
    int totalVendas = carregarVendasArquivo(vendas, 500);
    int i;
    float faturamento = 0;
    int qtdClientes = 0;
    int maxQtd = -1, minQtd = 999999;
    char itemMaisVendido[50], itemMenosVendido[50];

    for (i = 0; i < totalVendas; i++) {
        if (strcmp(vendas[i].data, data) == 0) {
            faturamento += vendas[i].valorTotal;
            qtdClientes++;
            if (vendas[i].quantidade > maxQtd) {
                maxQtd = vendas[i].quantidade;
                strcpy(itemMaisVendido, vendas[i].nome);
            }
            if (vendas[i].quantidade < minQtd) {
                minQtd = vendas[i].quantidade;
                strcpy(itemMenosVendido, vendas[i].nome);
            }
        }
    }
    printf("\nRELATORIO DO DIA %s\n", data);
    printf("Faturamento Bruto: R$ %.2f\n", faturamento);
    printf("Quantidade de clientes: %d\n", qtdClientes);
    if (qtdClientes > 0) {
        printf("Item mais vendido: %s (%d unidades)\n", itemMaisVendido, maxQtd);
        printf("Item menos vendido: %s (%d unidades)\n", itemMenosVendido, minQtd);
    } else {
        printf("Nenhuma venda nesta data.\n");
    }

    printf("\nLista de vendas em ordem decrescente:\n");
    ordenarVendasPorValorDecrescente(vendas, totalVendas);
    for (i = 0; i < totalVendas; i++) {
        if (strcmp(vendas[i].data, data) == 0) {
            printf("Venda: %s - %s (%s) - Qtd: %d - Total: R$ %.2f\n",
                   vendas[i].nome,
                   vendas[i].marca,
                   vendas[i].data,
                   vendas[i].quantidade,
                   vendas[i].valorTotal);
        }
    }
}

// Função principal
int main() {
    int opcao = -1;

    printf("=== SISTEMA DE VENDAS LOJA DE ROUPAS ===\n");

    do {
        printf("\n========= MENU PRINCIPAL =========\n");
        printf("1 - Registrar nova venda\n");
        printf("2 - Gerar relatorio por data\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Venda v;
                printf("\nDigite a data da venda (dd/mm/yyyy): ");
                scanf(" %10[^\n]", v.data);
                printf("Codigo do item: ");
                scanf("%d", &v.codigo);
                printf("Nome do item: ");
                scanf(" %49[^\n]", v.nome);
                printf("Marca do item: ");
                scanf(" %29[^\n]", v.marca);
                printf("Quantidade de itens: ");
                scanf("%d", &v.quantidade);
                printf("Preco unitario: ");
                scanf("%f", &v.precoUnitario);

                v.valorTotal = calcularValorTotal(v.quantidade, v.precoUnitario);
                printf("Total a pagar: R$ %.2f\n", v.valorTotal);
                printf("Quantidade total de itens nesta venda: %d\n", v.quantidade);

                gravarVendaArquivo(v);
                printf("Venda registrada com sucesso.\n");
                break;
            }

            case 2: {
                char data[11];
                printf("\nInforme a data para relatorios (dd/mm/yyyy): ");
                scanf(" %10[^\n]", data);
                gerarRelatoriosPorData(data);
                break;
            }

            case 0:
                printf("\nEncerrando o programa. Ate logo!\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
