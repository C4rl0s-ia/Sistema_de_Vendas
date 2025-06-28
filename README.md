# Sistema de Vendas - Loja de Roupas

## 🎯 Objetivo do Projeto

Este projeto tem como objetivo implementar um **sistema simples de vendas em C** para uma loja de roupas, com as seguintes funcionalidades:

- Registrar vendas, aplicando descontos automáticos.
- Armazenar os registros em **dois formatos de arquivo**: TXT (ponto e vírgula) e CSV (vírgula).
- Gerar relatórios filtrando por data específica.
- Apresentar estatísticas como faturamento, item mais vendido e menos vendido.

O sistema facilita o acompanhamento de vendas de maneira prática e pode ser expandido para outros tipos de relatórios e funcionalidades.

---

## 🛠️ Estruturas e Funções do Sistema

Abaixo, segue a explicação das principais funções e estruturas utilizadas:

---

### `struct Venda`
Define os dados de cada venda:
- `data`: Data no formato `dd/mm/yyyy`.
- `codigo`: Código numérico do item.
- `nome`: Nome do produto.
- `marca`: Marca do produto.
- `quantidade`: Quantidade vendida.
- `precoUnitario`: Valor unitário.
- `valorTotal`: Valor total com desconto, se aplicável.

---

### `float calcularValorTotal(int quantidade, float precoUnitario)`
Calcula o valor total da venda:
- Se quantidade >= 3, aplica 10% de desconto automaticamente.
- Retorna o total calculado.

---

### `void gravarVendaArquivo(Venda v)`
Registra a venda em dois arquivos:
- **loja_roupa.txt**: formato delimitado por ponto e vírgula `;`.
- **loja_roupa.csv**: formato delimitado por vírgula `,`, ideal para planilhas Excel.
- Ao criar o CSV, escreve automaticamente o cabeçalho na primeira execução.

---

### `int carregarVendasArquivo(Venda vendas[], int max)`
Carrega todas as vendas do arquivo TXT:
- Lê linha por linha e preenche o array `vendas`.
- Retorna a quantidade de vendas carregadas.
- Essa função é usada para gerar relatórios.

---

### `void ordenarVendasPorValorDecrescente(Venda vendas[], int n)`
Ordena o array de vendas em ordem decrescente de valor total:
- Utiliza o algoritmo **Bubble Sort** para manter o código simples.
- Permite listar as vendas com maiores valores primeiro.

---

### `void gerarRelatoriosPorData(char data[])`
Gera um relatório de vendas filtrando por data:
- Mostra o faturamento total do dia.
- Conta quantos clientes compraram.
- Identifica o item mais e menos vendido.
- Exibe uma lista ordenada das vendas.

---

### `main()`
Controla todo o fluxo do programa:
1. Exibe o menu de cadastro de vendas.
2. Coleta os dados de cada venda.
3. Salva os registros nos arquivos.
4. Pergunta ao usuário se deseja gerar um relatório por data.

---

## 📝 Notas Técnicas

- **Linguagem C**: escolhida por ser didática e permitir fácil manipulação de arquivos.
- **Arquivos TXT e CSV**: usados para permitir portabilidade dos dados.
- **scanf com especificadores**: foram utilizados para evitar problemas de leitura com espaços.
- **Algoritmo Bubble Sort**: simples de implementar para ordenar vendas.
- **Controle de cabeçalho CSV**: evita duplicação do cabeçalho usando `ftell()`.

---

## 💡 Sugestões de Expansão

Aqui vão algumas ideias de melhoria:

- Implementar **busca por faixa de datas** (por exemplo, relatório semanal).
- Gerar relatórios agrupados por produto ou marca.
- Permitir remoção e edição de registros.
- Criar uma interface gráfica usando uma biblioteca como **GTK**.
- Criar um modo de exportação em **JSON** ou **XML**.

---

## 🙌 Contribuição

Este projeto foi desenvolvido como base de aprendizado. Fique à vontade para:
- Adaptar a outros tipos de lojas.
- Melhorar a organização de arquivos.
- Incrementar a lógica de descontos.

Se precisar de ajuda, abra um **issue** ou envie uma mensagem!

---

**Autor:** [Seu Nome]  
**Data:** [Data Atual]
