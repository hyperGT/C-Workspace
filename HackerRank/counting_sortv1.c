int getMaxValue(int* arr, int arr_count){
    
    int max = INT_MIN;
        
    for (int i = 0; i < arr_count; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }  
    return max;
}

int* countingSort(int arr_count, int* arr, int* result_count) {
    
    int max_value = getMaxValue(arr, arr_count);        
    int* res = (int *)calloc(max_value + 1, sizeof(int));
    
    for(int i = 0; i < arr_count; i++){
        
        res[arr[i]]++;
    }
        
    *result_count = (arr_count <= 100) ? arr_count : max_value + 1;        
    return res;
}
