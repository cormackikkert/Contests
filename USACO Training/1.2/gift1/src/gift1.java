/*
ID: cormac.1
LANG: JAVA
TASK: gift1
 */

import java.io.*;
import java.util.*;
import java.lang.*;

public class gift1 {
    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new FileReader("gift1.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("gift1.out")));
        StringTokenizer s;

        Map<String, Integer> money = new HashMap<>();
        s = new StringTokenizer(f.readLine());

        final int NP = Integer.parseInt(s.nextToken());

        String[] names = new String[NP];

        for (int i = 0; i < NP; i++) {
            s = new StringTokenizer(f.readLine());
            String name = s.nextToken();
            money.put(name, 0);
            names[i] = name;
        }

        while (true) {
            String line = f.readLine();
            if (line == null) {
                break;
            }
            s = new StringTokenizer(line);
            String giver = s.nextToken();
            s = new StringTokenizer(f.readLine());

            int moneyToDivide = Integer.parseInt(s.nextToken());
            int numberToDivide = Integer.parseInt(s.nextToken());

            if (numberToDivide != 0) {
                money.put(giver, money.get(giver) - numberToDivide * (moneyToDivide / numberToDivide));
                for (int i = 0; i < numberToDivide; i++) {
                    s = new StringTokenizer(f.readLine());
                    String reciever = s.nextToken();
                    money.put(reciever, money.get(reciever) + moneyToDivide / numberToDivide);
                }
            }
        }

        for (int i = 0; i < NP; i++) {
            out.println(names[i] + " " + money.get(names[i]));
        }
        out.close();
    }
}
