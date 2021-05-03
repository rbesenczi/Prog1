#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Link {
	struct Link* pre;
	struct Link* suc;
};

struct List {
	struct Link* first;
	struct Link* last;
};

struct Name {
	struct Link lnk;
	char* p;
};

void init(struct List* lst);
struct List* create();
void clear(struct List* lst);
void destroy(struct List* lst);

void push_back(struct List* lst, struct Link* p);
void push_front(struct List* lst, struct Link* p);
void insert(struct List* lst, struct Link* p, struct Link* q);
void erase(struct List* lst, struct Link* p);

struct Link* advance(struct Link* p, int n);

struct Name* make_name(char* n);

int main()
{
	int count = 0;
	struct List* names = create();
	struct Link* curr;

	push_back(names, (struct Link*)make_name("Norah"));
	push_back(names, (struct Link*)make_name("Annamarie"));
	push_back(names, (struct Link*)make_name("Kris"));
	push_back(names, (struct Link*)make_name("John"));
	push_back(names, (struct Link*)make_name("Donald"));
	push_back(names, (struct Link*)make_name("Bill"));
	push_back(names, (struct Link*)make_name("Barack"));

	erase(names, advance(names->first,1));

	curr = names->first;
	for (; curr != 0; curr = curr->suc)
	{
		count++;
		printf("element %d: %s\n", count, ((struct Name*)curr)->p);
	}

	destroy(names);

	return 0;
}

void init(struct List* lst)
{
	assert(lst);
	lst->first = lst->last = 0;
}

struct List* create()
{
	struct List* lst = (struct List*)malloc(sizeof(struct List));
	init(lst);
	return lst;
}

void clear(struct List* lst)
{
	assert(lst);
	{
		struct Link* curr = lst->first;
		while(curr)
		{
			struct Link* next = curr->suc;
			free(curr);
			curr = next;
		}
		lst->first = lst->last = 0;
	}
}

void destroy(struct List* lst)
{
	assert(lst);
	clear(lst);
	free(lst);
}

void push_back(struct List* lst, struct Link* p)
{
	assert(lst);
	{
		struct Link* last = lst->last;
		if (last)
		{
			last->suc = p;
			p->pre = last;
		}
		else
		{
			lst->first = p;
			p->pre = 0;
		}
		lst->last = p;
		p->suc = 0;
	}
}

void erase(struct List* lst, struct Link* p)
{
	assert(lst);
	if(p == 0) return;
	
	struct Link* temp = p;

	if(p == lst->first)
	{
		if(p->suc){
			lst->first = p->suc;
			p->suc->pre = 0;
		}
		else
		{
			lst->first = lst->last = 0;
		}
	}
	else if(p == lst->last)
	{
		if(p->pre){
			lst->last = p->pre;
			p->pre->suc = 0;
		}
		else
		{
			lst->first = lst->last = 0;
		}
	}
	else
	{
		p->suc->pre = p->pre;
		p->pre->suc = p->suc;
	}
	free(temp);
	return;
}

struct Link* advance(struct Link* p, int n)
{
	if (n == 0) return p;
	else if (n < 0)
	{
		while (n < 0)
		{
			if(p->pre) p = p->pre;
			n++;
		}
	}
	else
	{
		while (n > 0)
		{
			if(p->suc) p = p->suc;
			n--;
		}
	}
	return p;
}

struct Name* make_name(char* n)
{
	struct Name* p = (struct Name*)malloc(sizeof(struct Name));
	p->p = n;
	return p;
}
