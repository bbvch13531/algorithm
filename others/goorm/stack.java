/*
https://level.goorm.io/exam/43218/%EC%8A%A4%ED%83%9D-stack/quiz/1
스택에 push, pop하고 출력하는 문제.
*/
import java.io.*;
import java.util.*;
import java.lang.Math;

class Main {
	public static Scanner scanner = new Scanner(System.in);
	public static void main(String[] args) throws Exception {
		Stack<Integer> stk = new Stack<>();
		int []arr = new int[10];
		int N = scanner.nextInt();
		int data, cnt=0;
		
		for(int i=0; i<N; i++){
			int opt = scanner.nextInt();
			
			if(opt == 0){
				data = scanner.nextInt();
				if(cnt == 10){
					System.out.println("overflow");
				}
				else{
					stk.push(data);
					cnt++;
				}
			}
			else if(opt == 1){
				if(cnt == 0){
					System.out.println("underflow");
				}
				else{
					stk.pop();
					cnt--;
				}
			}
			else{
				break;
			}
		}
		
		int len = 0;
		while(!stk.empty()){
			int peek = stk.peek();
			arr[len] = peek;
			len++;
			stk.pop();
		}
		for(int i=0; i<len; i++){
			System.out.printf("%d ", arr[len-i-1]);
		}
	}
}