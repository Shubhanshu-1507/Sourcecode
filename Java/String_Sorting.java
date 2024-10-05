public class String_Sorting {

    public static void printArr(String[] arr) {
        for (String s : arr) {
            System.out.print(s + " ");
        }
        System.out.println();
    }

    public static void swap(String[] arr, int i) {
        String temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }

    public static String[] bubbleSort(String[] arr) {
        boolean swapped;

        for (int j = 0; j < arr.length - 1; j++) {
            swapped = false;

            for (int i = 0; i < arr.length - 1 - j; i++) {
                if (arr[i].compareToIgnoreCase(arr[i + 1]) > 0) {
                    swap(arr, i);
                    swapped = true;
                }
            }

            if (!swapped) {
                break;
            }
        }

        return arr;
    }

    public static void main(String[] args) {
        String[] arr = {"B", "a", "D", "aa", "AA", "Z", "z"};

        printArr(bubbleSort(arr));
    }
}
