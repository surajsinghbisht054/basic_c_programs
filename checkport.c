/*
 * 
 *      __author__: Suraj Singh Bisht
 *                  surajsinghbisht054@gmail.com
 *                  www.bitforestinfo.com 
 * 
 * ============================================================
 *                 Created During C socket practise
 * ============================================================
 * 
 *  Tested On :
 *          Linux parrot 4.14.0-parrot13-amd64 #1 SMP Parrot 4.14.13-1parrot13 (2018-01-21) x86_64 GNU/Linux
 *          gcc (Debian 7.3.0-5) 7.3.0
 *
 * */

// include header
#include <stdlib.h>     // standard library
#include <stdio.h>      // Standard Input Output Library
#include <sys/socket.h> // socket header
#include <sys/types.h>  // Data types
#include <string.h>     // String
#include <netinet/in.h>
#include <arpa/inet.h> //
#include <unistd.h>

#define PORT_EXPRESSION_ITER 11


// Error Report On Screen
void error(char *msg)
{
    printf("[Error] %s\n", msg);
    printf("[X] Terminating Program...\n");
    exit(0);
}

// Data Type
typedef struct list{
    int data;
    int status;
    struct list * next;
} plist;

// append nodes
void listappend(plist *head, int val){
    /*
    *
    *  To Append New Node Into Linked List Structure.
    */

    plist *tmp;
    
    // starting point
    if(head->next == NULL){
        tmp = malloc(sizeof(plist));
        if (tmp==NULL){
            error("Error During Allocating Node For Port Storing List");
        }
        tmp->data = val;
        tmp->next = NULL;
        tmp->status = 0;
        head->next = tmp;
    }
    else{
        while(head->next!=NULL){
            //printf("Checking Node %i\n", head->data);
            tmp = head->next;
            head = tmp;


            //exit(0);
        }
        tmp = malloc(sizeof(plist));
        tmp->data = val;
        tmp->next = NULL;
        tmp->status = 0;
        head->next = tmp;    
    }
}

void expandlist(plist *head){
    /*
    *
    * This Function is dedicated To explore all node data value Into Terminal.
    * 
    */
    plist *tmp;
    while(head->next!=NULL){
            printf("Node->Data %i\n", head->data);
            tmp = head->next;
            head = tmp;


            //exit(0);
        }
        printf("Node->Data %i\n", head->data);

}
void checkport(int sockd, struct sockaddr_in client, int port, char *ip, plist *node){
    
    client.sin_port = htons(port);
    client.sin_addr.s_addr = inet_addr(ip);
    if(connect(sockd, (struct sockaddr*)&client, sizeof (client))<0){
        node->status=0;
        printf("Close\n");
    }else{
        node->status=2;
        printf("Open\n");
    }

    
}


void portscanner(plist *p, char *ip){
    /*
    * This Function is Completely Dedicated To Perform Port scanning
    * process and save result into linked list status block
    * 
    */
    int sockd;
    plist *tmp;
    tmp = p->next;
    p = tmp;
    
    /*
    
    struct sockaddr_in {
        short   sin_family;
        u_short sin_port;
        struct  in_addr sin_addr;
        char    sin_zero[8];
    };
    
    */
   struct sockaddr_in victim;

   sockd = socket(AF_INET, SOCK_STREAM, 0);
   
    struct timeval timeout;
    timeout.tv_sec  = 1;  // after 1 seconds connect() will timeout
    timeout.tv_usec = 0;

    setsockopt(sockd, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout));

   if (sockd<0){
       error("[Error] During Creation Of Socket Handler");
   }
   victim.sin_family = AF_INET;
   while (p->next!=NULL){
        printf("Scanning IP :%s | Port : %i ---> ", ip, p->data);
        checkport(sockd, victim, p->data, ip, p);
        tmp = p->next;
        p = tmp;

   }
        printf("Scanning IP :%s | Port : %i ---> ", ip, p->data);
        checkport(sockd, victim, p->data, ip, p);
        tmp = p->next;
        p = tmp;

   close(sockd);

}



void ranger(char *exp, plist *p){
    /*
    *
    * This Function is completely Dedicated To Generate Port Integers From Provided
    * Port Expression.
    * 
    */

    char s[6], e[6], *n; 
    int sn, en, i;

    // Get Tail
    n = strpbrk(exp, "-");

    // Store it In another variable
    // surpass '-' char
    n++;

    // copy value in ending variable
    strcpy(e, n);
    
    // convert string into integers
    en = atoi(e);

    // get head
    n = strtok(exp, "-");

    // store in another variable
    strcpy(s, n);
    
    // convert string into integers
    sn = atoi(s);
    
    // check range
    if (sn >= en)
    {
    //printf("Starting From : %s, End at : %s\n",s,e);
               //printf("Starting From : %i, End at : %i\n",sn,en);
;        error("Incorrect Range Found");
    }
    
    for (i = sn; i < en; i++)
    {
        listappend(p, i);
    }
}



// Argument Parser And Processing Function
void argument_parse(char *ip, char *port){
    /*
    *
    * This Function Is Completely Dedicated To Extract Port Integers From Port Expressions
    * And Also Generate Port Integers From Provided Port Range Expression.
    * 
    */

    plist *p;    // Port List Object Define

    p = malloc(sizeof(plist)); // Allocate Space For List Object
    p->next = NULL;
    p->data = 0;
    p->status = -1;

    int l = strlen(port); // length of characters in port expression
    char c;                // to handle every single character of port expression
    char pnum[PORT_EXPRESSION_ITER];
    int pn = 0, iport;

    bzero(pnum, sizeof(pnum)); // make sure, space is clear


    // iter all characters of port expresion
    for (int i = 0; i < l; i++)
    {
        c = port[i];

        // check if character is a valid expression
        if ((c == ' ') |
            (c == '1') |
            (c == '2') |
            (c == '3') |
            (c == '4') |
            (c == '5') |
            (c == '6') |
            (c == '7') |
            (c == '8') |
            (c == '9') |
            (c == '0') |
            (c == '-') |
            (c == ','))
        {
            // Start Storing Characters
            if (pn == 0)
            {
                bzero(pnum, sizeof(pnum));
                pnum[pn] = c;   // string starting
                pnum[PORT_EXPRESSION_ITER] = '\0'; // string end
                pn++;
            }

            // Split Expression And Save Into List 
            else if ((c == ',') & (pn != 0))
            {
                // check if range expression
                if (strpbrk(pnum, "-"))
                {
                    ranger(pnum, p);
                }
                else
                {
                    iport = atoi(pnum);
                    listappend(p ,iport);
                }

                // Reset Input character collector
                pn = 0;
                bzero(pnum, sizeof(pnum));
            }
           

            else if ((pn == 5)&(!strpbrk(pnum, "-")))
            {
                
                // check if range expression
                if (strpbrk(pnum, "-"))
                {
                    ranger(pnum, p);
                }
                else
                {
                    
                    iport = atoi(pnum);
                    listappend(p ,iport);
                }

                // Reset Input character collector
                pn = 0;
                bzero(pnum, sizeof(pnum));
                pnum[pn] = c;   // string starting
                pnum[PORT_EXPRESSION_ITER] = '\0'; // string end
                pn++;
            }
            else if (pn < 5)
            {
                
                pnum[pn] = c;
                pn++;
            
            }
            else if (strpbrk(pnum, "-"))
            {
                
                pnum[pn] = c;
                pn++;
            
            }
            else
            {

                printf("[-] Port Expression Droped Characters : %i\n", pn);
            }
        }
        else
        {
            //printf("%s", c);
            error("Please Provide Valid Port Range Expressions");
        }
    }

    iport = atoi(pnum);
    listappend(p ,iport);
    //expandlist(p);

    // Reset Input character collector
    pn = 0;
    bzero(pnum, sizeof(pnum));
    portscanner(p, ip);

}

// main function trigger
int main(int argc, char const *argv[]){
    /*
    * This Main Function Is Completely Dedicated To Verify And Filter User
    * Provided Arguments.
    * 
    */

    char ip[16];    // IP Address Expression
    char port[100]; // Port Range expression
    
    // if no arguments passed
    if (argc < 2)
    {
        printf(" Please Provide Arguments To Perform Function\n\n \
    :~$ %s IP_ADDRESS PORT-RANGE\n\nSupported Port Expression 1,2,3-80,5  \n\t\t\t[Note] Range Supported Only In Middle Of Expression \n\t\t\t\t like  port1,(Range: Port2-9) ,port10\n",
               argv[0]);

        error("Program Terminating... \n\t\tCause :- No Input Provided.");
    }

    // If Only One Argument is Provided
    else if (argc < 3)
    {
        printf("Please Provide Arguments To Perform Function\n\n \
    :~$ %s IP_ADDRESS PORT-RANGE\n\n\n",
               argv[0]);

        error("Program Terminating... \n\t\tCause : Insuffecient Input Provided.");
    }

    // Check if Provided Arguments are valid to process
    else if ((argc == 3) & (strlen(argv[1]) < 16) & (strlen(argv[1]) > 8))
    {
        printf("Starting CheckPort Program Design/Written By Surajsinghbisht054@gmail.com\n\n\n");

        strcpy(ip, argv[1]);   // Get IP address
        strcpy(port, argv[2]); // Get Port Range Expression
        argument_parse(ip, port); // Transfer Controls To Argument Parse Function
    }

    // Unformatted Arguments Provided
    else
    {
        printf("Please Provide Correct Arguments To Perform Function\n\n \
    :~$ %s IP_ADDRESS PORT-RANGE\n\n\n",
               argv[0]);

        error("Program Terminating... \n\t\tCause : Unformatted Input Provided.");
    }
    return 0;
}
