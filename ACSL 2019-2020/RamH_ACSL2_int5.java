// Hrishikesh Ram 01-22-2020
// Enloe High School, Raleigh NC, 11th Grade
// Senior Contest 2
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class RamH_ACSL2_int5 {
    private static int calcASF(String one, String two) {
        //arrays to hold chars
        ArrayList<Character> ones = new ArrayList<Character>();
        for (int i = 0; i < one.length(); i++) {
            ones.add(i, one.charAt(i));
        }
        ArrayList<Character> twos = new ArrayList<Character>();
        for (int i = 0; i < two.length(); i++) {
            twos.add(i, two.charAt(i));
        }

        boolean keepGoing = true;
        while (keepGoing) {
            int shortest = ones.size();
            if (twos.size() < ones.size()) {
                shortest = twos.size();
            }
            // loop through to delete like characters
            for (int i = 0; i < shortest; i++) {
                if (ones.get(i) == twos.get(i)) {
                    ones.set(i, '-');
                    twos.set(i, '-');
                }
            }
            ones.removeAll(Collections.singleton('-'));
            twos.removeAll(Collections.singleton('-'));

            // reset shortest after deletion
            shortest = ones.size();
            if (twos.size() < ones.size()) {
                shortest = twos.size();
            }

            //deleting one char in one string to shift to left and match up letters - check both first, then individual NAPE ANTI
            for (int i = 0; i < shortest - 1; i++) {
                if (ones.get(i + 1) == twos.get(i) && twos.get(i + 1) == ones.get(i) && !ones.contains('-') && !twos.contains('-')) {
                    twos.set(i, '-');
                } else if (ones.get(i + 1) == twos.get(i) && !ones.contains('-') && !twos.contains('-')) {
                    ones.set(i, '-');
                } else if (twos.get(i + 1) == ones.get(i) && !ones.contains('-') && !twos.contains('-')) {
                    twos.set(i, '-');
                }
            }

            if (!ones.contains('-') && !twos.contains('-')) {
                keepGoing = false;
            } else {
                ones.removeAll(Collections.singleton('-'));
                twos.removeAll(Collections.singleton('-'));
            }
        }

        int ASF = 0;
        int shortest = ones.size();
        int longest = twos.size();
        if (twos.size() < ones.size()) {
            shortest = twos.size();
            longest = ones.size();
        }
        for (int i = 0; i < shortest; i++) {
            ASF += (ones.get(i) - twos.get(i));
        }
        for (int i = shortest; i < longest; i++) {
            ASF++;
        }
        return ASF;
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("D://ACSL 2//2inttest.txt")).useDelimiter("\n");
        for (int i = 0; i < 5; i++) {
            String line = sc.next();
            String one = line.substring(0, line.indexOf(" ")).strip();
            String two = line.substring(line.indexOf(" ") + 1).strip();
            System.out.println(calcASF(one, two));
        }
    }
}
