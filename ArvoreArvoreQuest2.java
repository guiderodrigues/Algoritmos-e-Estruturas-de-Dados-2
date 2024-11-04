public class ArvoreArvoreQuest2 {
        No raiz;
    class No{
        char letra;
        No esq, dir;
        No2 raiz;
        No(char letra){ 
            this(letra,null,null,null);
        }
        No(char letra, No esq, No dir, No2 raiz){
            this.letra = letra;
            this.esq = esq;
            this.dir = dir;
            this.raiz = raiz;
        }
    }
    class No2{
        String palavra;
        No2 esq, dir;
        No2(String palavra){
            this(palavra, null,null);
        }
        No2(String palavra, No2 esq, No2 dir){
            this.palavra = palavra;
            this.esq = esq;
            this.dir = dir;
        }
    }
    int contarPalavras(String padrao){
        char alvo = padrao.charAt(0);
        int tam = padrao.length();
        return contarPalavras(alvo, raiz, tam);
     }
    int contarPalavras(char alvo, No i, int tam){
        int resp = 0;
        if (i == null){
            System.out.println("erro");
        }
        if (i.letra == alvo){
            resp = cincoLetras(i.raiz, tam);
        }
        if (i.letra < alvo){
            resp = contarPalavras(alvo, i.esq, tam);
        }
        if (i.letra > alvo){
            resp = contarPalavras(alvo, i.dir, tam);
        }
        return resp;
    }
    
    int cincoLetras(No2 i, int tam){
        int cont = 0;
        if (i != null){
            if (i.palavra.length() == tam){
                cont++;
            }
            cont += cincoLetras(i.esq, tam);
            cont += cincoLetras(i.dir, tam);
        }
        return cont;
    }
}
