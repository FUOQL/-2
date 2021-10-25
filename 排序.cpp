#include <iostream>
#include <math.h>

using namespace std;

bool insertSort(int array[], size_t arrLen) {
    if (arrLen < 0) {
        cout << "Please check your input." << endl;
        return false;
    }

    for (int orderedNum = 1; orderedNum < arrLen; ++orderedNum) {
        int insertValue = array[orderedNum];//将最后一个元素作为插入元素 
        int orderedIndex = orderedNum - 1;
        for (; orderedIndex >= 0; --orderedIndex) {//从后面开始遍历 
            if (insertValue < array[orderedIndex]) {
                array[orderedIndex + 1] = array[orderedIndex];
            }
            else {
                break;
            }
        }
        array[orderedIndex+1] = insertValue;
    }

    return true;
}
// 桶排序，arr 为待排序序列
bool insertSort_Sen(int array[], size_t arrLen) {
     if (arrLen < 0) {
        cout << "Please check your input." << endl;
        return false;
    }

    for (int orderedNum = 1; orderedNum < arrLen; ++orderedNum) {//遍历元素 
        int insertValue = array[orderedNum];
        int orderedIndex = orderedNum - 1;
        while(orderedIndex >=0 && array[orderedIndex] > insertValue) {
           array[orderedIndex + 1] = array[orderedIndex];
           --orderedIndex;
        }
        array[orderedIndex+1] = insertValue;
    }

    return true;
}

void printArray(int array[], int arrLen) {
    for (int i = 0; i < arrLen; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

bool buckertSort(int array[], size_t arrLen, size_t bucketSize) {
    const int DEFAULT_BUCKET_SIZE = 10;//默认桶的大小是10 
    if(arrLen < 2) {
        return true;
    }

    if (bucketSize < 1) {
        bucketSize = DEFAULT_BUCKET_SIZE;
    }

    // Find the scope of the array
    int min = array[0];
    int max = array[0];

    for (size_t i = 1; i < arrLen; ++i)
    {
        if (min > array[i]) {
            min = array[i];
        }
        else if (max < array[i]) {
            max = array[i];
        }
    }

    // 创建所有桶
    int **buckets = new int*[bucketSize]();
    int *bucketLen = new int[bucketSize]();
    int bucketScope = floor((max - min)/bucketSize) + 1;//设置桶的大小 
// 设置每个桶为空桶
    for (size_t j = 0; j < bucketSize; j++)
    {
        buckets[j] = new int[arrLen]();
    }

    int mapIndex = -1;

    // 将 arr 中的每个元素分散存储到各个桶中
    for (size_t k = 0; k < arrLen; ++k)
    {
        mapIndex = floor((array[k] - min)/bucketScope);
        buckets[mapIndex][bucketLen[mapIndex]++] = array[k];
    }

    // Sort value in bucket and put ordered value back to array
    int arrayIndex = 0;
		 //对各个桶进行排序
    for (size_t l = 0; l < bucketSize; l++)
    {
        if (bucketLen[l] > 0) {
		// 合并所有桶内的元素
            insertSort(buckets[l], bucketLen[l]);
            for (size_t m = 0; m < bucketLen[l]; ++m) {
                array[arrayIndex++] = buckets[l][m];
            }
        }
        delete [] buckets[l];
        buckets[l] = NULL;
    }

    delete [] buckets;
    delete [] bucketLen;

    return true;

}

int main(){
    int array0[] = {};
    int arrayLen = sizeof(array0)/sizeof(int);

    printArray(array0, arrayLen);
    insertSort(array0, arrayLen);
    printArray(array0, arrayLen);

    cout << "=========================================" << endl;

    int array1[] = {1};
    arrayLen = sizeof(array1)/sizeof(int);

    printArray(array1, arrayLen);
    buckertSort(array1, arrayLen, 1);
    printArray(array1, arrayLen);

    cout << "=========================================" << endl;

    int array2[] = {2, 1};
    arrayLen = sizeof(array2)/sizeof(int);

    printArray(array2, arrayLen);
    buckertSort(array2, arrayLen, 2);
    printArray(array2, arrayLen);

    cout << "=========================================" << endl;

    int array3[] = {1, 5, 3};
    arrayLen = sizeof(array3)/sizeof(int);

    printArray(array3, arrayLen);
    buckertSort(array3, arrayLen, 2);
    printArray(array3, arrayLen);


    cout << "=========================================" << endl;

    int array4[] = {9, 12, 8, 7};
    arrayLen = sizeof(array4)/sizeof(int);

    printArray(array4, arrayLen);
    buckertSort(array4, arrayLen, 2);
    printArray(array4, arrayLen);

    cout << "=========================================" << endl;

    int array5[] = {9, 12, 8, 7, 3};
    arrayLen = sizeof(array5)/sizeof(int);

    printArray(array5, arrayLen);
    buckertSort(array5, arrayLen, 2);
    printArray(array5, arrayLen);
}
