#include "fct10.h"

int main()
{
	srand(time(NULL));
	int v[6][6];///modif
	matrice_ad(&v);
	afisare_matrice(v);
	printf("\n");
	matrice_cost(&v);
	afisare_matrice(v);
	printf("\n");
	///am terminat de creat matricea de adiacenta, respectiv costuri peste aceasta
	///practic am reusit sa cream graful conform cerintei
	int sps[6]={0,0,0,0,0,0}, MAX=999999999;///modif
	int dist[6]={MAX,MAX,MAX,MAX,MAX,MAX};///modif
	int drumuri[6]={1,1,1,1,1,1};///vector continand nr de muchii de la nodul susrsa la toate celelalte; modif
	int sursa=rand() %6, nod=-1;///modif
	printf("%d",sursa);
	printf("\n");
	sps[sursa]=1;
	dist[sursa]=0;
	drumuri[sursa]=0;
	afisare_vector(sps);
	printf("\n");
	afisare_vector(dist);
	printf("\n");
	afisare_vector(drumuri);
	printf("\n");
	actualization(&dist,v,sursa);
    while(verif_vect(sps))
    {
    	nod=alegere_nod(&sps,dist);
    	actualization(&dist,v,nod,&drumuri);
	}
	printf("\n");
	afisare_vector(sps);
	printf("\n");
	afisare_vector(dist);
	printf("\n");
	///AM TERMINAT EX. 1
	afisare_vector(drumuri);
	printf("\n");
	return 0;
}
