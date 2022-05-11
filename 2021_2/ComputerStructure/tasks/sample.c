#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// #include<windows.h>

static int menu;
#define Trial 100
//#define Cache_size 8
//#define set_way 2
int Cache_size, set_way;
typedef struct {
    //int word[4];   //워드 생략
    int tag;      //태그 값
    int count;      //접근 회수
    int use_bit;      //유효 비트
    int access_time;   //접근 시간
} line_type;

typedef struct {
    //line_type line[set_way];
    line_type* line;
} set_type;

typedef struct {
    //set_type set[Cache_size / set_way];   //캐시메모리 블록
    set_type* set;   //캐시메모리 블록
} cache;

void init_cache(cache* c)  //캐시 초기화
{
    c->set = (set_type*)malloc(sizeof(set_type) * (Cache_size / set_way));
    int i, j;
    for (i = 0; i < Cache_size / set_way; i++) {
        c->set[i].line = (line_type*)malloc(sizeof(line_type) * (set_way));
        for (j = 0; j < set_way; j++) {
            c->set[i].line[j].tag = -1;
            c->set[i].line[j].use_bit = 0;
            c->set[i].line[j].count = 0;
            c->set[i].line[j].access_time = 0;
        }
    }
}
void print_cache(cache* c)
{
    int i, j;
    printf("캐쉬세트| 라인\t| Tag\t| Time \t| 유효비트 | \n");
    for (i = 0; i < Cache_size / set_way; i++) {
        for (j = 0; j < set_way; j++) {
            printf("세트%d   | %d\t| %d\t| %d\t| %d\t| ", i, j, c->set[i].line[j].tag, c->set[i].line[j].access_time, c->set[i].line[j].use_bit);
            printf("\n");
        }
        printf("\n");
    }
    printf("\n");
}

int cache_check(int tag, cache* c)  //캐시의 태그메모리 비교
{
    int i, j;
    int index = tag % (Cache_size / set_way); //세트 번호 추출
    //태그 비교
    for (i = 0; i < set_way; i++) {
        if (tag == c->set[index].line[i].tag) {
            if (menu == 1) {   //FIFO일때
               //c->set[index].line[i].count++;//필요없음(LFU에서 사용)
                printf("적중-> %d\n", c->set[index].line[i].tag);
                return 1;
            }
            else {   //LRU일때
               //c->set[index].line[i].count++;//필요없음(LFU에서 사용)
                for (j = 0; j < set_way; j++) // 캐시 적중 시 접근 시간 갱신
                {
                    if (c->set[index].line[i].access_time < c->set[index].line[j].access_time) {
                        c->set[index].line[j].access_time--;
                    }
                }
                c->set[index].line[i].access_time = set_way - 1;
                printf("적중-> %d\n", c->set[index].line[i].tag);
                return 1;
            }
        }
    }
    return 0;
}
//LRU 방식
// 캐시 8, 세트 2로 가정하고 테스트 진행
void LRU_method(cache* c, int tag) {
    //LRU 구현
    int setNum, lru = 0; //lru = 사용 안된지 가장 오래된 친구
    setNum = tag % (Cache_size / set_way); //세트 넘버

    for (int i = 0; i < set_way; i++) {
        if (c->set[setNum].line[i].use_bit == 0) { 
            c->set[setNum].line[i].use_bit = 1;   
            c->set[setNum].line[i].tag = tag;
            break;
        }
    }

    for (int i = 0; i < set_way; i++) { // 제일 오래된 친구 찾기
        if (c->set[setNum].line[lru].access_time > c->set[setNum].line[i].access_time){ // 세트 넙버에서 제일 오래된 친구는 숫자 낮은친구 
            lru = i;
        }
    }

    for (int i = 0; i < set_way; i++) { // 세트에 비어있는 캐시가 없으면 제일 오래된 친구 자리에 넣어준다
            if(c->set[setNum].line[i].use_bit != 0 ){
               c->set[setNum].line[lru].tag = tag;
               break;
        }
    }

    for (int i = 0; i < set_way; i++) { //들어온 애 제외하고 타임숫자 내리기
        if ((c->set[setNum].line[i].tag != tag) && (c->set[setNum].line[i].access_time > c->set[setNum].line[lru].access_time)) {
            c->set[setNum].line[i].access_time--;
        }
    }
    c->set[setNum].line[lru].access_time = set_way - 1;  //들어온애 제일 높은 숫자 주기

}

//FIFO 방식
void FIFO_method(cache* c, int tag) {
    //FIFO 구현
    int setNum = 0;
    setNum = tag % (Cache_size / set_way); //세트번호 찾기

    for (int i = 0; i < set_way; i++){
        if(c->set[setNum].line[i].use_bit ==0){ //유효비트가 0이면 채워주고 비트값들 넣어주기
            c->set[setNum].line[i].use_bit = 1;
            c->set[setNum].line[i].tag = tag;
            c->set[setNum].line[i].access_time = set_way - 1;
            break;
        }
        else { // 유효비트 1이고, 접근시간 0인애가 제일 먼저들어온 친구니까 바꿔주고 타임 세팅
            if(c->set[setNum].line[i].access_time == 0 && c->set[setNum].line[i].use_bit == 1){
                c->set[setNum].line[i].tag = tag;
                c->set[setNum].line[i].access_time = set_way - 1;
            }
            else if (c->set[setNum].line[i].tag != tag){ //다른애들 시간 내려주기
                c->set[setNum].line[i].access_time--;
            }
        }
    }
}

void memory_load(int tag, cache* c)            //주기억장치에서 데이터 블록 읽어오기
{
    int i, temp, valid = 0;
    FILE* memory = fopen("memory.txt", "r+");      //주기억장치 접근(오픈)
    if (memory == NULL) {
        // 파일이 존재하지 않을시 프로그램 종료
        printf("파일 오픈 실패! 프로그램을 종료합니다.\n");
        // return 0;
    }
    for (i = 0; i < 512; i++)         //512개의 주기억장치 블록 가정
    {
        fscanf(memory, "%d", &temp);   //주기억장치의 블록 번호 추출
        if (temp == tag)   //캐시의 태그와 메모리 블록 번호가 일치하는 블록을 찾아 교체 알고리즘 
        {
            if (menu == 1)
                FIFO_method(c, tag);// FIFO 방식 블록 교체
            else if (menu == 2)
                LRU_method(c, tag);   // LRU 방식 블록 교체   
            else
                printf("잘못 선택하셨습니다.");
            print_cache(c); //캐시 출력
        }
    }
}

void input_data(FILE* input, cache* c)
{
    int temp;
    int i;
    int hit = 0;
    for (i = 0; i < Trial; i++)  //명령어 수 만큼 반복
    {
        fscanf(input, "%d", &temp);
        printf("캐시 확인 : %d\n", temp);
        if (cache_check(temp, c))  //캐시 내에 태그 확인
        {
            hit++;  //캐시 적중
            print_cache(c);
        }
        else               //캐시 내에 명령어 태그가 없을 경우
        {
            printf("실패\n");
            memory_load(temp, c);  //메모리에서 명령어 블록 읽어오기
        }
    }
    printf("적중 : %d 회\n", hit);
}

int main() {

    cache c;
    FILE* input = fopen("input.txt", "r+");
    if (input == NULL) {
        // 파일이 존재하지 않을시 프로그램 종료
        printf("파일 오픈 실패! 프로그램을 종료합니다.\n");
        // return 0;
    }
    printf("캐시 라인 수를 입력하세요 :");
    scanf("%d", &Cache_size);
    printf("세트 수를 입력하세요 :");
    scanf("%d", &set_way);
    while (1) {
        printf("1. FIFO 방식\n2. LRU 방식\n방식을 선택해주세요:");
        scanf("%d", &menu);
        if (menu == 1 || menu == 2)
            break;
    }
    init_cache(&c);  //캐시 초기화
    input_data(input, &c); //데이터 입력
    system("pause");
}