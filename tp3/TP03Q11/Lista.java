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

public class Lista {
    static Scanner scan = new Scanner(System.in);

    public class Celula {
        public Personagem elemento;
        public Celula ant;
        public Celula prox;

        public Celula() {
            this(null);
        }

        public Celula(Personagem elemento) {
            this.elemento = elemento;
            this.ant = null;
            this.prox = null;
        }
    }
     public class Personagem {
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

  public Personagem() {
    this.id = "";
    this.name = "";
    this.alternateNames = new ArrayList<>();
    this.house = "";
    this.ancestry = "";
    this.species = "";
    this.patronus = "";
    this.hogwartsStaff = true;
    this.hogwartsStudent = true;
    this.actorName = "";
    this.alive = true;
    this.dateOfBirth = LocalDate.of(0000, 1, 1);
    this.yearOfBirth = -1;
    this.eyeColour = "";
    this.gender = "";
    this.hairColour = "";
    this.wizard = true;
  }

  public Personagem(String x) {
    buscarPorId(x, "/tmp/characters.csv");
  }

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
        this.hogwartsStaff = fields.length > 7 ? Boolean.parseBoolean(fields[7]) : false;
            this.hogwartsStudent = fields.length > 8 ? Boolean.parseBoolean(fields[8]) : false;
        this.actorName = fields.length > 9 ? fields[9] : "nao informado";
        this.alive = fields.length > 10 ? Boolean.parseBoolean(fields[10]) : false;
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
        this.wizard = fields.length > 17 ? Boolean.parseBoolean(fields[17]) : false;
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
          if (fields.length > 7 && fields[7].compareTo("VERDADEIRO") == 0) {
            this.hogwartsStaff = true;
          } else {
            this.hogwartsStaff = false;
          }
          if (fields.length > 8 && fields[8].compareTo("VERDADEIRO") == 0) {
            this.hogwartsStudent = true;
          } else {
            this.hogwartsStudent = false;
          }
          this.actorName = fields.length > 9 ? fields[9] : "nao informado";
          if (fields.length > 10 && fields[10].compareTo("VERDADEIRO") == 0) {
            this.alive = true;
          } else {
            this.alive = false;
          }
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
          if (fields.length > 17 && fields[17].compareTo("VERDADEIRO") == 0) {
            this.wizard = true;
          } else {
            this.wizard = false;
          }
          break;
        }
      }
      buffer.close();
      file.close();
    } catch (IOException e) {
      e.printStackTrace();
    }
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

public void imprimirPosition(int i) {
  System.out.println(toStringWithPosition(i));
}

public String toStringWithPosition(int position) {
  DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd-MM-yyyy");
  String formattedDate = dateOfBirth.format(formatter);
  String alternateNamesString = alternateNames.toString().replace("[", "{").replace("]", "}").replace("'", "");
  String resp = "[" + position + " ## " + id + " ## " + name + " ## " + alternateNamesString + " ## " + house + " ## ";
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
  }

  // void mostrar que chama imprimir e imprime cada personagem
    public void mostrar() {
        Celula aux = inicio;
        while (aux != null) {
            aux.elemento.imprimir();
            aux = aux.prox;
        }
    }

    int n, total;
    Celula inicio;
    Celula fim;

    public Lista() {
        n = 0;
        total = 10000;
        inicio = null;
        fim = null;
    }

    public void inserirInicio(Personagem x) {
      Celula novaCelula = new Celula(x);
      if (inicio == null) {
          inicio = novaCelula;
          fim = novaCelula;
      } else {
          novaCelula.prox = inicio;
          inicio.ant = novaCelula;
          inicio = novaCelula;
      }
      n++;
  }

  public void quicksort() {
    quicksortRec(inicio, fim);
}

private void quicksortRec(Celula esquerda, Celula direita) {
    if (esquerda != null && direita != null && esquerda != direita && esquerda.ant != direita) {
        Celula pivo = partition(esquerda, direita);
        quicksortRec(esquerda, pivo.ant);
        quicksortRec(pivo.prox, direita);
    }
}

private Celula partition(Celula esquerda, Celula direita) {
    Celula pivo = direita;
    Celula i = esquerda.ant;

    for (Celula j = esquerda; j != direita; j = j.prox) {
        if (compare(j.elemento, pivo.elemento) <= 0) {
            i = (i == null) ? esquerda : i.prox;
            swap(i, j);
        }
    }

    i = (i == null) ? esquerda : i.prox;
    swap(i, direita);
    return i;
}

private void swap(Celula celula1, Celula celula2) {
    Personagem temp = celula1.elemento;
    celula1.elemento = celula2.elemento;
    celula2.elemento = temp;
}

private int compare(Personagem Personagem1, Personagem Personagem2) {
    int estadoComparison = Personagem1.getCasa().compareTo(Personagem2.getCasa());
    if (estadoComparison == 0) {
        return Personagem1.getNome().compareTo(Personagem2.getNome());
    } else {
        return estadoComparison;
    }
}

    public static void main(String[] args) {
      Lista lista = new Lista();
      String linha;
      linha = scan.nextLine();
      while (!linha.equals("FIM")) {
        lista.inserirInicio(lista.new Personagem(linha));
        linha = scan.nextLine();
      }
      lista.quicksort();
      lista.mostrar();
    }

}
