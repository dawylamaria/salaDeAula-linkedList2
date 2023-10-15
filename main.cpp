#include <iostream>

struct No {
    int data;
    No* anterior;
    No* next;
};

void inserir(No *&head, int valor) {
    No* novoNo = new No;
    novoNo->data = valor;
    novoNo->next = NULL;
    novoNo->anterior = NULL;

    if (head == NULL) {
        head = novoNo;
        return;
    } else {
        No* aux = head;
        while (aux->next != NULL) {
            aux = aux->next;
        }

        aux->next = novoNo;
        novoNo->anterior = aux;
    }
}

using namespace std;
void imprimirLista(No *&head) {
    No* atual = head;
    while (atual != NULL) {
        cout << atual->data << " ";
        atual = atual->next;
    }
    cout << endl;
}

int encontrarValorDoMeio(No *&head) {
    No* anterior = head;
    No* proximo = head;

    while (proximo != NULL && proximo->next != NULL) {
        anterior = anterior->next;
        proximo = proximo->next->next;
    }

    return anterior->data;
}

int tamanho(No *&head) {
    int tamanho = 0;
    No* atual = head;
    while (atual != NULL) {
        tamanho++;
        atual = atual->next;
    }
    return tamanho;
}

void transformandoEmCircular(No *&head, int valor) {
    No* novoNo = new No;
    novoNo->data = valor;
    novoNo->next = NULL;

    if (head == NULL) {
        head = novoNo;
        novoNo->next = head; 
    } else {
        No* aux = head;
        while (aux->next != head) {
            aux = aux->next;
        }

        aux->next = novoNo;
        novoNo->next = head; 
    }
}

using namespace std;
int encontrarMaiorNo(No *head) {
    if (head == NULL) {
        cout << "A lista esta vazia!" << endl;
        return -1; 
    }

    int maior = head->data;
    No *atual = head;

    while (atual != NULL) {
        if (atual->data > maior) {
            maior = atual->data;
        }
        atual = atual->next;
    }

    return maior;
}



using namespace std;
int main(int argc, char** argv) {
	
	int maior;
	
	No* head = NULL;

    inserir(head, 1);
    inserir(head, 2);
    inserir(head, 3);
    inserir(head, 4);
    inserir(head, 5);
	
	int escolha;
	
	cout << "Escolha a questao(1 a 4): " << endl;
	cin >> escolha;
	
	switch(escolha){
		
		case 1:{
			cout << "Lista original:" << endl;
    		imprimirLista(head);

    		int meio = encontrarValorDoMeio(head);
    		cout << "Valor do meio: " << meio << endl;

    		cout << "Tamanho da lista: " << tamanho(head) << endl;

    		No* atual = head;
    		while (atual != NULL) {
        	No* temp = atual;
        	atual = atual->next;
        	delete temp;
	}
    
    }
    
    case 2:{
    	cout << "Lista circular:" << endl;
    	imprimirLista(head);

    	cout << "Tamanho da lista: " << tamanho(head) << endl;

    	No* atual = head;
    	do {
        	No* temp = atual;
        	atual = atual->next;
        	delete temp;
    	} 	while (atual != head);
			break;
	}
	
	case 3:{
		maior = encontrarMaiorNo(head);
		cout << "Maior NO na lista: " << maior << endl;
		break;
	}

			
	}
    
    return 0;
}
