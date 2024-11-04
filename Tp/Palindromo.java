import java.util.Scanner;

public class Palindromo {
    static boolean testePalindromo(String str) {
        boolean result = true;
        int esq = 0;
        int dir = str.length() - 1;
        while (esq < dir) {
            char charEsq = str.charAt(esq);
            char charDir = str.charAt(dir);
            if (!Character.isLetter(charEsq)) {
                esq++;
            } else if (!Character.isLetter(charDir)) {
                dir--;
            } else {
                if (charEsq != charDir) {
                    result = false;
                    break;
                }
                esq++;
                dir--;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        String str = "";
        Scanner scan = new Scanner(System.in);
        while (true) {
            str = scan.nextLine();
            if (str.equals("FIM")) {
                break; // Sair do loop quando a entrada for "FIM"
            }
            boolean result = testePalindromo(str);
            if (result) {
                System.out.println("SIM");
            } else {
                System.out.println("NAO");
            }
        }
        scan.close();
    }
}
