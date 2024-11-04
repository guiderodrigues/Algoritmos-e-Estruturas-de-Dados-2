#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replace(char *str, const char *find, const char *replace) {
    int find_len = strlen(find);
    int replace_len = strlen(replace);

    char *temp = strstr(str, find);
    while (temp != NULL) {
        memmove(temp + replace_len, temp + find_len, strlen(temp + find_len) + 1);
        memcpy(temp, replace, replace_len);
        temp = strstr(temp + replace_len, find);
    }}

typedef struct {
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

void ler(Personagem *personagens[], const char *arquivo) {
    FILE *file = fopen(arquivo, "r");
    if (file == NULL) {
        return;
    }

    char linha[1050];
    int i = 0;
    while (fgets(linha, sizeof(linha), file)) {
        personagens[i] = (Personagem *)malloc(sizeof(Personagem));
        if (personagens[i] == NULL) {
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
        char *endToken = strchr(field, ']');
        if (endToken != NULL) {
            *endToken = '\0';
            strcpy(personagens[i]->alternateNames, field);
        } else {
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

        personagens[i]->hogwartsStaff = (strcmp(field, "1") == 0);
        field = strtok(NULL, ";");

        personagens[i]->hogwartsStudent = (strcmp(field, "1") == 0);
        field = strtok(NULL, ";");

        strcpy(personagens[i]->actorName, field);
        field = strtok(NULL, ";");

        personagens[i]->alive = (strcmp(field, "1") == 0);
        field = strtok(NULL, ";");
        field = strtok(NULL, ";");

        if (strcmp("23-6-1980", field) == 0) {
            strcpy(personagens[i]->dateOfBirth, "23-06-1980");
        } else
            strcpy(personagens[i]->dateOfBirth, field);
        field = strtok(NULL, ";");

        strcpy(personagens[i]->yearOfBirth, field);
        field = strtok(NULL, ";");

        strcpy(personagens[i]->eyeColour, field);
        field = strtok(NULL, ";");

        strcpy(personagens[i]->gender, field);
        field = strtok(NULL, ";");

        strcpy(personagens[i]->hairColour, field);
        personagens[i]->wizard = (strcmp(personagens[i]->species, "human") == 0);
        field = strtok(NULL, ";");

        i++;
    }
    fclose(file);
}

void imprimir(Personagem *character) {
    char formattedAlternateNames[500];
    strcpy(formattedAlternateNames, character->alternateNames);
    char *inicio = formattedAlternateNames;
    char *fim = inicio + strlen(formattedAlternateNames) - 1;
    if (*inicio == '[') {
        *inicio = '{';
    }
    if (*fim == ']') {
        *fim = '}';
    }
    replace(formattedAlternateNames, "'", "");

    char saida[1000];
    sprintf(saida, "[%s ## %s ## {%s} ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s]\n",
            character->id, character->name, formattedAlternateNames, character->house, character->ancestry,
            character->species, character->patronus, "false", "false", character->actorName, "false",
            character->dateOfBirth, character->yearOfBirth, character->eyeColour, character->gender,
            character->hairColour, "false");

    replace(saida,"*","");
    printf("%s", saida);

}

void buscarPorId(Personagem **todos) {
    char entrada[100];
    scanf("%s", entrada);
    while (strcmp(entrada, "FIM") != 0) {
      int i = 0;
      for (int i = 0; i < 500; i++) {
        if (todos[i] != NULL && strcmp(todos[i]->id, entrada) == 0) {
          imprimir(todos[i]);
          i=500;
        }
      }
        scanf("%s", entrada);
    }
}

int main() {
  const int num_characters = 500; 
  Personagem *personagens[num_characters];

  for (int i = 0; i < num_characters; i++) {
    personagens[i] = NULL;
  }

  ler(personagens, "personagens.csv");
  buscarPorId(personagens);

  for (int i = 0; i < num_characters; i++) {
    if (personagens[i] != NULL) {
      free(personagens[i]);
      personagens[i] = NULL;
    }
  }

  return 0;
}