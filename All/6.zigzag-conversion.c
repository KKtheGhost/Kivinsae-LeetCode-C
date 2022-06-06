/*
 * @lc app=leetcode id=6 lang=c
 *
 * [6] Zigzag Conversion
 */

// @lc code=start

char * convert(char * s, int numRows){
    int length = strlen(s);
    if(length <= numRows || numRows == 1){ return s;}

    int node = 2*numRows - 2;
    int i = 0, j = 0, knode = 0, idx = 0;
    char *res=(char *)malloc(sizeof(char)*(length + 1));
    // Init res
    for(i = 0;i < length + 1; i++){
        res[i] = 0;
    }
    for(i=0; i < numRows; i++){
        j = i;
        knode = node - 2 * i;
        while(j < length){
            res[idx++] = s[j];
            if(!(i == 0|| i == numRows-1)){
                if(j + knode < length){
                    res[idx++]=s[j + knode];
                }
            }
            j+=node;
        }
    }
  return res;
}

// @lc code=end
// @lc MEDIUM