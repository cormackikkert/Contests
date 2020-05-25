/*
ID: cormac.1
LANG: JAVA
TASK: friday
 */

import java.io.*;
import java.util.*;

public class friday {
    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new FileReader("friday.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("friday.out")));

        StringTokenizer s = new StringTokenizer(f.readLine());

        int years = Integer.parseInt(s.nextToken());
        // M T W T F S S
        int[] answers = {0, 0, 0, 0, 0, 0, 0};
        int startOfMonth = 0;

        for (int year = 1900; year < 1900 + years; year++) {
            boolean isLeapYear = (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
            for (int month = 1; month <= 12; month ++) {
                answers[(startOfMonth + 12) % 7]++;
                int days = daysOfMonth(isLeapYear, month);
                startOfMonth = (startOfMonth + days) % 7;
            }
        }

        out.println(answers[5] + " " + answers[6] + " " + answers[0] + " " + answers[1] + " " + answers[2] + " " + answers[3] + " " + answers[4]);

        out.close();
    }

    public static int daysOfMonth(boolean isLeapYear, int month) {
        if (month == 2) {
            return (isLeapYear) ? 29 : 28;
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            return 30;
        } else {
            return 31;
        }
    }
}
