// Hrishikesh Ram
// Intermediate Contest 3 2020
// Enloe High School
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class RamH_ACSL3_int {
    private static List<List<String>> splitTerm(String input) {
        String[] terms = input.split("\\+");
        List<List<String>> termArr = new ArrayList<>();
        for (String term : terms) {
            List<String> subterms = new ArrayList<String>();
            for (int i = 0; i < term.length(); i++) {
                if (Character.isLetter(term.charAt(i))) {
                    subterms.add(Character.toString(term.charAt(i)));
                } else { // can only be a ~
                    if (i + 2 < term.length()) {
                        subterms.add(term.substring(i, i + 2));
                    } else {
                        subterms.add(term.substring(i));
                    }
                    i++;
                }
            }
            termArr.add(subterms);
        }
        return termArr;
    }

    private static int[][] gridMaker(String input) {
        int[][] grid = new int[4][4];
        for (List<String> term : splitTerm(input)) {
            int[][] array = new int[4][4];
            for (String letter : term) {
                switch (letter) {
                    case "A":
                        for (int i = 0; i < 4; i++) {
                            array[i][0]++;
                            array[i][1]++;
                        }
                        break;
                    case "B":
                        for (int i = 0; i < 4; i++) {
                            array[0][i]++;
                            array[1][i]++;
                        }
                        break;
                    case "C":
                        for (int i = 0; i < 4; i++) {
                            array[i][1]++;
                            array[i][2]++;
                        }
                        break;
                    case "D":
                        for (int i = 0; i < 4; i++) {
                            array[1][i]++;
                            array[2][i]++;
                        }
                        break;
                    case "~A":
                        for (int i = 0; i < 4; i++) {
                            array[i][2]++;
                            array[i][3]++;
                        }
                        break;
                    case "~B":
                        for (int i = 0; i < 4; i++) {
                            array[2][i]++;
                            array[3][i]++;
                        }
                        break;
                    case "~C":
                        for (int i = 0; i < 4; i++) {
                            array[i][0]++;
                            array[i][3]++;
                        }
                        break;
                    case "~D":
                        for (int i = 0; i < 4; i++) {
                            array[0][i]++;
                            array[3][i]++;
                        }
                        break;
                }
            }
            for (int i = 0; i < 4; i++) {
                for (int k = 0; k < 4; k++) {
                    if (array[i][k] == term.size()) {
                        grid[i][k] = 1;
                    }
                }
            }
        }
        return grid;
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("D:\\ACSL3\\3int.txt")).useDelimiter("\n");
        for (int j = 0; j < 5; j++) {
            String line = sc.next().strip();
            String hex = "";
            for (int i = 0; i < 4; i++) {
                hex += Integer.toHexString(Integer.parseInt(Arrays.toString(gridMaker(line)[i]).replaceAll("[\\[\\], ]", ""), 2)).toUpperCase();
            }
            System.out.println(hex);
        }
    }
}
