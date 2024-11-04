public class Pilha {
    class Celula {
        int elemento;
        Celula prox;
        Celula (int x){
            this(x, null);
        }
        Celula (int x, Celula cel){
            this.elemento = x;
            this.prox = cel;
        }
    }
    Celula topo;
    Pilha(int x){
        topo = new Celula(x);
    }
    void inserir (int x){
        Celula tmp = new Celula(x);
        tmp.prox = topo;
        topo = tmp;
        tmp = null;
    }
    int remover (){
        if(topo == null){
            System.out.println("Pilha vazia");
        }
        int resp = topo.elemento;
        Celula tmp = topo;
        topo = topo.prox;
        tmp.prox = null;
        tmp = null;
        return resp;
    }
    void mostrar (){

    }
}