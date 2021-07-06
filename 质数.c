#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void) {
//	int i, n, remain;
//	i = 2;
//	char q;
//	printf("这是一个判断你所输入的整数是否为质数的程序。\n");
//	do {
//		printf("请输入一个整数\n");
//		scanf("%d", &n);
//		while (i < n) {
//			remain = n % i;
//			if (remain == 0) {
//				break;	//TODO
//			}	//TODO
//			else i++;
//		}
//		if (i < n) {
//			printf("%d是一个合数，它的其中一个质因子是%d\n", n, i);	//TODO
//		} else printf("%d是一个质数\n", n);
//		printf("请问是否要继续？若要继续，请输入y，否则输入n。\n");
//		fflush(stdin);
//		scanf("%c", &q);
//	} while (q == 'y');                      这是我写的老程序

//下面是老师给的程序
	int i, m = 3, k, count = 0;
	for (m = 3; m <= 1000; m += 2) {
		k = (int)(sqrt(m));			//从2到根号m就好。
		for (i = 2; i <= k; i++) {
			if (m % i == 0) {
				break;	//TODO
			}	//TODO
			//我猜测是for里面不能用int
		}
		if (i == k + 1) {
			printf("%5d ", m);
			count++;
			if (count % 10 == 0) {
				printf("\n");	//TODO
			}//TODO
		}
	}

	system("pause");
	return 0;
}
