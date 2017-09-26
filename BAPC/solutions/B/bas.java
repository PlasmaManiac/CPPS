// Solution to Bad Signal
// Author: Bas den Heijer

// @EXPECTED_RESULTS@: CORRECT

import java.awt.geom.Point2D;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class bas {

	static Scanner in = new Scanner(System.in);

	public static void main(String[] args) throws FileNotFoundException {
		int n = in.nextInt();
		for (int i=0;i<n;i++)
			doShizzle();
	}

	private static void doShizzle() {
		int micCount = in.nextInt();
		long noise = in.nextInt();
		Point2D.Double listen = new Point2D.Double(in.nextInt(), in.nextInt());
		Point2D.Double[] mic = new Point2D.Double[micCount];
		double[] micStrength = new double[micCount];
		
		double supersum = 0;
		
		for (int i=0;i<micCount;i++) {
			mic[i] = new Point2D.Double(in.nextInt(), in.nextInt());
			micStrength[i] = in.nextInt();
			
			supersum += micStrength[i] / listen.distanceSq(mic[i]);
		}
		
		for (int i=0;i<micCount;i++) {
			double myStrength = micStrength[i] / listen.distanceSq(mic[i]);
			if (Math.abs(myStrength - 6*(noise + supersum - myStrength)) < 1e-6) {
				System.out.print("!Too close: "+(i+1)+", ");
			}
			if (myStrength > 6*(noise + supersum - myStrength)) {
				System.out.println(i+1);
				return;
			}
		}
		
		System.out.println("NOISE");
	}
}
