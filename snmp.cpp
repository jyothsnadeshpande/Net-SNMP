
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include<iostream>
#include<cstring>
using namespace std;

int main(void)
{
    pid_t cpid;
    cout<<"\t\t\t***WELCOME TO SNMP***\n\n\n";              
    int ch;                                              
  
    do
    {
      char *args[100];                                        // To be passed to the execvp() function
      char m[20][100];
      int num;
      cout<<"Enter the command to be executed\n";
      char path[20] = "/usr/bin/";
      char command[30];                                       // Contains the actual command
      cin>>command;     

      int i=0;
   
      while(command[i++])                                     // Append the command name to the path of the respective binary 
     {
       path[i+8]=command[i-1];
     }

     args[0] = path;
  
     char version[3] = "-v";                                  // Read the version number
     args[1] = version;
     cout<<"Enter the version\n";
     char ver[5];
     cin>>ver;
     args[2] = ver;
 
     char community[3] = "-c";                                // Read the community string
     args[3] = community;
     cout<<"Enter the community string\n";
     char commu[20];
     cin>>commu;
     args[4] = commu;

     cout<<"Enter the agent hostname or IP\n";            // Read the hostname
     char hostname[100];
     cin>>hostname;
     args[5] = hostname;

     cout<<"Enter the number of OIDs required\n";             // Read the arguments
     cin>>num;

     char OID[num][50];

     cout<<"Enter the required OIDs\n";
     for(int j=0;j<num;j++)
     {
       cin>>OID[j];
     }       

     for(int c=0;c<num;c++)
     {
       args[c+6] = OID[c];
     }             

     args[6+num] = NULL;                                        // Last argument is supposed to be null

     if(fork() == 0)                                            // Main code                          
       execvp(args[0],args);

     cpid = wait(NULL);                                         // Halts the parent process until the child terminates

     cout<<"OPTIONS:\n 1.STAY\n 2.EXIT\n";                 // Options for the user
     cout<<"Enter your choice:\n";
     cin>>ch;                                              // Read user choice

     if(ch>2 || ch<1)
     {
        cout<<"Invalid choice, enter again\n";
        cin>>ch; 
     }

  }
  while(ch==1);                                                  

 return 0;
}
  
