#include<stdio.h>
#include<stdlib.h>


/*
* Simply trying to implement singly linked list 
*
* Author:
*       Suraj Singh Bisht
*       surajsinghbisht054@gmail.com
*/



// node that can store single digit info
struct node {
    int i;
    struct node *next;
};



// create new node
struct node *createNode(int i){
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    tmp->i=i;
    tmp->next = NULL;
    return tmp;
}

// traverse list and print output
void traverse_list(struct node *front){
    struct node *tmp;
    int ind=0;

    // loop all nodes
    do{
        tmp=front;
        printf("Index : %d | Int : %d\n", ind++ ,tmp->i);
        front=tmp->next;
    }while(tmp->next!=NULL);
}



// append new node from rear
void appendNode(struct node *front, int d){
    struct node *tmp;
    struct node *rear;

    // loop all nodes
    do{
        tmp=front;
        front=tmp->next;
    }while(tmp->next!=NULL);
    
    // aftet execution of above loop, now tmp is our rear node
    rear = createNode(d);
    tmp->next=rear;
}

// get number of nodes in a list
int getLength(struct node *front){
    int l=0;
    struct node *tmp;

    // loop all nodes
    do{
        l++;
        tmp=front;
        front=tmp->next;
    }while(tmp->next!=NULL);

   return l; 
}



// search item and return index number
int finditem(struct node *front, int i){
    int index=0;
    struct node *tmp;

    // loop all nodes
    do{
        index++;
        tmp = front;
        front=tmp->next;
        if(tmp->i==i){
            index--;
            break;
        }
    }while(tmp->next!=NULL);


    if ((tmp->next==NULL)&&(tmp->i!=i)){
        index=-1;
    }
    return index;
}

// join two node list 
struct node *join(struct node *left, struct node *right){
    struct node *front;
    front = left;
    struct node *tmp;


    // end of left
    do{
        tmp=left;
        left=tmp->next;

    }while(tmp->next!=NULL);

    tmp->next=right;
    return front;
}

// append from front
struct node *insertStart(struct node *list, int i){
    struct node *tmp;
    struct node *newfront;

    tmp = createNode(i); // create new node
    newfront = join(tmp, list);
    return newfront;

}


// insert in middle of list
void insertMiddle(struct node *list, int index, int i){
    int pos=0;
    struct node *tmp;
    struct node *new;

    do{
        tmp=list;
        if(pos==index){
            // printf("Got That Index %d\n", tmp->i);
            new = createNode(i);
            new->next=tmp->next;
            tmp->next=new;
            
        }
        list=tmp->next;
        pos++;
    }while(tmp->next!=NULL);

}


// delete node
void delete(struct node *list, int index){
    struct node *tmp;
    struct node *garbage;
    int pos=0;

    do{

        tmp=list;
        pos++;
        if(index==pos){
            
            garbage = tmp->next;
            tmp->next = tmp->next->next;

            free(garbage);
            // free that node 
        }        
        list=tmp->next;
    }while(tmp->next!=NULL);
}


// demo of above functions
void create_list(){

    // create a head poniter variable for list
    struct node *pos_num;  // positive number
    struct node *neg_num;  // negative number
    struct node *rel_num;

    int len;    

    // create first node
    pos_num = createNode(0);
    neg_num = createNode(-3);
    
    // append new node and also insert data into new node 
    appendNode(pos_num, 1);
    appendNode(pos_num, 10); 
    appendNode(pos_num, 100); 
    appendNode(pos_num, 1000); 
    appendNode(pos_num, 10000); 
    appendNode(pos_num, 100000);
    appendNode(neg_num, -2);
    appendNode(neg_num, -1);





    // get total number of nodes in list
    len = getLength(pos_num);
    printf(" Length of pos_num : %d\n", len);
 
    // search item and return index of found item
    len = finditem(pos_num, 000);
    printf(" Find 0 at pos_num : %d\n", len);


    

    // travese positive number list
    printf("------ Traverse Pos_num\n");
    traverse_list(pos_num);

    // traverse negative number list
    printf("------ Traverse neg_num\n");
    traverse_list(neg_num);

    // join negative and postive list and return new head node pointer
    printf("------ Combined rel_num = neg_num + pos_num\n");
    rel_num = join(neg_num, pos_num);  
    traverse_list(rel_num);

    printf("------ After Inserting From Front in rel_num \n");
    // insert from front and return new head node pointer
    rel_num = insertStart(rel_num, -4);
    traverse_list(rel_num);

    // insert into the middle of list
    printf("------ After Inserting new item with data 5 After Index 4\n");
    insertMiddle(rel_num, 4, 5);
    traverse_list(rel_num);

    // delete node
    printf("------ After Deleting From Index 4\n");
    delete(rel_num, 4);
    traverse_list(rel_num);
            
}



// main function
int main(){
    create_list();
    return 0;
}

