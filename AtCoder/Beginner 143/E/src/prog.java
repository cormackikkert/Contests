import java.util.*;
import java.io.*;
import java.lang.*;

public class prog {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        StringTokenizer s = new StringTokenizer(scan.nextLine());
        int N = Integer.parseInt(s.nextToken());
        int M = Integer.parseInt(s.nextToken());
        int L = Integer.parseInt(s.nextToken());

        long[][] edges = new long[N][N];
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                edges[i][j] = Integer.MAX_VALUE;

        for (int i = 0; i < M; ++i) {
            s = new StringTokenizer(scan.nextLine());
            int A = Integer.parseInt(s.nextToken()) - 1;
            int B = Integer.parseInt(s.nextToken()) - 1;
            int C = Integer.parseInt(s.nextToken());
            edges[A][B] = C;
            edges[B][A] = C;
        }

        for (int k = 0; k < N; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    edges[i][j] = Math.min(edges[i][j], edges[i][k] + edges[k][j]);
                }
            }
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                edges[i][j] = (edges[i][j] <= L) ? 0 : Integer.MAX_VALUE;
            }
        }


        for (int k = 0; k < N; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    edges[i][j] = Math.min(edges[i][j], edges[i][k] + edges[k][j] + 1);
                }
            }
        }

        int Q = Integer.parseInt(scan.nextLine());
        for (int i = 0; i < Q; ++i) {
            s = new StringTokenizer(scan.nextLine());
            int S = Integer.parseInt(s.nextToken()) - 1;
            int T = Integer.parseInt(s.nextToken()) - 1;

            if (edges[S][T] < Integer.MAX_VALUE)
                System.out.println(edges[S][T]);
            else
                System.out.println(-1);
        }
    }
}
