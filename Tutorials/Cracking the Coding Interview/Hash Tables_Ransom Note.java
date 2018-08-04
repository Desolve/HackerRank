import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int m = in.nextInt();
        int n = in.nextInt();
        String word;
        boolean solution = true;
        Map<String, Integer> wordsMap = new HashMap<String, Integer>();
        for(int magazine_i=0; magazine_i < m; magazine_i++){
            word = in.next();
            if(wordsMap.containsKey(word))
                wordsMap.put(word, wordsMap.get(word)+1);
            else
                wordsMap.put(word, 1);
        }
        for(int ransom_i=0; ransom_i < n; ransom_i++){
            word = in.next();
            if(wordsMap.containsKey(word) && wordsMap.get(word) != 0){
                wordsMap.put(word, wordsMap.get(word)-1);
            } else {
                solution = false;
                break;
            }                
        }
        if (solution)
            System.out.print("Yes");
        else
            System.out.print("No");
        
    }
}
