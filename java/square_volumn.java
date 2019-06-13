/*
N개의 좌표를 입력받아 만들 수 있는 가장 큰 정사각형의 넓이를 출력하는 문제.

5
0 2
2 0
2 2
0 0
1 1

4.00

10
0 0
10 10
89 76
97 79
86 84
94 87
53 14
54 27
40 15
41 28

170.00
*/
import java.util.*;
import java.io.*;
import java.lang.Math;

public class Main {
	public static Scanner scanner = new Scanner(System.in);
	public static int[] x = new int[60], y = new int[60];
	public static void main(String[] args){
		int N = scanner.nextInt();
		
		double max = -1;
		double ans = -1;
		
		for(int i=0; i<N; i++){
			x[i] = scanner.nextInt();
			y[i] = scanner.nextInt();	
		}
		
		for(int i=0; i<N; i++){
			for(int j=i+1; j<N; j++){
				for(int k=j+1; k<N; k++){
					for(int l=k+1; l<N; l++){
						
						int res = isSquare(i, j, k ,l);
						// System.out.println(res);
						if(res == -1)
							continue;
						// 12, 34
						if(res == 1){
							ans = getV(i, k);
						}
						// 13, 24
						else if(res == 2){
							ans = getV(i, l);
						}
						// 14, 23
						else if(res == 3){
							ans = getV(i, j);
						}
						
						if(ans > max)
							max = ans;
						// compare to max
					}
				}
			}
		}
		double answer = Math.round(max*100)/100.0;
		System.out.printf("%.2f",answer);
	}
	
	private static int isSquare(int a, int b, int c, int d){
		
		// 12, 34
		if(((x[a] + x[b]) / 2 == (x[c] + x[d]) / 2) && ((y[a] + y[b]) / 2 == (y[c] + y[d]) / 2)){
			if(getD(a,d) == getD(c,a) && getD(a,b) == getD(c,d)){
				return 1;
			}
		}
		// 13, 24
		else if(((x[a] + x[c]) / 2 == (x[b] + x[d]) / 2) && ((y[a] + y[c]) / 2 == (y[b] + y[d]) / 2)){
			if(getD(a,c) == getD(b,d) && getD(a,b) == getD(a,d)){
				return 2;
			}
		}
		// 14, 23
		else if(((x[a] + x[d]) / 2 == (x[c] + x[b]) / 2) && ((y[a] + y[d]) / 2 == (y[c] + y[b]) / 2)){
			if(getD(a,d) == getD(b,c) && getD(a,b) == getD(a,c)){
				return 3;
			}
		}
		
		return -1;
	}
	private static int getD(int a, int b){
		return ((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
	}
	private static double getV(int a, int b){
		// a, b
		double res;
		int dx = (x[a] - x[b]) * (x[a] - x[b]);
		int dy = (y[a] - y[b]) * (y[a] - y[b]);
		
		res = dx + dy;
		return res;
	}
}