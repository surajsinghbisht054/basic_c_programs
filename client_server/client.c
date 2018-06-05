// include header
#include <stdlib.h>       // standard library
#include <stdio.h>        // standard input output library
#include <sys/socket.h>   // socket
#include <sys/types.h>    // data info
#include <netinet/in.h>   // server object struct
#include <netdb.h>        // host struct


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
 *         Tested Only In Ubuntu
 *
 * */

// error handling function
void error(char *msg){
    perror(msg);
    exit(0);
}


// main function
int main(int argc, char *argv[]){
    // check argument for server_address, server_port
    if (argc<3){
        printf("Usages : %s server_ip_address Server_port\n", argv[0]);
        exit(0);
    }

    // decleare variables
    int sockd;                      // socket
    int portno;                     // portnumber
    int n;                          // to store data
    char buffer[256];               // to handle string characters
    struct sockaddr_in serv_addr;   // server address struct handling
    struct hostent *server;         // host struct 

    // port number 
    portno = atoi(argv[2]);

    // collect various information and return as hostent struct
    server = gethostbyname(argv[1]);

    // check server return struct
    if (server==NULL){
        error("Error: During Gethostbyname");
    }

// struct  hostent {
//        char    *h_name;        /* official name of host */
//        char    **h_aliases;    /* alias list */
//        int     h_addrtype;     /* host address type */
//        int     h_length;       /* length of address */
//        char    **h_addr_list;  /* list of addresses from name server */
// #define h_addr  h_addr_list[0]  /* address, for backward compatiblity */
// };
    
    // create socket
    sockd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockd < 0){
        error("Error: During Socket Creation\n");
    }

    // time to clear server_addr struct
    bzero((char *)&serv_addr, sizeof(serv_addr));

    // time to insert values in serv_addr struct
    serv_addr.sin_family = AF_INET;    // Socket Family
    
    serv_addr.sin_port = htons(portno); // Port number

    // hmm, let's directly copy informations from server struct to serv_addr
    bcopy(
        (char *)server->h_addr,             // source
        (char *)&serv_addr.sin_addr.s_addr, // destination
        server->h_length                    // data length
        );

    // connect to server    
    n = connect(sockd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    // check connection
    if (n<0){
        error("Error: During Establising Connection With Server.");
    }
    // print informations
    printf("[+] Connection Ready...\n");
    printf("[-] Enter Your Message : ");

    // read user input
    fgets(buffer, 255, stdin);

    // sent user input to socket
    n = write(sockd, buffer, strlen(buffer));
    if (n<0){
        error("Error: During message sending process");
    }
    // make sure, buffer is clean
    bzero(buffer, 256);

    // read 
    n = read(sockd,buffer, 255 );
    if (n<0){
        error("Error: During Reading Data");
    }
    printf("[+] Data Received : %s \n", buffer);


    return 0;
}
