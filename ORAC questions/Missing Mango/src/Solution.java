import java.io.*;
import java.lang.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("manin.txt"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("manout.txt")));

        StringTokenizer s = new StringTokenizer(fin.readLine());

        int IX = Integer.parseInt(s.nextToken());
        int CX = Integer.parseInt(s.nextToken());
        int ID = Integer.parseInt(s.nextToken());
        int CD = Integer.parseInt(s.nextToken());

        if (Math.abs(IX + ID - CX) == CD)
            fout.println(IX + ID);
        else
            fout.println(IX - ID);
        fout.close();
    }
}
