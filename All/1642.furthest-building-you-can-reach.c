/*
 * @lc app=leetcode id=1642 lang=c
 *
 * [1642] Furthest Building You Can Reach
 *
 * https://leetcode.com/problems/furthest-building-you-can-reach/description/
 *
 * algorithms
 * Medium (45.26%)
 * Likes:    1882
 * Dislikes: 54
 * Total Accepted:    53.5K
 * Total Submissions: 117K
 * Testcase Example:  '[4,2,7,6,9,14,12]\n5\n1'
 *
 * You are given an integer array heights representing the heights of
 * buildings, some bricks, and some ladders.
 * 
 * You start your journey from building 0 and move to the next building by
 * possibly using bricks or ladders.
 * 
 * While moving from building i to building i+1 (0-indexed),
 * 
 * 
 * If the current building's height is greater than or equal to the next
 * building's height, you do not need a ladder or bricks.
 * If the current building's height is less than the next building's height,
 * you can either use one ladder or (h[i+1] - h[i]) bricks.
 * 
 * 
 * Return the furthest building index (0-indexed) you can reach if you use the
 * given ladders and bricks optimally.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
 * Output: 4
 * Explanation: Starting at building 0, you can follow these steps:
 * - Go to building 1 without using ladders nor bricks since 4 >= 2.
 * - Go to building 2 using 5 bricks. You must use either bricks or ladders
 * because 2 < 7.
 * - Go to building 3 without using ladders nor bricks since 7 >= 6.
 * - Go to building 4 using your only ladder. You must use either bricks or
 * ladders because 6 < 9.
 * It is impossible to go beyond building 4 because you do not have any more
 * bricks or ladders.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: heights = [4,12,2,7,3,18,20,3,19], bricks = 10, ladders = 2
 * Output: 7
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: heights = [14,3,19,3], bricks = 17, ladders = 0
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= heights.length <= 10^5
 * 1 <= heights[i] <= 10^6
 * 0 <= bricks <= 10^9
 * 0 <= ladders <= heights.length
 * 
 * 
 */

// @lc code=start

int heap[100000];
int heapcount;

void insert(int val) {
    int now = heapcount;
    heap[now] = val;
    heapcount++;
    while (now >= 1) {
        int p = (now - 1)/2;
        if (heap[now] < heap[p]) {
            int temp = heap[now];
            heap[now] = heap[p];
            heap[p] = temp;
            now=p;
        }
        else{break;}
    }
}
int pop() {
    int ret = heap[0];
    heap[0] = heap[--heapcount];
    int now = 0;
    while ((now*2 + 1) < heapcount) {
        int temp, next_pos=now;
        if (heap[now] > heap[now*2+1]) {
            next_pos = now*2+1;
        }
        if ((now*2 + 2) < heapcount && heap[next_pos] > heap[now*2+2]) {
            next_pos = now*2+2;
        }
        if (now == next_pos) break;
        temp = heap[now];
        heap[now] = heap[next_pos];
        heap[next_pos] = temp;
        now = next_pos;
    }
    return ret;
}
int furthestBuilding(int* heights, int heightsSize, int bricks, int ladders){
    int count=0;
    heapcount=0;
    for (int i = 0; i < heightsSize - 1; i++) {
        if (heights[i] > heights[i+1]) continue;
        insert(heights[i+1] - heights[i]);
        if (count < ladders) {
            count++;
        }
        else {
            int min = pop();
            if(min > bricks) return i;
            bricks -= min;
        }
    }
    return heightsSize-1;
}
// @lc code=end
// @lc MEDIUM