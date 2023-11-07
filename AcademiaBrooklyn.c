/* 
                        2º TRABALHO DE ESTRUTURA DE DADOS  
            CRIAÇÃO DE UMA C.R.U.D. UTILIZANDO A TAD ÁRVORE BINÁRIA
EQUIPE: Mahatma Gandhi, Ciro Coimbra, Alexsandro Martins, Jeiel Lucas e Rogério Pio
*/

/*          Sistema de Avaliação Física - Academia Brooklyn Total Body            */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define SIZE 70

typedef struct no{
    char *nome, *sexo;
    int matricula, idade;
    float peso, altura;
    struct no * dir;
    struct no * esq;
}Aluno;

Aluno *raiz = NULL;

Aluno * busca_arvore(int x, Aluno *pt){
    if(pt == NULL){ //arv. vazia
        return NULL;
    }else if(x == pt->matricula){ //encontrado
        return pt;
    }else if(x < pt->matricula){
        //esq! :D
        if(pt->esq == NULL){
            return pt;
        }else{
            return busca_arvore(x, pt->esq);
        }
    }else{
        //dir
        if(pt->dir == NULL){
            return pt;
        }else{
            return busca_arvore(x, pt->dir);
        }
    }
}

float imc(float peso, float altura){
    float imc;
    imc = peso / (pow(altura,2));
    printf("Indice de Massa Corporal (IMC): %.1f.\n", imc);
    if(imc<18.5){
        printf("Atencao! Abaixo do peso.\n\n");
    }else if(imc >= 18.5 && imc < 25){
        printf("Faixa de peso ideal!\n\n");
    }else if(imc >= 25 && imc < 30){
        printf("Atencao! Excesso de peso.\n\n");
    }else if(imc >= 30 && imc < 35){
        printf("Atencao! Obesidade classe I.\n\n");
    }else if(imc >= 35 && imc < 40){
        printf("Atencao! Obesidade classe II.\n\n");
    }else{
        printf("Atencao! Obesidade classe III.\n\n");
    }
    return imc;
}

int limparTerminal(){
  
  int sistema;
  #if linux
  
  sistema = 1;
  #elif __WIN32
  
  sistema = 2;
  #elif APPLE
  
  sistema = 3;
  #endif
  
  if (sistema == 1){
    system("clear");
    
  }else if (sistema == 2){
    system("cls");
    
  }else{
    system("clear");
    
  }
}

void atualizacao_arvore(int matricula, char *nome, int idade, float peso, float altura, char *sexo){
    
    Aluno * ptA = busca_arvore(matricula, raiz);

    if(ptA != NULL){ //arvore nao ta vazia
        if(ptA->matricula == matricula){
            ptA->nome = nome;
            ptA->idade = idade;
            ptA->peso = peso;
            ptA->altura = altura;
            ptA->sexo = sexo;
            printf("\nDados atualizados com sucesso!\n");
        }else{
            printf("\nMatricula nao encontrada!\n");
        }
    }
    else{ //arvore vazia
        printf("\nMatricula inexistente!\n");
    }
    menu();
}

void insercao_arvore(int x, char *nome, int idade, float peso, float altura, char *sexo){

    Aluno * pt = busca_arvore(x, raiz);
    
    if(pt != NULL){ //arvore nao ta vazia
        if(pt->matricula == x){
            printf("\nChave duplicada!\nMatricula ja existente!\n");
        }else{
            Aluno *pt1 = malloc(sizeof(Aluno));
            pt1->matricula = x;
            pt1->nome = nome;
            pt1->idade = idade;
            pt1->peso = peso;
            pt1->altura = altura;
            pt1->sexo = sexo;
            pt1->esq = NULL;
            pt1->dir = NULL;
            if(x <pt->matricula){
                pt->esq = pt1;
            }else{
                pt->dir = pt1;
            }
            printf("\nAluno cadastrado com sucesso!\n");
        }
    }
    else{ //arvore vazia
        Aluno *pt1 = malloc(sizeof(Aluno));
        pt1->matricula = x;
        pt1->nome = nome;
        pt1->idade = idade;
        pt1->peso = peso;
        pt1->altura = altura;
        pt1->sexo = sexo;
        pt1->esq = NULL;
        pt1->dir = NULL;
        raiz = pt1;
        printf("\nAluno cadastrado com sucesso!\n");
    }
    menu();
}

void dados_aluno(int matricula, Aluno *pt){
    
    if(matricula != pt->matricula){
        printf("\nMatricula inexistente!\n");
        menu();
    }
    else{
        printf("\nMatricula: %d\n", pt->matricula);
        printf("Aluno: %s\n", pt->nome);
        printf("Idade: %d anos\n", pt->idade);
        printf("Sexo: %s \n", pt->sexo);
        printf("Peso: %.1f Kg\n", pt->peso);
        printf("Altura: %.2f metros\n", pt->altura);
    }
}

void pre_ordem(Aluno *pt){
    
    printf("Matricula: %d\n aluno: %s \n idade: %d anos \n sexo: %s\n peso: %.1f Kg \n altura: %.2f metros\n\n", pt->matricula, pt->nome, pt->idade, pt->sexo, pt->peso, pt->altura);
    if(pt->esq != NULL){
        pre_ordem(pt->esq);
    }
    if(pt->dir != NULL){
        pre_ordem(pt->dir);
    }
}

Aluno *remocao_arvore(int x, Aluno *pt){
    
    if(pt == NULL){ /* arvore vazia */
        return NULL;
    }
    else if(pt->matricula > x){
        pt->esq = remocao_arvore(x, pt->esq);
    }
    else if(pt->matricula < x){
        pt->dir = remocao_arvore(x, pt->dir);
    }
    else{  /* achou o nó a remover*/
        if(pt->esq == NULL && pt->dir == NULL){ /* nó sem filhos */
            free(pt);
            pt = NULL;
        }
        else if(pt->esq == NULL){ /* nó só tem filho à direita */ 
            Aluno * pt1 = pt;
            pt = pt->dir;
            free(pt1);
        }
        else if(pt->dir == NULL){ /* nó só tem filho à esquerda */ 
            Aluno * pt1 = pt;
            pt = pt->esq;
            free(pt1);
        }
        else{   /* nó tem os dois filhos */
            Aluno * pt2 = pt->esq;
            while(pt2->dir != NULL){
                pt2 = pt2->dir;
            }
            pt->matricula = pt2->matricula; /* troca as informações */
            pt2->matricula = x;
            pt->esq = remocao_arvore(x, pt->esq);
        }
    }
    return pt;
}

int menu(){
    char nome[SIZE];
    char sex[SIZE];
    int age;
    float pes, alt;
    int escolha;

    printf("\n---------- MENU ----------\n");
    printf("\n1. Novo Cadastro\n2. Dados do Aluno\n3. Atualizacao Cadastral\n4. Remover Aluno\n0. Sair\n5. Todos alunos\n");
    printf("\nDigite uma opcao: ");
    scanf("%i", &escolha);

    if(escolha == 0){ //SAIR ok
        printf("\nVolte sempre!\n\n");
        exit(0);
    }
    else if (escolha == 5){
        limparTerminal();
        printf("\n----- ALUNOS CADASTRADOS -----\n\n");
        Aluno *busc = busca_arvore(raiz, raiz);
        if(busc == NULL){
            printf("Nenhum aluno cadastrado!\n");
        }
        else{
            pre_ordem(raiz);
        }
        menu();
    }
    else if(escolha == 1){  //CADASTRO ok
        int nova_matricula;
        limparTerminal();
        printf("\n---------- CADASTRO ----------\n");
        printf("\nNova matricula (APENAS numeros): ");
        scanf("%i", &nova_matricula);
        printf("Digite seu nome(APENAS O primeiro): ");
        scanf("%s", nome);
        printf("Digite sua idade (Ex: 22): ");
        scanf("%i", &age);
        printf("Digite seu sexo (Ex: Feminino): ");
        scanf("%s", sex);
        printf("Digite seu peso (Ex: 72.1): ");
        scanf("%f", &pes);
        printf("Digite sua altura (Ex: 1.73): ");
        scanf("%f", &alt);
        insercao_arvore(nova_matricula, nome, age, pes, alt, sex);
    }
    else if(escolha == 2){  //IMPRIMIR ok
        int matricula;
        limparTerminal();
        printf("\n---------- DADOS DO ALUNO ----------\n");
        printf("\nDigite a matricula: ");
        scanf("%i", &matricula);
        Aluno *ptS = busca_arvore(matricula, raiz);
        if(ptS == NULL){
            printf("\nMatricula inexistente!\n");
            menu();
        }
        dados_aluno(matricula, ptS);
        imc(ptS->peso, ptS->altura);
        menu();
    }
    else if(escolha == 3){  //ATUALIZAR ok
        int matricula;
        limparTerminal();
        printf("\n---------- ATUALIZACAO CADASTRAL ----------\n");
        printf("\nDIGITE OS NOVOS DADOS:\n");
        printf("\nPrimeiro nome: ");
        scanf("%s", nome);
        printf("Idade: ");
        scanf("%i", &age);
        printf("Sexo: ");
        scanf("%s", sex);
        printf("Peso: ");
        scanf("%f", &pes);
        printf("Altura: ");
        scanf("%f", &alt);
        printf("\nNumero da matricula que deseja atualizar: ");
        scanf("%i", &matricula);
        atualizacao_arvore(matricula, nome, age, pes, alt, sex);
    }
    else if(escolha == 4){  //REMOVER ok
        int matricula, opc;
        limparTerminal();
        printf("\n---------- REMOCAO ----------\n");
        printf("\nDigite a matricula: ");
        scanf("%i", &matricula);
        printf("\nDeseja remover?\n\n1. Sim\n2. Nao\n\n");
        printf("Digite sua opcao: ");
        scanf("%i", &opc);
        if(opc == 1){
            remocao_arvore(matricula, raiz);
            printf("\nAluno removido com sucesso!\n");
        }else if(opc == 2){
            printf("\nVoltando ao menu!\n");
        }else{
            printf("\nOpcao invalida!\n");
        }
        menu();
    }
    else{ //ERRO ok
        printf("\nOpcao invalida!\n");
        menu();
    }
}

int main(){
    
    printf("\nBem vindo a Academia Blooklyn Total Body!\n");
    menu();

    return 0;
}


