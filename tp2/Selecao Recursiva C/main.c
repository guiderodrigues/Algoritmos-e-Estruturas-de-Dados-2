#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Aluno: Guilherme Oliveira de Rodrigues
Última atualização: 28/04/2024
Objetivo: struct personagem
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
    bool wizard;
} Personagem;

void replace(char *str, const char *find, const char *replace)
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

void ler(Personagem *personagens[], const char *arquivo)
{
    FILE *file = fopen(arquivo, "r");
    if (file == NULL)
    {
        return;
    }

    char linha[1050];
    int i = 0;
    while (fgets(linha, sizeof(linha), file))
    {
        personagens[i] = (Personagem *)malloc(sizeof(Personagem));
        if (personagens[i] == NULL)
        {
            fclose(file);
            return;
        }

        replace(linha, ";;", ";*;");
        char *field = strtok(linha, ";");

        strcpy(personagens[i]->id, field);
        field = strtok(NULL, ";");

        strcpy(personagens[i]->name, field);
        field = strtok(NULL, ";");

        field++;
        char *endfield = strchr(field, ']');
        if (endfield != NULL)
        {
            *endfield = '\0';
            strcpy(personagens[i]->alternateNames, field);
        }
        else
        {
            strcpy(personagens[i]->alternateNames, "");
        }
        field = strtok(NULL, ";");

        strcpy(personagens[i]->house, field);
        field = strtok(NULL, ";");

        strcpy(personagens[i]->ancestry, field);
        field = strtok(NULL, ";");

        strcpy(personagens[i]->species, field);
        field = strtok(NULL, ";");

        strcpy(personagens[i]->patronus, field);
        field = strtok(NULL, ";");

        personagens[i]->hogwartsStaff = strcmp(field, "VERDADEIRO") == 0 ? true : false;
        field = strtok(NULL, ";");

        personagens[i]->hogwartsStudent = strcmp(field, "VERDADEIRO") == 0 ? true : false;
        field = strtok(NULL, ";");

        strcpy(personagens[i]->actorName, field);
        field = strtok(NULL, ";");

        personagens[i]->alive = strcmp(field, "VERDADEIRO") == 0 ? true : false;
        field = strtok(NULL, ";");
        field = strtok(NULL, ";");

        if (strcmp("23-6-1980", field) == 0)
        {
            strcpy(personagens[i]->dateOfBirth, "23-06-1980");
        }
        else
            strcpy(personagens[i]->dateOfBirth, field);
        field = strtok(NULL, ";");

        strcpy(personagens[i]->yearOfBirth, field);
        field = strtok(NULL, ";");

        strcpy(personagens[i]->eyeColour, field);
        field = strtok(NULL, ";");

        strcpy(personagens[i]->gender, field);
        field = strtok(NULL, ";");

        strcpy(personagens[i]->hairColour, field);
        personagens[i]->wizard = strcmp(field, "VERDADEIRO") == 0 ? true : false;
        field = strtok(NULL, ";");

        i++;
    }
    fclose(file);
}

// imprimir todos os bonecos na estrutura pedida
void mostrar(Personagem *personagens)
{
    char formattedAlternateNames[500];
    strcpy(formattedAlternateNames, personagens->alternateNames);
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
            personagens->id, personagens->name, formattedAlternateNames, personagens->house, personagens->ancestry,
            personagens->species, personagens->patronus, personagens->hogwartsStaff, personagens->hogwartsStudent, personagens->actorName, personagens->alive,
            personagens->dateOfBirth, personagens->yearOfBirth, personagens->eyeColour, personagens->gender,
            personagens->hairColour, personagens->wizard);

    replace(output, "*", "");
    replace(output, "'", "");
    printf("%s", output);
}

void swap(Personagem *xp, Personagem *yp)
{
    Personagem temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(Personagem **personagens, int n, int i)
{
    if (i == n || personagens[i] == NULL)
        return;

    int menor = i;
    for (int j = i + 1; j < n && personagens[j] != NULL; j++)
    {
        if (strcmp(personagens[menor]->name, personagens[j]->name) > 0)
        {
            menor = j;
        }
    }

    swap(&personagens[menor], &personagens[i]);

    selectionSort(personagens, n, i + 1);
}

void buscarPorId(Personagem **personagens)
{
    char input[100];
    scanf("%s", input);
    while (strcmp(input, "FIM") != 0)
    {
        int i = 0;
        while (i < 500)
        {
            if (personagens[i] != NULL && strcmp(personagens[i]->id, input) == 0)
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
    int n = 500;
    Personagem *personagens[n];
    int i = 0;
    while (i < n)
    {
        personagens[i] = NULL;
        i++;
    }
    ler(personagens, "/tmp/characters.csv");
    buscarPorId(personagens);
    int j = 0;
    while (j < n)
    {
        if (personagens[j] != NULL)
        {
            free(personagens[j]);
            personagens[j] = NULL;
        }
        j++;
    }
    return 0;
}