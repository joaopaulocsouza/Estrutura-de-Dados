#include "includes.h"

typedef struct data{
    char nome[30], sobrenome[30], genero[10], data[12];
    int gravidade;
}Data;

int get_single_char(void);

void header(){
    printf("---------------------------------------------------------------\n");
    printf("              Simulador de pronto socorro\n");
    printf("---------------------------------------------------------------\n\n");
};

int getGravidade(DATA data){
    Data* d = (Data*) data;
    return d->gravidade;
}

char *getNome(DATA data){
    Data* d = (Data*) data;
    return d->nome;
}

char *getSobrenome(DATA data){
    Data* d = (Data*) data;
    return d->sobrenome;
}

char *getData(DATA data){
    Data* d = (Data*) data;
    return d->data;
}

char *getSexo(DATA data){
    Data* d = (Data*) data;
    return d->genero;
}

void RegisterPatient(HEAP *heap){
    Data *data = (Data *) malloc(sizeof(Data));
    system("clear");
    header();
    printf("Insira o nome do(a) paciente:\n");
    scanf("%s", data->nome);
    printf("Insira o sobrenome do(a) paciente:\n");
    scanf("%s", data->sobrenome);

    printf("Insira a data de nascimento do(a) paciente:\n");
    scanf("%s", data->data);

    printf("Insira o genero do(a) paciente:\n");
    scanf("%s", data->genero);

    printf("Selecione o grau de urgencia do atendimento\n");
    printf("1 - Critíco\n");
    printf("2 - Urgente\n");
    printf("3 - Grave\n");
    printf("4 - Menos grave\n");
    printf("5 - Estável\n");
    scanf("%d", &data->gravidade);

    insertInfo(heap, data)?printf("Paciente cadastrado com sucesso\n"):printf("Não foi possivel cadastrar paciente\n");
}

void RegisterPatientFromFile(HEAP heap, Data temp){
    Data *data = (Data *)malloc(sizeof(Data));
    strcpy(data->nome, temp.nome);
    strcpy(data->sobrenome, temp.sobrenome);
    strcpy(data->data, temp.data);
    strcpy(data->genero, temp.genero);
    data->gravidade = temp.gravidade;

    insertInfo(heap, data);

}

void PrintPatient(DATA data){
    Data *d = (Data *) data;
    printf("%d %s %s %s %s\n", d->gravidade, d->nome, d->sobrenome, d->data, d->genero);
}

void ReadFile(HEAP *heap){
    Data temp;
    FILE *arq = fopen("Pacientes.txt", "r");
    printf(!arq?"Deu ruim":"Deu bom");

    while(!feof(arq)){
        fscanf(arq,"%s %s %s %s %d", temp.nome, temp.sobrenome, temp.data, temp.genero, &temp.gravidade);
        RegisterPatientFromFile(heap, temp);
    }

    fclose(arq);
}