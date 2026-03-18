# 🌍 War Estruturado em C

Projeto desenvolvido para a disciplina de Engenharia de Software com o objetivo de simular, de forma simplificada, o jogo War, aplicando conceitos fundamentais e intermediários da linguagem C.

---

## 🚀 Funcionalidades

* Cadastro dinâmico de territórios (quantidade definida pelo usuário)
* Armazenamento de:

  * Nome do território
  * Cor do exército
  * Número de tropas
* Exibição completa do mapa de territórios
* Sistema de ataque entre territórios
* Simulação de batalhas com dados aleatórios
* Atualização automática de domínio e tropas após ataques
* Validação de jogadas (impede ataques inválidos)
* Loop interativo de batalhas

---

## 🧠 Conceitos utilizados

* Structs (estruturas de dados compostas)
* Ponteiros (`Territorio*`)
* Alocação dinâmica de memória (`malloc` / `calloc`)
* Manipulação de memória (`free`)
* Modularização com funções
* Geração de números aleatórios (`rand` e `srand`)
* Manipulação de strings (`string.h`)
* Entrada e saída de dados (`scanf`, `fgets`)
* Controle de fluxo (`for`, `do-while`, `if/else`)

---

## ⚙️ Tecnologias

* Linguagem C
* Bibliotecas padrão:

  * `stdio.h`
  * `stdlib.h`
  * `string.h`
  * `time.h`

---

## 📌 Como executar

1. Compile o código:

```bash
gcc war.c -o war
```

2. Execute o programa:

```bash
./war
```

---

## 🎮 Como funciona

1. O usuário define quantos territórios deseja criar
2. Cada território é cadastrado com nome, cor e número de tropas
3. O sistema exibe o mapa completo
4. O jogador escolhe um território atacante e um defensor
5. O resultado da batalha é decidido por dados aleatórios
6. O mapa é atualizado automaticamente após cada ataque

---

## 🧩 Estrutura do Projeto

* `main` → controle geral do programa
* `listar` → exibição dos territórios
* `atacar` → lógica de batalha
* `liberarMemoria` → gerenciamento de memória

---

## 📈 Evolução do Projeto

Este projeto começou com um sistema simples de cadastro e evoluiu para incluir:

* Interatividade
* Lógica de jogo
* Gerenciamento dinâmico de memória

---

## 📚 Objetivo Acadêmico

Praticar e consolidar conceitos essenciais da linguagem C, com foco em:

* Organização de código
* Manipulação de memória
* Desenvolvimento de lógica aplicada
* Construção de sistemas interativos

---

## 💡 Melhorias futuras

* Sistema de turnos entre jogadores
* Inteligência artificial para ataques automáticos
* Persistência de dados em arquivo
* Interface mais amigável

---