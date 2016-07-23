#include "LintCode.h"


int Solution::StrStrNaive(const char *source, const char *target){
    if (!source || !target)
        return -1;
    if (source[0] == '\0' && target[0] == '\0')
        return 0;
    int i, j = 0;
    for (i = 0; source[i] != '\0'; i++) {
        for (j = 0; target[j] != '\0'; j++)
            if (source[i+j] != target[j])
                break;
        if (target[j] == '\0')
            return i;
    }
    return -1;
}
