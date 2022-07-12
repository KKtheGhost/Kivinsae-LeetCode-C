/*
 * @lc app=leetcode id=473 lang=c
 *
 * [473] Matchsticks to Square
 */

// @lc code=start
int a, b, c, d;
bool dfs(int* matchsticks, int matchsticksSize, int i){
    //Base Case
    if(i == matchsticksSize){
        if(a==0 && b==0 && c==0 && d==0) {return true;}
        else return false;
    }

    if(matchsticks[i]<=a){
        a-=matchsticks[i];
        if(dfs(matchsticks, matchsticksSize, i+1)) {return true;}
        a+=matchsticks[i];      // backtrack step
    }
    
    if(matchsticks[i]<=b){
        b-=matchsticks[i];
        if(dfs(matchsticks, matchsticksSize, i+1)) {return true;}
        b+=matchsticks[i];        // backtrack step                    
    }
    
    if(matchsticks[i]<=c){
        c-=matchsticks[i];
        if(dfs(matchsticks, matchsticksSize, i+1)) {return true;}
        c+=matchsticks[i];         // backtrack step
    }
    
    if(matchsticks[i]<=d){
        d-=matchsticks[i];
        if(dfs(matchsticks, matchsticksSize, i+1)) {return true;}
        d+=matchsticks[i];         // backtrack step
    }
	
	//If none of the explored option retuen true then  we have to return false
    return false;
}
int cmp(const void *a, const void *b) {
    return *(int*)b - *(int*)a;
}
bool makesquare(int* matchsticks, int matchsticksSize){
    if (matchsticksSize < 4) {return false;}
    int sum = 0;
	// if sum of all number of array is not divisible by 4 , then we can not create a square
	for (int i = 0; i < matchsticksSize; ++i) {sum += matchsticks[i];}
    if(sum % 4 != 0) {return false;}
    
	int sizeSum=sum/4;
    a = sizeSum; b = sizeSum; c = sizeSum; d = sizeSum;
	// here we sort our array in reverse order to escape more cases
	qsort(matchsticks, matchsticksSize, sizeof(int), cmp);
    
	return dfs(matchsticks, matchsticksSize, 0);
}
// @lc code=end
// @lc MEDIUM