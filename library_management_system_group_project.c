#include<stdio.h>
#include<conio.h>
#include<string.h>
void add(int);
void display(int);
void search(int);
void update(int);
void del(int);
struct library
{
	char sub[100];
	char book_name[100];
	char author_name[100];
	int total_pages;
	int quantity;
	int srl_no;
	float price;
}lib[100],temp;
void main()
{
	int op,i,flag=0;
	i=0;
	printf("*************** WELCOME TO LIBRARY MANAGEMENT SYSTEM ***************\n\n");
	
	while(flag!=1)
	{
		printf("\n1.Add book details\n2.Display book details\n3.Search a book\n4.Update book details\n5.Delete a book\n6.Exit\n");
		printf("\nenter option: ");
		scanf("%d",&op);
		printf("\n");
		switch(op)
		{
			case 1:
				add(i);
				break;
			case 2:
				display(i);
				break;
			case 3:
				search(i);
				break;
			case 4:
				update(i);
				break;
			case 5:
				del(i);
				break;
			case 6:
				flag=1;
				break;
			default:
				printf("enter correct option\n");
				break;				
		}
		i++;
		
	}
	
	
}
void add(int j)
{
	printf("enter serial no of book: ");
	scanf("%d",&lib[j].srl_no);
	printf("enter subject: ");
	scanf("%s",&lib[j].sub);
	printf("enter book name: ");
	fflush(stdin);
	gets(lib[j].book_name);
	fflush(stdin);
	printf("enter author name: ");
	gets(lib[j].author_name);
	printf("enter total pages: ");
	scanf("%d",&lib[j].total_pages);
	printf("enter quantity: ");
	scanf("%d",&lib[j].quantity);
	printf("enter price: ");
	scanf("%f",&lib[j].price);
}
void display(int j)
{
	int k,m;
	printf("Serial no of book\t");
	printf("Subject\t\t");
	printf("Book name\t");
	printf("Author name\t");
	printf("Pages\t");
	printf("Quantity\t");
	printf("Price\t\n");
	for(k=0;k<j;k++)
	{
		if(lib[k].srl_no==0)
		{
			continue;
		}
		else
		{
			printf("%d\t\t\t",lib[k].srl_no);
			printf("%s\t\t",lib[k].sub);
			printf("%s\t\t",lib[k].book_name);
			printf("%s\t\t",lib[k].author_name);
			printf("%d\t",lib[k].total_pages);
			printf("%d\t\t",lib[k].quantity);
			printf("%.2f\t\n",lib[k].price);//after point it will display 2 values
		}
	}
}
void search(int j)
{
	int k,f,op,flag=0;//f is used to know that word is found or not
	char word[20];
	while(flag!=1)
	{
		printf("\n1.Subject\n2.Book name\n3.Author name\n4.Exit\n");
		printf("enter op to be searched: ");
		scanf("%d",&op);
		for(k=0;k<j;k++)
		{
			if(lib[k].srl_no==0)
			{
				continue;
			}
			else
			{
				f=0;
				switch(op)
				{
					case 1:
						printf("enter letter/word to be searched: ");
						scanf("%s",&word);
						if(strstr(lib[k].sub,word)!=NULL)
						{
							printf("Serial no of the book details that has been found: %d\n",lib[k].srl_no);
							printf("\nSubject:%s\n",lib[k].sub);
							printf("Book name:%s\n",lib[k].book_name);
							printf("Author name:%s\n\n",lib[k].author_name);
							f++;
						}
						break;
					case 2:
						printf("enter letter/word to be searched: ");
						scanf("%s",&word);
						if(strstr(lib[k].book_name,word)!=NULL)
						{	
							printf("Serial no of the book details that has been found: %d\n",lib[k].srl_no);
							printf("\nSubject:%s\n",lib[k].sub);
							printf("Book name:%s\n",lib[k].book_name);
							printf("Author name:%s\n\n",lib[k].author_name);
							f++;
						}
						break;
					case 3:
						printf("enter letter/word to be searched: ");
						scanf("%s",&word);
						if(strstr(lib[k].author_name,word)!=NULL)
						{
							printf("Serial no of the book details that has been found: %d\n",lib[k].srl_no);
							printf("\nSubject:%s\n",lib[k].sub);
							printf("Book name:%s\n",lib[k].book_name);
							printf("Author name:%s\n\n",lib[k].author_name);
							f++;
						}
						break;
					case 4:
						flag=1;
						break;
					default:
						printf("Pls. enter correct choice");
						break;			
				}
			}
		}
		if(f==0)
		{
			printf("Not found\n");
		}
			
	}
	
	
}
void update(int j)
{
	int k,n,op,flag,l;
	printf("enter serial no for updation of book details: ");
	scanf("%d",&n);
	for(k=0;k<j;k++)
	{
		if(lib[k].srl_no==n)
		{
			l=0;
			flag=0;
			while(flag!=1)
			{
				printf("\n1.Subject\n2.Book name\n3.Author name\n4.Total pages\n5.Quantity\n6.Price\n7.Exit\n");
				printf("enter option to be updated: ");
				scanf("%d",&op);
				switch(op)
				{
					case 1:
						printf("enter subject name to be updated: ");
						scanf("%s",&lib[k].sub);
						break;
					case 2:
						printf("enter book name to be updated: ");
						fflush(stdin);
						gets(lib[k].book_name);
						break;
					case 3:
						printf("enter author name to be updated: ");
						fflush(stdin);
						gets(lib[k].author_name);
						break;
					case 4:
						printf("enter totoal pages to be updated: ");
						scanf("%d",&lib[k].total_pages);
						break;
					case 5:
						printf("enter quantity to be updated: ");
						scanf("%d",&lib[k].quantity);
						break;
					case 6:
						printf("enter price to be updated: ");
						scanf("%f",&lib[k].price);
						break;
					case 7:
						flag=1;
						break;	
					default:
						printf("enter correct option\n");
						break;
				}
				l++;
				
			}
			
		}
	}
}
void del(int j)
{
	int k,n;
	printf("enter serial no to delete: ");
	scanf("%d",&n);
	for(k=n-1;k<j;k++)
	{
		lib[k]=lib[k+1];
	}
}

