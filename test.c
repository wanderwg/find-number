#include<stdio.h>
#include<stdlib.h>
void Find_num(int arr[], int size) {
	int ret = 0;//用来存放整个数组元素异或后的值
	int sign = 0;//标记ret结果中第一个为1的位置
	int x = 0;
	int y = 0;//x,y为所求数组中只出现一次的两个数
	for (int i = 0; i < size; ++i) {
		ret ^= arr[i];
	}
	for (int i = 0; i < 32; ++i) {
		if ((ret&(1 << i)) == 1) {
			sign = i;//sign即为ret中第一个为1的位置
			break;
		}
	}
	for (int i = 0; i < size; ++i) {
		if ((arr[i] & (1 << sign))== 1) {
			x ^= arr[i];   //用x y将数组中元素分为两组，再进行异或运算
		}
		else {
			y ^= arr[i];
		}
	}
	printf("%d,%d\n",x,y);
}
int main() {
	int arr[] = { 2,7,4,1,7,5,2,1,5,9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	Find_num(arr, size);
	system("pause");
	return 0;
}

