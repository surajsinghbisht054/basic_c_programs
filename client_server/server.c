// include headers
#include <stdio.h>         // Standard Input Output Header
#include <stdlib.h>        // standard library
#include <sys/socket.h>   // Socket Header
#include <sys/types.h>    // Datatype For System Calls
#include <netinet/in.h>   // SOcket related data struct


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


// display error and exit
void error(char *msg){
    perror(msg);
    exit(0);
}

// main function
int main(int argc, char *argv[]){
    // check argument --
    if (argc<2){
        printf("Error; Please Provide Port Number As Argument.\n");
        printf("Usages : \n\t %s port_number \n", argv[0]);
        exit(0);
    }

    // initialise variables
    int sockd;  // To Handle Main Socket Function Object
    int newsock; // To handle Received Connection Socket From Client
    int port;    // Port number
    int clientlisten;  // client listening
    int n;       // to store number
    char buffer[256]; // to store client receiving messages


    // port number
    port = atoi(argv[1]); // Get Port Number As Integer


    /*
    
    struct sockaddr_in {
        short   sin_family;
        u_short sin_port;
        struct  in_addr sin_addr;
        char    sin_zero[8];
};
    
    */
    struct sockaddr_in client, server;

    // time to make sure, above struct buffer is clear... :) yup! little knowledge of exploitation    
    bzero((char *)&server, sizeof(server));

    // time to load, server struct (For Binding)

    server.sin_family = AF_INET;  // SOcket family
    server.sin_port = htons(port); // socket port
    server.sin_addr.s_addr = INADDR_ANY; // all clients allowed

    
    // socket initialise
    sockd = socket(AF_INET, SOCK_STREAM, 0);

    // check sockd 
    if (sockd <0){
        error("Something Wrong With Socket Creation Codes!");
    }

    // time to bind socket
    n = bind(sockd, (struct sockaddr *)&server, sizeof(server));

    // check bind
    if(n<0){
        error("Error: Something Wrong With Binding Codes.!");
    }
    // so, now our socket is ready to receive connections

    // 
    listen(sockd, 5); // limit client connections

    // wait and receive connection
    n = sizeof(client);
    newsock = accept(sockd, (struct sockaddr *)&client, &n);

    if (newsock<0){
        error("Error: During Receiving Connection From Clients.!");
    }

    n = read(newsock, buffer, 255); // Read Bytes From Socket And Save it in Buffer
    if(n<0){
        error("Error: During Reading Sent Data By Client.");
    } 
    printf("[+] Client Sent : %s\n", buffer);

    // so, we received message from client.. now it's time to reply back
    n = write(newsock, "HELLO Client", 13);

    if(n<0){
        error("Error: During Sending Data To Client");
    } 
    // return
    return 0;


}
