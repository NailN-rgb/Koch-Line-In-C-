#include <iostream>
#include <cmath>

void FirstAthenian(double PointCords[2]);    //
void SecondAthinian(double PointCords[2]);  //      афинные преобразования
void ThirdAthenian(double PointCords[2]);   //      
void FourthAthenian(double PointCords[2]);  //
void MatrixToVectorProducting(double Athenian[2][2], double PointCords[2]); //вспомогательная ф-я для умножения матриц
void ArrayCopy(double first[2], double second[2]); // вспомогательная ф-я для копирования матриц
void MainIterationMethod(int iteration, double PointCords[2], double AnPointCords[2]); //главный рекурсивный метод
void ToDisplay(double TrueCords[2], double ModPoints[2], double SecTrueCords[2], double SecModPoints[2]); //вспомогательный метод для выведения на экран


int iterate = 3; //число итераций, глобальный модификатор переменной фича))

int main()
{
    double firstPoint[2] { 0, 0 }; // начальные координаты Х и У
    double secondPoint[2]{ 1, 0 }; //

    std::cout << "Here first number - X - coord,  second - Y coord\n\n\n" << std::endl;
    MainIterationMethod(iterate, firstPoint, secondPoint);
    system("pause");
}

void ArrayCopy(double first[2], double second[2])
{
    for (int i = 0; i < 2; i++)
    {
        first[i] = second[i];
    }
}


void MatrixToVectorProducting(double Athenian[2][2], double PointCords[2])
{
    double tempCordArray[2];

    tempCordArray[0] = Athenian[0][0] * PointCords[0] + Athenian[0][1] * PointCords[1];
    tempCordArray[1] = Athenian[1][0] * PointCords[0] + Athenian[1][1] * PointCords[1];

    for (int i = 0; i < 2; i++)
    {
        PointCords[i] =tempCordArray[i];
    }
}


void FirstAthenian(double PointCords[2])
{
    for (int i = 0; i < 2; i++)
    {
        PointCords[i] = PointCords[i] / 3;
    }
}


void SecondAthinian(double PointCords[2])
{
    double AthenianMatrix[2][2]
    {
        0.5, -(sqrt(3) / 2), sqrt(3) / 2, 0.5
    };

    MatrixToVectorProducting(AthenianMatrix, PointCords);
    FirstAthenian(PointCords);

    PointCords[0] += (0.3333);
}

void ThirdAthenian(double PointCords[2])
{
    double AthenianMatrix[2][2]
    {
        0.5, -(sqrt(3) / 2), sqrt(3) / 2, 0.5
    };

    MatrixToVectorProducting(AthenianMatrix, PointCords);
    FirstAthenian(PointCords);

    PointCords[0] += 0.5;
    PointCords[1] += 0.289;
}

void FourthAthenian(double PointCords[2])
{
    PointCords[0] = (PointCords[0] / 3) + (0.6666);
    PointCords[1] /= 3;
}



void MainIterationMethod(int iteration, double PointCords[2], double AnPointCords[2])
{
    if (iteration >= 1)                                              //функция работает сразу с двумя точками для большей наглядности
    {                                                                //безусловно, возможна другая, более удобная реализация
        double TempPoint[2];                                         //
        ArrayCopy(TempPoint, PointCords);

        double AnTempPoint[2];
        ArrayCopy(AnTempPoint, AnPointCords);

        FirstAthenian(PointCords);
        FirstAthenian(AnPointCords);
        ToDisplay(TempPoint, PointCords, AnTempPoint, AnPointCords);
        MainIterationMethod(--iteration, PointCords, AnPointCords);
        iteration++;                    //после выхода из своего цикла рекурсивных итераций ф-я "возвращает" ранее занятую еденицу переменной
        ArrayCopy(PointCords, TempPoint);       //для продолжения работы с исходными координатами
        ArrayCopy(AnPointCords, AnTempPoint);   // здесь, исходная координата - это та координата, с которой был выполнен вход в функцию

        //первое афинное

        SecondAthinian(PointCords);
        SecondAthinian(AnPointCords);
        ToDisplay(TempPoint, PointCords, AnTempPoint, AnPointCords);
        MainIterationMethod(--iteration, PointCords, AnPointCords);
        iteration++;
        ArrayCopy(PointCords, TempPoint);
        ArrayCopy(AnPointCords, AnTempPoint);

        //второе афинное

        ThirdAthenian(PointCords);
        ThirdAthenian(AnPointCords);
        ToDisplay(TempPoint, PointCords, AnTempPoint, AnPointCords);
        MainIterationMethod(--iteration, PointCords, AnPointCords);
        iteration++;
        ArrayCopy(PointCords, TempPoint);
        ArrayCopy(AnPointCords, AnTempPoint);

        //третье афинное

        FourthAthenian(PointCords);
        FourthAthenian(AnPointCords);
        ToDisplay(TempPoint, PointCords, AnTempPoint, AnPointCords);
        MainIterationMethod(--iteration, PointCords, AnPointCords);
        ArrayCopy(PointCords, TempPoint);
        ArrayCopy(AnPointCords, AnTempPoint);
    }

}

void ToDisplay(double TrueCords[2], double ModPoints[2], double SecTrueCords[2], double SecModPoints[2])
{
    std::cout << "The section: (" << TrueCords[0] << "; " << TrueCords[1] << ") - (" << SecTrueCords[0] << "; " << SecTrueCords[1] << ")" << std::endl;
    std::cout << "Transformed to: (" << ModPoints[0] << "; " << ModPoints[1] << ") - (" << SecModPoints[0] << "; " << SecModPoints[1] << ")" << std::endl;
    std::cout << "\n\n\n";
}

