#include <stdio.h>
#include <math.h>

float calculateSD(const float data[], int n);

int main()
{
    //int i;
    float data[10];

    /*This is used to read  10 float numbers from the console
     and place them into array data */
    printf("Enter 10 elements: ");
    for (int i = 0; i < 10; ++i){
        if (scanf_s("%f", &data[i]) != 1) {
            printf("Invalid input at element %d\n", i + 1);
            return 1;
        }
    //scanf_s("%f", &data[i]);
        
    }   
    /* prints on the console the standard deviation of the numbers
         * inserted as input
         */
    printf("\nStandard Deviation = %.6f", calculateSD(data, 10));

    return 0;
}

//the function claculating the standard deviation
float calculateSD(const float data[], int n)
{
    //initialise sum, mean and the variance result
    float sum = 0.0f, mean, variance = 0.0;

    //int i;

    //sums the float numbers provided as input
    for (int i = 0; i < n; ++i)
    {
        sum += data[i];
    }

    //calculates the mean
    mean = sum / (float)n;

    ////It first calcluate the variance,
    // by calculating the deviations of each data point from the mean,
    // squares the result of each, sum all of them  and divide the result by 10
    for (int i = 0; i < 10; ++i) {
        float diff = data[i] - mean;
        variance += diff * diff;
    }
        //variance += pow(data[i] - mean, 2);

    variance = variance / (float)n;


    // It returns the standard deviation by calculating the square root of the variance
    return sqrt(variance);
}








