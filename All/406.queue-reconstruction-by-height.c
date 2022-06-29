/*
 * @lc app=leetcode id=406 lang=c
 *
 * [406] Queue Reconstruction by Height
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmpHeight(const void *a, const void *b) {
    if((*(int **)b)[0] == (*(int **)a)[0]) {
        return (*(int **)a)[1] - (*(int **)b)[1];
    }
    else {
        return  (*(int **)b)[0] - (*(int **)a)[0];
    }
}

void Inserter(int** res, int size, int* people)
{   
    int i;
    
    for(i = size - 1; i > people[1]; --i)
    {
        res[i][0] = res[i-1][0];
        res[i][1] = res[i-1][1];
    }
    res[people[1]][0] = people[0];
    res[people[1]][1] = people[1];
}

int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes){
    int** res = (int**)malloc(peopleSize*sizeof(int*));
    *returnColumnSizes = (int*)malloc(peopleSize*sizeof(int));
    for(int i = 0; i < peopleSize; ++i)
    {
        res[i] = (int*)malloc(2*sizeof(int));
        (*returnColumnSizes)[i] = 2;
    }
    qsort(people, peopleSize, sizeof(int*), cmpHeight);
    for(int i = 0; i < peopleSize; ++i)
    {
        Inserter(res, peopleSize, people[i]);
    }
    *returnSize = peopleSize;
    return res;
}
// @lc code=end
// @lc MEDIUM