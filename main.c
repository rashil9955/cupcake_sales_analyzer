
//Cupcakes Shop Data Review Program
//
// Rashil Shibakoti
// 12/05/2023
//
// CSC150 Fall 2023
// SDSU
//
// Ms. Kurtenbach
//
//


#include <stdio.h>

#define MONTHS 12


int readFile(int arrayC[], int size);
//opens the source file in read more, reads data from file to array

void calcTotalAvg(int arrayC[], int *total, float *avg);
//calculate the total sum of array elements and the average value

int calcMostSold(int arrayC[]);
//finds and returns the highest value in the array

int calcLeastSold(int arrayC[]);
//finds and returns the lowest value in the array

void sortData(int arrayC[]);
//sorts the array


void findMedian(int arrayC[], int size, float *median);
//as sortData is called earlier, the array is already sorted when findMedian function is called
//finds and print the median of the array

void PrintMonthName(int monthNumber);

void buildFrequencyArray(int arrayC[], int freqArray[]);

int findMode(int freqArray[]);

void printHistogram(int freqArray[]);

void displaySummary(int arrayC[], int total, float avg, int mostSold, int leastSold, float median);
//displays the sorted array, highest sold month, lowest sold month, total, average and sorted data



int main(){
    
    int arrayC[MONTHS];
    int freqArray[MONTHS] = {0};
    int total;
    float avg;
    float median;
    int size = 0;
    int mostSold, leastSold;
    

    readFile(arrayC, MONTHS);
    
    calcTotalAvg(arrayC, &total, &avg);
    
    mostSold = calcMostSold(arrayC);
    leastSold = calcLeastSold(arrayC);
    findMedian(arrayC, size, &median);

    
    sortData(arrayC);
    
    displaySummary(arrayC, total, avg, mostSold, leastSold, median);
    
    buildFrequencyArray(arrayC, freqArray);
    int mode = findMode(freqArray);
        
    printf("Mode of Sales is: %d\n", mode);
    printHistogram(freqArray);
    
    
    
    
    return 0;
}


int readFile(int arrayC[], int size) {
    
    FILE *file;
    int count;

    file = fopen("flav_month.txt", "r");

    if (file == NULL) {
    
        printf("Error opening file!!\n");
        
        return 0;
    }

    for (count = 0; count < size; count++) {
        
        if (fscanf(file, "%d", &arrayC[count]) != 1) {
            
            
            printf("Error reading from file.\n");
            fclose(file);
            
            return count;
        }
    }

    fclose(file);
    return count;
}


void calcTotalAvg(int arrayC[], int *total, float *avg){
    
    int i;
    int sum = 0;
    
    for (i = 0; i<MONTHS; i++){
        sum = sum + arrayC[i];
    }
    
    *total = sum;
    *avg = (float)sum/MONTHS;
}


int calcMostSold(int arrayC[]){
    int i, MostSold = 0;
    int soldNum = arrayC[0];
    

    for (i = 0; i < MONTHS; i++){
        if(arrayC[i] > soldNum){
            soldNum = arrayC[i];
            MostSold = i;
        }
    }

    
    return MostSold;
}



int calcLeastSold(int arrayC[]){
    int i, LeastSold = 0;
    int soldNum = arrayC[0];
    

    for (i = 1; i < MONTHS; i++){
        if(arrayC[i] < soldNum){
            soldNum = arrayC[i];
            LeastSold = i;
        }
            
    }
        

    return LeastSold;
}


void sortData(int arrayC[]){
    
    int x, hold, y;
    
    for (y = 0; y < MONTHS - 1; y++){
        for (x = 0; x < MONTHS - y - 1 ; x++){
            if (arrayC[x] > arrayC[x+1]){
                hold = arrayC[x+1];
                arrayC[x+1] = arrayC[x];
                arrayC[x] = hold;
            }
        }
    }
}


void findMedian(int arrayC[], int size, float *median) {
    
    if (size % 2 == 0) {
        
        *median = (arrayC[size / 2 - 1] + arrayC[size / 2]) / 2.0;
    
    } 
    
    else
    {
        
        
        *median = arrayC[size / 2];
    
    }
    
    
}



void PrintMonthName(int monthNumber){
    
    char *monthNames[] = {"January", "Feburary", "March", "April", "May", "June",
                          "July", "August", "September", "October", "November", "December"};
    
    if (monthNumber >= 0 && monthNumber < MONTHS ){
        
        printf("%s\n", monthNames[monthNumber]);
        
    } else {
        
        printf("Invalid month number.\n");
        
        
    }
}



void buildFrequencyArray(int arrayC[], int freqArray[]) {
    
    int i;
    
    for (i = 0; i < MONTHS; ++i) {
        
        freqArray[i] = 0;
    }

    
    for (i = 0; i < MONTHS; ++i) {
        
        freqArray[arrayC[i]] = freqArray[arrayC[i]] + 1;
    }
    
    
    
}


int findMode(int arrayC[]) {
    
    int i, j;
    int mode = 0;
    int maxFrequency = 0;

    for (i = 0; i < MONTHS; ++i) {
        int currentFrequency = 0;

        for (j = 0; j < MONTHS; ++j) {
            
            if (arrayC[j] == arrayC[i]) {
                
                currentFrequency++;
                
                
                
                
            }
            
        }

        if (currentFrequency > maxFrequency) {
            
            maxFrequency = currentFrequency;
            
            mode = arrayC[i];
        }
        
        
        
    }

    return mode;
}
    




void printHistogram(int freqArray[]) {
    
    int i , j;
    
    printf("Histogram of Sales Data: \n");

    for (i = 30 ; i <= 75 ; i = i + 5) {
        
        printf("%2d - %2d | ", i, i + 4);


        for (j = 0; j < freqArray[(i - 30) / 5]; j = j+1) {
            printf("*");
        }
        
        printf("\n");
    }
}




    

void displaySummary(int arrayC[], int total, float avg, int mostSold, int leastSold, float median){
    
    int x;
    
    printf("The month with Highest Sales is: ");
    PrintMonthName(mostSold);
    
    
    
    printf("The month with Lowest Sales is: \n\n" , leastSold);
    PrintMonthName(leastSold);
    
    printf("Total Sales is %d\n" , total);
    
    printf("Average Sales is %f\n" , avg);
    
    printf("Median is Sales is %f\n\n" , median);
    
    
    printf("Sorted Data is: \n");
    
    for (x = 0; x < MONTHS; x++){
        printf("%d\n", arrayC[x]);
    }
    
    printf("\n");
    
}


