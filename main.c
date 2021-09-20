#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct exponat
{
    char nume_exponat[50];
    char data_adaugarii[20];
    char descriere[200];
    char fisa_inreg[100];
    char sectie[200];
    char valoare[10];
    char restaurat[10];
    struct restaurator
    {
        char nume[20];
        char data_restaurare[20];
        char val_rest[10];
        char cnp[20];
        char varsta[10];
    } gigel;

};
void afisare(struct exponat a)
{
    strcpy(a.nume_exponat,a.nume_exponat+3);
    printf("Nume exponat: %s\n",a.nume_exponat);
    printf("Data adaugarii: %s\n",a.data_adaugarii);
    printf("Descriere: %s\n",a.descriere);
    printf("Fisa inregistrare: %s\n",a.fisa_inreg);
    printf("Sectie: %s\n",a.sectie);
    printf("Valoare: %s\n",a.valoare);
    if(strcmp(a.restaurat,"1")==0)
    {
        printf("Nume resturator: %s\n",a.gigel.nume);
        printf("CNP Restaurator: %s\n",a.gigel.cnp);
        printf("Varsta Restaurator: %s\n",a.gigel.varsta);
        printf("Data restaurarii: %s\n",a.gigel.data_restaurare);
        printf("Valoare restaurare: %s\n",a.gigel.val_rest);

    }
}
void afisare_nume(struct exponat a)
{
    printf("Nume exponat: %s\n",a.nume_exponat);
}
void citire(struct exponat *a,FILE* fp)
{
    ///nume
    fgets(a->nume_exponat,49,fp);
    a->nume_exponat[strcspn(a->nume_exponat, "\n")] = 0;
    ///data adaugarii
    fgets(a->data_adaugarii,19,fp);
    a->data_adaugarii[strcspn(a->data_adaugarii, "\n")] = 0;
    ///descr
    fgets(a->descriere,199,fp);
    a->descriere[strcspn(a->descriere, "\n")] = 0;
    ///fisa
    fgets(a->fisa_inreg,99,fp);
    a->fisa_inreg[strcspn(a->fisa_inreg, "\n")] = 0;
    ///sectia
    fgets(a->sectie,200,fp);
    a->sectie[strcspn(a->sectie, "\n")] = 0;
    ///valoare
    fgets(a->valoare,19,fp);
    a->valoare[strcspn(a->valoare, "\n")] = 0;
    ///restaurat
    fgets(a->restaurat,9,fp);
    a->restaurat[strcspn(a->restaurat, "\n")] = 0;
    if(strcmp(a->restaurat,"1")==0)
    {
        ///numele
        fgets(a->gigel.nume,19,fp);
        a->gigel.nume[strcspn(a->gigel.nume, "\n")] = 0;
        ///data restaurarii
        fgets(a->gigel.data_restaurare,19,fp);
        a->gigel.data_restaurare[strcspn(a->gigel.data_restaurare, "\n")] = 0;
        ///val rest
        fgets(a->gigel.val_rest,9,fp);
        a->gigel.val_rest[strcspn(a->gigel.val_rest, "\n")] = 0;
        ///cnp
        fgets(a->gigel.cnp,19,fp);
        a->gigel.cnp[strcspn(a->gigel.cnp, "\n")] = 0;
        ///varsta
        fgets(a->gigel.varsta,9,fp);
        a->gigel.varsta[strcspn(a->gigel.varsta, "\n")] = 0;
    }
}
int main()
{

    FILE* fp;
    fp = fopen("input.txt", "r");
    struct exponat *pointer;
    struct exponat a,b,c,d,e,f;
    ///time
    time_t mytime = time(NULL);
    char * time_str = ctime(&mytime);
    time_str[strlen(time_str)-1] = '\0';
    printf("%s\n",time_str);
    strcpy(time_str,time_str+20);
    //printf("%s\n", time_str);
    /// end of time
    pointer = &a;
    citire(pointer,fp);
    pointer = &b;
    citire(pointer,fp);
    pointer = &c;
    citire(pointer,fp);
    pointer = &d;
    citire(pointer,fp);
    pointer = &e;
    citire(pointer,fp);
    pointer = &f;
    citire(pointer,fp);
    int x,y;
    printf("Selectati tasta aferenta optiuni dorite:\nDescriere muzeu - tasta 1\nOrar vizita - tasta 2\nBilete - tasta 3\nTop 6 exponate de vizitat - tasta 4\nExponate adaugate in functie de data - tasta 5\nExponate din anul sistemului curent - tasta 6\nIesire din meniu - tasta 0\n");
    scanf("%d",&x);
    struct exponat *vectorrr[] = { &a, &b, &c, &d, &e, &f};
    while(x!=0)
    {
        if(x==1)
        {
            printf("--------------------------------------------------------------------------------------------------------------------\n");
            printf("Situat in centrul Romaniei, la Sibiu, Complexul National Muzeal ASTRA este cea mai importanta institutie etnomuzeala\ndin Romania.\n");
            printf("Conceput sub egida Asociatiunii Transilvane pentru Literatura Romana si Cultura Poporului Roman, institutie\ninfiintata in 1861 ,Muzeul ASTRA, pe atunci Muzeul Asociatiunii a vernisat prima expozitie in 19 august 1905.\n");
            printf("--------------------------------------------------------------------------------------------------------------------\n");
        }
        else if(x==2)
        {
            printf("--------------------------------------------------------------------------------------------------------------------\n");
            printf("                                                       ORAR\n");
            printf("*08:00 - 17:00 Octombrie - Aprilie\n");
            printf("*08:00 - 20:00 Mai - Septembrie\n");
            printf("--------------------------------------------------------------------------------------------------------------------\n");
        }
        else if(x==3)
        {
            printf("--------------------------------------------------------------------------------------------------------------------\n");
            printf("                                                   PROGRAM CASIERIE\n");
            printf("                                                    08:00 - 16:30\n");
            printf("  PRETUL BILETELOR ESTE:\n");
            printf("*Bilet individual adulti - 25 lei\n");
            printf("*Bilet grup adulti ( minim 20 persoane ) - 20 lei\n");
            printf("*Bilet individual pensionar - 12 lei\n");
            printf("*Bilet grup pensionar ( minim 20 persoane ) - 10 lei\n");
            printf("*Bilet individual elev/student - 7 lei\n");
            printf("*Bilet grup elevi/students ( minim 20 persoane ) - 5 lei\n");
            printf("*Bilet individual copii sub 6 ani - Intrare gratuita!\n");
            printf("--------------------------------------------------------------------------------------------------------------------\n");
        }
        else
            while(x==4)
            {
                printf("--------------------------------------------------------------------------------------------------------------------\n");
                printf("                                                       EXPONATE\n");
                afisare_nume(a);
                afisare_nume(b);
                afisare_nume(c);
                afisare_nume(d);
                afisare_nume(e);
                afisare_nume(f);
                printf("Introduceti numarul de ordine al unui exponat pentru a vizualiza fisa acestuia.\n");
                printf("Apasati tasta 0 pentru a reveni la meniul principal.\n");
                scanf("%d",&y);
                printf("--------------------------------------------------------------------------------------------------------------------\n");
                if(y==0)
                {
                    break;
                }
                else
                    switch(y)
                    {
                    case 1:
                        afisare(a);
                        break;
                    case 2:
                        afisare(b);
                        break;
                    case 3:
                        afisare(c);
                        break;
                    case 4:
                        afisare(d);
                        break;
                    case 5:
                        afisare(e);
                        break;
                    case 6:
                        afisare(f);
                        break;
                    }
            }
        if(x==5)
        {
        int nr=0;
        printf("------------------------------------------------------------------------------------------------------------------------");
        char blabla[20];
        printf("Introduceti o data: ");
        scanf("%s",blabla);
        int i;
        for(i=0;i<6;i++)
            if(strcmp(blabla,vectorrr[i]->data_adaugarii)==0)
        {
            printf("%s\n",vectorrr[i]->nume_exponat);
            nr++;
        }
        printf("In total se potrivesc %d exponate \n",nr);
        printf("------------------------------------------------------------------------------------------------------------------------");
        }
        else
        {
            if(x==6)
            {
                printf("------------------------------------------------------------------------------------------------------------------------");
                int i;
                for(i=0;i<6;i++)
                {
                    char data_exponat[20];
                    strcpy(data_exponat,vectorrr[i]->data_adaugarii);
                    strcpy(data_exponat,data_exponat+6);
                    //printf("%s\n",data_exponat);
                    if ( strcmp(time_str,data_exponat)==0)
                    {
                       printf("%s: %s",vectorrr[i]->nume_exponat,vectorrr[i]->data_adaugarii);
                       printf("\n");
                    }

                }
                printf("------------------------------------------------------------------------------------------------------------------------");
            }
        }
        printf("Ati revenit, introduceti alta optiune:\n");
        printf("Selectati tasta aferenta optiuni dorite:\nDescriere muzeu - tasta 1\nOrar vizita - tasta 2\nBilete - tasta 3\nTop 6 exponate de vizitat - tasta 4\nExponate adaugate in functie de data - tasta 5\nExponate din anul sistemului curent - tasta 6\nIesire din meniu - tasta 0\n");
        scanf("%d",&x);

    }
    return 0;
}
