int missingNum(int *arr, int size) {
    long long n = size + 1;

    long long total = n * (n + 1) / 2;
    long long sum = 0;

    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }

    return (int)(total - sum);
}
