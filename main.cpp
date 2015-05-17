#include <iostream>
using namespace std;

void Gaussian_Elimination(double** MA, int N)
{
    int i,j,k; //Index
    double D;//Divisor
    ///////////////////////////////////////////////////DEKLARACJA DYNAMICZNEJ TABLICY
    MA = new double *[N];
    for(i = 0; i < N; i++)
    {
        MA[i] = new double [N+2];
    }
    //////////////////////////////////////////////////ZBIERA DANE POTRZEBNE DO ROZWIAZANIA ZADAWANIA
    for(i = 0; i < N; i++)
    {
        for(j = 1; j <= N+1; j++)
        {
            if(j<=N)cout<<"Podaj współczynnik zmiennej nr "<<j<<" w równaniu nr "<<i+1<<endl;
            else cout<<"Podaj wynik równania nr "<<i+1<<endl;
            cin>>MA[i][j];
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
        j=i+1;
        for(j; j<N; j++)
        {
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
}
int main()
{
    double** MA;//coefficientMatrix
    int N;//numbersOfUnknowns
    cout<<"Podaj ilość niewiadomych w równaniach"<<endl;
    cin>>N;
    Gaussian_Elimination(MA,N);
    delete[] MA;
    return 0;
}


