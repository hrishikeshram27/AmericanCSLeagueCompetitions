// Hrishikesh Ram
// Senior Contest 3 2020
// Enloe High School
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class RamH_ACSL3_sr {
    // order of priority
    // 8 adjacent 1s is 1 variable, order B to D to ~B to A to C to ~A to ~D to ~C
    // 4 adjacent is the and of 2 variables --> priority rows (b/~b and d/~d), columns (a/~a and c/~c), then blocks of 4 in corners (like A~B)
    // like B~C, 2 on either end
    // 4 corners is ~C~D
    // 2 adjacent 1s, top to bottom left to right, horizontal then vertical
    // 1 on either end, like B~C~D
    // single 1s, 4 variable terms

    private static int[][] transpose4(int[][] grid) {
        int[][] transposed = new int[4][4];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                transposed[j][i] = grid[i][j];
            }
        }
        return transposed;
    }

    private static int[][] hexToGrid(String input) {
        String[] hexRows = input.split("");
        int[][] grid = new int[4][4];
        for (int i = 0; i < 4; i++) {
            String[] row = String.format("%4s", Integer.toBinaryString(Integer.parseInt(hexRows[i], 16))).replace(' ', '0').split("");
            for (int j = 0; j < 4; j++) {
                grid[i][j] = Integer.parseInt(row[j]);
            }
        }
        return grid;
    }

    private static String gridToBool(int[][] grid) {
        String bool = "";
        // check for 8 - need to remove the 1s if 8 is found
        for (int i = 0; i < 3; i++) { // top to bottom rows
            if (Arrays.equals(grid[i], new int[]{1, 1, 1, 1}) && Arrays.equals(grid[i + 1], new int[]{1, 1, 1, 1})) {
                if (i == 0) {
                    bool += "B+";
                    for (int x = 0; x < 2; x++) {
                        for (int y = 0; y < 4; y++) {
                            grid[x][y] = 0;
                        }
                    }
                } else if (i == 1) {
                    bool += "D+";
                    for (int x = 1; x < 3; x++) {
                        for (int y = 0; y < 4; y++) {
                            grid[x][y] = 0;
                        }
                    }
                } else {
                    bool += "~B+";
                    for (int x = 2; x < 4; x++) {
                        for (int y = 0; y < 4; y++) {
                            grid[x][y] = 0;
                        }
                    }
                }
            } else if (Arrays.equals(transpose4(grid)[i], new int[]{1, 1, 1, 1}) && Arrays.equals(transpose4(grid)[i + 1], new int[]{1, 1, 1, 1})) {
                if (i == 0) {
                    bool += "A+";
                    for (int x = 0; x < 4; x++) {
                        for (int y = 0; y < 2; y++) {
                            grid[x][y] = 0;
                        }
                    }
                } else if (i == 1) {
                    bool += "C+";
                    for (int x = 0; x < 4; x++) {
                        for (int y = 1; y < 3; y++) {
                            grid[x][y] = 0;
                        }
                    }
                } else {
                    bool += "~A+";
                    for (int x = 0; x < 4; x++) {
                        for (int y = 2; y < 4; y++) {
                            grid[x][y] = 0;
                        }
                    }
                }
            }
        }
        // end checking for 8

        //check for 4 adjacent: rows, then columns, then blocks
        for (int i = 0; i < 4; i++) {
            if (Arrays.equals(grid[i], new int[]{1, 1, 1, 1})) { // rows
                if (i == 0) {
                    bool += "B~D";
                } else if (i == 1) {
                    bool += "BD";
                } else if (i == 2) {
                    bool += "~BD";
                } else {
                    bool += "~B~D";
                }
                bool += "+";
                grid[i] = new int[]{0, 0, 0, 0};
            }
        }
        for (int i = 0; i < 4; i++) {
            if (Arrays.equals(transpose4(grid)[i], new int[]{1, 1, 1, 1})) { // columns
                if (i == 0) {
                    bool += "A~C";
                } else if (i == 1) {
                    bool += "AC";
                } else if (i == 2) {
                    bool += "~AC";
                } else {
                    bool += "~A~C";
                }
                bool += "+";
                for (int x = 0; x < 4; x++) {
                    grid[x][i] = 0;
                }
            }
        }
        if (grid[0][0] == 1 && grid[0][1] == 1 && grid[1][0] == 1 && grid[1][1] == 1) {
            bool += "AB+";
            grid[0][0] = grid[0][1] = grid[1][0] = grid[1][1] = 0;
        } else if (grid[0][1] == 1 && grid[0][2] == 1 && grid[1][1] == 1 && grid[1][2] == 1) {
            bool += "BC+";
            grid[0][1] = grid[0][2] = grid[1][1] = grid[1][2] = 0;
        } else if (grid[0][2] == 1 && grid[0][3] == 1 && grid[1][2] == 1 && grid[1][3] == 1) {
            bool += "~AB+";
            grid[0][2] = grid[0][3] = grid[1][2] = grid[1][3] = 0;
        } else if (grid[1][0] == 1 && grid[1][1] == 1 && grid[2][0] == 1 && grid[2][1] == 1) {
            bool += "AD+";
            grid[1][0] = grid[1][1] = grid[2][0] = grid[2][1] = 0;
        } else if (grid[1][1] == 1 && grid[1][2] == 1 && grid[2][1] == 1 && grid[2][2] == 1) {
            bool += "CD+";
            grid[1][1] = grid[1][2] = grid[2][1] = grid[2][2] = 0;
        } else if (grid[1][2] == 1 && grid[1][3] == 1 && grid[2][2] == 1 && grid[2][3] == 1) {
            bool += "~AD+";
            grid[1][2] = grid[1][3] = grid[2][2] = grid[2][3] = 0;
        } else if (grid[2][0] == 1 && grid[2][1] == 1 && grid[3][0] == 1 && grid[3][1] == 1) {
            bool += "A~B+";
            grid[2][0] = grid[2][1] = grid[3][0] = grid[3][1] = 0;
        } else if (grid[2][1] == 1 && grid[2][2] == 1 && grid[3][1] == 1 && grid[3][2] == 1) {
            bool += "~BC+";
            grid[2][1] = grid[2][2] = grid[3][1] = grid[3][2] = 0;
        } else if (grid[2][2] == 1 && grid[2][3] == 1 && grid[3][2] == 1 && grid[3][3] == 1) {
            bool += "~A~B+";
            grid[2][2] = grid[2][3] = grid[3][2] = grid[3][3] = 0;
        } else if (grid[0][0] == 1 && grid[0][1] == 1 && grid[3][0] == 1 && grid[3][1] == 1) { // end rows
            bool += "A~D+";
            grid[0][0] = grid[0][1] = grid[3][0] = grid[3][1] = 0;
        } else if (grid[0][1] == 1 && grid[0][2] == 1 && grid[3][1] == 1 && grid[3][2] == 1) {
            bool += "C~D+";
            grid[0][1] = grid[0][2] = grid[3][1] = grid[3][2] = 0;
        } else if (grid[0][2] == 1 && grid[0][3] == 1 && grid[3][2] == 1 && grid[3][3] == 1) {
            bool += "~A~D+";
            grid[0][2] = grid[0][3] = grid[3][2] = grid[3][3] = 0;
        } else if (grid[0][0] == 1 && grid[1][0] == 1 && grid[0][3] == 1 && grid[1][3] == 1) { // end columns
            bool += "B~C+";
            grid[0][0] = grid[1][0] = grid[0][3] = grid[1][3] = 0;
        } else if (grid[1][0] == 1 && grid[2][0] == 1 && grid[1][3] == 1 && grid[2][3] == 1) {
            bool += "~CD+";
            grid[1][0] = grid[2][0] = grid[1][3] = grid[2][3] = 0;
        } else if (grid[2][0] == 1 && grid[3][0] == 1 && grid[2][3] == 1 && grid[3][3] == 1) {
            bool += "~B~C+";
            grid[2][0] = grid[3][0] = grid[2][3] = grid[3][3] = 0;
        } else if (grid[0][0] == 1 && grid[3][0] == 1 && grid[0][3] == 1 & grid[3][3] == 1) {
            bool += "~C~D+";
            grid[0][0] = grid[3][0] = grid[0][3] = grid[3][3] = 0;
        } // end checking for 4

        // check for 2
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] == 1 && grid[i][j + 1] == 1) {
                    if (i == 0) {
                        if (j == 0) {
                            bool += "AB~D+";
                        } else if (j == 1) {
                            bool += "BC~D+";
                        } else {
                            bool += "~AB~D+";
                        }
                    } else if (i == 1) {
                        if (j == 0) {
                            bool += "ABD+";
                        } else if (j == 1) {
                            bool += "BCD+";
                        } else {
                            bool += "~ABD+";
                        }
                    } else if (i == 2) {
                        if (j == 0) {
                            bool += "A~BD+";
                        } else if (j == 1) {
                            bool += "~BCD+";
                        } else {
                            bool += "~A~BD+";
                        }
                    } else {
                        if (j == 0) {
                            bool += "A~B~D+";
                        } else if (j == 1) {
                            bool += "~BC~D+";
                        } else {
                            bool += "~A~B~D+";
                        }
                    }
                    grid[i][j] = grid[i][j + 1] = 0;
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if (transpose4(grid)[i][j] == 1 && transpose4(grid)[i][j + 1] == 1) {
                    if (i == 0) {
                        if (j == 0) {
                            bool += "AB~C+";
                        } else if (j == 1) {
                            bool += "A~CD+";
                        } else {
                            bool += "A~B~C+";
                        }
                    } else if (i == 1) {
                        if (j == 0) {
                            bool += "ABC+";
                        } else if (j == 1) {
                            bool += "ACD+";
                        } else {
                            bool += "A~BC+";
                        }
                    } else if (i == 2) {
                        if (j == 0) {
                            bool += "~ABC+";
                        } else if (j == 1) {
                            bool += "~ACD+";
                        } else {
                            bool += "~A~BC+";
                        }
                    } else {
                        if (j == 0) {
                            bool += "~AB~C+";
                        } else if (j == 1) {
                            bool += "~A~CD+";
                        } else {
                            bool += "~A~B~C+";
                        }
                    }
                    grid[j][i] = grid[j + 1][i] = 0;
                }
            }
        }
        for (int x = 0; x < 4; x++) {
            if (grid[0][x] == 1 && grid[3][x] == 1) { // end column adjacent 2
                if (x == 0) {
                    bool += "A~C~D+";
                } else if (x == 1) {
                    bool += "AC~D+";
                } else if (x == 2) {
                    bool += "~AC~D+";
                } else {
                    bool += "~A~C~D+";
                }
                grid[x][0] = grid[x][3] = 0;
            }
        }
        for (int x = 0; x < 4; x++) {
            if (grid[x][0] == 1 && grid[x][3] == 1) { // end row adjacent 2
                if (x == 0) {
                    bool += "B~C~D+";
                } else if (x == 1) {
                    bool += "B~CD+";
                } else if (x == 2) {
                    bool += "~B~CD+";
                } else {
                    bool += "~B~C~D+";
                }
                grid[x][0] = grid[x][3] = 0;
            }
        }
        // end checking for 2

        //check for 1
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (grid[i][j] == 1) {
                    if (i == 0) { // row of B~D
                        if (j == 0) {
                            bool += "AB~C~D+";
                        } else if (j == 1) {
                            bool += "ABC~D+";
                        } else if (j == 2) {
                            bool += "~ABC~D+";
                        } else {
                            bool += "~AB~C~D+";
                        }
                    } else if (i == 1) {
                        if (j == 0) {
                            bool += "AB~CD+";
                        } else if (j == 1) {
                            bool += "ABCD+";
                        } else if (j == 2) {
                            bool += "~ABCD+";
                        } else {
                            bool += "~AB~CD+";
                        }
                    } else if (i == 2) {
                        if (j == 0) {
                            bool += "A~B~CD+";
                        } else if (j == 1) {
                            bool += "A~BCD+";
                        } else if (j == 2) {
                            bool += "~A~BCD+";
                        } else {
                            bool += "~A~B~CD+";
                        }
                    } else {
                        if (j == 0) {
                            bool += "A~B~C~D+";
                        } else if (j == 1) {
                            bool += "A~BC~D+";
                        } else if (j == 2) {
                            bool += "~A~BC~D+";
                        } else {
                            bool += "~A~B~C~D+";
                        }
                    }
                    grid[i][j] = 0;
                }
            }
        } // end checking 1

        return bool.substring(0, bool.length() - 1);  // removes the last + sign
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("D:\\ACSL3\\3sr.txt")).useDelimiter("\n");
        for (int j = 0; j < 5; j++) {
            System.out.println(gridToBool(hexToGrid(sc.next().strip())));
        }
    }
}
