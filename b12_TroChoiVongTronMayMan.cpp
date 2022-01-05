#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
    int data;
    Node* next;
} *List;

struct ListCircle       //kieu dslkvong
{
    struct Node* head = NULL;
    struct Node* tail = NULL;
};

struct Node* createNode(int data){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if(!p){
        exit(1);
    }
    p->data = data;
    p->next = NULL;
    return p;
}

//check empty
bool isEmpty(ListCircle &c){
    return c.head == NULL;
}

//count nodes 
int countNodes(ListCircle &c){
    int num = 0;
    List p = c.head;
    do{
        num++;
        p = p->next;
    }while(p != c.head);
    return num;
}

//display list
void showList(ListCircle &c){
    List p = c.head;
    printf("Danh sach lien ket vong: \n");
    do{
        int data = p->data;
        printf("%d --> ", data);
        p = p->next;
    }while(p != c.head);
    printf("\n");
}

//add a new node at first
void addFirst(ListCircle &c, int data){
    List p = createNode(data);
    if(!isEmpty(c)){
        p->next = c.head;
        c.head = p;
        c.tail->next = c.head;
    }
    else{
        c.head = p;
        c.tail = p;
        c.tail->next = c.head;
    }
}

//add a new node at tail
void addTail(ListCircle &c, int data){
    List p = createNode(data);
    c.tail->next = p;
    c.tail = p;
    c.tail->next = c.head;
}

//add a node at any position, pos = 1, 2, 3...
void addAtPos(ListCircle &c, int pos, int data){
    List p = createNode(data);
    int len = countNodes(c);
    if(pos < 1 || pos > (len + 1)){
        printf("input p again\n");
        return;
    }
    else if(pos == 1){
        addFirst(c, data);
    }
    else if(pos > 1 && pos < (len + 1)){
        //duyet den vi tri pos - 1
        List p1 = c.head;
        int i = 1;      //bien dem vi tri
        while(i < pos - 1){
            p1 = p1->next;
            i++;
        }

        //them node vao giua pos-1 vs pos
        p->next = p1->next;
        p1->next = p;
    }
    else{       //pos = len + 1
        addTail(c, data);
    }
}

//dao nguoc dslk_vong
void convert(ListCircle &c){
    List cur = c.head;
    List pre = c.tail;
    List next = NULL;
    List p = cur;       //luu tru
    do{
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }while(cur != c.head);
    c.head = pre;
    c.tail = p;
}

//the lucky game
void playGame(ListCircle &c, int n, int k){
    //khoi tao dslk n node
    int i = n;
    while(i > 0){
        addFirst(c, i);
        i--;
    }
    printf("Ban dau tren ban tron co %d nguoi, sap xep nhu sau: \n", n);
    showList(c);

    //tim nguoi may man
    while(c.head->next != c.head){
        int count = 1;
        List p = NULL;      //khoi tao
        do{
            p = c.head;
            c.head = c.head->next;
            count++;
        }while(count < k);
        List p1 = c.head;
        c.head = c.head->next;
        p->next = c.head;
        c.tail = p;
        free(p1);
    }
    printf("Voi so dem la %d thi cuoi cung ta tim duoc nguoi may man la: \n", k);
    showList(c);
}

int main(){
    ListCircle c;

    //input data
    int n, k;
    printf("Input number of people, n: ");
    scanf("%d", &n);
    printf("Input a number to count, k: ");
    scanf("%d", &k);

    playGame(c, n, k);
    return 0;
}