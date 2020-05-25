import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    // A utility function that returns maximum of two integers
    static int max(int a, int b) { return (a > b)? a : b; }

    // Returns the maximum value that can be put in a knapsack of capacity W
    static int knapSack(int W, int wt[], int val[], int n, int avoid)
    {
        int i, w;
        int K[][] = new int[n+1][W+1];

        // Build table K[][] in bottom up manner
        for (i = 0; i <= n; i++)
        {
            for (w = 0; w <= W; w++)
            {
                int index;
                if (avoid == -1) {
                    index = i;
                } else {
                    index = (i <= avoid) ? i : i + 1;
                }
                if (i==0 || w==0)
                    K[i][w] = 0;
                else if (wt[index-1] <= w)
                    K[i][w] = max(val[index-1] + K[i-1][w-wt[index-1]],  K[i-1][w]);
                else
                    K[i][w] = K[i-1][w];
            }
        }

        return K[n][W];
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        StringTokenizer s = new StringTokenizer(scan.nextLine());
        int N = Integer.parseInt(s.nextToken());
        int T = Integer.parseInt(s.nextToken());
        int[] val = new int[N];
        int[] wts = new int[N];
        for (int i = 0; i < N; ++i) {
            s = new StringTokenizer(scan.nextLine());
            wts[i] = Integer.parseInt(s.nextToken());
            val[i] = Integer.parseInt(s.nextToken());
        }

        int best = knapSack(T, wts, val, N, -1);
        for (int i = 0; i < N; ++i) {
            best = Math.max(best, knapSack(T-1, wts, val, N-1, i) + val[i]);
        }
        System.out.println(best);
    }
}
