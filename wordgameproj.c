#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<string.h>
int lives=2;
int first_level_score=0;
int second_level_score=0;
int third_level_score=0;
char key[20];
struct char_array
{
	char word[20];
	struct char_array *next;
};
char queue_array[20][20];
int rear=-1,front=-1;
void add_queue(char w[])
{
	if(rear==-1&&front==-1)
	{
		rear++;
		front++;
		strcpy(queue_array[rear],w);
	}
	else
	{
		rear++;
		strcpy(queue_array[rear],w);
	}
}
void de_queue()
{
	if(front==-1&&rear==-1)
	{
		printf("can't delete");
	}
	else
	{
		front++;
	}
}
void append(struct char_array** head_ref, char new_data[20]) 
{ 
    /* 1. allocate node */
    struct char_array* new_node = (struct char_array*) malloc(sizeof(struct char_array)); 
  
    struct char_array *last = *head_ref;  /* used in step 5*/
   
    /* 2. put in the data  */
    strcpy(new_node->word  , new_data);
	//printf("%s\n",new_node->word); 
  
    /* 3. This new node is going to be the last node, so make next  
          of it as NULL*/
    new_node->next = NULL; 
  
    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL) 
    { 
       *head_ref = new_node; 
       return; 
    }    
    /* 5. Else traverse till the last node */
    while (last->next != NULL) 
        last = last->next; 
   
    /* 6. Change the next of last node */
    last->next = new_node; 
    return;     
}
int printRandoms(int lower, int upper,int count)
{
    int i;
    for (i = 0; i < count; i++) {
        int num = (rand() %(upper - lower + 1)) + lower;
		return num;
    }
}
char *sort(char *v)
{
	int i=0,j,len;
	char *t,temp;
	t=v;
	len=strlen(t);
	while(t[i]!='\0')
	{
		j=i+1;
		while(t[j]!='\0')
		{
			if(t[i]>t[j])
			{
				temp=t[i];
				t[i]=t[j];
				t[j]=temp;
			}
			j++;
		}
		i++;
	}
	return t;
}
void read_file(char string[60])
{
  FILE *fp;
  char st[20];
  char scanned_word[20];
  fp=fopen("D:\\DataStructuresProject\\dictionary.txt","r"); 
  int i=0,v;
  if (fp)  
  { v=printRandoms(10,1000,1);
    while(fgets(string, 20, fp))
	{
		i++;
		if(i==v)
		break;
	} 
	i=0;
	while(string[i]!='\n')
	{
		i++;
	}
    string[i] = '\0';
    //printf("\nThe name read from the file is %s.\n", string );
    strcpy(st,string);
    //printf("st:%s\n",st);
	printf("\nAnd Your Word Is %s.\n",sort(string) );
	//printf("crct:%s",st);
	printf("Enter Your Word:\n");
	scanf("%s",scanned_word);
	printf("correct_word:%s",scanned_word);
	if(strcmp(scanned_word,st)==0) 
	{
		first_level_score++;
	}
	else
	{
		if(lives==2)
		{
			printf("\nOops!! You went wrong...Better luck next time");
			lives--;
		}
		else if(lives==1)
		{
			printf("\nOoops!!You Went Wrong Again...You Lost the game...Try Again");
			exit(0);
		}
		
	}
	printf("\nyour score:%d",first_level_score); 
  }
  else          
  {
    printf("An error occurred while opening the file.\n");
  }
  fclose(fp);  
}
void dispay(struct char_array **l)
{ printf("IN DISPLAY\n");
    while(*l!=NULL)
    {
        printf("%s\n",(*l)->word);
        (*l)=(*l)->next;
    }
}
void read_file2(char string[60],int val)
{
  int i=0,v;
  FILE *fp;
  char filename[20],file_word[20][20],text[20];
  fp=fopen("D:\\trialthing\\newdictionary.txt","r"); /* open file for input */
  if (fp) 
  {        
    v=val;
    while(fgets(string, 60, fp))
	{
		i++;
		if(i==v)
		break;
	} 
	i=0;
	while(string[i]!='\n')
	{
		i++;
	}
	i=0;
	while(string[i]!='\n')
	{
		//printf("\nin while\n");
		printf("%c",string[i]);
		if(string[i]==' ')
		{
			printf("\n");
		}
		i++;
	}
	string[i]='\0';
    //printf("The name read from the file is %s.\n", string );
    for(i=0;i<5;i++)
    {
    	printf("\nenter %d word\n",i+1);
    	scanf("%s",&text);
    	add_queue(text);
    	//printf("\nrearVAL:%d frontVAL:%d",rear,front);
    	if(front!=rear)
    	{
    		//printf("not '-1' rear:%c front:%c",queue_array[rear][strlen(queue_array[rear]-1)],queue_array[front][strlen(queue_array[front])-1]);
    		if(queue_array[rear][strlen(queue_array[rear]-1)]==queue_array[front][strlen(queue_array[front])-1])
    		{
    			printf("\ncontinue\n");
    			de_queue();
			}
			else{
				lives--;
				printf("\noops!!went wrong\n");
				if(i==5) second_level_score--;
				if(lives==0)
				{
					printf("\nlives completed\n");
					exit(0);
				}
				break;
			}
		}
  }
  if(i==5)
  second_level_score++;
  printf("\nyour SECOND LEVEL SCORE:%d\n",second_level_score);
}
  else          
  {
    printf("An error occurred while opening the file.\n");
  }
  fclose(fp); 
}
void generate_list(struct char_array **list)
{
	int i,v,j=0;
	FILE *fp;
	char string[5][20];
	fp=fopen("D:\\DataStructuresProject\\dictionary.txt","r"); 
	if (fp)  
  { 
  	for(i=0;i<5;i++)
  	{
  		j=0;
  		rewind(fp);
	v=printRandoms(25,1000,1);
    while(fgets(string[i], 20, fp))
	{
		j++;
		if(j==v)
		break;
	} 
	j=0;
	while(string[i][j]!='\n')
	{
		j++;
	}
    string[i][j] = '\0';
    //printf("\n%s\n",string[i]);
    append(list,string[i]);
    //printf("\nafter appending\n");
   // printf("\n%s\n",(*list)->word);
	}
}
	
}
void display_word(struct char_array **l)
{
int i,j,ii,len,iii,kk,f=0;
char word[20],word2[20],letter;
FILE *fp;
char d='_';
fp=fopen("D:\\DataStructuresProject\\dictionary.txt","r"); 
for(iii=0;iii<5;iii++)
{
	f=0;
	if(lives<=0){
		printf("\nYOU HAVE NO MORE LIVES\n");
		exit(0);
	}
    strcpy(word,(*l)->word);
    //printf("\n%s\n%s\n",word,(*l)->word);
    len=strlen(word);
	for(i=0;i<len;i++)
	{
		word2[i]='#';
	}
	word2[i]='\0';
	for(i=0;i<len;i++)
	{
		printf("%c",word2[i]);
	}
	printf("\n");
	for(i=0;i<len;i++)
	{
		printf("\nENTER A CHAR\n");
		scanf(" %c",&letter);
		for(j=0;j<len;j++)
		{
			if(letter==word[j])
			{
				word2[j]=letter;
			}
		}
		for(ii=0;ii<len;ii++)
		{
			printf("%c",word2[ii]);
		}
		if(strcmp(word,word2)==0)
		{
			printf("\nwon\n");
			third_level_score++;
			f=1;
			break;
		}
	//	printf("\nword:%s\nword2:%s",word,word2);
	}
	if(f==0)
	{
		printf("OOPS!!! YOU LOST ONE LIFE");
		lives--;
	}
	printf("\nYOUR SCORE:%d\n",third_level_score);
	(*l)=(*l)->next;
}
}
void main()
{
	int i,k;
	char name[20],c[40];
	struct char_array *list=NULL,*v=NULL;
	printf("\n********************************~~~~~WELCOME TO THE WORD GAME~~~~~*************************************\n");
	printf("enter your name:");
	scanf("%s",name);
	printf("Ooohhh!!!that's really a good name,welcome to the 1st level %s",name);
	printf("IN THIS GAME YOU WILL BE GIVEN 2 LIVES");
	printf("\n********************************~~~~~WELCOME TO THE FIRST LEVEL~~~~~*************************************\n");
	printf("IN THIS LEVEL A WORD WITH JUMBELED LETTER IS DISPLAYED, YOU SHOULD GUESS THE ACTUAL WORD AND ENTER THE WORD,\n IF THE WORD IS CORRECT THE WORDS WILL BE CONTINUED IN A SIMILAR FASHION 10 WORDS WILL BE DISPLAYED\n AT ANY POINT OF TIME IF YOU COMMIT A MISTAKE THEN YOUR LIVES WILL BE DEDUCTED \nAND IF YOU LOOSE THE 2 LIVES THEN YOU WILL LOOSE THE GAME");
	char ch[20];
	for(i=0;i<5;i++)
	{
		read_file(ch);
	}
	printf("Hurray !!! You entered the 2nd level....  \n");
	printf("*****************************~~~~~WELCOME TO THE SECOND LEVEL~~~~~***********************************\n");
	if(lives>0)
	{
		k=printRandoms(1,30,1);
		read_file2(c,k);
	}
	front=-1;rear=-1;
	if(lives>0)
	{
		k=printRandoms(30,50,1);
		read_file2(c,k);
	}
	front=-1;rear=-1;
	if(lives>0)
	{
		k=printRandoms(30,100,1);
		read_file2(c,k);
	}
	front=-1;rear=-1;
	if(lives>0)
	{
		k=printRandoms(30,140,1);
		read_file2(c,k);
	}
	front=-1;rear=-1;
	if(lives>0)
	{
		k=printRandoms(30,360,1);
		read_file2(c,k);
	}
	
	printf("*****************************~~~~~WELCOME TO THE THIRD LEVEL~~~~~***********************************\n");
	generate_list(&list);
	//dispay(&list);
	display_word(&list);	
}
	
