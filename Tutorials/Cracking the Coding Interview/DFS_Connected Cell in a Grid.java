import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    
    public static int getBiggestRegion(int[][] matrix) {
        int max = 0;
        for (int i = 0; i < matrix.length; i++){
            for (int j = 0; j < matrix[0].length; j++){
                if(matrix[i][j] == 1)
                    max = Math.max(max, cnt(matrix, i, j));
            }
        }
        return max;
    }
    private static int cnt(int[][] matrix, int i, int j){
		if (i < 0 || j < 0 || i >= matrix.length || j >= matrix[0].length) return 0;
		if (matrix[i][j] == 0) return 0;
		matrix[i][j]--;
		return 1+cnt(matrix, i+1, j)+
		+ cnt(matrix, i + 1, j)
        + cnt(matrix, i - 1, j)
        + cnt(matrix, i, j + 1)
        + cnt(matrix, i, j - 1)
        + cnt(matrix, i + 1, j + 1)
        + cnt(matrix, i - 1, j - 1)
        + cnt(matrix, i - 1, j + 1)
        + cnt(matrix, i + 1, j - 1);
	}
    
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int grid[][] = new int[n][m];
        for(int grid_i=0; grid_i < n; grid_i++){
            for(int grid_j=0; grid_j < m; grid_j++){
                grid[grid_i][grid_j] = in.nextInt();
            }
        }
        System.out.println(getBiggestRegion(grid));
    }
}
