#include<stdio.h>
#include<stdlib.h>
void Find_num(int arr[], int size) {
	int ret = 0;//���������������Ԫ�������ֵ
	int sign = 0;//���ret����е�һ��Ϊ1��λ��
	int x = 0;
	int y = 0;//x,yΪ����������ֻ����һ�ε�������
	for (int i = 0; i < size; ++i) {
		ret ^= arr[i];
	}
	for (int i = 0; i < 32; ++i) {
		if ((ret&(1 << i)) == 1) {
			sign = i;//sign��Ϊret�е�һ��Ϊ1��λ��
			break;
		}
	}
	for (int i = 0; i < size; ++i) {
		if ((arr[i] & (1 << sign))== 1) {
			x ^= arr[i];   //��x y��������Ԫ�ط�Ϊ���飬�ٽ����������
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

