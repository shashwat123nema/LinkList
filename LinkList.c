#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
   int data;
   struct node *next;
};
 // Link List will end when user input -1 as input into Link List

struct node *start = NULL;          // this is start pointer this contains the address of starting element of Link List

void insert_at_begin(int); // insert element at start of Link List
void insert_at_end(int);   // insert element at end of Link List 
void traverse();           // print current Link List 
void delete_from_begin();  // delete 1st element in Link List  
void delete_from_end();    // delete Last element in Link List 
void insert();             // prompts user to input data into Link List 
void print();              // prints the current Link List (same as traverse() function below)
int search(int);           // search for a element in present Link List and returns "1" if successfull otherwise returns "0"  
int del_element(int);      // first searches element if present in Link List and delete its node   
void bubbleSort();         // This function sorts the Link List in ascending order using Bubble Sorting technique 
void swap(struct node*,struct node*);  // common swap() function used while sorting 
int maximum_no();             // return the maximum number present in current Link List   
void insert_noduplicates();   // same as insert() but if duplicates are entered it is not entered into Link List
void reverse();             // reverse the order of Link List(start pointer start from last node)
int count = 0;              // contains value of number of nodes in present Link List(count=0 if no Link List)
 
int main() {
    
   return 0;
}
void reverse() 
{ 
    struct node *prev = NULL; 
    struct node *current = start; 
    struct node *next = NULL; 
    while (current != NULL) { 
 
        next = current->next; 
  
        current->next = prev; 
        
        prev = current; 
        
        current = next; 
    } 
    start = prev; 
} 
int maximum_no(){

    struct node *t;
   
   t = start;
   
   if (t == NULL) {
      return INT_MIN;
   }
   
   int temp=t->data;
   
   while (t->next != NULL) {
    if(t->data>temp)
    temp=t->data;
      t = t->next;
   }
   if(t->data>temp)
    temp=t->data;
    return temp;
}
void insert(){
    int input;
   scanf("%d",&input);
   insert_at_begin(input);
  do{
         scanf("%d",&input);
      if(input==-1)
      break;
      insert_at_end(input);
      
  }while(1);}
void print(){
        traverse();
}
void insert_at_begin(int x) {
   struct node *t;
   
   t = (struct node*)malloc(sizeof(struct node));
   count++;
     
   if (start == NULL) {
      start = t;
      start->data = x;
      start->next = NULL;
      return;
   }
   
   t->data = x;
   t->next = start;
   start = t;
}
 
void insert_at_end(int x) {
   struct node *t, *temp;
   
   t = (struct node*)malloc(sizeof(struct node));
   count++;
   
   if (start == NULL) {
      start = t;
      start->data = x;
      start->next = NULL;
      return;
   }
   
   temp = start;
   
   while (temp->next != NULL)
      temp = temp->next;  
   
   temp->next = t;
   t->data    = x;
   t->next    = NULL;
}
 
void traverse() {
   struct node *t;
   
   t = start;
   
   if (t == NULL) {
      return;
   }
   
   
   while (t->next != NULL) {
      printf("%d ", t->data);
      t = t->next;
   }
   printf("%d\n", t->data);
}
 
void delete_from_begin() {
   struct node *t;
   int n;
   
   if (start == NULL) {
      return;
   }
   
   n = start->data;
   t = start->next;
   free(start);
   start = t;
   count--;
   
}

void delete_from_end() {
   struct node *t, *u;
   int n;

   if (start == NULL) {
      return;
   }
   count--;

   if (start->next == NULL) {
      n = start->data;
      free(start);
      start = NULL;
       return;
   }

   t = start;

   while (t->next != NULL) {
      u = t;
      t = t->next;
   }

   n = t->data;
   u->next = NULL;
   free(t);

}
int search(int element){
    struct node *t;
    if(start==NULL)
    return 0;
    else{
        t=start;
        if(t->data==element)
        return 1;
        while(t->next!=NULL){
        if(t->data==element)
        return 1;
        t=t->next;};
        return 0;
    }
}
int del_element(int el){
    struct node *t,*current;
    if(start==NULL){
    return 0;}
    else{
        t=start;
        current=t;
        if(t->data==el){
            start=t->next;
            free(t);
            count--;
            return 1;}
        while(t->next!=NULL){
            t=t->next;
            if(t->data==el){
                current->next=t->next;
                free(t);
                count--;}
            current=t;
        }
    }
    return 0;
    }
void bubbleSort()
{
    int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;

    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;
        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
       }
        lptr = ptr1;
    }
    while (swapped);
}
void swap(struct node *a, struct node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void insert_noduplicates(){
    int input;
    scanf("%d",&input);
   insert_at_begin(input);
  do{  
        scanf("%d",&input);
    if(input==-1)
      break;
      if(search(input)==0)
      insert_at_end(input);
      }while(1);}
