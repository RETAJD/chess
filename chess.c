#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

// szachy
char planszaszachowa[33][49]={' '};

int liczba=1; // liczba szachowa np C2 itp
int gracz=0;  //uzytkownik


void plansza()
{
                                                     //
    for(int i=0;i<33;i++)
    {
        for(int j=0;j<49;j++)
        {
            if(i%4==0 ) planszaszachowa[i][j]='-';
            else{
            if(j%6==0 ) planszaszachowa[i][j]='|';
            else   planszaszachowa[i][j]=' ';
            }
                                                       // printf("%c",planszaszachowa[i][j]);
        }

            if(i==2 || i==6 || i==10 ||i==14||i==18||i==22||i==26||i==30||i==34||i==38||i==42||i==46)
                {
                                                       // printf("%d",liczba);
                    liczba++;
                }

    }

}

void wyswietlanie()
{
    printf("   A     B     C     D     E     F     G     H\n");
    int liczba=1;
    for(int i = 0;i<33;i++)
    {
        for(int j=0;j<49;j++)
        {
            printf("%c",planszaszachowa[i][j]);
        }
        if(i==2 || i==6 || i==10 ||i==14||i==18||i==22||i==26||i==30||i==34||i==38||i==42||i==46)
                {
                    printf("%d",liczba);
                    liczba++;
                }
        printf("\n");
    }
}
void startowe_ustawienie()
{
    // Wieza    Skoczek    Goniec  Hetman  Król  Goniec Skoczek   Wie¿a
    planszaszachowa[2][3]='W';
    planszaszachowa[2][9]='S';
    planszaszachowa[2][15]='G';
    planszaszachowa[2][21]='H';
    planszaszachowa[2][27]='K';
    planszaszachowa[2][33]='G';
    planszaszachowa[2][39]='S';
    planszaszachowa[2][45]='W';

    planszaszachowa[6][3]='P';
    planszaszachowa[6][9]='P';
    planszaszachowa[6][15]='P';
    planszaszachowa[6][21]='P';
    planszaszachowa[6][27]='P';
    planszaszachowa[6][33]='P';
    planszaszachowa[6][39]='P';
    planszaszachowa[6][45]='P';

    planszaszachowa[30][3]='w';
    planszaszachowa[30][9]='s';
    planszaszachowa[30][15]='g';
    planszaszachowa[30][21]='h';
    planszaszachowa[30][27]='k';
    planszaszachowa[30][33]='g';
    planszaszachowa[30][39]='s';
    planszaszachowa[30][45]='w';


    planszaszachowa[26][3]='p';
    planszaszachowa[26][9]='p';
    planszaszachowa[26][15]='p';
    planszaszachowa[26][21]='p';
    planszaszachowa[26][27]='p';
    planszaszachowa[26][33]='p';
    planszaszachowa[26][39]='p';
    planszaszachowa[26][45]='p';

}

int rozszI, rozszJ;
char wspol[2];
void rozszyfrowanie()   // C1   D4
{
   // if(gracz%2==0) printf("Gracz 1\n" );
  // else  printf("Gracz 2\n" );

    printf("podaj wspol pionka: " );
    scanf("%s",&wspol);
    if(  (wspol[0]<65 || wspol[0]>72)  || (wspol[1]<49 || wspol[1]>56  ) ) rozszyfrowanie();
    else
    {
        if(wspol[0]=='A') rozszJ=3;
        if(wspol[0]=='B') rozszJ=9;
        if(wspol[0]=='C') rozszJ=15;
        if(wspol[0]=='D') rozszJ=21;
        if(wspol[0]=='E') rozszJ=27;
        if(wspol[0]=='F') rozszJ=33;
        if(wspol[0]=='G') rozszJ=39;
        if(wspol[0]=='H') rozszJ=45;

        if(wspol[1]=='1') rozszI=2;
        if(wspol[1]=='2') rozszI=6;
        if(wspol[1]=='3') rozszI=10;
        if(wspol[1]=='4') rozszI=14;
        if(wspol[1]=='5') rozszI=18;
        if(wspol[1]=='6') rozszI=22;
        if(wspol[1]=='7') rozszI=26;
        if(wspol[1]=='8') rozszI=30;
    }
}// ZWRACA W WSPOL U GORY  i I j  PIONKA Z NP C4

int czy_poprawny(int wejI, int wejJ, int DoI, int DoJ)
{
    // pionek maly
    if(planszaszachowa[wejI][wejJ]=='p')
    {
        if(wejI==26 && DoI==18 && planszaszachowa[22][wejJ]==' ' && planszaszachowa[18][wejJ]==' ' && wejJ==DoJ) // ruch o 2 miejsca startowe pl 0
        {
            return 1;
        }
        if(wejI-DoI==4 && ((wejJ-DoJ)==6 || (wejJ-DoJ)==-6) && (planszaszachowa[DoI][DoJ]>=65 && planszaszachowa[DoI][DoJ]<=90))  //bicie pionkiem
        {
            // punkty dla player 0
            return 1;
        }
        if(wejI-DoI==4 && wejJ==DoJ && planszaszachowa[DoI][DoJ]==' ')
        {
            return 1;
        }
        else return 0;
    }

    /////////WiezA mala
    if(planszaszachowa[wejI][wejJ]=='w')
    {
        if(DoJ==wejJ)
        {
                for(int i=wejI-4;i>DoI;i=i-4)   // szuka po pionie
                {

                    if(planszaszachowa[i][DoJ]!=' ') return 0;
                }
                if(planszaszachowa[DoI][DoJ]>=65 && planszaszachowa[DoI][DoJ]<=90) // sprawdza czy bicie
                {
                    return 1;
                }
                else if(planszaszachowa[DoI][DoJ]==' ') // zwykly ruch pionowy
                {
                    return 1;
                }
                return 0;
        }

        if(DoJ!=wejJ && DoI==wejI)
        {
            for(int i=wejJ+6;i<DoJ;i=i+6)
            {
                    if(planszaszachowa[wejI][i]!=' ') return 0;
            }
            if(planszaszachowa[DoI][DoJ]>=65 && planszaszachowa[DoI][DoJ]<=90) // sprawdza czy bicie
                {
                    return 1;
                }

            else if(planszaszachowa[DoI][DoJ]==' ') // zwykly ruch pionowy
                {
                    return 1;
                }
            return 0;
        }
        return 0;
    }

    // skoczek maly
    if(planszaszachowa[wejI][wejJ]=='s')
    {
            if( ((wejI-DoI)==8 ||  (wejI-DoI)==-8) && ((wejJ-DoJ)==6 || (wejJ-DoJ)==-6))
            {
                if(planszaszachowa[DoI][DoJ]>=65 && planszaszachowa[DoI][DoJ]<=90) // sprawdza czy bicie
                {
                    return 1;
                }
                else if(planszaszachowa[DoI][DoJ]==' ') // zwykly ruch pionowy
                {
                    return 1;
                }
                return 0;
            }
            return 0;
    }
    //goniec maly
    if(planszaszachowa[wejI][wejJ]=='g')
    {
        if(DoJ>wejJ && DoI<wejI)
        {
            int asd=wejJ+6;
            for(int i=wejI-4;i>DoI;i=i-4)
            {
                printf("asd");
                if(planszaszachowa[i][asd]!=' ') return 0;
                asd=asd+6;
            }

            if(planszaszachowa[DoI][DoJ]>=65 && planszaszachowa[DoI][DoJ]<=90) // sprawdza czy bicie
            {
                return 1;
            }
            if(planszaszachowa[DoI][DoJ]==' ') // zwykly ruch pionowy
            {
                return 1;
            }
                return 0;

        }

        if(DoJ>wejJ && DoI>wejI)
        {
            int asd=wejJ+6;
            for(int i=wejI+4;i<DoI;i=i+4)
            {
                if(planszaszachowa[i][asd]!=' ') return 0;
                asd=asd+6;
            }

            if(planszaszachowa[DoI][DoJ]>=65 && planszaszachowa[DoI][DoJ]<=90) // sprawdza czy bicie
            {
                return 1;
            }
            if(planszaszachowa[DoI][DoJ]==' ') // zwykly ruch pionowy
            {
                return 1;
            }
                return 0;
        }

        if(DoJ<wejJ && DoI<wejI)
        {
            int asd=wejJ-6;
            for(int i=wejI-4;i>DoI;i=i-4)
            {
                if(planszaszachowa[i][asd]!=' ') return 0;
                asd=asd-6;
            }

            if(planszaszachowa[DoI][DoJ]>=65 && planszaszachowa[DoI][DoJ]<=90) // sprawdza czy bicie
            {
                return 1;
            }
            if(planszaszachowa[DoI][DoJ]==' ') // zwykly ruch pionowy
            {
                return 1;
            }
                return 0;
        }

        if(DoJ<wejJ && DoI>wejI)
        {
            int asd=wejJ-6;
            for(int i=wejI+4;i<DoI;i=i+4)
            {
                if(planszaszachowa[i][asd]!=' ') return 0;
                asd=asd-6;
            }

            if(planszaszachowa[DoI][DoJ]>=65 && planszaszachowa[DoI][DoJ]<=90) // sprawdza czy bicie
            {
                return 1;
            }
            if(planszaszachowa[DoI][DoJ]==' ') // zwykly ruch pionowy
            {
                return 1;
            }
                return 0;
        }

        return 0;
    }
    //HETMAN
    if(planszaszachowa[wejI][wejJ]=='h')
    {
        if(DoJ>wejJ && DoI<wejI)
        {
            int asd=wejJ+6;
            for(int i=wejI-4;i>DoI;i=i-4)
            {
                printf("asd");
                if(planszaszachowa[i][asd]!=' ') return 0;
                asd=asd+6;
            }

            if(planszaszachowa[DoI][DoJ]>=65 && planszaszachowa[DoI][DoJ]<=90) // sprawdza czy bicie
            {
                return 1;
            }
            if(planszaszachowa[DoI][DoJ]==' ') // zwykly ruch pionowy
            {
                return 1;
            }
                return 0;

        }

        if(DoJ>wejJ && DoI>wejI)
        {
            int asd=wejJ+6;
            for(int i=wejI+4;i<DoI;i=i+4)
            {
                if(planszaszachowa[i][asd]!=' ') return 0;
                asd=asd+6;
            }

            if(planszaszachowa[DoI][DoJ]>=65 && planszaszachowa[DoI][DoJ]<=90) // sprawdza czy bicie
            {
                return 1;
            }
            if(planszaszachowa[DoI][DoJ]==' ') // zwykly ruch pionowy
            {
                return 1;
            }
                return 0;
        }

        if(DoJ<wejJ && DoI<wejI)
        {
            int asd=wejJ-6;
            for(int i=wejI-4;i>DoI;i=i-4)
            {
                if(planszaszachowa[i][asd]!=' ') return 0;
                asd=asd-6;
            }

            if(planszaszachowa[DoI][DoJ]>=65 && planszaszachowa[DoI][DoJ]<=90) // sprawdza czy bicie
            {
                return 1;
            }
            if(planszaszachowa[DoI][DoJ]==' ') // zwykly ruch pionowy
            {
                return 1;
            }
                return 0;
        }

        if(DoJ<wejJ && DoI>wejI)
        {
            int asd=wejJ-6;
            for(int i=wejI+4;i<DoI;i=i+4)
            {
                if(planszaszachowa[i][asd]!=' ') return 0;
                asd=asd-6;
            }

            if(planszaszachowa[DoI][DoJ]>=65 && planszaszachowa[DoI][DoJ]<=90) // sprawdza czy bicie
            {
                return 1;
            }
            if(planszaszachowa[DoI][DoJ]==' ') // zwykly ruch pionowy
            {
                return 1;
            }
                return 0;
        }
        if(DoJ==wejJ)
        {
                for(int i=wejI-4;i>DoI;i=i-4)   // szuka po pionie
                {

                    if(planszaszachowa[i][DoJ]!=' ') return 0;
                }
                if(planszaszachowa[DoI][DoJ]>=65 && planszaszachowa[DoI][DoJ]<=90) // sprawdza czy bicie
                {
                    return 1;
                }
                else if(planszaszachowa[DoI][DoJ]==' ') // zwykly ruch pionowy
                {
                    return 1;
                }
                return 0;
        }


        if(DoJ!=wejJ && DoI==wejI)
        {
            for(int i=wejJ+6;i<DoJ;i=i+6)
            {
                    if(planszaszachowa[wejI][i]!=' ') return 0;
            }
            if(planszaszachowa[DoI][DoJ]>=65 && planszaszachowa[DoI][DoJ]<=90) // sprawdza czy bicie
                {
                    return 1;
                }

            else if(planszaszachowa[DoI][DoJ]==' ') // zwykly ruch pionowy
                {
                    return 1;
                }
            return 0;
        }
        return 0;
    }
    //KRÓL
    if(planszaszachowa[wejI][wejJ]=='k')
    {
        if((planszaszachowa[DoI][DoJ]>=65 && planszaszachowa[DoI][DoJ]<=90) && (wejI-DoI==0 || wejI-DoI==4 || wejI-DoI==-4) && (wejJ-DoJ==0 || wejJ-DoJ==6 || wejJ-DoJ==-6)) return 1;
        if((wejI-DoI==0 || wejI-DoI==4 || wejI-DoI==-4) && (wejJ-DoJ==0 || wejJ-DoJ==6 || wejJ-DoJ==-6) && planszaszachowa[DoI][DoJ]==' ' ) return 1;
        return 0;
    }
}

int czy_poprawny1(int wejI, int wejJ, int DoI, int DoJ)
{
    // pionek DUZY
    if(planszaszachowa[wejI][wejJ]=='P')
    {
        if(wejI==6 && DoI==14 && planszaszachowa[10][wejJ]==' ' && planszaszachowa[14][wejJ]==' ' && wejJ==DoJ) // ruch o 2 miejsca startowe pl 1
        {
            return 1;
        }
        if(wejI-DoI==-4 && ((wejJ-DoJ)==6 || (wejJ-DoJ)==-6) && (planszaszachowa[DoI][DoJ]>=97 && planszaszachowa[DoI][DoJ]<=122))  //bicie pionkiem
        {
            // punkty dla player 0
            return 1;
        }
        if(wejI-DoI==-4 && wejJ==DoJ && planszaszachowa[DoI][DoJ]==' ')
        {
            return 1;
        }
        else return 0;
    }

    /////////WiezA duza
    if(planszaszachowa[wejI][wejJ]=='W')
    {
        if(DoJ==wejJ)
        {
                for(int i=wejI-4;i>DoI;i=i-4)   // szuka po pionie
                {

                    if(planszaszachowa[i][DoJ]!=' ') return 0;
                }
                if(planszaszachowa[DoI][DoJ]>=97 && planszaszachowa[DoI][DoJ]<=122) // sprawdza czy bicie
                {
                    return 1;
                }
                else if(planszaszachowa[DoI][DoJ]==' ') // zwykly ruch pionowy
                {
                    return 1;
                }
                return 0;
        }

        if(DoJ!=wejJ && DoI==wejI)
        {
            for(int i=wejJ+6;i<DoJ;i=i+6)
            {
                    if(planszaszachowa[wejI][i]!=' ') return 0;
            }
            if(planszaszachowa[DoI][DoJ]>=97 && planszaszachowa[DoI][DoJ]<=122) // sprawdza czy bicie
                {
                    return 1;
                }

            else if(planszaszachowa[DoI][DoJ]==' ') // zwykly ruch pionowy
                {
                    return 1;
                }
            return 0;
        }
        return 0;
    }

    // skoczek maly
    if(planszaszachowa[wejI][wejJ]=='s')
    {
            if( ((wejI-DoI)==8 ||  (wejI-DoI)==-8) && ((wejJ-DoJ)==6 || (wejJ-DoJ)==-6))
            {
                if(planszaszachowa[DoI][DoJ]>=65 && planszaszachowa[DoI][DoJ]<=90) // sprawdza czy bicie
                {
                    return 1;
                }
                else if(planszaszachowa[DoI][DoJ]==' ') // zwykly ruch pionowy
                {
                    return 1;
                }
                return 0;
            }
            return 0;
    }
    //goniec maly
    if(planszaszachowa[wejI][wejJ]=='G')
    {
        if(DoJ>wejJ && DoI<wejI)
        {
            int asd=wejJ+6;
            for(int i=wejI-4;i>DoI;i=i-4)
            {
                printf("asd");
                if(planszaszachowa[i][asd]!=' ') return 0;
                asd=asd+6;
            }

            if(planszaszachowa[DoI][DoJ]>=97 && planszaszachowa[DoI][DoJ]<=122) // sprawdza czy bicie
            {
                return 1;
            }
            if(planszaszachowa[DoI][DoJ]==' ') // zwykly ruch pionowy
            {
                return 1;
            }
                return 0;
        }

        if(DoJ>wejJ && DoI>wejI)
        {
            int asd=wejJ+6;
            for(int i=wejI+4;i<DoI;i=i+4)
            {
                if(planszaszachowa[i][asd]!=' ') return 0;
                asd=asd+6;
            }

            if(planszaszachowa[DoI][DoJ]>=97 && planszaszachowa[DoI][DoJ]<=122) // sprawdza czy bicie
            {
                return 1;
            }
            if(planszaszachowa[DoI][DoJ]==' ') // zwykly ruch pionowy
            {
                return 1;
            }
                return 0;
        }

        if(DoJ<wejJ && DoI<wejI)
        {
            int asd=wejJ-6;
            for(int i=wejI-4;i>DoI;i=i-4)
            {
                if(planszaszachowa[i][asd]!=' ') return 0;
                asd=asd-6;
            }

            if(planszaszachowa[DoI][DoJ]>=97 && planszaszachowa[DoI][DoJ]<=122) // sprawdza czy bicie
            {
                return 1;
            }
            if(planszaszachowa[DoI][DoJ]==' ') // zwykly ruch pionowy
            {
                return 1;
            }
                return 0;
        }

        if(DoJ<wejJ && DoI>wejI)
        {
            int asd=wejJ-6;
            for(int i=wejI+4;i<DoI;i=i+4)
            {
                if(planszaszachowa[i][asd]!=' ') return 0;
                asd=asd-6;
            }

            if(planszaszachowa[DoI][DoJ]>=97 && planszaszachowa[DoI][DoJ]<=122) // sprawdza czy bicie
            {
                return 1;
            }
            if(planszaszachowa[DoI][DoJ]==' ') // zwykly ruch pionowy
            {
                return 1;
            }
                return 0;
        }

        return 0;
    }
    //HETMAN
    if(planszaszachowa[wejI][wejJ]=='h')
    {
        if(DoJ>wejJ && DoI<wejI)
        {
            int asd=wejJ+6;
            for(int i=wejI-4;i>DoI;i=i-4)
            {
                printf("asd");
                if(planszaszachowa[i][asd]!=' ') return 0;
                asd=asd+6;
            }

            if(planszaszachowa[DoI][DoJ]>=97 && planszaszachowa[DoI][DoJ]<=122) // sprawdza czy bicie
            {
                return 1;
            }
            if(planszaszachowa[DoI][DoJ]==' ') // zwykly ruch pionowy
            {
                return 1;
            }
                return 0;
        }

        if(DoJ>wejJ && DoI>wejI)
        {
            int asd=wejJ+6;
            for(int i=wejI+4;i<DoI;i=i+4)
            {
                if(planszaszachowa[i][asd]!=' ') return 0;
                asd=asd+6;
            }

            if(planszaszachowa[DoI][DoJ]>=97 && planszaszachowa[DoI][DoJ]<=122) // sprawdza czy bicie
            {
                return 1;
            }
            if(planszaszachowa[DoI][DoJ]==' ') // zwykly ruch pionowy
            {
                return 1;
            }
                return 0;
        }

        if(DoJ<wejJ && DoI<wejI)
        {
            int asd=wejJ-6;
            for(int i=wejI-4;i>DoI;i=i-4)
            {
                if(planszaszachowa[i][asd]!=' ') return 0;
                asd=asd-6;
            }

            if(planszaszachowa[DoI][DoJ]>=97 && planszaszachowa[DoI][DoJ]<=122) // sprawdza czy bicie
            {
                return 1;
            }
            if(planszaszachowa[DoI][DoJ]==' ') // zwykly ruch pionowy
            {
                return 1;
            }
                return 0;
        }

        if(DoJ<wejJ && DoI>wejI)
        {
            int asd=wejJ-6;
            for(int i=wejI+4;i<DoI;i=i+4)
            {
                if(planszaszachowa[i][asd]!=' ') return 0;
                asd=asd-6;
            }

            if(planszaszachowa[DoI][DoJ]>=97 && planszaszachowa[DoI][DoJ]<=122) // sprawdza czy bicie
            {
                return 1;
            }
            if(planszaszachowa[DoI][DoJ]==' ') // zwykly ruch pionowy
            {
                return 1;
            }
                return 0;
        }
        if(DoJ==wejJ)
        {
                for(int i=wejI-4;i>DoI;i=i-4)   // szuka po pionie
                {

                    if(planszaszachowa[i][DoJ]!=' ') return 0;
                }
                if(planszaszachowa[DoI][DoJ]>=97 && planszaszachowa[DoI][DoJ]<=122) // sprawdza czy bicie
                {
                    return 1;
                }
                else if(planszaszachowa[DoI][DoJ]==' ') // zwykly ruch pionowy
                {
                    return 1;
                }
                return 0;
        }


        if(DoJ!=wejJ && DoI==wejI)
        {
            for(int i=wejJ+6;i<DoJ;i=i+6)
            {
                    if(planszaszachowa[wejI][i]!=' ') return 0;
            }
            if(planszaszachowa[DoI][DoJ]>=97 && planszaszachowa[DoI][DoJ]<=122) // sprawdza czy bicie
                {
                    return 1;
                }

            else if(planszaszachowa[DoI][DoJ]==' ') // zwykly ruch pionowy
                {
                    return 1;
                }
            return 0;
        }
        return 0;
    }
    //KRÓL
    if(planszaszachowa[wejI][wejJ]=='k')
    {
        if((planszaszachowa[DoI][DoJ]>=97 && planszaszachowa[DoI][DoJ]<=122) && (wejI-DoI==0 || wejI-DoI==4 || wejI-DoI==-4) && (wejJ-DoJ==0 || wejJ-DoJ==6 || wejJ-DoJ==-6)) return 1;
        if((wejI-DoI==0 || wejI-DoI==4 || wejI-DoI==-4) && (wejJ-DoJ==0 || wejJ-DoJ==6 || wejJ-DoJ==-6) && planszaszachowa[DoI][DoJ]==' ' ) return 1;
        return 0;
    }
}


void przesuniecie(int a,int b)
{
                rozszyfrowanie();
                if(czy_poprawny(a,b,rozszI,rozszJ)==1 && gracz%2==0)
                {
                    //printf("%d %d\n",rozszI,rozszJ);
                    planszaszachowa[rozszI][rozszJ]=planszaszachowa[a][b];
                    planszaszachowa[a][b]=' ';
                }
                else if(czy_poprawny1(a,b,rozszI,rozszJ)==1 && gracz%2==1)
                {
                    //printf("%d %d\n",rozszI,rozszJ);
                    planszaszachowa[rozszI][rozszJ]=planszaszachowa[a][b];
                    planszaszachowa[a][b]=' ';
                }
                else przesuniecie(a,b);
}

void podaj_pionek()
{
         if(gracz%2==0) printf("Gracz 1\n" );
         else  printf("Gracz 2\n" );
    rozszyfrowanie();
    if(gracz%2==0)
    {
        if(planszaszachowa[rozszI][rozszJ]>=97  &&  planszaszachowa[rozszI][rozszJ]<=122) //sprawdza czy mala litera bo gracz zero to male
        {
                przesuniecie(rozszI,rozszJ);
                system("cls");
                wyswietlanie();
        }
        else podaj_pionek();
        gracz++;
    }
    else{

        if(planszaszachowa[rozszI][rozszJ]>=65  &&  planszaszachowa[rozszI][rozszJ]<=90)  //65  90
        {
                przesuniecie(rozszI,rozszJ);
                system("cls");
                wyswietlanie();
        }
        else podaj_pionek();
        gracz++;
    }
}
void gra()
{
    plansza();
    startowe_ustawienie();
    wyswietlanie();
    while(1)
    {
         podaj_pionek();
    }
}


int main(){


   gra();


    return 0;
}
