# 📊 Sistema de Vendas - Loja de Roupas

Este projeto é um sistema em linguagem C para **registro, armazenamento e geração de relatórios de vendas** de uma loja de roupas. O programa permite cadastrar vendas, armazenar os dados em arquivos TXT e CSV, e gerar relatórios detalhados por data, ordenando os resultados pelo valor total da venda.

---

## ✨ Funcionalidades

✅ Cadastro de vendas com desconto automático para grandes quantidades  
✅ Armazenamento simultâneo em arquivos `.txt` e `.csv`  
✅ Relatórios por data, incluindo:
- Faturamento bruto
- Quantidade de clientes atendidos
- Item mais vendido
- Item menos vendido
- Listagem das vendas em ordem decrescente de valor

✅ Menu interativo com opções:
1. Registrar nova venda
2. Gerar relatório por data
0. Sair

---

## 🎯 Objetivo

O sistema foi desenvolvido para **demonstrar conceitos de manipulação de arquivos, uso de structs, ordenação e operações básicas de relatórios** em C. Pode ser utilizado como projeto acadêmico, estudo de caso ou base para sistemas mais robustos.

---

## ⚙️ Estrutura de Dados

A principal estrutura utilizada é a `struct Venda`:

```c
typedef struct {
    char data[11];           // Formato dd/mm/yyyy
    int codigo;              // Código do item
    char nome[50];           // Nome do item
    char marca[30];          // Marca
    int quantidade;          // Quantidade vendida
    float precoUnitario;     // Preço por unidade
    float valorTotal;        // Valor total da venda (com desconto)
} Venda;
```c