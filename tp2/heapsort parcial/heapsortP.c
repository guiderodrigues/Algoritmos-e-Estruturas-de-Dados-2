#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Aluno: Guilherme Oliveira de Rodrigues
Última atualização: 04/05/2024
Objetivo: Heapsort parcial por cor do cabelo e nome
*/

typedef struct
{
    char id[100];
    char name[100];
    char alternateNames[5][100];
    char house[100];
    char ancestry[100];
    char species[100];
    char patronus[100];
    bool hogwartsStaff;
    bool hogwartsStudent;
    char actorName[100];
    bool alive;
    char dateOfBirth[100];
    char yearOfBirth[100];
    char eyeColour[100];
    char gender[100];
    char hairColour[100];
    int wizard;
} Personagem;

void replace(char *str, char *find, char *replace)
{
    int find_len = strlen(find);
    int replace_len = strlen(replace);
    char *tmp = strstr(str, find);
    while (tmp != NULL)
    {
        memmove(tmp + replace_len, tmp + find_len, strlen(tmp + find_len) + 1);
        memcpy(tmp, replace, replace_len);
        tmp = strstr(tmp + replace_len, find);
    }
}

int cmpStrings(char *str1, char *str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] > str2[i])
        {
            return 1;
        }
        else if (str1[i] < str2[i])
        {
            return -1;
        }
        i++;
    }
    if (str1[i] == '\0' && str2[i] != '\0')
    {
        return -1;
    }
    else if (str1[i] != '\0' && str2[i] == '\0')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void limparString(char *str) {
    int i, j = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (!isspace(str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

void ler(Personagem personagens[], char *arquivo)
{
    FILE *file = fopen(arquivo, "r");

    char linha[1050];
    int i = 0;
    while (fgets(linha, sizeof(linha), file))
    {

        replace(linha, ";;", ";*;");
        char *field = strtok(linha, ";");

        strcpy(personagens[i].id, field);
        field = strtok(NULL, ";");

        strcpy(personagens[i].name, field);
        field = strtok(NULL, ";");

        field++;
        char *endfield = strchr(field, ']');
        if (endfield != NULL)
        {
            *endfield = '\0';
            strcpy(personagens[i].alternateNames, field);
        }
        else
        {
            strcpy(personagens[i].alternateNames, "");
        }
        field = strtok(NULL, ";");

        strcpy(personagens[i].house, field);
        field = strtok(NULL, ";");

        strcpy(personagens[i].ancestry, field);
        field = strtok(NULL, ";");

        strcpy(personagens[i].species, field);
        field = strtok(NULL, ";");

        strcpy(personagens[i].patronus, field);
        field = strtok(NULL, ";");

        personagens[i].hogwartsStaff = strcmp(field, "VERDADEIRO") == 0 ? true : false;
        field = strtok(NULL, ";");

        personagens[i].hogwartsStudent = strcmp(field, "VERDADEIRO") == 0 ? true : false;
        field = strtok(NULL, ";");

        strcpy(personagens[i].actorName, field);
        field = strtok(NULL, ";");

        personagens[i].alive = strcmp(field, "VERDADEIRO") == 0 ? true : false;
        field = strtok(NULL, ";");
        field = strtok(NULL, ";");

        if (strcmp("23-6-1980", field) == 0)
        {
            strcpy(personagens[i].dateOfBirth, "23-06-1980");
        }
        else
            strcpy(personagens[i].dateOfBirth, field);
        field = strtok(NULL, ";");

        strcpy(personagens[i].yearOfBirth, field);
        field = strtok(NULL, ";");

        strcpy(personagens[i].eyeColour, field);
        field = strtok(NULL, ";");

        strcpy(personagens[i].gender, field);
        field = strtok(NULL, ";");

        strcpy(personagens[i].hairColour, field);
        field = strtok(NULL, ";");

        limparString(field);
        if (strcmp(field, "VERDADEIRO") == 0)
        {
            personagens[i].wizard = 1;
        }
        else
        {
            personagens[i].wizard = 0;
        }
        i++;
    }
    fclose(file);
}

void mostrar(Personagem character)
{
    char formattedAlternateNames[500];
    strcpy(formattedAlternateNames, character.alternateNames);
    char *inicio = formattedAlternateNames;
    char *fim = inicio + strlen(formattedAlternateNames) - 1;
    if (*inicio == '[')
    {
        *inicio = '{';
    }
    if (*fim == ']')
    {
        *fim = '}';
    }
    replace(formattedAlternateNames, "*", "");
    char output[1000];
    sprintf(output, "[%s ## %s ## {%s} ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s]\n",
            character.id, character.name, formattedAlternateNames, character.house, character.ancestry,
            character.species, character.patronus, character.hogwartsStaff ? "true" : "false", character.hogwartsStudent ? "true" : "false", character.actorName, character.alive ? "true" : "false",
            character.dateOfBirth, character.yearOfBirth, character.eyeColour, character.gender,
            character.hairColour, character.wizard ? "true" : "false");
    replace(output, "*", "");
    replace(output, "'", "");
    printf("%s", output);
}

void mostrar2(Personagem character)
{
    char formattedAlternateNames[500];
    strcpy(formattedAlternateNames, character.alternateNames);
    char *inicio = formattedAlternateNames;
    char *fim = inicio + strlen(formattedAlternateNames) - 1;
    if (*inicio == '[')
    {
        *inicio = '{';
    }
    if (*fim == ']')
    {
        *fim = '}';
    }
    replace(formattedAlternateNames, "*", "");
    char output[1000];
    sprintf(output, "[%s ## %s ## {%s} ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s]\n",
            character.id, character.name, formattedAlternateNames, character.house, character.ancestry,
            character.species, character.patronus, character.hogwartsStaff ? "true" : "false", character.hogwartsStudent ? "true" : "false", character.actorName, character.alive ? "true" : "false",
            character.dateOfBirth, character.yearOfBirth, character.eyeColour, character.gender,
            character.hairColour, character.wizard ? "true" : "false");
    replace(output, "*", "");
    replace(output, "'", "");
    printf("%s", output);
}
int comp = 0;
int trocas = 0;

void partialBubbleSort(Personagem personagens[], int n, int k) {
    for (int i = 0; i < k; i++) {
        comp++;
        for (int j = 0; j < k - 1 - i; j++) {
            comp++;
            if (strcmp(personagens[j].hairColour, personagens[j + 1].hairColour) > 0 ||
                (strcmp(personagens[j].hairColour, personagens[j + 1].hairColour) == 0 &&
                 strcmp(personagens[j].name, personagens[j + 1].name) > 0)) {
                comp+=3;
                Personagem tmp = personagens[j];
                personagens[j] = personagens[j + 1];
                personagens[j + 1] = tmp;
                trocas++;
            }
        }
    }
}
void maxHeapify(Personagem personagens[], int n, int i) {
    int maior = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && (strcmp(personagens[l].hairColour, personagens[maior].hairColour) > 0 || 
                  (strcmp(personagens[l].hairColour, personagens[maior].hairColour) == 0 && strcmp(personagens[l].name, personagens[maior].name) < 0)))
        maior = l;

    if (r < n && (strcmp(personagens[r].hairColour, personagens[maior].hairColour) > 0 || 
                  (strcmp(personagens[r].hairColour, personagens[maior].hairColour) == 0 && strcmp(personagens[r].name, personagens[maior].name) < 0)))
        maior = r;

    if (maior != i) {
        Personagem tmp = personagens[i];
        personagens[i] = personagens[maior];
        personagens[maior] = tmp;

        maxHeapify(personagens, n, maior);
    }
}

void buildMaxHeap( Personagem personagens[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(personagens, n, i);
}

void heapSortPartial( Personagem personagens[], int n, int k) {
    buildMaxHeap(personagens, n);

    for (int i = n - 1; i >= n - k; i--) {
         Personagem tmp = personagens[0];
        personagens[0] = personagens[i];
        personagens[i] = tmp;

        maxHeapify(personagens, i, 0);
    }
}

void buscarPorId(Personagem *personagens, Personagem *vetor[])
{
    char input[100];
    scanf("%s", input);
    while (strcmp(input, "FIM") != 0)
    {
        int i = 0;
        while (i < 500)
        {
            if (&personagens[i] != NULL && strcmp(personagens[i].id, input) == 0)
            {

                mostrar(personagens[i]);
                i = 500;
            }
            i++;
        }
        scanf("%s", input);
    }
}

int main()
{
    int n = 405;
    Personagem personagens[n];
    ler(personagens, "/tmp/characters.csv");
    Personagem personagensOrdenados[405];
    char input[100];
    int pos = 0;
    scanf("%s", input);
    while (strcmp(input, "FIM") != 0)
    {
        int i = 0;
        while (i < 405)
        {
            if (personagens[i].id != NULL && strcmp(personagens[i].id, input) == 0)
            {
                personagensOrdenados[pos] = personagens[i];
                pos++;
                i = 405;
            }
            i++;
        }
        scanf("%s", input);
    }
    clock_t before = clock();
    heapSortPartial(personagensOrdenados, pos, 10);
     for (int i = 0; i < pos; i++)
     {
         if (personagensOrdenados[i].id != NULL)
         {
             mostrar2(personagensOrdenados[i]);
         }
     }
     clock_t after = clock();
     double tmpo = ((double)after - before) / CLOCKS_PER_SEC * 1000.0;
     FILE *saida = fopen("matricula_heapsort.txt", "w");
     fprintf(saida, "806574\t%lf\t%d\t%d", tmpo, comp, trocas);
    fclose(saida);

    return 0;
}