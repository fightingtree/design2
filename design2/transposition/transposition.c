
#include<stdio.h>



#include<string.h>

#include<stdlib.h>






char mingwenjuzhen[1000][1000],miwenjuzhen[1000][1000],miyao[10000];

void jiemi();
void jiami();
void choose();

int main(int argc,char *argv[])

{
    if(argc<4){
        printf("1:encrption/2:decrption keyword(1<=n<=5,5) plaintext/ciphertext\n");
        return 0;
    }
    if(atoi(argv[1])==1){
        int key;
        key  = atoi(argv[2]);
        char text[100];
        strcpy(text,argv[3]);
        jiami(key,text);
    }
    else{
        int key;
        key = atoi(argv[2]);
        char text[100];
        strcpy(text,argv[3]);
        jiemi(key,text);
    }

    return 0;

}


void jiami(int n,char mingwen[100])

{

   // printf("请输入明文\n");

    //scanf("%s",mingwen);
  

    int l,k=0,l1=0,i,j,q=1,w=0,aa=0,bb=0,a[10000]= {0};


    while(n)

    {

        k++;

        miyao[k]=n%10;

        n/=10;

    }

 //   printf("密钥为:\n");

    for(i=k; i>=1; i--)

    {

        a[k-i+1]=miyao[i];

    //    printf("%d ",miyao[i]);

    }

 //   printf("\n");

    l=strlen(mingwen);

    if(l%k!=0)//计算矩阵行数

        aa=l/k+1;

    else

        aa=l/k;

    if(aa==1)

    {

        printf("密文为:\n\n");

        for(i=1; i<=k; i++)

        {

            for(j=0; j<l; j++)

            {

                if(a[i]==j+1)

                {

                    printf("%c",mingwen[j]);

                }

            }

        }

    }

    else

    {

        for(i=0; i<aa;)

        {

            if(i==aa-1)

                break;

            for(j=0; j<l; j++)

            {

                mingwenjuzhen[i+1][q++]=mingwen[j];

                w++;

                if(w==k)

                {

                    i++;

                    w=0;

                    q=1;

                }

            }

        }

        printf("密文为:\n\n");

        for(i=k; i>=1; i--)

        {

            for(j=1; j<=aa; j++)

            {

                printf("%c",mingwenjuzhen[j][miyao[i]]);

            }

        }

    }

   // printf("\n\n");

    //printf("解密密钥为:\n");

    for(i=1; i<=k; i++)

    {

        for(j=1; j<=k; j++)

        {

            if(i==a[j])

            {

           //     printf("%d ",j);

            }

        }

    }

   

}

void jiemi(int m,char miwen[100])

{

   // printf("请输入密文:\n");

    //getchar();

    //gets(miwen);

    int i,j,l,k=0,b[1000]= {0},aa=0,q=1,w=0,bb=0;

    char s1[1000]= {0};

    l=strlen(miwen);//密文长度

  
   // printf("请输入解密密钥m(0<m<10)\n");

    //scanf("%d",&m);

    while(m)

    {

        k++;

        miyao[k]=m%10;

        m/=10;

    }

   // printf("解密密钥为:\n");

    for(i=k; i>=1; i--)

    {

        b[k-i+1]=miyao[i];

   //     printf("%d ",miyao[i]);

    }

 //   printf("\n");

    if(l%k==0)//计算矩阵行数

        aa=l/k;

    else

        aa=l/k+1;

    if(aa==1)

    {

        for(i=0; i<l; i++)

        {

            if(miwen[i]==' ')

                continue;

            else

                s1[bb++]=miwen[i];

        }

        printf("明文为:\n\n");

        for(i=1; i<=k; i++)

        {

            for(j=0; j<l; j++)

            {

                if(b[i]==j+1)

                    printf("%c",s1[j]);

 

            }

        }

    }

    else

    {

        for(i=0; i<l;)

        {

            for(j=0; j<k; j++)

            {

                for(int r=0; r<aa; r++)

                {

                    miwenjuzhen[r+1][j+1]=miwen[i];

                    i++;

                }

            }

        }

        printf("明文是:\n\n");

        for(i=1; i<=aa; i++)

        {

            for(j=1; j<=k; j++)

            {

                if(miwenjuzhen[i][b[j]]==' ')

                    continue;

                else

                    printf("%c",miwenjuzhen[i][b[j]]);

            }

        }

        printf("\n\n");

    }

 //   printf("密钥为:\n");

    for(i=1; i<=k; i++)

    {

        for(j=1; j<=k; j++)

        {

            if(i==b[j])

            {

        //        printf("%d ",j);

            }

        }

    }


}





