/*
백준 2564 색종이 문제
https://www.acmicpc.net/problem/2563
*/

import java.util.*;
import java.io.*;


public class Main {
	public static Scanner scanner = new Scanner(System.in);
	
  public static void main(String[] args) {
		int T = scanner.nextInt();
		int[][] map = new int[100][100];
		int px, py;
		int cnt=0;
		for(int i=0; i<T; i++){
			int N = scanner.nextInt();
			cnt = 0;
			for(int[] row:map){
				Arrays.fill(row,0);	
			}
			for(int j=0; j<N; j++){
				px = scanner.nextInt();
				py = scanner.nextInt();
				
				for(int x=0; x<10; x++){
					for(int y=0; y<10; y++){
						map[px+x][py+y] = 1;
					}
				}
			}
			
			for(int m=0; m<100; m++){
				for(int n=0; n<100; n++){
					if(map[m][n] == 1)
						cnt++;
				}
			}
			System.out.println(cnt);
		}
  }
}
