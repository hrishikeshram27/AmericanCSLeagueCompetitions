// Hrishikesh Ram 12/12/2019
// Enloe High School, Raleigh NC, 11th Grade
// Intermediate Contest 1
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class RamH_ACSL1_int5 {
    private static String transform(int n, int p){
        StringBuilder result = new StringBuilder();
        String num = Integer.toString(n);
        int indexNum = Integer.parseInt(Character.toString(num.charAt(num.length()-p)));
        for(int i=0;i<num.length()-p;i++){
            int x = Integer.parseInt(Character.toString(num.charAt(i)));
            result.append(Integer.toString(x + indexNum).charAt(Integer.toString(x + indexNum).length() - 1));
        }
        result.append(indexNum);
        for(int i=num.length()-p+1;i<num.length();i++){
            result.append(Math.abs(Integer.parseInt(Character.toString(num.charAt(i))) - indexNum));
        }
        return result.toString();
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("src//ACSL1Int_Input.txt")).useDelimiter("\n");
        for(int i=0;i<5;i++){
            String line = sc.next();
            int n = Integer.parseInt(line.substring(0,line.indexOf(" ")));
            int p = Integer.parseInt(line.substring(line.indexOf(" ")).replaceAll("[^0-9]",""));
            System.out.println(transform(n,p));
        }
        sc.close();
    }
}
