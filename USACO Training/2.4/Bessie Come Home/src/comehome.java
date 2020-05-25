/*
ID: cormac.1
TASK: comehome
LANG: JAVA
 */

import java.io.*;
import java.lang.*;
import java.util.*;

public class comehome {
    static Map<Character, Integer> dist = new HashMap<>();
    static Set<Character> toSearch = new HashSet<>();
    static Map<Character, ArrayList<Edge>> neighbours = new HashMap<>();

    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("comehome.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("comehome.out")));

        for (char c : "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ".toCharArray()) {
            dist.put(c, Integer.MAX_VALUE);
            toSearch.add(c);
            neighbours.put(c, new ArrayList<>());
        }

        dist.put('Z', 0);

        StringTokenizer s = new StringTokenizer(fin.readLine());
        int P = Integer.parseInt(s.nextToken());
        for (int i = 0; i < P; ++i) {
            s = new StringTokenizer(fin.readLine());
            char n1 = s.nextToken().charAt(0);
            char n2 = s.nextToken().charAt(0);
            int dist = Integer.parseInt(s.nextToken());
            neighbours.get(n1).add(new Edge(n2, dist));
            neighbours.get(n2).add(new Edge(n1, dist));

        }
        Character current;
        while (true) {
            current = Collections.min(toSearch, new searchComp());
            toSearch.remove(current);

            if ('A' <= current && current < 'Z') {
                break;
            }
            for (Edge e : neighbours.get(current)) {
                if (dist.get(e.node) > dist.get(current) + e.dist) {
                    dist.put(e.node, dist.get(current) + e.dist);
                }
            }
        }
        fout.println(current + " " + dist.get(current));
        fout.close();

    }

    public static class searchComp implements Comparator<Character>
    {
        public int compare(Character c1, Character c2)
        {
            return dist.get(c1) - dist.get(c2);
        }
    }

    public static class Edge {
        Character node;
        Integer dist;
        Edge(char c, int dist) {
            this.node = c;
            this.dist = dist;
        }
    }
}
