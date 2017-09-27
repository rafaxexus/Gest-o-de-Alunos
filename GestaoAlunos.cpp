#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno {
	int id;
	char nome[12];
	struct Aluno *anterior;
	struct Aluno *proximo;
}ALUNO;

//nr aluno
int idAluno = 0;


//Lista alunos
ALUNO *INICIO = NULL;
ALUNO *FIM = NULL;

void criarAluno(){
	ALUNO *aluno = (ALUNO *)malloc(sizeof(ALUNO));
	if (aluno != NULL){
		idAluno++;
		aluno->id = idAluno;
		puts("nome:");
		fflush(stdin);
		gets_s(aluno->nome);

		if (FIM != NULL){
			//Lista com alunos 
			FIM->proximo = aluno;
			aluno->anterior = FIM;
			FIM = aluno;
			aluno->proximo = NULL;
		}
		else{
			//Lista vazia(1º aluno) 
			aluno->proximo = NULL;
			aluno->anterior = NULL;
			INICIO = aluno;
			FIM = aluno;
		}
		puts("Aluno criado!");

		fflush(stdin);
		getchar();
	}
	else{
		puts("Memória insuficiente !");
	}
}
ALUNO * buscar(int id){
	ALUNO *aluno;

	if (FIM){
		for (aluno = INICIO; aluno != NULL; aluno = aluno->proximo){
			if (aluno->id == id){
				return aluno;
			}
		}
		return NULL;
	}
	return NULL;
}

void verAluno(){
	int id;
	puts("Id aluno: ");

	scanf_s("%d", &id);

	ALUNO *aluno = buscar(id);
	if (aluno == NULL){
		puts("Aluno inxistente !");
	}
	else{
		printf("\nId: %d  Nome: %s\n", aluno->id, aluno->nome);

	}
	fflush(stdin);
	getchar();
}

void eliminar(ALUNO *aluno){

	//elimina 1º aluno
	if (INICIO == aluno){
		INICIO = aluno->proximo;
	}

	if (aluno->proximo){
		aluno->proximo->anterior = aluno->anterior;
	}
	else{
		FIM = aluno->anterior; //elimina ultimo aluno
	}

	if (aluno->anterior){
		aluno->anterior->proximo = aluno->proximo;
	}

	free(aluno);
	puts("Aluno eliminado !");

	fflush(stdin);
	getchar();
}


void eliminarAluno(){
	int id;
	puts("Id aluno: ");

	scanf_s("%d", &id);

	ALUNO *aluno = buscar(id);
	if (aluno == NULL){
		puts("Aluno inxistente !");
	}
	else{
		eliminar(aluno);
	}
}



void listarAlunos(){
	ALUNO *ptr;

	if (FIM != NULL){
		for (ptr = INICIO; ptr != NULL; ptr = ptr->proximo){
			printf("\nId: %d  Nome: %s\n", ptr->id, ptr->nome);
		}
	}
	else{
		printf("\n Nao existem alunos!\n");
	}

}

void inserir(ALUNO *curAluno){
	ALUNO *aluno = (ALUNO *)malloc(sizeof(ALUNO));
	if (aluno != NULL){
		idAluno++;
		aluno->id = idAluno;
		puts("nome:");
		fflush(stdin);
		gets_s(aluno->nome);

		if (curAluno == INICIO){
			aluno->anterior = INICIO->anterior;
			aluno->proximo = INICIO;
			INICIO->anterior = aluno;
			INICIO = aluno;
		}
		else{
			aluno->anterior = curAluno->anterior;
			aluno->proximo = curAluno;
			curAluno->anterior->proximo = aluno;
			curAluno->anterior = aluno;
		}

		puts("Aluno inserido!");

		fflush(stdin);
		getchar();
	}
	else{
		puts("Memória insuficiente !");
	}
}

void inserirAluno(){
	int id;
	puts("Id aluno: ");

	scanf_s("%d", &id);

	ALUNO *aluno = buscar(id);
	if (aluno == NULL){
		puts("Aluno inxistente !");
	}
	else{
		inserir(aluno);
	}
}




void menu(){
	int opcao;

	while (1){
		puts("1... Criar aluno");
		puts("2... Visualizar aluno");
		puts("3... Eliminar aluno");
		puts("4... Listar alunos");
		puts("5... Inserir aluno");
		puts("6... Sair");

		scanf_s("%d", &opcao);

		switch (opcao){
		case 1:
			criarAluno();
			break;
		case 2:
			verAluno();
			break;
		case 3:
			eliminarAluno();
			break;
		case 4:
			listarAlunos();
			break;
		case 5:
			inserirAluno();
			break;
		case 6:
			exit(0);

		}
	}
}

int main(){

	menu();
}
