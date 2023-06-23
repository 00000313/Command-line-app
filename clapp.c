#include<stdio.h>
#include<string.h>

typedef struct student {
                    int rollno;
                    char name[25];
                    }ST;
                    
int numberofstudentsadded;
   
ST s[100];

void add();
void list();
void search();
void edits();
void deletes();
int main() {
int ch;
char m;
numberofstudentsadded=0;
while(1)
 {  
 printf("1.Add student \n");
 printf ("2.Edit student \n");
 printf("3.Search student\n");
 printf ("4.Delete student \n");
 printf ("5.list of all students \n");
 printf ("6.exit\n");
 printf("Enter your choice (1-6)");
 scanf("%d",&ch);
 fflush(stdin);
  
if(ch==1)
   {
     if(numberofstudentsadded<100)
        {
         add();
        }
     else{
          printf("Only 100 students can be added,press any key to continue...");
          getchar();
          fflush(stdin);
         }
   }
else if(ch==5)
   {
          if(numberofstudentsadded>0)
    	  list();
          else
	      printf("No students added yet,press any key to continue...");
	      m=getchar();
	      fflush(stdin);
   }
else if(ch==3)
   {
    if(numberofstudentsadded>0)
       	 search();
       	 else printf("No student added yet,press any key to continue....");
       	 m=getchar();
       	 fflush(stdin);       	
   }
   
else if(ch==4)
   {
       if(numberofstudentsadded>0)
 	    deletes();
	   else
	   {	  
	     printf("NO student added yet , press any key to continue....");
	     m=getchar();
	     fflush(stdin);		
	   }
   }
	   
else if(ch==2)
   {
      if(numberofstudentsadded>0)
        edits();
      else
       	 printf("No students added yet,press any key to continue...");
		 m=getchar();
	     fflush(stdin);
   }
   
else if(ch==6)
       break;
else{
   	   printf("Please enter valid input\n");
	}    
 }
 return 0;
}

 
void add()
{
int rl,e;
char nm[25];
char m;

printf("Add module\n");
printf("----------\n");
printf("Enter roll number:");
scanf("%d",&rl);
fflush(stdin);
if(rl<101 || rl>200)
  {
     printf("Invalid roll \n");
     return;
  }
   for(e=0;e<numberofstudentsadded;e++)
     {
      if(s[e].rollno==rl)
       {
       printf ("roll number is already allocate to %s",s[e].name);
       return;
       }
     }
   printf ("Enter name:");
   fgets(nm,25,stdin);
   fflush (stdin);
   printf ("Save (Y/N)");
   scanf ("%c",&m);
   fflush(stdin);
   if(m!='Y' && m!='y')
    {
        printf ("Student not added, Press any key to continue ");
        m=getchar ();
        fflush (stdin);
        return;
    }
    s[numberofstudentsadded].rollno=rl;
    strcpy(s[numberofstudentsadded].name,nm);
    printf("Student added\n");
    numberofstudentsadded++;
    printf("Press any key to continue :");
    m=getchar();
    printf("\n");
  }
 
void edits()
      { 
       char nm[25],m;
       int rl, found,e;
       printf("Edit module\n ");
       printf ("-----------\n");
       printf("Enter roll number to edit :");
       scanf ("%d",&rl);
       fflush(stdin);
 
    if(rl<101 || rl>200)
    {   
      printf("Invalid roll number, press any key to continue :");
      m=getchar();
      fflush(stdin);
      return;
    }   

     for(e=0;e<numberofstudentsadded;e++)
     {
       if(rl==s[e].rollno)
        {
           found=1;
           break;
         
          }
     }
       if(found==0)
       {
           printf("roll number not found\n");
           printf("Press any key to continue:\n");        
           return;
       }
     else{
           printf("Roll number is allocated to %s",s[e].name);
           printf("Edit (Y/N)\n");
           m=getchar();
           fflush(stdin);
         if(m!='Y' && m!='y')
           {
               printf ("Student not edited, Press any key to continue ");
               m=getchar ();
               fflush (stdin);
               return;
           }
         printf("Enter new name :");
         fgets(nm,25,stdin);
         fflush(stdin);
         strcpy(s[e].name,nm);
         printf ("Student updated successfully , ");
         printf("Press any key to continue");
         m=getchar();
   }
}

void list()
{
char m;
int e;
printf("list module\n");
printf("list of all students\n");
printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");

for(e=0;e<numberofstudentsadded;e++)
{
 printf ("Roll number of student is : %d\n",s[e].rollno);
 printf("Name of student is : %s\n",s[e].name);
 printf("------------------------\n");
}
printf("press any key to continue:");
m=getchar();
fflush(stdin);
}



void search()
{
int e,found,rl;
char m;
found=0;
printf("Search module\n");
printf("--------------\n");
printf ("Enter roll number to search\n");
scanf("%d",&rl);
fflush (stdin);
if(rl<101 || rl>200)
 { 
  printf("Invalid roll number, press any key to continue \n");
  m=getchar ();
  fflush (stdin);
  return;
 }

for(e=0;e<numberofstudentsadded;e++)
  {
   if(rl==s[e].rollno)
    {
      found=1;
      break;
    }
    }
    if(found==0)
     {
       printf("Roll no not found , ");
       printf("press any key to continue");
       m=getchar();
       fflush(stdin);
       return;
    }
    else{
         printf("\nName:%sRoll number:%d\n",s[e].name,rl);
        
        printf("press any key to continue ");
        m=getchar();
        fflush(stdin);
	   }
}

void deletes()
{
    int ep,rl,e,found;
    char m;
    printf ("Enter roll no to delete\n");
    scanf("%d",&rl);
    found=0;
     fflush(stdin);
       if(rl<101 || rl>200)
       { 
         printf("Invalid roll number, press any key to continue \n");
         m=getchar();
         fflush(stdin);
         return;
       }
  for(e=0;e<numberofstudentsadded;e++)
   {
    if(rl==s[e].rollno)
    {
     found=1;
     break;
    }
  }
    if(found==0)
    {
        printf("roll no not found , press any key to continue.....\n");
        return;
    }
    if(found==1)
        {
		printf("Student found\n");
        printf("Roll no:%d , Name %s\n",s[e].rollno,s[e].name);
        printf("are you sure you want to delete");
        printf("\n(Y/N)");
        m=getchar();
        fflush(stdin);
        if(m!='y' && m!='Y')
        {
        	printf("Student not deleted......");
        	printf("press any key to continue....");
        	return;
        }
       else{
            ep=numberofstudentsadded-2;
          while(e<=ep)
            {
            	s[e].rollno=s[e+1].rollno;
            	strcpy(s[e].name,s[e+1].name);
            	e++;
		    }
		    numberofstudentsadded--;
		    printf("Student deleted successfully.....\npress any key to continue....");
		   } 
       }
}
