/*
두 좌표를 입력받아 점, 선분, 정사각형, 직사각형 판별하는 문제
*/
import java.util.*;
import java.io.*;

/* [Notice for Java]
 * - 기본 제공되는 뼈대 코드는 입출력의 이해를 돕기위해 제공되었습니다.
 * - 뼈대코드의 활용은 선택사항이며 코드를 직접 작성하여도 무관합니다.
 * 
 * - 별도의 병렬 처리나 시스템콜, 네트워크/파일접근 등을 하지 마세요 
 * - 입출력의 양이 많은 문제는 BufferedReader와 BufferedWriter를 사용하면 시간을 단축할 수 있습니다.
 * - 클래스 이름은 항상 Main이어야 합니다. 주의하세요.
 * - 모든 입력과 출력은 System.in과 System.out 스트림을 이용해야 합니다.
 */

public class Main{

    //표준입력을 수행할 Scanner를 선언한다 
    public static Scanner scanner = new Scanner(System.in);


    public static void main(String[] args){   //프로그램의 시작부 
			//첫 번째 점 P의 좌표 
			int px = scanner.nextInt();
			int py = scanner.nextInt();
			//두 번째 점 Q의 좌표 
			int qx = scanner.nextInt();
			int qy = scanner.nextInt();

			if(px == qx && py == qy){
				System.out.println("DOT");
			}
			else if((px == qx && py != qy) || (px != qx && py == qy)){
				System.out.println("SEGMENT");
			}
			else if(qx - px == qy - py){
				System.out.println("SQUARE");
			}
			else{
				System.out.println("RECTANGLE");
			}
    }
}