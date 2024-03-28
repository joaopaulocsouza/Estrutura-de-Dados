#include "includes.h"

typedef struct data{
    char nome[30], sobrenome[30], genero[10], data[12];
    int gravidade;
}Data;

int main(){
    int status, select_program,cont = 0;
    bool verify = true;
    char nome[30], sobrenome[30];
    HEAP *heap = createHeap();

    header();
    printf("1 - ler arquivo txt\n2 - inserir pacientes manualmente\n");
    scanf("%d", &select_program);

    if(select_program == 1){
    ReadFile(heap);
    while (verify){
        system("clear");
        header();
        printf("Insira o valor referente a função que deseja realizar\n");
        printf("1 - Listar pacientes registrados\n");
        printf("2 - Chamar paciente para o atendimento\n");
        printf("3 - Buscar paciente pelo nome e sobrenome \n");
        printf("4 - Finalizar programa\n");
        scanf("%d", &status);
        switch (status)        {
            case 1:
                ListPatients(heap);
                break;
            case 2:
                removeInfo(heap);
                break;
            case 3:
                printf("Informe o nome: \n");
                scanf("%s", nome);
                printf("Informe o sobrenome: \n");
                scanf("%s", sobrenome);
                Find(heap, nome, sobrenome);
                break;
            case 4:
                verify = false;
                break;
        }
        while(cont != 1){
            printf("Digite 1 para prosseguir: ");
            scanf("%d", &cont);
        }
        cont = 0;
        status = 999;
    }}else{
        while (verify){
            system("clear");
            header();
            printf("Insira o valor referente a função que deseja realizar\n");
            printf("1 - Cadastrar pacientes\n");
            printf("2 - Listar pacientes registrados\n");
            printf("3 - Chamar paciente para o atendimento\n");
            printf("4 - Buscar paciente pelo nome e sobrenome \n");
            printf("5 - Finalizar programa\n");
            scanf("%d", &status);
            switch (status){
                case 1:
                    RegisterPatient(heap);
                    break;
                case 2:
                    ListPatients(heap);
                    break;
                case 3:
                    removeInfo(heap);
                    break;
                case 4:
                    printf("Informe o nome: \n");
                    scanf("%s", nome);
                    printf("Informe o sobrenome: \n");
                    scanf("%s", sobrenome);
                    Find(heap, nome, sobrenome);
                    break;
                case 5:
                    verify = false;
                    break;
            }
             while(cont != 1){
                printf("Digite 1 para prosseguir: ");
                scanf("%d", &cont);
            }
            cont = 0;
        }
    }
    
    system("clear");
    header();
    destroyHeap(heap);
    printf("programa finalizado\n");
    return 0;
}