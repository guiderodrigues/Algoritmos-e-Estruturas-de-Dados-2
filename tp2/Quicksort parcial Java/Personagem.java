
//Questao 1
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/*
Aluno: Guilherme Oliveira de Rodrigues
Úlitma atualização: 25/04/2024
Objetivo: Organizar parcialmente os personagens de Harry Potter em ordem pelo nome.
*/
public class Personagem {
  static Scanner scan = new Scanner(System.in);
  static int comp = 0;
  private String id;
  private String name;
  private List<String> alternateNames;
  private String house;
  private String ancestry;
  private String species;
  private String patronus;
  private boolean hogwartsStaff;
  private boolean hogwartsStudent;
  private String actorName;
  private boolean alive;
  private LocalDate dateOfBirth;
  private int yearOfBirth;
  private String eyeColour;
  private String gender;
  private String hairColour;
  private boolean wizard;

  public String getId() {
    return id;
  }

  public void setId(String id) {
    this.id = id;
  }

  public String getNome() {
    return name;
  }

  public void setNome(String nome) {
    this.name = nome;
  }

  public List<String> getAlt() {
    return alternateNames;
  }

  public void setAlt(List<String> alt) {
    this.alternateNames = alt;
  }

  public String getCasa() {
    return house;
  }

  public void setCasa(String casa) {
    this.house = casa;
  }

  public String getAncestry() {
    return ancestry;
  }

  public void setAncestry(String ancestralidade) {
    this.ancestry = ancestralidade;
  }

  public String getEspecie() {
    return species;
  }

  public void setEspecie(String especie) {
    this.species = especie;
  }

  public String getPatrono() {
    return patronus;
  }

  public void setPatrono(String patrono) {
    this.patronus = patrono;
  }

  public boolean getStaff() {
    return hogwartsStaff;
  }

  public void setStaff(boolean staff) {
    this.hogwartsStaff = staff;
  }

  public boolean getEstudante() {
    return hogwartsStudent;
  }

  public void setEstudante(boolean estudante) {
    this.hogwartsStudent = estudante;
  }

  public String getAtor() {
    return actorName;
  }

  public void setAtor(String ator) {
    this.actorName = ator;
  }

  public boolean getVivo() {
    return hogwartsStaff;
  }

  public void setVivo(boolean vivo) {
    this.alive = vivo;
  }

  public LocalDate getData() {
    return dateOfBirth;
  }

  public void setData(LocalDate data) {
    this.dateOfBirth = data;
  }

  public int getAno() {
    return yearOfBirth;
  }

  public void SetAno(int ano) {
    this.yearOfBirth = ano;
  }

  public String getOlho() {
    return eyeColour;
  }

  public void setOlho(String olho) {
    this.eyeColour = olho;
  }

  public String getGenero() {
    return gender;
  }

  public void setGenero(String genero) {
    this.gender = genero;
  }

  public String getCabelo() {
    return hairColour;
  }

  public void setCabelo(String cabelo) {
    this.hairColour = cabelo;
  }

  public boolean getBruxo() {
    return wizard;
  }

  public void setBruxo(boolean bruxo) {
    this.wizard = bruxo;
  }

  int trocas = 0;

  protected Personagem clone() throws CloneNotSupportedException {
    Personagem novo = new Personagem();
    novo.id = this.id;
    novo.name = this.name;
    novo.alternateNames = this.alternateNames;
    novo.house = this.house;
    novo.ancestry = novo.ancestry;
    novo.species = this.species;
    novo.patronus = this.patronus;
    novo.hogwartsStaff = this.hogwartsStaff;
    novo.hogwartsStudent = this.hogwartsStudent;
    novo.actorName = this.actorName;
    novo.alive = this.alive;
    novo.dateOfBirth = this.dateOfBirth;
    novo.yearOfBirth = this.yearOfBirth;
    novo.eyeColour = this.eyeColour;
    novo.gender = this.gender;
    novo.hairColour = this.hairColour;
    novo.wizard = this.wizard;
    return novo;
  }

  public void ler(String nomeArquivo) throws IOException {
    FileReader file = new FileReader(nomeArquivo);
    BufferedReader buffer = new BufferedReader(file);

    String line;
    boolean firstLine = true;

    while ((line = buffer.readLine()) != null) {
      if (firstLine) {
        firstLine = false;
        continue;
      }

      String[] fields = line.split(",");
      if (fields.length > 0) {
        this.id = fields.length > 0 ? fields[0] : "nao informado";
        this.name = fields.length > 1 ? fields[1] : "nao informado";
        this.alternateNames = new ArrayList<>();
        if (fields.length > 2 && !fields[2].isEmpty()) {
          String[] alternateNamesArray = fields[2].substring(1, fields[2].length() - 1).split(", ");
          this.alternateNames.addAll(Arrays.asList(alternateNamesArray));
        }
        this.house = fields.length > 3 ? fields[3] : "nao informado";
        this.ancestry = fields.length > 4 ? fields[4] : "nao informado";
        this.species = fields.length > 5 ? fields[5] : "nao informado";
        this.patronus = fields.length > 6 ? fields[6] : "nao informado";
        this.hogwartsStaff = fields.length > 7 ? fields[7].equalsIgnoreCase("VERDADEIRO") : false;
        this.hogwartsStudent = fields.length > 8 ? fields[8].equalsIgnoreCase("VERDADEIRO") : false;
        this.actorName = fields.length > 9 ? fields[9] : "nao informado";
        this.alive = fields.length > 10 ? fields[10].equalsIgnoreCase("VERDADEIRO") : false;
        DateTimeFormatter formatter1 = DateTimeFormatter.ofPattern("dd-MM-yyyy");
        DateTimeFormatter formatter2 = DateTimeFormatter.ofPattern("d-M-yyyy");
        try {
          this.dateOfBirth = fields.length > 12 ? LocalDate.parse(fields[12], formatter1) : null;
        } catch (DateTimeParseException e) {
          this.dateOfBirth = fields.length > 12 ? LocalDate.parse(fields[12], formatter2) : null;
        }
        this.yearOfBirth = fields.length > 13 ? Integer.parseInt(fields[13]) : -1;
        this.eyeColour = fields.length > 14 ? fields[14] : "nao informado";
        this.gender = fields.length > 15 ? fields[15] : "nao informado";
        this.hairColour = fields.length > 16 ? fields[16] : "nao informado";
        this.wizard = fields.length > 17 ? fields[17].equalsIgnoreCase("VERDADEIRO") : false;
      }
    }

    buffer.close();
    file.close();
  }

  public void buscarPorId(String characterId, String nomeArquivo) {
    try {
      FileReader file = new FileReader(nomeArquivo);
      BufferedReader buffer = new BufferedReader(file);

      String line;
      boolean firstLine = true;

      while ((line = buffer.readLine()) != null) {
        if (firstLine) {
          firstLine = false;
          continue;
        }

        String[] fields = line.split(";");

        if (fields.length > 0 && fields[0].equals(String.valueOf(characterId))) {
          this.id = fields.length > 0 ? fields[0] : "nao informado";
          this.name = fields.length > 1 ? fields[1] : "nao informado";
          this.alternateNames = new ArrayList<>();
          if (fields.length > 2 && !fields[2].isEmpty()) {
            String[] alternateNamesArray = fields[2].substring(1, fields[2].length() - 1).split(", ");
            this.alternateNames.addAll(Arrays.asList(alternateNamesArray));
          }
          this.house = fields.length > 3 ? fields[3] : "nao informado";
          this.ancestry = fields.length > 4 ? fields[4] : "nao informado";
          this.species = fields.length > 5 ? fields[5] : "nao informado";
          this.patronus = fields.length > 6 ? fields[6] : "nao informado";
          this.hogwartsStaff = fields.length > 7 ? fields[7].equalsIgnoreCase("VERDADEIRO") : false;
          this.hogwartsStudent = fields.length > 8 ? fields[8].equalsIgnoreCase("VERDADEIRO") : false;
          this.actorName = fields.length > 9 ? fields[9] : "nao informado";
          this.alive = fields.length > 10 ? fields[10].equalsIgnoreCase("VERDADEIRO") : false;
          DateTimeFormatter formatter1 = DateTimeFormatter.ofPattern("dd-MM-yyyy");
          DateTimeFormatter formatter2 = DateTimeFormatter.ofPattern("d-M-yyyy");
          try {
            this.dateOfBirth = fields.length > 12 ? LocalDate.parse(fields[12], formatter1) : null;
          } catch (DateTimeParseException e) {
            this.dateOfBirth = fields.length > 12 ? LocalDate.parse(fields[12], formatter2) : null;
          }
          this.yearOfBirth = fields.length > 13 ? Integer.parseInt(fields[13]) : -1;
          this.eyeColour = fields.length > 14 ? fields[14] : "nao informado";
          this.gender = fields.length > 15 ? fields[15] : "nao informado";
          this.hairColour = fields.length > 16 ? fields[16] : "nao informado";
          this.wizard = fields.length > 17 ? fields[17].equalsIgnoreCase("VERDADEIRO") : false;
          break;
        }
      }
      buffer.close();
      file.close();
    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  public static void swap(Personagem[] personagens, int i, int j) {
    Personagem temp = personagens[i];
    personagens[i] = personagens[j];
    personagens[j] = temp;
  }
  
  private static void partialQuicksort(Personagem[] personagens, int esq, int dir, int k) {
    if (esq < dir) {
        int pivotIndex = partition(personagens, esq, dir);
        if (pivotIndex - esq < k) {
            partialQuicksort(personagens, esq, pivotIndex - 1, k);
        }
        if (pivotIndex < k) {
            partialQuicksort(personagens, pivotIndex + 1, dir, k);
        }
    }
}

private static int partition(Personagem[] personagens, int esq, int dir) {
  Personagem pivot = personagens[esq];
  int i = esq + 1, j = dir;
  while (i <= j) {
      if (personagens[i] != null && (personagens[i].house.compareTo(pivot.house) < 0 || 
          (personagens[i].house.equals(pivot.house) && personagens[i].name.compareTo(pivot.name) < 0))) {
          i++;
      } else if (personagens[j] != null && (personagens[j].house.compareTo(pivot.house) > 0 || 
          (personagens[j].house.equals(pivot.house) && personagens[j].name.compareTo(pivot.name) > 0))) {
          j--;
      } else {
          swap(personagens, i, j);
          i++;
          j--;
      }
  }
  swap(personagens, esq, j);
  return j;
}

  public void imprimir() {
    System.out.println(toString());
  }

  public String toString() {
    DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd-MM-yyyy");
    String formattedDate = dateOfBirth.format(formatter);
    String alternateNamesString = alternateNames.toString().replace("[", "{").replace("]", "}").replace("'", "");
    String resp = "[" + id + " ## " + name + " ## " + alternateNamesString + " ## " + house + " ## ";
    resp += ancestry + " ## " + species + " ## ";
    resp += patronus + " ## " + hogwartsStaff + " ## ";
    resp += hogwartsStudent + " ## " + actorName + " ## ";
    resp += alive + " ## " + formattedDate + " ## ";
    resp += yearOfBirth + " ## " + eyeColour + " ## ";
    resp += gender + " ## " + hairColour + " ## ";
    resp += wizard + "]";
    return resp;
  }

  public void imprimirNome() {
    System.out.println(name);
  }

  public static boolean sequentialSearch(Personagem[] personagems, int quant, String nome) {
    boolean achou = false;
    for (int i = 0; i < quant; i++) {
      comp++;
      if (personagems[i].name.equals(nome)) {
        achou = true;
        break;
      }
    }
    return achou;
  }

  public static void main(String[] args) {
    Personagem[] Personagens = new Personagem[1000];
    String linha = scan.nextLine();
    int quant = 0;
    while (!linha.equals("FIM")) {
      String id = linha;
      Personagens[quant] = new Personagem();
      Personagens[quant].buscarPorId(id, "/tmp/characters.csv");
      quant++;
      linha = scan.nextLine();
    }
    partialQuicksort(Personagens, 0, quant-1,10);
    for (int i = 0; i < 10; i++) {
      Personagens[i].imprimir();
    }
    scan.close();
  }
}