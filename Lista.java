public class Lista {
    CelLista inicio;
    CelLista fim;
    class CelLista{
        CelPilha topo;
        CelLista prox;
    }
    class CelPilha{
        int elemento;
        CelPilha prox;
    }
    CelLista maiorPilha(){
        CelLista maior = inicio;
        int tamMaior = getTam(maior);
        for (CelLista i = inicio; i !=null; i=i.prox){
            int tamAtual = getTam(i);
            if (tamMaior < tamAtual){
                maior = i;
            }
        }
        return maior;
    }
    int getTam(CelLista i){
        int cont = 0;
        for (CelPilha j = i.topo; j != null; j = j.prox){
            cont++;
        }
        return cont;
    }
}
