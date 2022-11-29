#include<stdio.h>

int header_char_read()
{

    FILE *p1,*p2;

    char c;

    p1 =   fopen("header.c","r");
    p2 =  fopen("output.txt","w");

    if(!p1) printf("Not open!");

    else
    {

        int flag=0;
        while((c=fgetc(p1))!=EOF)
        {
            if(c=='<') flag=1;
            else if(c=='>') break;
            else if(flag==1)
                printf("%c",c);

        }

    }
    fclose(p1);

}

int count_string_read()
{

    FILE *p1,*p2;

    p1 =   fopen("header.c","r");
    p2 =  fopen("output.txt","w");

    char sr[500];
    int val = 0;

    while(fgets(sr,sizeof(sr),p1))
    {

        char cnt [20];
        val++;
        sprintf(cnt,"%d; ",val);
        fputs(cnt,p2);
        fputs(sr,p2);
        //printf("%s",sr);
    }
    fclose(p2);
    fclose(p2);

}
int main()
{

    count_string_read();

}


