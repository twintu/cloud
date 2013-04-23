#include <stdio.h>
#include <stdlib.h>
#include <libvirt/libvirt.h>

int main(int argc, char *argv[])
{
    virConnectPtr conn;
    virDomainPtr vdp;
    int i=-1,ch; 	
    char *host;
    conn = virConnectOpen("xen:///");
    if (conn == NULL) {
        fprintf(stderr, "Failed to open connection to xen:///\n");
        return 1;
    }
    //host = virConnectGetHostname(conn);

    vdp=virDomainLookupByName(conn,"ubuntu_connection");
    printf("\nMenu\n----\n1.Connect\n2.Suspend\n3.Resume\n 4.Shutdown\n");

    printf("Enter your choice:\n");
    scanf("%d",&ch);

    switch(ch) {

        case 1:

            i=virDomainCreate(vdp);
            if(i==0)
            {
                printf("Success\n");
            }else{
                printf("Failed\n");
            }
            break;


        case 2:

            /* suspend*/	    
            i=virDomainSuspend(vdp);
            if(i==0)
            {
                printf("Success\n");
            }else{
                printf("Failed\n");	
            }
            break;


        case 3:

            /*resume*/
            i=virDomainResume(vdp);
            if(i==0)
            {	
                printf("Success\n");
            }else{
                printf("Failed\n");	
            }
            break;

        case 4:
           
            /*shutdown*/
            i=virDomainDestroy(vdp);
            if(i==0)
            {
                printf("Success\n");
            }else{
                printf("Failed\n");	
            }
            break;        

         default:
        
            printf("INVALID");


            virConnectClose(conn);
            return 0;
    }
}
