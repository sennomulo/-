#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void) {
//	int i, n, remain;
//	i = 2;
//	char q;
//	printf("����һ���ж���������������Ƿ�Ϊ�����ĳ���\n");
//	do {
//		printf("������һ������\n");
//		scanf("%d", &n);
//		while (i < n) {
//			remain = n % i;
//			if (remain == 0) {
//				break;	//TODO
//			}	//TODO
//			else i++;
//		}
//		if (i < n) {
//			printf("%d��һ����������������һ����������%d\n", n, i);	//TODO
//		} else printf("%d��һ������\n", n);
//		printf("�����Ƿ�Ҫ��������Ҫ������������y����������n��\n");
//		fflush(stdin);
//		scanf("%c", &q);
//	} while (q == 'y');                      ������д���ϳ���

//��������ʦ���ĳ���
	int i, m = 3, k, count = 0;
	for (m = 3; m <= 1000; m += 2) {
		k = (int)(sqrt(m));			//��2������m�ͺá�
		for (i = 2; i <= k; i++) {
			if (m % i == 0) {
				break;	//TODO
			}	//TODO
			//�Ҳ²���for���治����int
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
