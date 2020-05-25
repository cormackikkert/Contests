/*
ID: cormac.1
TASK: maze1
LANG: JAVA
 */

import java.io.*;
import java.util.*;
import java.lang.*;

public class maze1 {
    static int W;
    static int H;
    static char[][] maze;

    static Map<Integer, Integer> cost = new HashMap<>();

    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("maze1.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new PrintWriter("maze1.out")));

        StringTokenizer s = new StringTokenizer(fin.readLine());
        W = Integer.parseInt(s.nextToken());
        H = Integer.parseInt(s.nextToken());

        maze = new char[2*H+1][2*W+1];
        for (int y = 0; y < 2 * H + 1; ++y) {
            char[] line = fin.readLine().toCharArray();
            for (int x = 0; x < 2 * W + 1; ++x) {
                maze[y][x] = line[x];
            }
        }

        for (int x = 0; x < W; ++x) {
            if (maze[0][2*x+1] == ' ') {
                BFS(XYToIndex(x, 0));
            }
            if (maze[2*H][2*x+1] == ' ') {
                BFS(XYToIndex(x, H-1));
            }
        }

        for (int y = 0; y < H; ++y) {
            if (maze[2*y+1][0] == ' ') {
                BFS(XYToIndex(0, y));
            }
            if (maze[2*y+1][2*W] == ' ') {
                BFS(XYToIndex(W-1, y));
            }
        }
        int maxCost = 0;
        for (Integer x : cost.values()) {
            maxCost = Math.max(x, maxCost);
        }
        fout.println(maxCost);
        fout.close();
    }

    public static void BFS(int index) {
        HashSet<Integer> seen = new HashSet<>();
        Queue<Integer> queue = new LinkedList<>();


        queue.add(index);
        cost.put(index, 1);

        while (!queue.isEmpty()) {
            Integer point = queue.remove();
            int x = indexToX(point);
            int y = indexToY(point);
            for (int[] deltas : new int[][] {{-1, 0}, {1, 0}, {0, 1}, {0, -1}}) {
                if (!(0 <= x + deltas[0] && x + deltas[0] < W && 0 <= y + deltas[1] && y + deltas[1] < H)) continue;
                if (maze[2*y+1+deltas[1]][2*x+1+deltas[0]] == ' ') {
                    Integer newPoint = XYToIndex(x + deltas[0], y+deltas[1]);
                    if (!seen.contains(newPoint)) {
                        seen.add(newPoint);
                        queue.add(newPoint);
                        if (cost.containsKey(newPoint)) {
                            cost.put(newPoint, Math.min(cost.get(newPoint), 1 + cost.get(point)));
                        } else {
                            cost.put(newPoint, cost.get(point) + 1);
                        }
                    }
                }
            }
        }

    }

    public static int indexToX(int index) {
        return index % W;
    }

    public static int indexToY(int index) {
        return index / W;
    }

    public static int XYToIndex(int x, int y) {
        return y * W + x;
    }
}
