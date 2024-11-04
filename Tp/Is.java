public class Is {
    public static boolean isVogal(String str) {
        int tam = str.length();
        int vogais = 0;
        char[] array = str.toCharArray();
        for (int i = 0; i < tam; i++) {
            char letra = Character.toLowerCase(array[i]);
            if (letra == 'a' ||  letra == 'e' ||  letra == 'i'|| letra == 'o' || letra == 'u') {
                vogais++;
            }
        }
        if (vogais == tam){
            return true;
        }
        else return false;
    }
    public static boolean isConsoante(String str) {
        int tam = str.length();
        int cons = 0;
        char[] array = str.toCharArray();
        for (int i = 0; i < tam; i++) {
            char letra = Character.toLowerCase(array[i]);
            if (letra > 97 &&  letra < 101 ||  letra > 101 && letra < 105 || letra > 105 && letra < 117 || letra > 117 && letra < 122) {
                cons++;
            }
        }
        if (cons == tam){
            return true;
        }
        else return false;
    }

    public static boolean isInt (String str){
         int tam = str.length();
        int inteiro = 0;
        char[] array = str.toCharArray();
        for (int i = 0; i < tam; i++) {
            if (array[i] >= 48 &&  array[i] <= 57) {
                inteiro++;
            }
        }
        if (inteiro == tam){
            return true;
        }
        else return false;
    }

    public static boolean isReal(String str) {
        int tam = str.length();
        int pontos = 0;
        for (int i = 0; i < tam; i++) {
            char caractere = str.charAt(i);

            if (Character.isDigit(caractere)) {
                continue;
            }
            else if (caractere == 46 && pontos == 0) {
                pontos++;
            }
            else {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        String str = MyIO.readLine();
        isVogal(str);
        isConsoante(str);
        isInt(str);
        isReal(str);
        if(isVogal(str)){
            MyIO.print("SIM ");
        }
        else MyIO.print("NAO ");
        if(isConsoante(str)){
            MyIO.print("SIM ");
        }
        else MyIO.print("NAO ");
        if(isInt(str)){
            MyIO.print("SIM ");
        }
        else MyIO.print("NAO ");
         if(isReal(str)){
            MyIO.print("SIM");
        }
        else MyIO.print("NAO");
    }
}
