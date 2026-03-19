# 🌍 War Estruturado em C

Projeto desenvolvido para a disciplina de Engenharia de Software com o objetivo de simular, de forma simplificada, o jogo War, aplicando conceitos fundamentais e avançados da linguagem C.

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

### 🆕 Sistema de Missões Estratégicas

* Cada jogador recebe uma missão aleatória no início do jogo
* Missões armazenadas dinamicamente com `malloc`
* Uso de ponteiros (`char*`) para manipulação das missões
* Verificação automática de condição de vitória ao final de cada turno
* Exibição da missão apenas uma vez no início do jogo

---

## 🧠 Conceitos utilizados

* Structs (estruturas de dados compostas)
* Ponteiros (`Territorio*`, `char*`)
* Alocação dinâmica de memória (`malloc / calloc`)
* Manipulação de memória (`free`)
* Modularização com funções
* Passagem de parâmetros por valor e referência
* Geração de números aleatórios (`rand` e `srand`)
* Manipulação de strings (`string.h`)
* Entrada e saída de dados (`scanf`, `fgets`)
* Controle de fluxo (`for`, `while`, `if/else`)

---

## ⚙️ Tecnologias

* Linguagem C

Bibliotecas padrão:

* `stdio.h`
* `stdlib.h`
* `string.h`
* `time.h`

---

## 📌 Como executar

Compile o código:

gcc war.c -o war // ou gcc war_2.c -o war_2 // ou gcc war_3.c -o war_3

Execute o programa:

./war // ou ./war_2 // ou ./war_3

---

## 🎮 Como funciona

1. O jogador cadastra os territórios
2. O sistema sorteia uma missão estratégica
3. O mapa é exibido na tela
4. O jogador escolhe um território atacante e um defensor
5. O resultado da batalha é definido por dados aleatórios
6. O mapa é atualizado automaticamente
7. O sistema verifica, a cada turno, se a missão foi cumprida
8. O jogo termina quando a condição de vitória é atingida

---

## 🧩 Estrutura do Projeto

* `main` → controle geral do programa
* `atribuirMissao` → sorteio da missão
* `exibirMissao` → exibição inicial da missão
* `verificarMissao` → valida condição de vitória
* `exibirMapa` → exibição dos territórios
* `atacar` → lógica de batalha
* `liberarMemoria` → gerenciamento de memória

---

## 📈 Evolução do Projeto

Este projeto evoluiu de um sistema simples para uma simulação mais completa do jogo War, incluindo:

* Cadastro de dados
* Interatividade
* Lógica de batalha
* Gerenciamento dinâmico de memória
* Sistema de missões estratégicas

---

## 📚 Objetivo Acadêmico

Praticar e consolidar conceitos essenciais e intermediários da linguagem C, com foco em:

* Organização e modularização de código
* Uso eficiente de memória
* Aplicação de ponteiros
* Desenvolvimento de lógica aplicada
* Construção de sistemas interativos

---

## 💡 Melhorias futuras

* Sistema de múltiplos jogadores
* Diferentes tipos de missões com regras específicas
* Inteligência artificial para decisões automáticas
* Persistência de dados em arquivos
* Interface mais amigável (CLI aprimorada)
