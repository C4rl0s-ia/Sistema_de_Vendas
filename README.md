# 📊 Sistema de Vendas - Loja de Roupas

Este projeto é um sistema em linguagem C para **registro, armazenamento e geração de relatórios de vendas** de uma loja de roupas. O programa permite cadastrar vendas, salvar os dados em arquivos TXT e CSV e gerar relatórios detalhados por data, incluindo faturamento, quantidade de clientes e ranking dos produtos mais e menos vendidos.

---

## 🎯 Objetivo do Projeto

Desenvolver um sistema simples e funcional que auxilie no **controle de vendas diárias** de uma loja de roupas, aplicando conceitos fundamentais de programação em C, tais como:

- Manipulação de arquivos (`fopen`, `fprintf`, `fscanf`)
- Uso de `struct` para organização dos dados
- Operações de ordenação
- Relatórios dinâmicos por data
- Menu interativo com `switch` e loops

---

## 🧩 Estrutura de Dados

O sistema usa a seguinte estrutura principal:

```c
typedef struct {
    char data[11];           // Data no formato dd/mm/yyyy
    int codigo;              // Código do item vendido
    char nome[50];           // Nome do produto
    char marca[30];          // Marca do produto
    int quantidade;          // Quantidade vendida
    float precoUnitario;     // Preço unitário
    float valorTotal;        // Valor total da venda (considerando desconto)
} Venda;
```
Essa `struct` armazena todas as informações relevantes sobre cada venda registrada.

---

## ⚙️ Funções e Explicações

### `float calcularValorTotal(int quantidade, float precoUnitario)`
Responsável por calcular o valor total da venda. Aplica automaticamente um desconto de 10% caso a quantidade seja igual ou maior que 3 itens.

### `void gravarVendaArquivo(Venda v)`
Salva a venda em dois arquivos simultaneamente:

- TXT (loja_roupa.txt) usando `;` como separador
- CSV (loja_roupa.csv) usando `,` como separador e com cabeçalho automático se o arquivo estiver vazio

O uso de dois formatos facilita tanto o uso humano (TXT) quanto a importação em planilhas (CSV).

### `int carregarVendasArquivo(Venda vendas[], int max)`
Lê todas as vendas do arquivo TXT e armazena em um vetor de `Venda`, retornando quantos registros foram carregados. Esta função permite processar as vendas posteriormente, por exemplo, ao gerar relatórios.

### `void ordenarVendasPorValorDecrescente(Venda vendas[], int n)`
Ordena o vetor de vendas em ordem decrescente de valor total, utilizando o algoritmo **Bubble Sort**.

### `void gerarRelatoriosPorData(char data[])`
Gera um relatório completo da data informada:

- Faturamento bruto
- Número de clientes
- Produto mais vendido
- Produto menos vendido
- Listagem detalhada das vendas em ordem decrescente de valor total

### `main()`
Função principal que apresenta o menu interativo com opções:

1. Registrar nova venda
2. Gerar relatório por data
0. Sair

Utiliza do-while e switch para facilitar a navegação do usuário.

---

## 🖥️ Como Executar

Compilação:

```powershell
gcc main.c -o vendas.exe
```

Execução:

```powershell
.\vendas.exe
```

---

## 🛠️ Tecnologias e Conceitos Utilizados
- Linguagem C
- Manipulação de arquivos texto e CSV
- Estruturas (`struct`)
- Vetores
- Algoritmo de ordenação
- Sistema de menu interativo
- Condicionais (`if`, `switch`)
- Laços (`for`, `do-while`)

---

## 💡 Próximas Atualizações
Algumas sugestões de evolução do projeto:

- 📈 Relatórios por período (ex.: semana, mês, ano)
- ✏️ Edição e exclusão de vendas já registradas
- 🔐 Autenticação de usuários
- 📄 Exportação automática em PDF
- 🖥️ Interface gráfica com bibliotecas como GTK
- 🚀 Melhoria do algoritmo de ordenação (QuickSort)
- 📊 Dashboard de estatísticas gerais
- 🔄 Backup automático dos arquivos de vendas

👨‍💻 Autor
Este projeto foi desenvolvido com fins educacionais, como prática de conceitos fundamentais da linguagem C e aprendizado de boas práticas de desenvolvimento.