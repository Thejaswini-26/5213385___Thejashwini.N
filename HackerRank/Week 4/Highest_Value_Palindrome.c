char* highestValuePalindrome(char* s, int n, int k) {
    char* result = strdup(s);
    int* changed = calloc(n, sizeof(int));
    int i, j;

    for (i = 0, j = n - 1; i < j; i++, j--) {
        if (result[i] != result[j]) {
            char max = result[i] > result[j] ? result[i] : result[j];
            result[i] = result[j] = max;
            changed[i] = changed[j] = 1;
            k--;
        }
    }

    if (k < 0) {
        free(changed);
        free(result);
        return strdup("-1");
    }

    for (i = 0, j = n - 1; i <= j; i++, j--) {
        if (result[i] != '9') {
            if (i == j && k >= 1) {
                result[i] = '9';
                k--;
            } else if (changed[i] || changed[j]) {
                if (k >= 1) {
                    result[i] = result[j] = '9';
                    k--;
                }
            } else {
                if (k >= 2) {
                    result[i] = result[j] = '9';
                    k -= 2;
                }
            }
        }
    }

    free(changed);
    return result;
}