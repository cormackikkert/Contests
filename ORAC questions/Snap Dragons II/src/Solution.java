import java.io.*;
import java.util.*;
import java.lang.*;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("snapin.txt"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("snapout.txt")));

        StringTokenizer s = new StringTokenizer(fin.readLine());
        int R = Integer.parseInt(s.nextToken());
        int C = Integer.parseInt(s.nextToken());
        int rRose = Integer.parseInt(s.nextToken());
        int cRose = Integer.parseInt(s.nextToken());
        int rScarlet = Integer.parseInt(s.nextToken());
        int cScarlet = Integer.parseInt(s.nextToken());

        if ((Math.abs(rRose - rScarlet) + Math.abs(cRose - cScarlet)) % 2 == 0)
            fout.println("SCARLET");
        else
            fout.println("ROSE");
        fout.close();
    }
}
