#include <stdio.h>
#include <stdlib.h>

// 문자 크기 정의
#define CHAR_SIZE 26

// 새로운 Trie 노드를 저장할 데이터 구조
struct Trie
{
    int isLeaf; //노드가 리프 노드인 경우 1
    struct Trie* character[CHAR_SIZE]; // 문자의 집합
};

// 새로운 Trie 노드를 반환하는 함수
struct Trie* getNewTrieNode()
{
    struct Trie* node = (struct Trie *)malloc(sizeof(struct Trie));
    node->isLeaf = 0;

    for (int i = 0; i < CHAR_SIZE; i++)
        node->character[i] = NULL;

    return node;
};

// Trie 에 문자열을 삽입하는 반복함수
void insert (struct Trie *head, char *str)
{
    // 루트 노드에서 시작
    struct Trie* curr = head;
    while (*str)
    {
        // 경로가 존재하지 않는 경우 새 노드 생성
        if (curr->character[*str - 'a'] == NULL)
            curr->character[*str - 'a'] = getNewTrieNode();
        
        // 다음 노드로 이동
        curr = curr->character[*str - 'a'];
        str++;
    }
    // 현재 노드를 리프로 표시
    curr->isLeaf = 1;
}

// Trie 에서 문자열을 검색하는 반복 함수.
// 문자열이 Trie 에서 발견되면 1을 반환
// 그렇지 않으면 0을 반환
int search(struct Trie *head, char *str)
{
    // Trie 가 비어있으면 0을 반환
    if (head == NULL)
        return 0;
    
    struct Trie *curr = head;
    while (*str)
    {
        // 다음 노드로 이동
        curr = curr->character[*str - 'a'];

        // 문자열이 유효하지 않은 경우 (Trie 의 끝에 도달)
        if (curr == NULL)
            return 0;
        
        str++;
    }

    // 현재 노드가 리프이고 문자열의 끝에 도달
    return curr->isLeaf;
}

int main()
{
    struct Trie *head = getNewTrieNode();
    int cnt = 0, n1, n2;
    char a[501];

    scanf("%d %d", &n1, &n2);
    for (int i = 0; i < n1; i++)
    {
        scanf("%s", a);
        insert(head, a);
    }

    for (int i = 0; i < n2; i++)
    {
        scanf("%s", a);
        cnt += search(head, a);
    }
    printf("%d", cnt);

    return 0;
}
