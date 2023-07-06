#include <iostream>
#include <stdio.h>
#include <fstream>
#include <time.h>


int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
    int pivotIndex = start + count;
    std::swap(arr[pivotIndex], arr[start]);
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            std::swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{
    if (start >= end)
        return;
    int p = partition(arr, start, end);
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}



int main()
{
    std::string filename;
    setlocale(LC_ALL, "");
    std::cout << "Введите название файла: ";
    std::cin >> filename;

    std::ifstream file(filename);
    int el;
    int length = 0;
    int* arr = NULL;

    while (file >> el) {

        arr = (int*)(int*)realloc(arr, (length + 1) * sizeof(int));  // Заполнение массива из файла
        arr[length] = el;
        length += 1;                                        
                                                                            
    }                                                                        

    file.close();

    time_t start = clock();

    quickSort(arr, 0, length - 1);

    time_t stop = clock();
    double time = (stop - start);

    std::cout << time << "ms";

    std::ofstream fout(filename);

    for (int i = 0; i < length; i++)
    {
        fout << arr[i] << " ";                                  // Вывод массива в файл
    }   

    fout.close();

    int _;

    std::cin >> _;

    return 0;

}
