public class Quicksort{
    public static void quicksort (int [] arr, int esq, int dir){
        int i = esq, j = dir, pivo = (esq + dir)/2;
        while (i < esq){
            while (arr[i] < pivo)
            i++;
            while (arr[j] > pivo)
            j--;
            if (i <= j){
                int tmp = arr[i];
                tmp = arr[j];
                arr[j] = tmp;
                i++;
                j--;
            }
            if (esq < j){
                quicksort(arr, esq, j);
            }
            if (i < dir){
                quicksort(arr, i, dir);
            }
        }
    }
}