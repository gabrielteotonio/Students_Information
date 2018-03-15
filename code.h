struct student
{
	char name[81];
	char id[12];
	float grade;
};
typedef struct student Student;

struct list2
{
	Student*info;
	struct list2*prev;
	struct list2*next;
};
typedef struct list2 List2;

List2* lst2_create(void)
{
	return NULL;
}

int lst2_empty(List2*l)
{
	return(l==NULL);
}

List2* lst2_insert_end(List2*l, char*name, char*id, float grade)
{
	Student*a=(Student*)malloc(sizeof(Student));
	List2*new=(List2*)malloc(sizeof(List2));
	List2*p=l;
	strcpy(a->name,name);
	strcpy(a->id, id);
	a->grade=grade;
	new->info=a;
	new->prev=NULL;
	new->next=NULL;
	if(lst2_empty(l))
	{
		l=new; 
	}
	else
	{
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=new;
		new->prev=p;
	}
	return l;
}

List2* lst2_insert_beg(List2*l, char*name, char*id, float grade)
{
	Student*a=(Student*)malloc(sizeof(Student));
	List2*new=(List2*)malloc(sizeof(List2));
	strcpy(a->name,name);
	strcpy(a->id, id);
	a->grade=grade;
	new->prev=NULL;
	new->next=l;
	l->prev=new;
	return new;
}

void lst2_print(List2* l)
{
	List2*p;
	for(p=l; p!=NULL; p=p->next)
	{
		printf("\nStudent's name: %s", p->info->name);
		printf("\nStudent's id: %s", p->info->id);
		printf("\nStudent's grade: %d",p->info->grade);
	}
	printf("\n");
}

List2* lst2_search(List2*l, char*id)
{
	int flag;
	List2*p;
	for(p=l ;p!=NULL; p=p->next)
	{
		flag=strcmp(l->info->id, id);
		if(flag==0)
		{
			return p;
		}
	}
	return NULL;
}

List2* lst2_take_beg(List2*l, Student*a)
{
	Student*a=(Student*)malloc(sizeof(Student));
	List2*p;
	a=l->info;
	free(l->info);
	l->next->prev=NULL;
	p=l->next;
	free(l);
	return p;
}

List2* lst2_take_end(List2*l, Student* a)
{
	Student*a=(Student*)malloc(sizeof(Student));
	List2*p=l;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	a=p->info;	
	free(p->info);
	p->prev->next=NULL;
	free(p);
	return l;
}

void ls2_release(List2*l)
{
	List2*p=l;
	List2*g;
	while(p!=NULL)
	{
		g=p;
		free(p->info);
		p=p->next;
		free(g);
	}
	free(p);
}

float Avg(List2*l)
{
	int count=0;
	float avg=0;
	float sigma=0;
	List2*p;
	for(p=l; p!=NULL; p=p->next)
	{
		sigma=sigma+(p->info->grade);
		count=count+1;
	}
	avg=sigma/count;
	return avg;
}

float max(List2*l)
{
	float maximum=0;
	List2*p;
	for(p=l; p!=NULL; p=p->prox)
	{
		if((p->info->grade)>maximum)
		{
			maximum=p->info->grade;
		}
	}
	return maximum;
}

float min(List2*l)
{
	float minimum=l->info->grade;
	List2*p;
	for(p=l; p!=NULL; p=p->next)
	{
		if((p->info->grade)< minimum)
		{			
			minimum=p->info->grade;		
		}
	}
}

List2* lst2_take_id(List2*l,char*id, Student* a)
{
	Student*a=(Student*)malloc(sizeof(Student));
	List2*p;
	List2*q;
	p=lst2_search(l,id);
	if(!p==NULL)
	{
		if(p->next==NULL)
		{
			a=p->info;
			free(p->info);
			p->prev->next=NULL;
			free(p);
			return l;
		}
		else 
		{
			if(p->prev==NULL)
			{
				a=p->info;
				free(p->info);
				q=p->next;
				q->prev=NULL;
				free(p);
				return q;
			}
			else
			{
				a=p->info;
				free(p->info);
				p->prev->next=p->next;
				p->next->prev=p->prev;
				free(p);
				return l;
			}
		}	
	}
	else
	{
		return NULL;
	}
}

int quantity(List2*l)
{
	int count=0;
	List2*p;
	for(p=l; p!=NULL; p=p->next)
	{
		count=count+1;
	}
	return count;
}
