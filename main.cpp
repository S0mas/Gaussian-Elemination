#include <iostream>
using namespace std;

int podaj_i_sprawdz_wartosc()
{
    int wartosc;
    while(!(cin>>wartosc))
    {
        cout<<"Blad. Niepoprawna wartosc\n";
        cin.clear();
        cin.ignore( 1000, '\n' );
    }
    return wartosc;
}

int start()
{
        int N;//numbersOfUnknowns
        cout<<"Podaj ilosc niewiadomych w rownaniach"<<endl;
        while(!(cin>>N)||N<=0)
        {
            cout<<"Blad. Liczba niewiadomych musi byc wieksza od 0\n";
            cin.clear();
            cin.ignore( 1000, '\n' );
        }
        return N;
}


void Gaussian_Elimination(int N)
{
    double** MA = 0;//coefficientMatrix
    int i,j,k; //Index
    double D;//Divisor
    int temp;
    ///////////////////////////////////////////////////DEKLARACJA DYNAMICZNEJ TABLICY
    MA = new double *[N];
    for(i = 0; i < N; i++)
    {
        MA[i] = new double [N+2];
    }
    //////////////////////////////////////////////////ZBIERA DANE POTRZEBNE DO ROZWIAZANIA ZADANIA
    for(i = 0; i < N; i++)
    {
        for(j = 1; j <= N+1; j++)
        {
            if(j<=N)cout<<"Podaj wspolczynnik zmiennej nr "<<j<<" w rownaniu nr "<<i+1<<endl;
            else cout<<"Podaj wynik rownania nr "<<i+1<<endl;
            MA[i][j]=podaj_i_sprawdz_wartosc();
        }
    }
    ///////////////////////////////////////////////////WYSWITLA WPISANE DANE W POSTACI MACIERZY
    for(i = 0; i < N; i++)
    {
        cout<<endl;
        for(j = 1; j <= N+1; j++)
        {
            cout<<MA[i][j]<<"\t";
        }
    }
    cout<<endl;
    ///////////////////////////////////////////////////ROZWIAZUJE MACIERZ ZA POMOCA ELIMINACJI GAUSSA
    for(i=0; i<N-1; i++)
    {
        for(j=i+1; j<N; j++)
        {
            if(MA[i][i+1]==0)////////////////////////////ZAMIENIA KOLEJNOŚĆ WIERSZY W PRZYPADKU DZIELENIA PRZEZ ZERO
            {
                for(k=1; k<N+2; k++)
                {
                    temp = MA[i+1][k];
                    MA[i+1][k] = MA[i][k];
                    MA[i][k] = temp;
                }

            }
            D=MA[j][i+1]/MA[i][i+1];
            for(k=1; i+k<=N+1; k++)
            {
                MA[j][i+k]-=D*MA[i][i+k];

            }
        }
    }
    ///////////////////////////////////////////////////WYŚWIETLA ROZWIAZANIE W POSTACI MACIERZY TRÓJKĄTNEJ
    for(i = 0; i < N; i++)
    {
        cout<<endl;
        for(j = 1; j <= N+1; j++)
        {
            cout<<MA[i][j]<<"\t";
        }
    }
    cout<<endl;
    //////////////////////////////////////////////////////TWORZY MACIERZ JEDNOSTOWA
    for(i=N-1; i>=0; i--)
    {
        for(j=N-1; j>i; j--)
        {

            D=MA[i][j+1]/MA[j][j+1];
            for(k=1; j+k<=N+1; k++)
            {
                MA[i][j+k]-=D*MA[j][j+k];
            }
        }
        MA[i][N+1]=MA[i][N+1]/MA[i][i+1];
        MA[i][i+1]=MA[i][i+1]/MA[i][i+1];
    }
     //////////////////////////////////////////////////////WYSWIETLA MACIERZ JEDNOSTKOWA
    for(i = 0; i < N; i++)
    {
        cout<<endl;
        for(j = 1; j <= N+1; j++)
        {
            cout<<MA[i][j]<<"\t";
        }
    }
    delete[] MA;
}
void opcje()
{
    cout<<endl<<endl;
    cout<<"\t1 - dodaj rownanie"<<endl;
    cout<<"\tInna Liczba - zakoncz program"<<endl;
}

int main()
{
    bool exit = false;
    cout<<endl<<endl<<"WITAJ W OBLICZARCE ROWNAN LINIOWYCH METODA GAUSSA"<<endl<<endl;
    do
    {
        opcje();
        switch (podaj_i_sprawdz_wartosc())
        {
            case 1:
                Gaussian_Elimination(start());
                break;
            default:
                exit = true;
                cout<<endl<<"Zakonczono";
                break;
        }
    }while(exit == false);
    return 0;
}


