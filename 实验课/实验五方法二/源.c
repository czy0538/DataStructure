#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
struct student
{
	int number;
	char name[9];
	int score;
};
int PartitionNumber(struct student stu[], int low, int high)
{//��ѧ�ſ��� 
	int pivotkey = stu[1].number;
	while (low < high)
	{
		while (low < high && stu[high].number >= pivotkey)
			high--;
		struct student temp = stu[high];
		stu[high] = stu[low];
		stu[low] = temp;
		while (low < high && stu[low].number <= pivotkey)
			low++;
		temp = stu[high];
		stu[high] = stu[low];
		stu[low] = temp;
	}
	return low;
}
void BubbleSort(struct student stu[], int n)
{//�����ƽ���ð������ 
	for (int i = 1; i <= n - 1; i++)
	{//����n-1��
		bool noswap = true;
		for (int j = 1; j <= n - i; j++)
		{//ͨ��������ÿ�˰ѵ�ǰ����������ֵ�����ֵ�ƶ��ײ�
			if (strcmp(stu[j].name, stu[j + 1].name) > 0)
			{
				struct student temp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
				noswap = false;
			}
		}
		if (noswap)
			break;
	}
}
int PartitionScore(struct student stu[], int low, int high)
{//�Գɼ����� 
	int pivotkey = stu[1].score;
	while (low < high)
	{
		while (low < high && stu[high].score >= pivotkey)
			high--;
		struct student temp = stu[high];
		stu[high] = stu[low];
		stu[low] = temp;
		while (low < high && stu[low].score <= pivotkey)
			low++;
		temp = stu[high];
		stu[high] = stu[low];
		stu[low] = temp;
	}
	return low;
}
void quickSort(struct student stu[], int low, int high, int c)
{
	int i;
	if (low < high)
	{
		if (c == 1)
			i = PartitionNumber(stu, low, high);
		if (c == 3)
			i = PartitionScore(stu, low, high);
		quickSort(stu, low, i - 1, c);
		quickSort(stu, i + 1, high, c);
	}
}

int main()
{
	int n, c;
	scanf("%d%d", &n, &c);
	struct student stu[n + 1];
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %s %d", &stu[i].number, &stu[i].name, &stu[i].score);
	}
	if (c == 1)
		quickSort(stu, 1, n, 1);
	if (c == 2)
	{
		BubbleSort(stu, n);
		for (int i = 1; i <= n; i++)
		{//������һ��ʱ����ѧ���������� 
			if (strcmp(stu[i].name, stu[i + 1].name) == 0)
				if (stu[i].number > stu[i + 1].number)
				{
					struct student temp = stu[i];
					stu[i] = stu[i + 1];
					stu[i + 1] = temp;
				}
		}
	}
	if (c == 3)
	{
		quickSort(stu, 1, n, 3);
		for (int i = 1; i <= n; i++)
		{//���ɼ�һ��ʱ����ѧ���������� 
			if (stu[i].score == stu[i + 1].score)
				if (stu[i].number > stu[i + 1].number)
				{
					struct student temp = stu[i];
					stu[i] = stu[i + 1];
					stu[i + 1] = temp;
				}
		}

	}
	printf("\n");
	for (int i = 1; i <= n; i++)
	{
		printf("%06d %s %d\n", stu[i].number, stu[i].name, stu[i].score);
	}
}
