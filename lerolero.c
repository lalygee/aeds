#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int valor;
    struct Node* proximo;
}Node;

typedef struct{
    Node* head;
    int numElem;
}Lista;

Lista* criarLista(){
    Lista *l = malloc(sizeof(Lista));
    l.head = NULL;
    l.numElem = 0;
    return l;
}

Node* criarNo(int valor){
    Node *n = malloc(sizeof(Node));
    n.valor = valor;
    n.proximo = NULL;
    return n;
}

bool isEmpty(Lista *l){
    return l.head==NULL;
}

void inserirInicio(List *l, int valor){
    if(isEmpty(l)){
        l.head = criarNo(valor);
        return;
    }

    Node* n = criarNo(valor);
    n.proximo = l.head.proximo;
    l.head = n;

    return;
}

int contarNos(Lista *l){
    
    Node *i = l.head;
    int quantidade = 0;
    
    while (i != NULL){
        quantidade++;
        i = i.proximo;
    }
    return quantidade;
}

int contaNoRescurs(Node* noAtual){
    if(noAtual == NULL){
        return 0;
    }

    return 1 + contaNoRescurs(noAtual.proximo);
}

void imprimirLista(lista *l){
    if(isEmpty(l)){
        return;
    }

    Node* i = l.head;
    while(i != NULL){
        printf("%d ", i.valor);
        i = i.proximo;
    }
    printf("\n");
}

void recus(Node* noAtual){
    if(noAtual == NULL){
        return;
    }
    printf("%d ", noAtual.valor);
    recus(noAtual.proximo);
}

void inverte(Node* noAtual){
    if(noAtual == NULL){
        return;
    }
    inverte(noAtual.proximo);
    printf("%d ", noAtual.valor);
}

Node* search(lista* l, int valor){

    Node* i = l.head;
    while(i != NULL){
        if(i.valor == valor){
            return i;
        }
    }
    return NULL;
}

void colocaFim(Lista *l, int valor){
    if(numElem == 0){
        l.head = criarNo(valor);
        return;
    }

    Node* i = l.head;
    while(i.proximo != NULL){
        i = i.proximo;
    }
    
    i.proximo = criarNo(valor);

    return;
}

void numero(Lista *l, int valor){
    if(isEmpty(l)){
        l.head = criarNo(valor);
        return;
    }

    if(l.numElem == 1){
        if(l.head.valor > valor){
            inserirInicio(l, valor);
            return;
        }
        colocaFim(l, valor);
        return;
    }

    Node* i = l.head;
    while(i != NULL){
        if(i.valor <= valor && i.proximo.valor >= valor){
            Node* n = criarNo(valor);
            n.proximo = i.proximo;
            i.proximo = n;
            return;
        }
    }
}
