#include <cstdio>
#include <cstring>

using namespace std;

int main(){
	int A,B;
	scanf("%d %d",&A, &B);

	if(A>8 || B>8){
		printf(":(");
	}
	else{
		printf("Yay!");
	}
	return 0;
}
/*
import java.io.*;
import java.util.*;
import java.lang.*;

class Main {
	public static void main(String[] args) throws Exception {
		Vector <Integer> in = new Vector<Integer>();
		Vector <Item> vec = new Vector<Item>();
		Scanner scn = new Scanner(System.in);
		// Scanner scn = new Scanner("1 2 3 4 5 6 4 5 3\n");
		int t=0;
		int minI=0;
		boolean hasRemoved = false, hasItem = false;
		while (true){
			if(scn.hasNextInt()){
				in.add(scn.nextInt());
			}
			else
				break;
		}
		for(int j=0; j<in.size(); j++){
			// System.out.printf("%d ",vec.get(i));
			int nextin = in.get(j);
			// System.out.printf("nextin = %d \n",nextin);
			if(vec.size() < 3){
				// System.out.printf("vec add = %d %d\n",nextin, t);
				vec.add(new Item(nextin, t));
			}
			else{
				Item it;
				hasItem = false;
				int hasI=0;
				for(int i=0; i<3; i++){
					it = vec.get(i);
					if(it.val == nextin){
						hasItem = true;
						hasI = i;
						break;
					}
				}
				if(hasItem == false){
					int minTime = 9999;
					minI = -1;
					for(int i=0; i<3; i++){
						// System.out.printf("vectime=%d mintime=%d\n", vec.get(i).time, minTime);
						if(vec.get(i).time < minTime){
							minTime = vec.get(i).time;
							minI = i;
						}
						// 가장 오래 된 아이템 찾기
						// 버리기
					}
				Item oldItem = vec.get(minI);
					System.out.println(oldItem.val);
					vec.remove(minI);
					// System.out.printf("remove\n");
					vec.add(new Item(nextin, t));
					hasRemoved = true;
				}
				// System.out.printf("oldest item = %d %d\n",oldItem.val, oldItem.time);
				// 만약 같은 아이템인 경우
				
				else{
					Item dupItem = vec.get(hasI);
					if(dupItem.val == nextin){
						dupItem.time = t;
						vec.remove(minI);
						vec.add(new Item(nextin, t));
						// System.out.printf("time update\n");
						// 시간 갱신
					}
				}
			}
			t++;
		}
		if(hasRemoved == false)
			System.out.println("0");
	}
}

class Item{
	int val;
	int time;
	public Item(int val, int time){
		this.val = val;
		this.time = time;
	}
}
*/
