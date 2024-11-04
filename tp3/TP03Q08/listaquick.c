#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

void limparString(char str[])
{
    int i, j = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (!isspace(str[i]))
        {
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

typedef struct Celula
{
    Personagem personagem;
    struct Celula *prox;
    struct Celula *ant;
} Celula;

typedef struct Lista
{
    Celula *inicio;
    Celula *fim;
    int size;
} Lista;

Celula *newCelula(Personagem personagem)
{
    Celula *tmp = (Celula *)malloc(sizeof(Celula));
    tmp->personagem = personagem;
    tmp->prox = NULL;
    tmp->ant = NULL;
    return tmp;
}

Lista *newLista()
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->size = 0;
    return lista;
}

void inserirFim(Lista *lista, Personagem personagem)
{
    if (lista->fim == NULL)
    {
        lista->fim = newCelula(personagem);
        lista->inicio = lista->fim;
        return;
    }
    lista->fim->prox = newCelula(personagem);
    lista->fim->prox->ant = lista->fim;
    lista->fim = lista->fim->prox;
}

Personagem removerInicio(Lista *lista)
{
    Celula *tmp = lista->inicio;
    Personagem res = lista->inicio->personagem;
    lista->inicio = lista->inicio->prox;
    lista->inicio->ant = NULL;
    free(tmp);
    return res;
}

int cmpPersonagens(Personagem j1, Personagem j2)
{
    int a = cmpStrings(j1.house, j2.house);
    if (a != 0)
        return a;
    return cmpStrings(j1.name, j2.name);
}

void swap(Lista *lista, Celula *i, Celula *j)
{
    Personagem aux = i->personagem;
    i->personagem = j->personagem;
    j->personagem = aux;
}

void quicksortR(Lista *lista, Celula *left, Celula *right)
{
    Celula *i = left;
    Celula *j = right;
    Personagem pivot = right->personagem;
    while (j != i->ant && j != i->ant->ant)
    {
        while (cmpPersonagens(i->personagem, pivot) == -1)
            i = i->prox;
        while (cmpPersonagens(pivot, j->personagem) == -1)
            j = j->ant;
        if (j != i->ant && j != i->ant->ant)
        {
            swap(lista, i, j);
            i = i->prox;
            j = j->ant;
        }
    }
    if (left != j && j != left->ant)
    {
        quicksortR(lista, left, j);
    }
    if (right != i && i != right->prox)
    {
        quicksortR(lista, i, right);
    }
}

void quicksort(Lista *lista)
{
    Personagem j;
    Celula *c1 = newCelula(j);
    Celula *c2 = newCelula(j);
    lista->inicio->ant = c1;
    lista->inicio->ant->prox = lista->inicio;
    lista->fim->prox = c2;
    lista->fim->prox->ant = lista->fim;
    quicksortR(lista, lista->inicio, lista->fim);
    lista->inicio->ant = NULL;
    lista->fim->prox = NULL;
    free(c1);
    free(c2);
}

void mostrar(Lista *lista)
{
    for (Celula *i = lista->inicio; i != NULL; i = i->prox)
    {
        Personagem personagem = i->personagem;
        char formattedAlternateNames[500];
        strcpy(formattedAlternateNames, personagem.alternateNames);
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
                personagem.id, personagem.name, formattedAlternateNames, personagem.house, personagem.ancestry,
                personagem.species, personagem.patronus, personagem.hogwartsStaff ? "true" : "false", personagem.hogwartsStudent ? "true" : "false", personagem.actorName, personagem.alive ? "true" : "false",
                personagem.dateOfBirth, personagem.yearOfBirth, personagem.eyeColour, personagem.gender,
                personagem.hairColour, personagem.wizard ? "true" : "false");

        replace(output, "*", "");
        replace(output, "'", "");
        printf("%s", output);
    }
}
int main(void)
{
    Personagem *personagens = (Personagem *)malloc(500 * sizeof(Personagem));
    Lista *lista = newLista();
    char *linha = (char *)malloc(40 * sizeof(char));
    ler(personagens, "/tmp/characters.csv");
    scanf("%s", linha);
    while (strcmp(linha, "FIM") != 0)
    {
        for (int i = 0; i < 406; i++)
        {
            // printf("%s\n", personagens[i].id);
            if (strcmp(personagens[i].id, linha) == 0)
            {
                inserirFim(lista, personagens[i]);
                // printf("inseriu\n");
                break;
            }
            // printf("nao inseriu\n");
        }
        scanf("%s", linha);
    }
    quicksort(lista);
    mostrar(lista);
    return 0;
}