# 🏋️‍♂️ Sistema de Avaliação Física - Academia Brooklyn Total Body

Projeto desenvolvido para a disciplina **Estrutura de Dados**, com o objetivo de implementar um **sistema CRUD completo utilizando TAD de Árvore Binária**.
O sistema simula o cadastro e gerenciamento de alunos de uma academia, armazenando informações pessoais e físicas para cálculo do **IMC (Índice de Massa Corporal)**.

---

## ⚙️ Tecnologias Utilizadas

* Linguagem **C**
* Biblioteca padrão (`stdio.h`, `stdlib.h`, `math.h`)
* Estrutura de Dados: **Árvore Binária de Busca (BST)**

---

## 🧠 Conceitos Aplicados

* Criação de **nós dinâmicos** com alocação de memória (`malloc`)
* Operações básicas em árvores binárias:

  * **Inserção**
  * **Busca**
  * **Atualização**
  * **Remoção**
  * **Percurso em Pré-Ordem**
* Implementação de um **sistema de menu interativo**
* Cálculo do **IMC** com classificação segundo a OMS

---

## 🧩 Estrutura do Código

```
.
├── AcademiaBrooklyn.c      # Código principal do sistema
└── README.md               # Documentação do projeto
```

### Principais Funções

| Função                 | Descrição                                  |
| ---------------------- | ------------------------------------------ |
| `busca_arvore()`       | Busca recursiva por matrícula              |
| `insercao_arvore()`    | Insere um novo aluno na árvore             |
| `atualizacao_arvore()` | Atualiza dados de um aluno existente       |
| `remocao_arvore()`     | Remove um aluno da árvore                  |
| `pre_ordem()`          | Lista todos os alunos cadastrados          |
| `imc()`                | Calcula e exibe o índice de massa corporal |
| `menu()`               | Interface de interação com o usuário       |

---

## 🧮 Funcionalidades do Sistema

### 1️⃣ Cadastrar Novo Aluno

* Insere um novo registro com matrícula, nome, idade, peso, altura e sexo.

### 2️⃣ Consultar Dados de um Aluno

* Busca por matrícula e exibe todas as informações, além do cálculo automático do **IMC**.

### 3️⃣ Atualizar Cadastro

* Permite alterar as informações de um aluno já existente.

### 4️⃣ Remover Aluno

* Remove o aluno desejado da árvore binária.

### 5️⃣ Listar Todos os Alunos

* Exibe todos os registros percorrendo a árvore em **pré-ordem**.

### 0️⃣ Sair

* Encerra o programa de forma segura.

---

## 💡 Exemplo de Execução

```
Bem vindo à Academia Brooklyn Total Body!

---------- MENU ----------

1. Novo Cadastro
2. Dados do Aluno
3. Atualização Cadastral
4. Remover Aluno
5. Todos Alunos
0. Sair

Digite uma opção: 1
Nova matrícula: 101
Digite seu nome: Ana
Idade: 25
Sexo: Feminino
Peso: 60.5
Altura: 1.68

Aluno cadastrado com sucesso!
```

---

## 📊 Exemplo de Cálculo do IMC

```
Índice de Massa Corporal (IMC): 21.4
Faixa de peso ideal!
```

---

## 🧱 Estrutura da Árvore

A organização dos dados segue o formato de uma **Árvore Binária de Busca (BST)**:

```
               [ Matricula 101 ]
              /                \
     [100]                     [102]
```

* Inserções à esquerda: matrícula menor que o nó atual
* Inserções à direita: matrícula maior que o nó atual

---

## 👥 Equipe do Trabalho

| Membros              |
| -------------------- |
| Mahatma Gandhi       |
| Ciro Coimbra         |               
| Alexsandro Martins   |
| Jeiel Lucas          |
| Rogério Pio          |

---

## 🧩 Possíveis Melhorias Futuras

* Salvar e carregar dados a partir de um arquivo `.txt`
* Implementar percursos **in-ordem** e **pós-ordem**
* Adicionar interface gráfica simples (ex: com GTK ou ncurses)
* Melhorar tratamento de erros e validações de entrada

---

## 🏁 Como Compilar e Executar

### Compilação

No terminal:

```bash
gcc AcademiaBrooklyn.c -o academia -lm
```

### Execução

```bash
./academia
```

> 💬 O programa utiliza funções específicas de limpeza de tela compatíveis com Windows, Linux e macOS.

---

## 📜 Licença

Este projeto foi desenvolvido para fins acadêmicos na disciplina de **Estrutura de Dados**.
Você pode reutilizá-lo livremente para fins de estudo e aprendizado.
