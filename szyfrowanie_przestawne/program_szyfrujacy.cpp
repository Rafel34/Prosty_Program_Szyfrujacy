#include<iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;

int wybor;
FILE *wejscie, *wyjscie;
char znak;
char plik_jawny[20];
char plik_niezaszyfrowany[20];
char plik_zaszyfrowany[20];
int klucz;


int szyfrowanie()
{
    cout<<"plik do zaszyfrowania : " <<endl;
    cin>>plik_niezaszyfrowany;



    cout<<"plik wynikowy : ";
    cin>>plik_zaszyfrowany;
    if((wejscie=fopen(plik_niezaszyfrowany,"r"))!=NULL)
    {
        if((wyjscie=fopen(plik_zaszyfrowany,"w"))!=NULL)
        {
            while((znak=getc(wejscie))!=EOF)   //petla czyta znak ze strumienia dopuki nie napotka znaku konca linii
            {




                znak+=klucz;
                putc(znak,wyjscie);


            }
            fclose(wyjscie);
        }
        fclose(wejscie);
    }
    cout<<"Szyfrowanie zostalo zakonczone"<<endl;
}



void rozszyfrowanie()
{
    cout<<"plik do rozszyfrowania : ";
    cin>>plik_zaszyfrowany;
    cout<<"plik wynikowy : " ;
    cin>>plik_jawny;

    if((wejscie=fopen(plik_zaszyfrowany,"r"))!=NULL)  //tylko do odczytu istniejacy
    {
        if((wyjscie=fopen(plik_jawny,"w"))!=NULL)
        {
            while((znak=getc(wejscie))!=EOF)   //pobieranie znaku  tak dlugo az nie nastapi znak konca pliku
            {


                znak-=klucz;
                putc(znak,wyjscie);

            }

        }
        fclose(wyjscie);
    }
    fclose(wejscie);
        cout<<"Deszyfrowanie zostalo zakonczone"<<endl;
}





int main()
{
    do
    {


    cout << "Podaj klucz : " << endl;
    cin.clear();
    cin.sync();
    cin>>klucz;
        if(cin.fail())
        cout<<"nie podales liczby"<<endl;


    }while(!cin.good());

    while(true)
    {

        cout<<endl;
        cout<<"WYBIERZ OPCJE : "<<endl;
        cout<<"1.SZYFROWANIE"<<endl;
        cout<<"2.DESZYFROWANIE"<<endl;
        cout<<"3.WYJDZ"<<endl;
        cin>>wybor;
        switch(wybor)
        {
        case 1:
            szyfrowanie();
            break;

        case 2:
            rozszyfrowanie();
            break;
        case 3:
            return 0;
            break;

        default:
            cout<<"nie ma takiej opcjii"<<endl;

        }
    }
    return 0;
}

