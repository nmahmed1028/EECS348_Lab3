
#include <stdio.h>
#include <stdlib.h>

#define MONTHS 12

float* read_data_from(char *file_name){
    float* month_sales_data = (float*)malloc(sizeof(float) * MONTHS);
    FILE *fp = fopen(file_name, "r+");
    for(int i = 0; i < MONTHS; ++i){
        fscanf(fp, "%f\n", &month_sales_data[i]);
    }

    return month_sales_data;
}



void print_data(const char *months[], const float *sales){
    printf("Month\tSales\n");
    for(int i = 0; i < MONTHS; ++i){
        printf("%30s\t%10f\n",months[i], sales[i]);
    }
}



void print_summary(const char *months[], const float *sales){
    printf("\nSales Summary:\nMinimum sales: ");
    float min = sales[0];
    for(int i = 0; i < MONTHS; ++i){
        if(sales[i] < min){
            min = sales[i];
        }
    }
    printf("%f\n", min);

    printf("Maximum sales: ");
    float max = sales[0];
    for(int i = 0; i < MONTHS; ++i){
        if(sales[0] > max){
            max = sales[i];
        }
    }
    printf("%f\n", max);

    printf("Average sales: ");
    float total = 0;
    for(int i = 0; i < MONTHS; ++i){
        total = total + sales[i];
    }
    float average = total / MONTHS;
    printf("%f\n", average);
}



void print_moving_avg(const char *months[], const float *sales){
    printf("\nSix-Month Moving Average Report:\n");
    int start = 0;
    int end = 5;
    float total = 0;
    while(start < 7){
        printf("%s     - %s     ", months[start], months[end]);
        for(int i = start; i <= end; i++){
            total = total + sales[i];
        }
        float average = total / 6;
        printf("%f\n", average);
        start++;
        end++;
        total = 0;
    }
}



void print_high_to_low(const char *months[], float *sales){
    printf("\nSales Report (Highest to Lowest):\nMonth\tSales\n");
    int max_index = 0;
    for (int i = 0; i < 12; i++){
        for (int j = 0; j < 12; j++){
            if (sales[j] > sales[max_index]){
                max_index = j;
            }
        }
        printf("%-8s\t%0.2f\n", months[max_index], sales[max_index]);
        sales[max_index] = 0;
    }

}




int main(){
    float* sales = read_data_from("data.txt");
    const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    print_data(months, sales);
    print_summary(months, sales);
    print_moving_avg(months, sales);
    print_high_to_low(months, sales);
    return 0;
}