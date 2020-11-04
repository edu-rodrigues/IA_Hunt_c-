#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;

struct caca
{
    int posicaoCacaY;
    int posicaoCacaX;
    bool viva;

};

struct s_cacador
{
    int posicaoCacadorY;
    int posicaoCacadorX;
    int alcance = 5;
    bool cacando = false;
};





int const linhas = 30;
int const colunas = 30;

int matriz[linhas][colunas] ;
int possibilidadeCacadorX[8], possibilidadeCacadorY[8];
int possibilidadeCacaX[8], possibilidadeCacaY[8];
vector <caca> cacas;
s_cacador cacador;



void PreenchePossibilidades()
{
    

    ///////////////////////////////////////////////////////

    // POSSIBILIDADES DA CACA


}

void CriaMatriz()
{
    for (int i = 0; i < linhas ; i++)
    {
        for (int j = 0; j < colunas; j++)
        {        

            matriz[i][j] = 0;

            //cout << matriz[i][j] << " "; 
        }
        //cout << endl;
    }
}

void ImprimeMatriz()
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void CriaPosicoes()
{
    srand(time(NULL));
    cacador.posicaoCacadorX = rand() % 29;
    cacador.posicaoCacadorY = rand() % 29;
    matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 7;

    for (int i = 0; i < 5; i++)
    {
        caca temp;
        temp.posicaoCacaX = rand() % 29;
        temp.posicaoCacaY = rand() % 29;       

        while(cacador.posicaoCacadorX == temp.posicaoCacaX & cacador.posicaoCacadorY == temp.posicaoCacaY)
        {
            temp.posicaoCacaX = rand() % 29;
            temp.posicaoCacaY = rand() % 29;
        }

        cacas.push_back(temp);       
        
        matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = i + 1;

        cout << cacas[i].posicaoCacaY << " ";
        cout << cacas[i].posicaoCacaX << " " << endl ;


    }
    
    
}


void MovimentaCaca()
{
    int random =0;
    int i = 0;



    while (i < 5)
    {
        if (cacas[i].viva)
        {
            random = rand() % 7;
            switch (random)
            {
            case 0:
                // anda para vertical superior esquerda
                if (cacas[i].posicaoCacaX > 0 && cacas[i].posicaoCacaY > 0
                    && matriz[cacas[i].posicaoCacaX - 1][cacas[i].posicaoCacaY - 1] == 0) // a ca�a so se movera se houver espa�o
                {                                                                      // e n�o esteja ocupado por outra ca�a ou ca�ador
                    matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = 0;
                    cacas[i].posicaoCacaX--;
                    cacas[i].posicaoCacaY--;
                    matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = i + 1;

                    cout << cacas[i].posicaoCacaX << " - " << cacas[i].posicaoCacaY << "andou " << random << endl;
                    i++;

                }
                else
                {
                    cout << "sorteando novamente";
                }
                break;
            case 1:
                // anda para cima
                if (cacas[i].posicaoCacaX > 0 && matriz[cacas[i].posicaoCacaX - 1][cacas[i].posicaoCacaY] == 0)
                {
                    matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = 0;
                    cacas[i].posicaoCacaX--;
                    matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = i + 1;

                    cout << cacas[i].posicaoCacaX << " - " << cacas[i].posicaoCacaY << "andou " << random << endl;
                    i++;

                }
                else
                {
                    cout << "sorteando novamente";
                }

                break;
            case 2:
                // anda para vertical superior direita
                if (cacas[i].posicaoCacaX > 0 && cacas[i].posicaoCacaY < 29
                    && matriz[cacas[i].posicaoCacaX - 1][cacas[i].posicaoCacaY + 1] == 0)
                {
                    matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = 0;
                    cacas[i].posicaoCacaX--;
                    cacas[i].posicaoCacaY++;
                    matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = i + 1;

                    cout << cacas[i].posicaoCacaX << " - " << cacas[i].posicaoCacaY << "andou " << random << endl;
                    i++;

                }
                else
                {
                    cout << "sorteando novamente";
                }


                break;
            case 3:
                // anda para direita
                if (cacas[i].posicaoCacaY < 29 && matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY + 1] == 0)
                {
                    matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = 0;
                    cacas[i].posicaoCacaY++;
                    matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = i + 1;

                    cout << cacas[i].posicaoCacaX << " - " << cacas[i].posicaoCacaY << "andou " << random << endl;
                    i++;

                }
                else
                {
                    cout << "sorteando novamente";
                }

                break;
            case 4:
                // anda para vertical inferior direita
                if (cacas[i].posicaoCacaX < 29 && cacas[i].posicaoCacaY < 29
                    && matriz[cacas[i].posicaoCacaX + 1][cacas[i].posicaoCacaY + 1] == 0)
                {
                    matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = 0;
                    cacas[i].posicaoCacaX++;
                    cacas[i].posicaoCacaY++;
                    matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = i + 1;

                    cout << cacas[i].posicaoCacaX << " - " << cacas[i].posicaoCacaY << "andou " << random << endl;
                    i++;

                }
                else
                {
                    cout << "sorteando novamente";
                }
                break;
            case 5:
                // anda para baixo

                if (cacas[i].posicaoCacaX < 29 && matriz[cacas[i].posicaoCacaX + 1][cacas[i].posicaoCacaY] == 0)
                {
                    matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = 0;
                    cacas[i].posicaoCacaX++;
                    matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = i + 1;

                    cout << cacas[i].posicaoCacaX << " - " << cacas[i].posicaoCacaY << "andou " << random << endl;
                    i++;

                }
                else
                {
                    cout << "sorteando novamente";
                }

                break;
            case 6:
                // anda para vertical inferior esquerda
                if (cacas[i].posicaoCacaX < 29 && cacas[i].posicaoCacaY > 0
                    && matriz[cacas[i].posicaoCacaX + 1][cacas[i].posicaoCacaY - 1] == 0)
                {
                    matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = 0;
                    cacas[i].posicaoCacaX++;
                    cacas[i].posicaoCacaY--;
                    matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = i + 1;

                    cout << cacas[i].posicaoCacaX << " - " << cacas[i].posicaoCacaY << "andou " << random << endl;
                    i++;

                }
                else
                {
                    cout << " sorteando novamente" << endl;
                }
                break;
            case 7:
                // anda para esquerda
                if (cacas[i].posicaoCacaY > 0 && matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY - 1] == 0)
                {
                    matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = 0;
                    cacas[i].posicaoCacaY--;
                    matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = i + 1;

                    cout << cacas[i].posicaoCacaX << " - " << cacas[i].posicaoCacaY << "andou " << random << endl;
                    i++;

                }
                else
                {
                    cout << "sorteando novamente";
                }

            default:
                break;
            }


        }
        else
        {
             i++;
        }
    }

}




void MovimentaCacador(int choose)
{

    //diagonal superior esquerda
    possibilidadeCacadorX[0] = cacador.posicaoCacadorX - 1;
    possibilidadeCacadorY[0] = cacador.posicaoCacadorY - 1;

    //cima
    possibilidadeCacadorX[1] = cacador.posicaoCacadorX - 1;
    possibilidadeCacadorY[1] = cacador.posicaoCacadorY;

    //diagonal superior direita
    possibilidadeCacadorX[2] = cacador.posicaoCacadorX - 1;
    possibilidadeCacadorY[2] = cacador.posicaoCacadorY + 1;

    // direita
    possibilidadeCacadorX[3] = cacador.posicaoCacadorX;
    possibilidadeCacadorY[3] = cacador.posicaoCacadorY + 1;

    // diagonal inferior direita
    possibilidadeCacadorX[4] = cacador.posicaoCacadorX + 1;
    possibilidadeCacadorY[4] = cacador.posicaoCacadorY + 1;

    // baixo
    possibilidadeCacadorX[5] = cacador.posicaoCacadorX + 1;
    possibilidadeCacadorY[5] = cacador.posicaoCacadorY;

    // diagonal inferior esquerda
    possibilidadeCacadorX[6] = cacador.posicaoCacadorX + 1;
    possibilidadeCacadorY[6] = cacador.posicaoCacadorY - 1;

    // esquerda
    possibilidadeCacadorX[7] = cacador.posicaoCacadorX;
    possibilidadeCacadorY[7] = cacador.posicaoCacadorY - 1;


    if (choose==9)
    {
        choose = rand() % 7;
    }

    switch (choose)
    {
    case 0:
        if (cacador.posicaoCacadorX != 0 && cacador.posicaoCacadorY != 0)
        {
            // anda para vertical superior esquerda
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 0;
            cacador.posicaoCacadorX--;
            cacador.posicaoCacadorY--;
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 7;

            cout << cacador.posicaoCacadorX << " - " << cacador.posicaoCacadorY << "andou " << choose << endl;

        }
        else
        {
            cout << " n eh possivel";
        }
        break;
    case 1:
        // anda para cima
        if (cacador.posicaoCacadorX > 0)
        {
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 0;
            cacador.posicaoCacadorX--;
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 7;
            cout << cacador.posicaoCacadorX << " - " << cacador.posicaoCacadorY << "andou " << choose << endl;

        }
        else
        {
            cout << "nao eh possivel";
        }

        break;
    case 2:
        // anda para vertical superior direita
        if (cacador.posicaoCacadorX > 0 && cacador.posicaoCacadorY < 29)
        {
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 0;
            cacador.posicaoCacadorX--;
            cacador.posicaoCacadorY++;
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 7;
            cout << cacador.posicaoCacadorX << " - " << cacador.posicaoCacadorY << "andou " << choose << endl;

        }
        else
        {
            cout << "nao eh possivel";
        }


        break;
    case 3:
        // anda para direita
        if (cacador.posicaoCacadorY < 29)
        {

            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 0;
            cacador.posicaoCacadorY++;
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 7;

            cout << cacador.posicaoCacadorX << " - " << cacador.posicaoCacadorY << "andou " << choose << endl;

        }
        else
        {
            cout << "n eh possivel";
        }

        break;
    case 4:
        // anda para vertical inferior direita
        if (cacador.posicaoCacadorX < 29 && cacador.posicaoCacadorY < 29)
        {
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 0;
            cacador.posicaoCacadorX++;
            cacador.posicaoCacadorY++;
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 7;

            cout << cacador.posicaoCacadorX << " - " << cacador.posicaoCacadorY << "andou " << choose << endl;

        }
        else
        {
            cout << "n eh possivel";
        }
        break;
    case 5:
        // anda para baixo

        if (cacador.posicaoCacadorX < 29)
        {
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 0;
            cacador.posicaoCacadorX++;
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 7;

            cout << cacador.posicaoCacadorX << " - " << cacador.posicaoCacadorY << "andou " << choose << endl;

        }
        else
        {
            cout << "n eh possivel";
        }

        break;
    case 6:
        // anda para vertical inferior esquerda
        if (cacador.posicaoCacadorX < 29 && cacador.posicaoCacadorY > 0)
        {
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 0;
            cacador.posicaoCacadorX++;
            cacador.posicaoCacadorY--;
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 7;

            cout << cacador.posicaoCacadorX << " - " << cacador.posicaoCacadorY << "andou " << choose << endl;

        }
        else
        {
            cout << "n eh possivel";
        }
        break;
    case 7:
        // anda para esquerda
        if (cacador.posicaoCacadorY > 0)
        {
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 0;
            cacador.posicaoCacadorY--;
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 7;

            cout << cacador.posicaoCacadorX << " - " << cacador.posicaoCacadorY << "andou " << choose << endl;

        }
        else
        {
            cout << "n eh possivel";
        }
        break;

    default:
        break;
    }

    cout << "------------------------------" << endl;
    ImprimeMatriz();
}


void Atacar(int foco)
{
    matriz[cacas[foco].posicaoCacaX][cacas[foco].posicaoCacaY] = 0;
    cacas[foco].viva = false;
    ImprimeMatriz();
}

void Cacar(int foco)
{
    int quadrado1, quadrado2, maisProximo;
    float distancia;
    float menorDistancia= 1000;    

    for (int i = 0; i < 8; i++)
    {
        quadrado1 = (possibilidadeCacadorX[i] - cacas[foco].posicaoCacaX) * (possibilidadeCacadorX[i] - cacas[foco].posicaoCacaX);
        quadrado2 = (possibilidadeCacadorY[i] - cacas[foco].posicaoCacaY) * (possibilidadeCacadorY[i] - cacas[foco].posicaoCacaY);

        distancia = sqrt(quadrado1 + quadrado2);

        if (distancia < menorDistancia)
        {
            menorDistancia = distancia;
            maisProximo = i;
        }
         
        cout  << "esta eh a dsitancia e o I " << distancia << " -- " << i << endl;
    }
    if (menorDistancia == 0)
    {
        Atacar(foco);
    }
    else
    {
        MovimentaCacador(maisProximo);
    }
    
}



void Varredura()
{
    int foco[5];
    int encontrados = 0;
    int posicaoAchadoX[5];
    int posicaoAchadoY[5];

    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            int alcanceX = cacador.posicaoCacadorX - cacador.alcance + i;
            int alcanceY = cacador.posicaoCacadorY - cacador.alcance + j;


            if (matriz[alcanceX][alcanceY] == 1 || matriz[alcanceX][alcanceY] == 2 
                || matriz[alcanceX][alcanceY] == 3 || matriz[alcanceX][alcanceY] == 4 
                   || matriz[alcanceX][alcanceY] == 5 && matriz[alcanceX][alcanceY] != 7)
            {
                
                posicaoAchadoX[encontrados] = alcanceX;
                posicaoAchadoY[encontrados] = alcanceY;
                foco[encontrados] = matriz[alcanceX][alcanceY]; // guarda qual eh a caca
                encontrados++;

            }
        }      
    }
    cout << "encontrados: " << encontrados << endl;



    if (encontrados == 1)
    {
        Cacar(foco[0] -1);
    }
    else if (encontrados > 1)
    {
        int maisProximo;
        float menorDistancia= 300;
        int quadrado1, quadrado2; // variaveis para calcular qual a caca esta mais proxima
        float distancia;          // variaveis para calcular qual a caca esta mais proxima
        for (int k = 0; k < encontrados; k++)
        {
            quadrado1 = (cacador.posicaoCacadorX - posicaoAchadoX[k]) * (cacador.posicaoCacadorX - posicaoAchadoX[k]);
            quadrado2 = (cacador.posicaoCacadorY - posicaoAchadoY[k]) * (cacador.posicaoCacadorY - posicaoAchadoY[k]);
            distancia = sqrt(quadrado1 + quadrado2);

            if (distancia < menorDistancia)
            {
                menorDistancia = distancia;
                maisProximo = foco[k];
            }
        }

        Cacar(maisProximo -1);
    }
    else
    {
        MovimentaCacador(9);
    }


  
}






int main()
{
    CriaMatriz();
    CriaPosicoes();

    int escolha;

    cout << "digite a quantidade de turnos " << endl;
    cin >> escolha;

    while(escolha!=0)
    {    

    for (int i = 0; i < escolha; i++)
    {
        Varredura();
        MovimentaCaca();
    }
    cout << "digite a quantidade de turnos " << endl;
    cin >> escolha;
    }
}