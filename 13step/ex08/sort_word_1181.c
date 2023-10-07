/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//비교 수행하는 함수, qsort의 4번째 인자
int compare(const void* arg1, const void* arg2) 
{   //길이순 정렬
	if (strlen((const char*)arg1) > strlen((const char*)arg2)) return 1;
	else if (strlen((const char*)arg1) < strlen((const char*)arg2)) return -1;
	//길이 같으면 사전순
	else return strcmp((char*)arg1, (char*)arg2);
} 
int main(void)
{    
	int size, length = 51;
	char arr[20000][51] = { 0 };
	scanf("%d", &size);

	for (int i = 0; i < size; i++)      
		scanf("%s", arr[i]);

	//정렬
	qsort(arr, size, sizeof(arr[0]), compare);
	printf("\n\n----after sorting----\n\n");
	//정렬 후 같은 문자열은 생략하고 출력
	for (int i = 0; i < size; i++) {
        printf("strcmp(arr[%d], arr[%d + 1]) = %d\n", i, i, strcmp(arr[i], arr[i + 1]));
		if (strcmp(arr[i], arr[i+1]) != 0 || i == size - 1)
			printf("%s\n", arr[i]);
	}
	return 0;
}*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *first, const void *second)
{
    if (strlen((const char *)first) > strlen((const char *)second))
        return 1;
    else if (strlen((const char *)first) < strlen((const char *)second))
        return -1;
    else
        return strcmp((const char *)first, (const char *)second);
}

int main()
{
    int n;
    char arr[20001][51];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", arr[i]);
    
    qsort(arr, n, 51, compare);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(arr[i], arr[i + 1]) != 0 || i == n - 1)
            printf("%s\n", arr[i]);
    }

    return 0;
}