import java.io.*;
public class ScaryProblem {
    public static void main(String[] args) 
            throws Exception {
        System.setOut(new PrintStream(
                new BufferedOutputStream(
                new FileOutputStream(
                "LOCATION")), true));
}}