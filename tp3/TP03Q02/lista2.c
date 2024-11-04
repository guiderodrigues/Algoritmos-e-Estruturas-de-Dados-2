#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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

typedef struct Lista {
  Personagem *arr;
  int n;
  int total;
} Lista;

Lista *newLista() {
  Lista *lista = (Lista *)malloc(sizeof(Lista));
  lista->arr = (Personagem *)malloc(500 * sizeof(Personagem));
  lista->n = 0;
  lista->total = 500;
  return lista;
}

Lista *inserirInicio(Lista *lista, Personagem Personagem) {
  for (int i = lista->n; i > 0; i--) {
    lista->arr[i] = lista->arr[i - 1];
  }
  lista->arr[0] = Personagem;
  lista->n++;
  return lista;
}

Lista *inserirFim(Lista *lista, Personagem Personagem) {
  lista->arr[lista->n] = Personagem;
  lista->n++;
  return lista;
}

Lista *removerInicio(Lista *lista) {
  if (lista->n > 0) {
    imprimirMensagemRemocao(lista->arr[0].name);
    for (int i = 0; i < lista->n - 1; i++) {
      lista->arr[i] = lista->arr[i + 1];
    }
    lista->n--;
  }
  return lista;
}

Lista *removerFim(Lista *lista) {
  if (lista->n > 0) {
    imprimirMensagemRemocao(lista->arr[lista->n - 1].name);
    lista->n--;
  }
  return lista;
}

Lista *inserir(Lista *lista, Personagem Personagem, int pos) {
  for (int i = lista->n; i > pos; i--) {
    lista->arr[i] = lista->arr[i - 1];
  }
  lista->arr[pos] = Personagem;
  lista->n++;
  return lista;
}

Lista *remover(Lista *lista, int pos) {
  if (pos >= 0 && pos < lista->n) {
    imprimirMensagemRemocao(lista->arr[pos].name);
    for (int i = pos; i < lista->n - 1; i++) {
      lista->arr[i] = lista->arr[i + 1];
    }
    lista->n--;
  }
  return lista;
}

void metodos(Lista *lista, Personagem *personagens) {
  char *metodo = (char *)malloc(3 * sizeof(char));
  scanf("%s", metodo);
  //printf("Metodo:%s\n", metodo);
  if (strcmp(metodo, "II") == 0) {
    char id [40];
    scanf("%s", &id);
    //printf("ID:%s\n", id);
     for (int i = 0; i < 406; i++) {
      if (strcmp(personagens[i].id, id) == 0) {
        inserirInicio(lista, personagens[i]);
        break;
      }
  }
  } else if (strcmp(metodo, "IF") == 0) {
    char id [40];
    scanf("%s", &id);
    //printf("ID:%s\n", id);
     for (int i = 0; i < 406; i++) {
      if (strcmp(personagens[i].id, id) == 0) {
        inserirFim(lista, personagens[i]);
        break;
      }
  }
  } else if (strcmp(metodo, "I*") == 0) {
    char id [40];
    int pos;
    scanf("%d", &pos);
    scanf("%s", &id);
    //printf("Pos:%d ID:%s\n", pos, id);
    for (int i = 0; i < 406; i++) {
      if (strcmp(personagens[i].id, id) == 0) {
        inserir(lista, personagens[i], pos);
        break;
      }
  }
  } else if (strcmp(metodo, "RI") == 0) {
    removerInicio(lista);
  } else if (strcmp(metodo, "RF") == 0) {
    removerFim(lista);
  } else if (strcmp(metodo, "R*") == 0) {
    int pos;
    scanf("%d", &pos);
    //printf("Pos:%d\n", pos);
    remover(lista, pos);
  }
  free(metodo);
}

void mostrar(Lista *lista, int n) {
    for (int i = 0; i < lista->n; i++) {
        Personagem personagem = lista->arr[i];
        char formattedAlternateNames[500];
        strcpy(formattedAlternateNames, personagem.alternateNames);
        char *inicio = formattedAlternateNames;
        char *fim = inicio + strlen(formattedAlternateNames) - 1;
        if (*inicio == '[') {
            *inicio = '{';
        }
        if (*fim == ']') {
            *fim = '}';
        }
        replace(formattedAlternateNames, "*", "");
        char output[1000];
        sprintf(output, "[%d ## %s ## %s ## {%s} ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s]\n",
                i, personagem.id, personagem.name, formattedAlternateNames, personagem.house, personagem.ancestry,
                personagem.species, personagem.patronus, personagem.hogwartsStaff ? "true" : "false", personagem.hogwartsStudent ? "true" : "false", personagem.actorName, personagem.alive ? "true" : "false",
                personagem.dateOfBirth, personagem.yearOfBirth, personagem.eyeColour, personagem.gender,
                personagem.hairColour, personagem.wizard ? "true" : "false");

        replace(output, "*", "");
        replace(output, "'", "");
        printf("%s", output);
    }
}

int main(void) {
  Personagem *personagens = (Personagem *)malloc(500 * sizeof(Personagem));
  Lista *lista = newLista();
  char *linha = (char *)malloc(40 * sizeof(char));
  ler(personagens, "/tmp/characters.csv");
  scanf("%s", linha);
  //printf("Linha:%s\n", linha);
  int j = 0;
  while (strcmp(linha, "FIM") != 0) {
   for (int i = 0; i < 406; i++) {
    //printf("%s\n", personagens[i].id);
    if (strcmp(personagens[i].id, linha) == 0) {
        inserirFim(lista, personagens[i]);
        //printf("inseriu\n");
        break;
    }
    //printf("nao inseriu\n");
}
    //mostrar(lista, j);
    scanf("%s", linha);
    //printf("Linha: %s\n", linha);
    j++;
  }
  int n;
  scanf("%d", &n);
  //printf("N: %d\n", n);
  for (int i = 0; i < n; i++) {
    metodos(lista, personagens);
  }
  mostrar(lista, n);
  return 0;
}