#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

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
void imprimirMensagemRemocao(char *nome) { printf("(R) %s\n", nome); }

#define MAX_SIZE 500

typedef struct {
  Personagem arr[MAX_SIZE];
  int n;
  int total;
} Lista;

Lista newLista() {
  Lista lista;
  lista.n = 0;
  lista.total = 500;
  return lista;
}

Lista inserirInicio(Lista lista, Personagem personagem) {
  for (int i = lista.n; i > 0; i--) {
    lista.arr[i] = lista.arr[i - 1];
  }
  lista.arr[0] = personagem;
  lista.n++;
  return lista;
}

Lista inserirFim(Lista lista, Personagem personagem) {
  lista.arr[lista.n] = personagem;
  lista.n++;
  return lista;
}

Lista removerInicio(Lista lista) {
  if (lista.n > 0) {
    imprimirMensagemRemocao(lista.arr[0].name);
    for (int i = 0; i < lista.n - 1; i++) {
      lista.arr[i] = lista.arr[i + 1];
    }
    lista.n--;
  }
  return lista;
}

Lista removerFim(Lista lista) {
  if (lista.n > 0) {
    imprimirMensagemRemocao(lista.arr[lista.n - 1].name);
    lista.n--;
  }
  return lista;
}

Lista inserir(Lista lista, Personagem Personagem, int pos) {
  for (int i = lista.n; i > pos; i--) {
    lista.arr[i] = lista.arr[i - 1];
  }
  lista.arr[pos] = Personagem;
  lista.n++;
  return lista;
}

Lista remover(Lista lista, int pos) {
  if (pos >= 0 && pos < lista.n) {
    imprimirMensagemRemocao(lista.arr[pos].name);
    for (int i = pos; i < lista.n - 1; i++) {
      lista.arr[i] = lista.arr[i + 1];
    }
    lista.n--;
  }
  return lista;
}

Personagem findPersonagemById(Personagem personagens [], int n, char id []) {
  for (int i = 0; i < n; i++) {
    if (strcmp(personagens[i].id, id) == 0) {
      return personagens[i];
    }
  }
}

void metodos(Lista lista, Personagem personagens [], int n) {
  char linha[30];
  fgets(linha, 30, stdin);
  char *metodo = strtok(linha, " ");
  if (strcmp(metodo, "II") == 0) {
    char *id = strtok(NULL, " ");
    Personagem p = findPersonagemById(personagens, n, id);
    inserirInicio(lista, p);
  } else if (strcmp(metodo, "IF") == 0) {
    char *id = strtok(NULL, " ");
    Personagem p = findPersonagemById(personagens, n, id);
      inserirFim(lista, p);
  } else if (strcmp(metodo, "I*") == 0) {
    char *pos_str = strtok(NULL, " ");
    int pos = atoi(pos_str);
    char *id = strtok(NULL, " ");
    Personagem p = findPersonagemById(personagens, n, id);
    inserir(lista, p, pos);
  } else if (strcmp(metodo, "RI") == 0) {
    removerInicio(lista);
  } else if (strcmp(metodo, "RF") == 0) {
    removerFim(lista);
  } else if (strcmp(metodo, "R*") == 0) {
    char *pos_str = strtok(NULL, " ");
    int pos = atoi(pos_str);
    remover(lista, pos);
  }
}

void mostrar(Lista lista) {
  for (int i = 0; i < lista.n; i++) {
    printf("[%d ", i);
    printf("## %s ## ", lista.arr[i].name);
    printf("## %s ## ", lista.arr[i].house);
    printf("## %s ## ", lista.arr[i].patronus);
    printf("## %s ## ", lista.arr[i].species);
    printf("## %s ## ", lista.arr[i].dateOfBirth);
    printf("## %s ## ", lista.arr[i].yearOfBirth);
    printf("## %s ## ", lista.arr[i].eyeColour);
    printf("## %s ## ", lista.arr[i].gender);
    printf("## %s ## ", lista.arr[i].hairColour);
    printf("## %d ]\n", lista.arr[i].wizard);
    }
}



int main(void) {
  Personagem personagens [500];
  Lista lista = newLista();
  char linha [50];
  ler(personagens, "characters.csv");
  scanf("%s", linha);
  printf("Linha: %s\n", linha);
  while (strcmp(linha, "FIM") != 0) {
    Personagem p = findPersonagemById(personagens, 500, linha);
    printf("Personagem: %s\n", p.name);
    inserirFim(lista, p);
    mostrar(lista);
    scanf("%s", linha);
    printf("Linha: %s\n", linha);
  }
  int n;
  scanf("%d", &n);
  printf("N: %d\n", n);
  for (int i = 0; i < n; i++) {
    metodos(lista, personagens,n);
  } 
  mostrar(lista);
  return 0;
}