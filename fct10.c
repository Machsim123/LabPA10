#include "fct10.h"

void addAtBeginning(Node **head, int val)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->val=val;
	newNode->next = *head;
	*head = newNode;
}

void addAtEnd(Node** head, int val)
{
	Node *aux=*head;
	Node* newNode = (Node*)malloc(sizeof(Node)); 
	newNode->val=val;
	if (*head == NULL) addAtBeginning(&*head, val);
	else{  
		while (aux->next!=NULL) aux = aux->next;
		aux->next = newNode;  
		newNode->next = NULL; 
	}
}

void display(Node *head)
{
	while (head!=NULL){
		printf ("%d ", head->val);
		head=head->next;
	}
	printf("\n");
}

void matrice_ad(int v[6][6])///modif
{
	int i,j,nr=0;
	for(i=0;i<6;i++)
	   for(j=0;j<6;j++)
	      {
		  if(i<j) 
		     {v[i][j]=rand() % 2; v[j][i]=v[i][j];}
		  else if(i==j) v[i][j]=0;}
		
}

void matrice_cost(int v[6][6])///modif
{
	int i,j,nr=0;
	for(i=0;i<6;i++)
	   for(j=0;j<6;j++)
	      if(i<j && v[i][j]==1)
		     v[i][j]=v[j][i]=rand() %21;
}

void afisare_matrice(int v[6][6])///modif
{
	int i,j;
	for(i=0;i<6;i++)
	   {for(j=0;j<6;j++)
	      printf("%2d ",v[i][j]);
	    printf("\n");
	   }
}

int verif_vect(int sps[6])///modif
{
	int i;
	for(i=0;i<6;i++)
	if(sps[i]!=1)  return 1;
	return 0;
}

int alegere_nod(int sps[6], int dist[6])///modif
{
	int i, min=99999999, mini=-1;
	for(i=0;i<6;i++)
	if(sps[i]!=1 && min>dist[i]) 
	{
	 min=dist[i]; 
	 mini=i;
	}
	sps[mini]=1;
	return mini;
}

void actualization(int dist[6], int v[6][6], int nod, int drumuri[6])///modif
{
	int i,j;
	i=nod;
	for(j=0;j<6;j++)
	    if(v[i][j]!=0 && dist[j]>v[i][j]+dist[i]) 
		{
		dist[j]=v[i][j]+dist[i];
		drumuri[j]++;
	   }
}

void afisare_vector(int v[6])///modif
{
	int i;
	for(i=0;i<6;i++)
		printf("%2d ",v[i]);
}

