#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_POKEMONS 151
#define MAX_TIPOS 36

typedef struct {
    int numero;
    char nome[64];
    char tipagem[64];
    char estagio[32];
} Pokemon;

typedef struct {
    char nome[32];
    int quantidade;
} Tipo;

int compararNumero(const void *a, const void *b) {
    const Pokemon *p1 = (const Pokemon *)a;
    const Pokemon *p2 = (const Pokemon *)b;
    return (p1->numero > p2->numero) - (p1->numero < p2->numero);
}

int compararTipo(const void *a, const void *b) {
    const Tipo *t1 = (const Tipo *)a;
    const Tipo *t2 = (const Tipo *)b;
    return strcmp(t1->nome, t2->nome);
}

int indiceEstagio(const char *estagio) {
    const char *nomes[] = {"Inicial", "Intermediario", "Final", "Unico"};
    int i;
    for (i = 0; i < 4; i++) {
        if (strcmp(estagio, nomes[i]) == 0) {
            return i;
        }
    }
    return -1;
}

int possuiTipo(const char *tipagem, const char *tipo) {
    char copia[64];
    char *parte;
    strcpy(copia, tipagem);
    parte = strtok(copia, "/");
    while (parte != NULL) {
        if (strcmp(parte, tipo) == 0) {
            return 1;
        }
        parte = strtok(NULL, "/");
    }
    return 0;
}

int main(void) {
    Pokemon pokemons[MAX_POKEMONS];
    Tipo tipos[MAX_TIPOS];
    const char *nomesEstagios[] = {"Inicial", "Intermediario", "Final", "Unico"};
    int quantidadesEstagios[4] = {0, 0, 0, 0};
    int quantidade = 0, quantidadeTipos = 0;
    int soma = 0;
    int i, j, indice;
    char linha[256], copia[64];
    char *parte;
    FILE *entrada, *arquivoNumeros, *arquivoEstagios, *arquivoTipos;

    entrada = fopen("pokemons.txt", "r");
    if (entrada == NULL) {
        printf("Erro: coloque pokemons.txt na mesma pasta de execucao.\n");
        return 1;
    }

    if (fgets(linha, sizeof(linha), entrada) == NULL) {
        printf("Erro: o arquivo pokemons.txt esta vazio.\n");
        fclose(entrada);
        return 1;
    }

    while (quantidade < MAX_POKEMONS && fgets(linha, sizeof(linha), entrada) != NULL) {
        Pokemon p;
        if (sscanf(linha, "%d;%63[^;];%63[^;];%31[^\r\n]",
                   &p.numero, p.nome, p.tipagem, p.estagio) != 4) {
            printf("Aviso: linha ignorada por estar incompleta.\n");
            continue;
        }
        indice = indiceEstagio(p.estagio);
        if (indice == -1) {
            printf("Aviso: estagio desconhecido para %s.\n", p.nome);
            continue;
        }
        pokemons[quantidade] = p;
        quantidadesEstagios[indice]++;
        soma += p.numero;
        quantidade++;
    }
    fclose(entrada);

    if (quantidade == 0) {
        printf("Erro: nenhum Pokemon valido encontrado.\n");
        return 1;
    }

    qsort(pokemons, quantidade, sizeof(Pokemon), compararNumero);

    for (i = 0; i < quantidade; i++) {
        strcpy(copia, pokemons[i].tipagem);
        parte = strtok(copia, "/");
        while (parte != NULL) {
            indice = -1;
            for (j = 0; j < quantidadeTipos; j++) {
                if (strcmp(tipos[j].nome, parte) == 0) {
                    indice = j;
                    break;
                }
            }
            if (indice == -1 && quantidadeTipos < MAX_TIPOS) {
                indice = quantidadeTipos++;
                strcpy(tipos[indice].nome, parte);
                tipos[indice].quantidade = 0;
            }
            if (indice != -1) {
                tipos[indice].quantidade++;
            }
            parte = strtok(NULL, "/");
        }
    }

    qsort(tipos, quantidadeTipos, sizeof(Tipo), compararTipo);

    arquivoNumeros = fopen("numeros_pokedex.txt", "w");
    if (arquivoNumeros == NULL) {
        printf("Erro ao criar numeros_pokedex.txt.\n");
        return 1;
    }
    fprintf(arquivoNumeros, "NUMEROS DA POKEDEX EM ORDEM CRESCENTE\n\n");
    for (i = 0; i < quantidade; i++) {
        fprintf(arquivoNumeros, "%04d\n", pokemons[i].numero);
    }
    fprintf(arquivoNumeros, "\nTOTAL DE POKEMONS: %d\n", quantidade);
    fprintf(arquivoNumeros, "MEDIA DOS NUMEROS: %.2f\n", (double)soma / quantidade);
    if (fclose(arquivoNumeros) != 0) {
        printf("Erro ao fechar numeros_pokedex.txt.\n");
        return 1;
    }

    arquivoEstagios = fopen("estagios_evolutivos.txt", "w");
    if (arquivoEstagios == NULL) {
        printf("Erro ao criar estagios_evolutivos.txt.\n");
        return 1;
    }
    fprintf(arquivoEstagios, "CONTAGEM POR ESTAGIO EVOLUTIVO\n");
    for (i = 0; i < 4; i++) {
        fprintf(arquivoEstagios, "%s: %d\n", nomesEstagios[i], quantidadesEstagios[i]);
    }
    fprintf(arquivoEstagios, "TOTAL: %d\n", quantidade);
    for (i = 0; i < 4; i++) {
        fprintf(arquivoEstagios, "\n=== %s (%d POKEMONS) ===\n",
                nomesEstagios[i], quantidadesEstagios[i]);
        for (j = 0; j < quantidade; j++) {
            if (strcmp(pokemons[j].estagio, nomesEstagios[i]) == 0) {
                fprintf(arquivoEstagios, "%04d - %s\n",
                        pokemons[j].numero, pokemons[j].nome);
            }
        }
    }
    if (fclose(arquivoEstagios) != 0) {
        printf("Erro ao fechar estagios_evolutivos.txt.\n");
        return 1;
    }

    arquivoTipos = fopen("tipagens.txt", "w");
    if (arquivoTipos == NULL) {
        printf("Erro ao criar tipagens.txt.\n");
        return 1;
    }
    fprintf(arquivoTipos, "CONTAGEM POR TIPO DE POKEMON\n");
    fprintf(arquivoTipos, "Pokemons com dois tipos aparecem nos dois grupos.\n\n");
    for (i = 0; i < quantidadeTipos; i++) {
        fprintf(arquivoTipos, "%s: %d\n", tipos[i].nome, tipos[i].quantidade);
    }
    for (i = 0; i < quantidadeTipos; i++) {
        fprintf(arquivoTipos, "\n=== %s (%d POKEMONS) ===\n",
                tipos[i].nome, tipos[i].quantidade);
        for (j = 0; j < quantidade; j++) {
            if (possuiTipo(pokemons[j].tipagem, tipos[i].nome)) {
                fprintf(arquivoTipos, "%04d - %s (%s)\n",
                        pokemons[j].numero, pokemons[j].nome, pokemons[j].tipagem);
            }
        }
    }
    if (fclose(arquivoTipos) != 0) {
        printf("Erro ao fechar tipagens.txt.\n");
        return 1;
    }

    printf("Total de Pokemons: %d\n", quantidade);
    printf("Media dos numeros da Pokedex: %.2f\n\n", (double)soma / quantidade);
    printf("Estagios evolutivos:\n");
    for (i = 0; i < 4; i++) {
        printf("%s: %d\n", nomesEstagios[i], quantidadesEstagios[i]);
    }
    printf("\nTipagens:\n");
    for (i = 0; i < quantidadeTipos; i++) {
        printf("%s: %d\n", tipos[i].nome, tipos[i].quantidade);
    }
    printf("\nArquivos gerados: numeros_pokedex.txt, estagios_evolutivos.txt e tipagens.txt\n");
    return 0;
}
