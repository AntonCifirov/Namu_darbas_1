#pragma once
#include "C:\Users\ARGO\source\repos\ND_1\mylib.h"

duom sorting(duom temp)
{
    sort(temp.paz.begin(), temp.paz.end());

    return temp;

}

double findMedian(duom temp, int n)
{
    duom temp1 = sorting(temp);
    if (n % 2 == 0)
    {
        double median = (temp1.paz[n / 2] + temp1.paz[(n / 2) - 1]) / 2 + 0.5;
        return median;
    }
    else
    {
        double median = (temp1.paz[(n / 2)]);
        return median;
    }
}

