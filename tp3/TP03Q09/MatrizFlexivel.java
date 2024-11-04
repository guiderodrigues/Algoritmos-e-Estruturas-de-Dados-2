import java.util.Scanner;

/*
 * Autor: Guilherme Oliveira de Rodrigues
 * Ultima atualizacao: 24/05/2024
 * Objetivo: Implementar uma matriz flexivel
 */

public class MatrizFlexivel {
    static Scanner scan = new Scanner(System.in);

    public class Celula{
        Celula esq;
        Celula dir;
        Celula sup;
        Celula inf;
        int elemento;
    
        Celula(){
            esq = null;
            dir = null;
            sup = null;
            inf = null;
            elemento = 0;
        }
    }

    public class Matriz{
        Celula inicio;
        int linhas;
        int colunas;
        
        Matriz(int l, int c){
            linhas = l;
            colunas = c;
            Celula[][] mat = new Celula[l][c];
            for(int i = 0; i < l; i++){
                for(int j = 0; j < c; j++){
                    mat[i][j] = new Celula();
                }
            }

            for(int i = 0; i < l; i++){
                for(int j = 0; j < c; j++){
                    if(j!=c-1){
                        mat[i][j].dir = mat[i][j+1];
                    }
                    if(j!=0){
                        mat[i][j].esq = mat[i][j-1];
                    }
                    if(i!=0){
                        mat[i][j].sup = mat[i-1][j];
                    }
                    if(i!=l-1){
                        mat[i][j].inf = mat[i+1][j];
                    }
                }
            }

            inicio = mat[0][0];
        }

        public void leLinha(){
            Celula aux = inicio;
            Celula aux2 = inicio;
            for(int i=0;i<linhas;i++){
                aux2 = aux;
                for(int j=0;j<colunas;j++){
                    aux2.elemento = scan.nextInt();
                    aux2 = aux2.dir;
                }
                aux = aux.inf;
            }
        }

        void mostrarDiagonalPrincipal(){
            Celula aux = inicio;
            for(int i=0;i<linhas;i++){
                System.out.print(aux.elemento + " ");
                if(i!=linhas-1){
                    aux = aux.inf;
                    aux = aux.dir;
                }
            }
            System.out.println();
        }

        void mostrarDiagonalSecundaria(){
            Celula aux = inicio;
            for(int i=0;i<linhas-1;i++){
                aux = aux.dir;
            }

            for(int i=0;i<linhas;i++){
                System.out.print(aux.elemento + " ");
                if(i!=linhas-1){
                    aux = aux.inf;
                    aux = aux.esq;
                }
            }
            System.out.println();
        }

        public void mostrar(){
            Celula aux = inicio;
            while(aux!=null){
                Celula aux2 = aux;
                while(aux2!=null){
                    System.out.print(aux2.elemento + " ");
                    aux2 = aux2.dir;
                }
                System.out.println();
                aux = aux.inf;
            }
        }
        public Matriz soma(Matriz mat){
            if(linhas!=mat.linhas || colunas!=mat.colunas){
                return null;
            }

            Matriz result = new Matriz(linhas, colunas);
            Celula aux11 = inicio;
            Celula aux12 = inicio;
            Celula aux21 = mat.inicio;
            Celula aux22 = mat.inicio;
            Celula aux31 = result.inicio;
            Celula aux32 = result.inicio;

            for(int i=0;i<linhas;i++){
                aux12 = aux11;
                aux22 = aux21;
                aux32 = aux31;
                for(int j=0;j<colunas;j++){
                    aux32.elemento = aux12.elemento + aux22.elemento;
                    aux12 = aux12.dir;
                    aux22 = aux22.dir;
                    aux32 = aux32.dir;
                }
                aux11 = aux11.inf;
                aux21 = aux21.inf;
                aux31 = aux31.inf;
            }

            return result;
        }
       
        public Matriz multiplicacao(Matriz mat){
            Matriz res = new Matriz(linhas, mat.colunas);
            Celula aux11 = inicio;
            Celula aux12 = inicio;
            Celula aux21 = mat.inicio;
            Celula aux22 = mat.inicio;
            Celula aux31 = res.inicio;
            Celula aux32 = res.inicio;
            for(int i=0;i<linhas;i++){
                aux11 = inicio;
                aux32 = aux31;
                for(int j=0;j<mat.colunas;j++){
                    int soma = 0;
                    aux12 = aux11;
                    aux22 = aux21;
                    for(int k=0;k<linhas;k++){
                        soma+=aux12.elemento*aux22.elemento;
                        aux12 = aux12.inf;
                        aux22 = aux22.dir;
                    }
                    
                    aux32.elemento = soma;
                    aux11 = aux11.dir;
                    aux32 = aux32.dir;
                }
                aux21 = aux21.inf;
                aux31 = aux31.inf;
            }
    
            return res;
        }
    }
    
    public static void main(String[] args) {
        MatrizFlexivel matriz = new MatrizFlexivel();
        MatrizFlexivel.Matriz m1;
        MatrizFlexivel.Matriz m2;

        int qtd = scan.nextInt();
        for(int i=0;i<qtd;i++){
            m1 = matriz.new Matriz(scan.nextInt(), scan.nextInt());
            m1.leLinha();
            m2 = matriz.new Matriz(scan.nextInt(), scan.nextInt());
            m2.leLinha();

            m1.mostrarDiagonalPrincipal();
            m1.mostrarDiagonalSecundaria();
            m1.soma(m2).mostrar();
            m2.multiplicacao(m1).mostrar();
        }

        scan.close();
    }
}
