// Hrishikesh Ram 12/12/2019
// Enloe High School, Raleigh NC, 11th Grade
// Senior Contest 1
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class RamH_ACSL1_sr5 {
    private static int primeFactors(long n) {
        List<Long> factors = new ArrayList<>();
        for (int i = 2; i <= n; i++) { // 1 doesn't count
            while (n % i == 0) { //can have multiple of the same prime factor
                if (!factors.contains((long) i)) { //no duplicates
                    factors.add((long) i);
                }
                n /= i;
            }
        }
        return factors.size();
    }

    private static String transform(long n, int p) {
        StringBuilder result = new StringBuilder();
        String num = Long.toString(n);
        int indexNum = Integer.parseInt(Character.toString(num.charAt(num.length() - p)));
        for (int i = 0; i < num.length() - p; i++) {
            int x = Integer.parseInt(Character.toString(num.charAt(i)));
            result.append((x + indexNum));
        }
        result.append(primeFactors(n));
        for (int i = num.length() - p + 1; i < num.length(); i++) {
            result.append(Math.abs(Integer.parseInt(Character.toString(num.charAt(i))) - indexNum));
        }
        return result.toString();
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("src//ACSL1Senior_Input.txt")).useDelimiter("\n");
        for (long i = 0; i < 1; i++) {
            String line = sc.next();
            long n = Long.parseLong(line.substring(0, line.indexOf(" ")));
            int p = Integer.parseInt(line.substring(line.indexOf(" ")).replaceAll("[^0-9]", ""));
            System.out.println(transform(n, p));
        }
        sc.close();
    }
}
