#include <stdlib.h>
#include <stdio.h>

struct node {

    int data;
    struct node *next;


};
typedef struct node node;

node* insertFront(node *head, int d);
node* insertBack(node *head, int d);
void print(node *head);
int max(node *head);
int min(node *head);
int locInList(node *head, int x);

int main(){

    node *head = NULL;
    int num = 0;
    int lookup = 0;


    printf("Enter a number: ");
    scanf("%d", &num);
    head = insertBack(head, num);
    printf("Enter another number: ");
    scanf("%d", &num);
    head = insertFront(head, num);
    printf("Enter another number: ");
    scanf("%d", &num);
    head = insertFront(head, num);
    printf("Enter another number: ");
    scanf("%d", &num); 
    head = insertBack(head, num);
    printf("Enter final number: ");
    scanf("%d", &num);
    head = insertBack(head, num); 
    print(head);

    printf("Max: %d\n", max(head));
    printf("Min: %d\n", min(head));
    printf("Enter a number to lookup location of: ");
    scanf("%d", &lookup);
    printf("Location in List for %d: %d\n", lookup, locInList(head, lookup));
    printf("Enter another number to lookup location of: ");
    scanf("%d", &lookup);
    printf("Location in List for %d: %d\n", lookup, locInList(head, lookup)); 

}

node* insertFront(node *head, int d){

    node *tmp = NULL;
    tmp = malloc(sizeof(node));
    tmp->data = d;
    tmp->next = head;
    head = tmp;
    return head;

}

node* insertBack(node *head, int d){

    node *tmp = NULL;
    tmp = malloc(sizeof(node));
    tmp->data = d;
    tmp->next = NULL;
    if (head == NULL){

        head = tmp;
    }
    else {

        node *last = head;

        while (last->next != NULL){

        last = last->next;
    }
    last->next = tmp;
    }

   

    return head;
}

void print(node *head){

    node *tmp = NULL;
    tmp = head;

    while (tmp != NULL){
    printf("%d ", tmp->data);
    tmp = tmp->next;
    }
    puts("");
    puts("");
}

int max(node *head){

    node *tmp = NULL;
    tmp = head;
    int max = tmp->data;

    while (tmp != NULL){

        if (max < tmp->data){
            max = tmp->data;
        }
        tmp = tmp->next;
        }

        return max;
}

int min(node *head){

    node *tmp = NULL;
    tmp = head;

    int min = tmp->data;

    while (tmp != NULL){

        if (min > tmp->data){
            min = tmp->data;
        }
        tmp = tmp->next;
        }
        return min;
}

int locInList(node *head, int x){

    node *tmp = NULL;
    tmp = head;
    int i = 0;

    if (head->data == x){
            return i;
    }
    while (head->data != x) {

        head = head->next;
        i++;
        if (head->data == x){
            return i;
            break;
        }
        else if (head->next == NULL){
            return -1;
        }
    }
}