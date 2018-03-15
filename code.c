#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"code.h"

void main()
{
	List2*new=lst2_create();
	int menu;
	do
	{
		printf("\n========= Choose one of the following options =========");
		printf("\n1 - Insert a new student into the database");
		printf("\n2 - Withdraw a student");
		printf("\n3 - Search a student");
		printf("\n4 - View the database");
		printf("\n5 - Database's summary");
		printf("\n0 - Exit");
		printf("\n Type the number corresponding to your choice: ");
		scanf("%d", &menu);
		
		if(menu==0)
		{
			return ;
		}
		else
		{
			if( menu==1)
			{
				int submenu1;
				do
				{
					printf("\n1 - Insert at the beginning");
					printf("\n2 - Insert at the end");
					printf("\n0 - Exit");
					scanf("%d", &submenu1);
					if(submenu1==0)
					{
						submenu1=3;
					}
					if(submenu1==1)
					{
						char name[81];
						char id[12];
						float grade;
						printf("\nType the student's name: ");
						scanf("%s",name);
						printf("\nType the student's id: ");
						scanf("%s",id);
						printf("\nType the student's grade: ");
						scanf("%f", &grade);
						new=lst2_insert_beg(new,name,id,grade);
						printf("\nStudent added successfully");
					}
					if(submenu1==2)
					{
						char name[81];
						char id[12];
						float grade;
						printf("\nType the student's name: ");
						scanf("%s",name);
						printf("\nType the student's id: ");
						scanf("%s",id);
						printf("Type the student's grade: ");
						scanf("%f", &grade);
						new=lst2_insert_end(new,name,id,grade);
						printf("\nStudent added successfully");
					}
				}while((submenu1<0) || (submenu1>2));
				submenu1=0;
			}
			else
			{
				if(menu==2)
				{
					int submenu2;
					Student* student;
					do
					{
						printf("\n1 - Withdraw at the beginning");
						printf("\n2 - Withdraw at the end");
						printf("\n3 - Withdraw by using the id");
						printf("\n0 - Exit");
						scanf("%d", &submenu2);	
						if(submenu2==0)
						{
							submenu2=4;
						}						
						if( submenu2==1)
						{
							if(!lst2_empty(new))
							{
								new=lst2_take_beg(new,student);
								printf("\nName of student withdrawn: %s", student->name);
								printf("\nId of student withdrawn: %s", student->id);
								printf("\nGrade of student withdrawn: %f", student->grade);
							}
							else
							{
								printf("\nEmpty list!\n Invalid withdraw!");
							}
						}
						if(submenu2==2)
						{
							if(!lst2_empty(new))
							{
								new=lst2_take_end(new,student);
								printf("\nName of student withdrawn: %s", student->name);
								printf("\nId of student withdrawn: %s", student->id);
								printf("\nGrade of student withdrawn: %f", student->grade);
							}
							else
							{
								printf("\nEmpty list!\n Invalid withdraw");
							}
						}
						if(submenu2==3)
						{
							if(!lst2_empty(new))
							{
								List2* aux;
								char id[12];
								printf("\nType the student's id for withdrawing: ");
								scanf("%s", id);
								aux=lst2_search(new,id);
								if(!aux==NULL)
								{
									printf("\nName of student withdrawn: %s", student->name);
									printf("\nId of student withdrawn: %s", student->id);
									printf("\nGrade of student withdrawn: %f", student->grade);
								}
								else
								{
								 	printf("\nStudent not found");
								}		
							}
							else
							{
								printf("\nEmpty list!\n Invalid withdraw");
							}
						}
					}while((submenu2<0) || (submenu2>3));
				}
				else
				{
					if(menu==3)
					{
						List2* search;
						char id[12];
						printf("Type the student's id for withdrawing: ");
						scanf("%s",id);
						search=lst2_search(new,id);
						if(!search==NULL)
						{
							printf("\nStudent's name: %s", search->info->name);
							printf("\nStudent's id: %s", search->info->id);
							printf("\nStudent's grade: %f", search->info->grade);
						}
						else
						{
							printf("\nStudent not found");
						}
					}
					else
					{
						if(menu==4)
						{
							if(!lst2_empty(new))
							{
								lst2_print(new);
							}
							else
							{
								printf("\nEmpty database");
							}
						}
						else
						{
							if(menu==5)
							{
								float maximum;
								float minimum;
								float avg;
								int total;
								if(!lst2_empty(new))
								{
									maximum=max(new);
									minimum=min(new);
									avg=Avg(new);
									total=quantity(new);
									printf("\nMaximum grade = %f", &maximum);
									printf("\nMinimum grade = %f", &minimum);
									printf("\nGrade average = %f", &media);
									printf("\nTotal of inserted students = %d", &total);
								}
								else
								{
									printf("\nEmpty list!");
								}
							}
						}
					}
				}
		
			}
		}	
	}while((menu<0) || (menu> 5));
}
