// Paige Mortensen
// cs 302 
// hw 4: sorting and time complexity

#include <iostream>
#include <fstream> // csv
#include <cstdlib> // random
#include <chrono> // timing
#include <string>
#include <cstddef> // to hold large #s w/ type std::size_t

int getMenuChoice();
int getDataAmmount();
void generateData(int[], int);
void generateCSV(std::string, std::string, std::string, double, std::size_t, std::size_t, double, std::size_t, std::size_t);
void bubbleSort(int[], int, std::size_t*, std::size_t*);
void selectionSort(int[], int, std::size_t*, std::size_t*);
void mergeSort(int[], int, int, int[], std::size_t*, std::size_t*);
void merge(int[], int, int, int, int[], std::size_t*, std::size_t*);

int main(){
    int option;
    do{
        std::cout << "\n***SORTING***" << std::endl;
        option = getMenuChoice();

        double totalUnsortedDuration = 0;
        double totalSortedDuration = 0;

        std::size_t comparisons = 0; 
        std::size_t *ptr_comp = &comparisons;

        std::size_t swaps = 0;
        std::size_t *ptr_swaps = &swaps;

        // unsorted totals
        std::size_t totalComp = 0;
        std::size_t *ptr_totComp = &totalComp;

        std::size_t totalSwaps = 0;
        std::size_t *ptr_totSwap = &totalSwaps;

        // sorted totals
        std::size_t totalSortedComp = 0;
        std::size_t *ptr_totSComp = &totalSortedComp;

        std::size_t totalSortedSwaps = 0;
        std::size_t *ptr_totSSwap = &totalSortedSwaps;


        switch(option){
            case 1: // bubble sort
                { // need to create a new scope inside a switch statement if declaring new variable
                    int num = getDataAmmount();
                    int data[num];
                    std::string unsortedData, sortedData;
                    std::string file;
                    file = "bubble" + std::to_string(num) + ".csv";                    

                    int i;
                    for(i=0; i<10; i++){
                        generateData(data, num);
                        
                        *ptr_comp, *ptr_swaps, totalUnsortedDuration, totalSortedDuration, *ptr_totComp, *ptr_totSwap, *ptr_totSComp, *ptr_totSSwap = 0; // set duration to 0
                        auto start = std::chrono::high_resolution_clock::now(); // start
                        bubbleSort(data, num, ptr_comp, ptr_swaps); // unsorted
                        auto stop = std::chrono::high_resolution_clock::now();
                        auto unsortedDuration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start); // stop
                        unsortedData += ("," + std::to_string(unsortedDuration.count()) + "," + std::to_string(*ptr_comp) + "," + std::to_string(*ptr_swaps) + "\n");  
                        totalUnsortedDuration += unsortedDuration.count();
                        *ptr_totComp += *ptr_comp;
                        *ptr_totSwap += *ptr_swaps;

                        *ptr_comp, *ptr_swaps, totalUnsortedDuration, totalSortedDuration, *ptr_totComp, *ptr_totSwap, *ptr_totSComp, *ptr_totSSwap = 0; // set duration to 0
                        auto start_s = std::chrono::high_resolution_clock::now(); // start
                        bubbleSort(data, num, ptr_comp, ptr_swaps); // unsorted
                        auto stop_s = std::chrono::high_resolution_clock::now();
                        auto sortedDuration = std::chrono::duration_cast<std::chrono::microseconds>(stop_s - start_s); // stop
                        sortedData += ("," + std::to_string(sortedDuration.count()) + "," + std::to_string(*ptr_comp) + "," + std::to_string(*ptr_swaps) + "\n");  
                        totalSortedDuration += sortedDuration.count();
                        *ptr_totSComp += *ptr_comp;
                        *ptr_totSSwap += *ptr_swaps;
                    }// end for loop
                    generateCSV(file, unsortedData, sortedData, totalUnsortedDuration/i, *ptr_totComp/i, *ptr_totSwap/i, totalSortedDuration/i, *ptr_totSComp/i, *ptr_totSSwap/i);
                    break;
                }
            case 2: // selection sort
                {
                    int num = getDataAmmount();
                    int data[num];
                    std::string unsortedData, sortedData;
                    std::string file;
                    file = "selection" + std::to_string(num) + ".csv";                    

                    int i;
                    for(i=0; i<10; i++){
                        generateData(data, num);
                        
                        *ptr_comp, *ptr_swaps, totalUnsortedDuration, totalSortedDuration, *ptr_totComp, *ptr_totSwap, *ptr_totSComp, *ptr_totSSwap = 0; // set duration to 0
                        auto start = std::chrono::high_resolution_clock::now(); // start
                        selectionSort(data, num, ptr_comp, ptr_swaps); // unsorted
                        auto stop = std::chrono::high_resolution_clock::now();
                        auto unsortedDuration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start); // stop
                        unsortedData += ("," + std::to_string(unsortedDuration.count()) + "," + std::to_string(*ptr_comp) + "," + std::to_string(*ptr_swaps) + "\n");  
                        totalUnsortedDuration += unsortedDuration.count();
                        *ptr_totComp += *ptr_comp;
                        *ptr_totSwap += *ptr_swaps;

                        *ptr_comp, *ptr_swaps, totalUnsortedDuration, totalSortedDuration, *ptr_totComp, *ptr_totSwap, *ptr_totSComp, *ptr_totSSwap = 0; // set duration to 0
                        auto start_s = std::chrono::high_resolution_clock::now(); // start
                        selectionSort(data, num, ptr_comp, ptr_swaps); // unsorted
                        auto stop_s = std::chrono::high_resolution_clock::now();
                        auto sortedDuration = std::chrono::duration_cast<std::chrono::microseconds>(stop_s - start_s); // stop
                        sortedData += ("," + std::to_string(sortedDuration.count()) + "," + std::to_string(*ptr_comp) + "," + std::to_string(*ptr_swaps) + "\n");  
                        totalSortedDuration += sortedDuration.count();
                        *ptr_totSComp += *ptr_comp;
                        *ptr_totSSwap += *ptr_swaps;
                    }// end for loop
                    generateCSV(file, unsortedData, sortedData, totalUnsortedDuration/i, *ptr_totComp/i, *ptr_totSwap/i, totalSortedDuration/i, *ptr_totSComp/i, *ptr_totSSwap/i);
                    break;
                }
            case 3: // merge sort
                {
                    int num = getDataAmmount();
                    int data[num];
                    std::string unsortedData, sortedData;
                    std::string file;
                    file = "merge" + std::to_string(num) + ".csv";                    

                    int i;
                    for(i=0; i<10; i++){
                        generateData(data, num);
                        
                        *ptr_comp, *ptr_swaps, totalUnsortedDuration, totalSortedDuration, *ptr_totComp, *ptr_totSwap, *ptr_totSComp, *ptr_totSSwap = 0; // set duration to 0
                        auto start = std::chrono::high_resolution_clock::now(); // start
                        mergeSort(data, 0, 1, data, ptr_comp, ptr_swaps); // unsorted
                        auto stop = std::chrono::high_resolution_clock::now();
                        auto unsortedDuration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start); // stop
                        unsortedData += ("," + std::to_string(unsortedDuration.count()) + "," + std::to_string(*ptr_comp) + "," + std::to_string(*ptr_swaps) + "\n");  
                        totalUnsortedDuration += unsortedDuration.count();
                        *ptr_totComp += *ptr_comp;
                        *ptr_totSwap += *ptr_swaps;

                        *ptr_comp, *ptr_swaps, totalUnsortedDuration, totalSortedDuration, *ptr_totComp, *ptr_totSwap, *ptr_totSComp, *ptr_totSSwap = 0; // set duration to 0
                        auto start_s = std::chrono::high_resolution_clock::now(); // start
                        mergeSort(data, 0, 1, data, ptr_comp, ptr_swaps); // unsorted
                        auto stop_s = std::chrono::high_resolution_clock::now();
                        auto sortedDuration = std::chrono::duration_cast<std::chrono::microseconds>(stop_s - start_s); // stop
                        sortedData += ("," + std::to_string(sortedDuration.count()) + "," + std::to_string(*ptr_comp) + "," + std::to_string(*ptr_swaps) + "\n");  
                        totalSortedDuration += sortedDuration.count();
                        *ptr_totSComp += *ptr_comp;
                        *ptr_totSSwap += *ptr_swaps;
                    }// end for loop
                    generateCSV(file, unsortedData, sortedData, totalUnsortedDuration/i, *ptr_totComp/i, *ptr_totSwap/i, totalSortedDuration/i, *ptr_totSComp/i, *ptr_totSSwap/i);
                    break;
                }
            case 0: // exit
                return 0;
                break;
        }
    }while(option != 0);
}

int getMenuChoice(){
	int option;
	std::cout << "1. Bubble sort\n2. Selection sort\n3. Merge sort\n0. EXIT\n" << std::endl;
	std::cin >> option;
	return option;
}

int getDataAmmount(){
    int numData;
    std::cout << "How much data would you like to sort?" << std::endl;
    std::cin >> numData;
    return numData;
}

void generateData(int data[], int numVals){
    for(int i=0; i<numVals; i++){
        data[i] = (rand() % (1000000 + 1)); // range from 0 - 10^6
    }
}

void generateCSV(std::string file, std::string unsortedData, std::string sortedData, 
                double avgUnDuration, std::size_t avgUnComp, std::size_t avgUnSwaps,
                double avgSDuration, std::size_t avgSComp, std::size_t avgSSwaps){
    std::fstream fout;
    fout.open(file, std::ios::out | std::ios::app); // opens an existing csv file or creates a new file
    fout << ",Run Time, Comparisons, Swaps" << std::endl;
    fout << unsortedData << std::endl; // print data from 10 runs
    fout << "Average," << avgUnDuration << "," << avgUnComp << ","  << avgUnSwaps << std::endl;

    fout << ",Sorted,," << std::endl;
    fout << ",Run Time, Comparisons, Swaps" << std::endl;
    fout << sortedData << std::endl; // print data from 10 runs
    fout << "Average," << avgSDuration << "," << avgSComp << ","  << avgSSwaps << std::endl;
    fout.close();
}

void bubbleSort(int data[], int numVals, std::size_t* comparisons, std::size_t* swaps){
    int temp;
    for(int i=0; i<numVals-2; i++){
        for(int j=0; j<numVals-2; j++){
            (*comparisons)++;
            if(data[j] > data[j+1]){
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;  
                (*swaps)++;
            }
        }
    }
}

void selectionSort(int data[], int numVals, std::size_t* comparisons, std::size_t* swaps){
    int temp;
    for(int i=0; i<numVals-1; i++){
        int smallIndex = i;
        for(int j=i+1; j<numVals-1; j++){
            (*comparisons)++;
            if(data[j] < data[smallIndex]){
                smallIndex = j;
            }
        }
        temp = data[i];
        data[i] = data[smallIndex];
        data[smallIndex] = temp;
        (*swaps)++;
    }
}

void merge(int a[], int begin, int mid, int end, int b[], std::size_t* comparisons, std::size_t* swaps){
    int i = begin;
    int j = end;
    for(int k=begin; k<end; k++){
        (*comparisons)++;
        if(a[i] <= a[j]){
            b[k] = a[i];
            i++;
            (*swaps)++;           
        }else{
            b[k] = a[j];
            j++;
            (*swaps)++;
        }
    }
}

void mergeSort(int data[], int left, int right, int sortedData[], std::size_t* ptr_comp, std::size_t* ptr_swaps){
    int mid;
    if(right > left){
        mid = (left+right)/2;
        mergeSort(data, left, mid, sortedData, ptr_comp, ptr_swaps);
        mergeSort(data, mid+1, right, sortedData, ptr_comp, ptr_swaps);
        merge(data, left, mid, right, sortedData, ptr_comp, ptr_swaps);
    }
}