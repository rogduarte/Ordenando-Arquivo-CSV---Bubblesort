#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct registro{
    char regiao_sigla [2];
    char estado_sigla [2];
    char municipio [30];
    char revenda [90];
    char cnpj[14];
    char produto [3];
    char data[10];
    float valor_venda;
    float valor_compra;
    char bandeira [30];
}reg;

reg lista[17478];

void imprimeLista(reg *valor, int n);
void ordenaDados(reg *valor, int n);
void troca (reg *a,reg *b);

int main(void){
    setlocale(LC_ALL, "Portuguese");

    char buf[1024];
    int cont_linhas = 0;
    int contador = 0;
    int linha =0;
    int tam=0;
    int opcao;
    char trans_arq[1024];

    FILE *arquivo = fopen("glpfev2020.csv", "r");

    if (!arquivo) {
        printf("Não é possível abrir o arquivo\n");
    }

    while (fgets(buf, 1024, arquivo)) {
        contador = 0;
        cont_linhas++;

        if (cont_linhas == 1) {
            continue;
        }
        char *campo = strtok(buf, ";");
        while (campo) {
            if (contador == 0) {
                strcpy(trans_arq, campo);
                strcpy(lista[linha].regiao_sigla, trans_arq);
            }
            if (contador == 1) {
                strcpy(trans_arq, campo);
                strcpy(lista[linha].estado_sigla, trans_arq);
            }
            if (contador == 2) {
                strcpy(trans_arq, campo);
                strcpy(lista[linha].municipio, trans_arq);
            }
            if (contador == 3) {
                strcpy(trans_arq, campo);
                strcpy(lista[linha].revenda, trans_arq);
            }
            if (contador == 4) {
                strcpy(trans_arq, campo);
                strcpy(lista[linha].cnpj, trans_arq);
            }
            if (contador == 5) {
                strcpy(trans_arq, campo);
                strcpy(lista[linha].produto, trans_arq);
            }
            if (contador == 6) {
                strcpy(trans_arq, campo);
                strcpy(lista[linha].data, trans_arq);
            }
            if (contador == 7) {
                strcpy(trans_arq, campo);
                lista[linha].valor_venda = atof(trans_arq);
            }
            if (contador == 8) {
                strcpy(trans_arq, campo);
                lista[linha].valor_compra = atof(trans_arq);
            }
            if (contador == 9) {
                strcpy(trans_arq, campo);
                strcpy(lista[linha].bandeira, trans_arq);
            }
            campo = strtok(NULL, ";");
            contador++;
        }
        linha++;
        tam++;
    }
    do{
        system("cls");
        printf("\n####- MAPA ESTRUTURA DE DADOS II -####");
        printf("\n");
        printf("\n####- ORDENAÇÃO BUBBLESORT -####");
        printf("\n[1]MOSTRAR ARQUIVO CSV:");
        printf("\n[2]ORDENAR ARQUIVO CSV 1ª COLUNA:");
        printf("\n[3]ENCERRAR PROGRAMA:");
        printf("\n");
        printf("\nEscolha uma opção do Menu:");
        scanf("\n%d",&opcao);
        switch(opcao){
            case 1:
            system("cls");
            imprimeLista(lista,tam);
            system("pause");
            break;
            case 2:
            system("cls");
            ordenaDados(lista,tam);
            printf("\nDADOS ORDENADOS!!!\n");
            system("pause");
            case 3:
            system ("cls");
            printf("\nSAINDO DO PROGRAMA");
            break;
            default:
                printf("\nOpção Inválida!!!\n");
                system("pause");
            break;
        }
    }while(opcao!=3);
    fclose(arquivo);
    return 0;
}

void imprimeLista(reg *valor, int n){
    int i;
    for (i = 0; i < n; i++){

        printf("\n");
        printf("Região_Sigla: \t%.2s \n", valor[i].regiao_sigla);
        printf("Estado_Sigla: \t%.2s \n", valor[i].estado_sigla);
        printf("Município: \t%.30s \n", valor[i].municipio);
        printf("Revenda: \t%.90s \n", valor[i].revenda);
        printf("CNPJ: \t\t%.14s \n", valor[i].cnpj);
        printf("Produto: \t%.3s \n", valor[i].produto);
        printf("Data: \t\t%.10s \n", valor[i].data);
        printf("Valor de Venda: %.2f \n", valor[i].valor_venda);
        printf("Valor de Compra:%.2f \n", valor[i].valor_compra);
        printf("Bandeira:\t%.30s \n", valor[i].bandeira);
        printf("\n");
        printf("##########################################################################################");
        printf("\n");
    }
    printf("\n");
}

void ordenaDados(reg *valor, int n){
    int i,j,r;
    reg aux;
    for (i=0;i<n-1;i++){
        for (j=i+1;j<n;j++){
            r = strcmp(valor[i].regiao_sigla,valor[j].regiao_sigla);
            if (r > 0){
                troca(&valor[i],&valor[j]);
            }
        }
    }

}
void troca(reg *a, reg *b){
    reg aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
