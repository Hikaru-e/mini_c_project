#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define nom_max_ch 50
#define ville_max_ch 20

struct Date
{
    int jour;
    int mois;
    int anne;
};

struct Adresse
{
    int num;
    char ville[nom_max_ch];
};

struct Etudiant
{
    char NomComplet[ville_max_ch];
    int cne;
    struct Date dat;
    struct Adresse adr;
}*LEtd;


int nbrEtd=0;       //quand l'utilisateur va choisir d'ajouter un �tudiant, cette variable sera initialis� avec le nombre entr� par l'utilisateur

//********************* La fonction menu *********************
int menu()
{
    int choix;
    system("cls");
    printf("\n\n\t\t\t******\n");
    printf("\t\t\t*MENU*\n");
    printf("\t\t\t******");
    printf("\n\n\t[1]  Modifier tous les elements de tableau\t\t\t");
    printf("\n\t[2]  Modifier un element de tableau\t\t\t");
    printf("\n\t[3]  Ajoute d'un/des etudiant(s)\t\t\t");
    printf("\n\t[4]  Afficher le contenu de tableau\t\t\t");
    printf("\n\t[5]  Afficher par CNE\t\t\t");
    printf("\n\t[6]  Supprimer par CNE\t\t");
    printf("\n\t[7]  Recherche par dichotomie\t\t");
    printf("\n\t[8]  Echanger\t\t");
    printf("\n\t[9]  Tri\t");
    printf("\n\n\t[10]  EXIT\t\t\t\t\t\t");
    printf("\n\n\t(note) Vous devez quittez le programme en choisissant le choix \"10\" pour sauvegarder vos donn�es dans un fichier");
    printf("\n\n\tENTRER VOTRE CHOIX : ");
    scanf("%d",&choix);
    return choix;
}

//********************* La fonction saisie, peut �tre aussi utilis� pour modifier tous les �l�ments du tableau *********************
struct Etudiant * saisie(int taille)
{
    system("cls");
    int i;
    printf("\n==================================================");
    for(i=0;i<(taille+nbrEtd);i++)
    {
        printf("\n\n=> Etudiant N%d\t",i+1);

        printf("\tNom Complet\t: ");
        fflush(stdin);
        gets((LEtd+i)->NomComplet);


        printf("\n\t\t\tCNE\t\t: ");
        fflush(stdin);
        scanf("%d",&(LEtd+i)->cne);

        printf("\n\t\t\tDate : \n\t\t\t\t Jour\t: ");
        fflush(stdin);
        scanf("%d",&(LEtd+i)->dat.jour);
        printf("\n\t\t\t\t Mois\t: ");
        scanf("%d",&(LEtd+i)->dat.mois);
        printf("\n\t\t\t\t Anne\t: ");
        scanf("%d",&(LEtd+i)->dat.anne);

        printf("\n\t\t\tNum Adresse\t: ");
        fflush(stdin);
        scanf("%d",&(LEtd+i)->adr.num);

        printf("\n\t\t\tVille \t\t: ");
        fflush(stdin);
        gets((LEtd+i)->adr.ville);
        printf("\n==================================================");
    }
    return LEtd;
}

//********************* La fonction d'affichage des informations des �tudiants *********************
void Afficher(struct Etudiant * LEtd,int taille)
{
    system("cls");
    int i;
    printf("\n==================================================");
    for(i=0;i<(taille+nbrEtd);i++)
    {
        printf("\n%d.\t\tNom Complet \t: %s",i+1,(LEtd+i)->NomComplet);
        printf("\n\t\tCNE \t\t: %d",(LEtd+i)->cne);
        printf("\n\t\tDate \t\t: %d/%d/%d",(LEtd+i)->dat.jour,(LEtd+i)->dat.mois,(LEtd+i)->dat.anne);
        printf("\n\t\tNum Adresse \t: %d",(LEtd+i)->adr.num);
        printf("\n\t\tVille \t\t: %s",(LEtd+i)->adr.ville);
        printf("\n==================================================");
    }
}

//********************* La fonction de modification d'un �l�ment *********************
void ModifierElement(struct Etudiant * LEtd,int indice)
{
    printf("\n\n=> Etudiant N%d\t",indice+1);

    printf("\tNom Complet\t: ");
    fflush(stdin);
    gets((LEtd+indice)->NomComplet);

    printf("\n\t\t\tCNE\t\t: ");
    fflush(stdin);
    scanf("%d",&(LEtd+indice)->cne);

    printf("\n\t\t\tDate : \n\t\t\t\t Jour\t: ");
    fflush(stdin);
    scanf("%d",&(LEtd+indice)->dat.jour);
    printf("\n\t\t\t\t Mois\t: ");
    scanf("%d",&(LEtd+indice)->dat.mois);
    printf("\n\t\t\t\t Anne\t: ");
    scanf("%d",&(LEtd+indice)->dat.anne);

    printf("\n\t\t\tNum Adresse\t: ");
    fflush(stdin);
    scanf("%d",&(LEtd+indice)->adr.num);

    printf("\n\t\t\tVille \t\t: ");
    fflush(stdin);
    gets((LEtd+indice)->adr.ville);

    system("COLOR A");
    printf("\n\n\t\t** OPERATION REUSSIE **");
    printf("\n\n\tAPPUYEZ SUR UNE TOUCHE POUR CONTINUER...");
    getchar();
}

//********************* Fonction de recherche des informations d'un �tudiant selon son CNE *********************
void AfficheParCNE(struct Etudiant *LEtd, int cne, int taille)
{
    system("cls");
    int i,introuvable=0;
    for (i=0;i<taille;i++)
    {
        if((LEtd+i)->cne==cne)
        {
            system("COLOR A");
            printf("\n==============================================");
            printf("\n%d.  CNE=%d  => ",i+1,(LEtd+i)->cne);
            printf("\tNom Complet \t: %s",(LEtd+i)->NomComplet);
            printf("\n\t\tCNE \t\t: %s",(LEtd+i)->NomComplet);
            printf("\n\t\tDate \t\t: %d/%d/%d",(LEtd+i)->dat.jour,(LEtd+i)->dat.mois,(LEtd+i)->dat.anne);
            printf("\n\t\tNum Adresse \t: %d",(LEtd+i)->adr.num);
            printf("\n\t\tVille \t\t: %s",(LEtd+i)->adr.ville);
            printf("\n==============================================");
            break;
        }
        else if (i==taille-1)
            introuvable=1;
    }
    if (introuvable==1)
    {
        system("COLOR 4");
        printf("\n\n\t\t\aAUCUN ETUDIANT PORTE \"%d\" COMME CNE DANS LA LISTE...",cne);
    }
}

//********************* Fonction qui supprime la premi�re occurrence d'un �tudiant selon son CNE *********************
void SupprimerEtdParCNE(struct Etudiant *LEtd, int cne, int *taille)
{
    system("cls");
    int i,j,introuvable=0;
    //La variable "introuvable" recoit la valeur "1" si l'etudiant recherch� n'est pas trouv�
    for (i=0;i<*taille;i++)
    {
        if((LEtd+i)->cne==cne)
        {
            for(j=i;j<*(taille)-1;j++)
                LEtd[j]=LEtd[j+1];
            *(taille)-=1;

            //on n'a plus besoin de la derni�re case du tableau, donc on la lib�re
            LEtd = (struct Etudiant*) realloc(LEtd,*(taille)*sizeof(struct Etudiant));

            system("COLOR A");
            printf("\n\n\t\t** OPERATION REUSSIE **");
            printf("\n\n\tAPPUYEZ SUR UNE TOUCHE POUR CONTINUER...");
            fflush(stdin);
            getchar();
            break;
        }
    //la boucle va executer les instructions de "else if" si et seulement si la boucle va arriver � la derniere case du tableau et va pas trouver le CNE chercher
        else if (i==(*taille-1))
            introuvable=1;
    }
    if (introuvable==1)
    {
        system("COLOR 4");
        printf("\n\n\t\t\aAUCUN ETUDIANT PORTE \"%d\" COMME CNE DANS LA LISTE...",cne);
        fflush(stdin);
        getchar();
    }
    system("COLOR A");
    printf("\n\n\n\tVOULEZ VOUS AFFICHER LA LISTE D'ETUDIANTS ? (y/n) ");
    fflush(stdin);
    if ((getchar()=='y') || (getchar()=='Y'))
        Afficher(LEtd,*taille);
}

//********************* Fonction recherche par dichotomie d'un �tudiant *********************
struct Etudiant * ChercherDich(struct Etudiant *LEtd, int nbetud)
{
        system("cls");
        char aChercher[50] ;
        int  min, max, milieu, trouve ;
        int  compare, longueur ;

        printf("\n\n\t\t========================\n");
        printf("\t\t*RECHERCHE DICHOTOMIQUE*\n");
        printf("\t\t========================\n");
        printf("\n\n=========> Entrez le nom de l'etudiant recherche : ");
        fflush(stdin);
        gets(aChercher);

        longueur = strlen(aChercher) ;

        min = 0           ;
        max = nbetud - 1 ;
        trouve = 0 ;
        while (!trouve && min <= max)
        {
            milieu = (min + max) / 2 ;
            compare = strncmp(aChercher, (LEtd+milieu)->NomComplet, longueur);
            if ( compare < 0 )
                max = milieu - 1 ;
            else  if (compare > 0)
                min = milieu + 1 ;
            else
                trouve = 1 ;
        }
        if (!trouve)
        {
            system("cls");
            system("COLOR 4");
            printf("\n\n\t\aDESOLE, ON N'A PA PUS TROUVER \"%s\" DANS LA LISTE\n", aChercher);
        }

        else
        {
            system("COLOR A");
            Afficher(LEtd+milieu,1);
            return (LEtd+milieu);
        }
}

//********************* Fonction permet d��changer deux �tudiants d�indices i et j. *********************
void echange_Etd(int i, int j,struct Etudiant* LEtd)
{
    struct Etudiant tmp;
    tmp= *(LEtd+i);
    *(LEtd+i)=*(LEtd+j);
    *(LEtd+j)=tmp;
}

//********************* Fonction de tri par s�lection du tableau des �tudiants *********************
void Tri (struct Etudiant *LEtd, int nbPers) {
    int i, j, indicePetitElm ;

    for (i = 0 ; i < nbPers-1 ; i++)
    {
        indicePetitElm = i ;
        for ( j = i+1 ; j < nbPers ; j++ )
        {
            if ( strcmp( (LEtd+j)->NomComplet , (LEtd+indicePetitElm)->NomComplet ) < 0 )
                indicePetitElm = j ;
        }
        if (indicePetitElm != i)
            echange_Etd(i, indicePetitElm, LEtd);
    }
}

//********************* Fonction d'joute d'un our plusieurs �tudiants *********************
void AjourEtd(struct Etudiant* LEtd,int taille)
{
    int i;
    printf("\n\n\tCombien d'etudiant voulez vous ajouter ? ");
    scanf("%d",&nbrEtd);
    LEtd = (struct Etudiant*) realloc(LEtd,(taille+nbrEtd)*sizeof(struct Etudiant));
    printf("\n==================================================");
    for (i=taille;i<(taille+nbrEtd);i++)
    {

        printf("\n\n=> Etudiant N%d\t",i+1);

        printf("\tNom Complet\t: ");
        fflush(stdin);
        gets((LEtd+i)->NomComplet);

        printf("\n\t\t\tCNE\t\t: ");
        fflush(stdin);
        scanf("%d",&(LEtd+i)->cne);

        printf("\n\t\t\tDate : \n\t\t\t\t Jour\t: ");
        fflush(stdin);
        scanf("%d",&(LEtd+i)->dat.jour);
        printf("\n\t\t\t\t Mois\t: ");
        scanf("%d",&(LEtd+i)->dat.mois);
        printf("\n\t\t\t\t Anne\t: ");
        scanf("%d",&(LEtd+i)->dat.anne);

        printf("\n\t\t\tNum Adresse\t: ");
        fflush(stdin);
        scanf("%d",&(LEtd+i)->adr.num);

        printf("\n\t\t\tVille \t\t: ");
        fflush(stdin);
        gets((LEtd+i)->adr.ville);
        printf("\n==================================================");

    }
}



#define etd_tab "Etudiants.txt" //constante de nom du fichier

//********************* La fonction principale *********************
int main()
{
    FILE* in;
    int dim,cne,indice;
    int i,j;
	/*
	  "dim" est la dimension ou le nombre d'etudiants
	  "indice" est l'indice que l'utilisateur va entrer lors la modification d'un element du tableau
	*/
	
    do
    {
        printf("\n\n\tPour commencer, veuillez saisir le nombre d'etudiants : ");
        fflush(stdin);
        scanf("%d",&dim);
    }while (dim<=0);
    
    //********************* reservation dynamique du tableau LEtd *********************
    LEtd = (struct Etudiant*) malloc(dim*sizeof(struct Etudiant));
    
    
    printf("\n\n\tVoulez vous entrer les information de %d etudiant(s) maintenant ? (y/n) ",dim);
    fflush(stdin);
    if ((getchar()=='y') || (getchar()=='Y'))
        saisie(dim);

    system("COLOR A");
    printf("\n\n\n\t==> APPUYER SUR UNE TOUCHE POUR ENTRER LA MENU...");
    fflush(stdin);
    getchar();
    system("cls");
    
    //********************* d�but de la boucle switch *********************
    
    while(1)
    {
    system("COLOR A");
    switch(menu()) //la fonction menu va etre appele est sa valeur de retour va etre un argument de la boucle switch
        {
        case 1:
            saisie(dim);
            printf("\n\n\t\aAPPUYEZ SUR UNE TOUCHE POUR QUITTER...");
            fflush(stdin);
            getchar();
            break;
        case 2:
            Afficher(LEtd,dim);
            printf("\n\n\tEntrez l'indice d'element pour modification : ");
            scanf("%d",&indice);
            ModifierElement(LEtd,indice-1);
            printf("\n\n\t\aAPPUYEZ SUR UNE TOUCHE POUR QUITTER...");
            fflush(stdin);
            getchar();
            break;
        case 3:
            system("cls");
            AjourEtd(LEtd,dim);
            printf("\n\n\t\aAPPUYEZ SUR UNE TOUCHE POUR QUITTER...");
            fflush(stdin);
            getchar();
            break;
        case 4:
            Afficher(LEtd,dim);
            printf("\n\n\t\aAPPUYEZ SUR UNE TOUCHE POUR QUITTER...");
            fflush(stdin);
            getchar();
            break;
        case 5:
            system("cls");
            printf("\n\n\tVeuiller entrer un CNE (un entier) : ");
            scanf("%d",&cne);
            AfficheParCNE(LEtd, cne, dim);
            printf("\n\n\t\aAPPUYEZ SUR UNE TOUCHE POUR QUITTER...");
            fflush(stdin);
            getchar();
            break;
        case 6:
            system("cls");
            printf("\n\n\tVeuiller entrer un CNE (un entier) : ");
            scanf("%d",&cne);
            SupprimerEtdParCNE(LEtd, cne, &dim);
            printf("\n\n\t\aAPPUYEZ SUR UNE TOUCHE POUR QUITTER...");
            fflush(stdin);
            getchar();
            break;
        case 7:
            Tri (LEtd,dim) ;
            ChercherDich(LEtd,dim);
            printf("\n\n\t\aAPPUYEZ SUR UNE TOUCHE POUR QUITTER...");
            fflush(stdin);
            getchar();
            break;
        case 8:
            system("cls");
            Afficher(LEtd,dim);
            printf("\n\n\t==> Entrer les deux indices : ");
            scanf("%d %d",&i,&j);
            echange_Etd(i-1,j-1,LEtd);
            system("COLOR A");
            printf("\n\n\t\t** OPERATION REUSSIE **");
            printf("\n\n\t\aAPPUYEZ SUR UNE TOUCHE POUR QUITTER...");
            fflush(stdin);
            getchar();
            break;
        case 9:
            system("cls");
            Tri(LEtd,dim);
            system("COLOR A");
            printf("\n\n\t\t** OPERATION REUSSIE **");
            printf("\n\n\t\aAPPUYEZ SUR UNE TOUCHE POUR QUITTER...");
            fflush(stdin);
            getchar();
            break;
        case 10:
            system("cls");
            in=fopen(etd_tab,"w");
            for(i=0;i<(dim+nbrEtd);i++)
               fprintf(in,"%d.\t\t\tNom Complet\t: %s\n\t\t\tCNE\t\t: %d\n\t\t\tDate\t\t: %d/%d/%d\n\t\t\tNum Adresse\t: %d\n\t\t\tVille \t\t: %s\n\n", i+1, (LEtd+i)->NomComplet, (LEtd+i)->cne, (LEtd+i)->dat.jour, (LEtd+i)->dat.mois, (LEtd+i)->dat.anne, (LEtd+i)->adr.num, (LEtd+i)->adr.ville);
            fclose(in);
        	system("COLOR A");
            printf("\n\n\t\tMERCI POUR UTILISER NOTRE PROGRAMME ");
            free(LEtd);
            fflush(stdin);
            getchar();
            exit(0);
        default:
        	system("COLOR 4");
            printf("\n\t\t\aCHOIX INVALIDE..");
            printf("\n\n\tAPPUYEZ SUR UNE TOUCHE POUR RESSAYER ...");
            fflush(stdin);
            getchar();
            break;
        }
        system("cls");
	}
    free(LEtd);
    return 0;

}
