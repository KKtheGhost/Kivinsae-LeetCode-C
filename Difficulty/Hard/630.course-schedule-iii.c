/*
 * @lc app=leetcode id=630 lang=c
 *
 * [630] Course Schedule III
 *
 * https://leetcode.com/problems/course-schedule-iii/description/
 *
 * algorithms
 * Hard (35.77%)
 * Likes:    2156
 * Dislikes: 60
 * Total Accepted:    62.5K
 * Total Submissions: 171.4K
 * Testcase Example:  '[[100,200],[200,1300],[1000,1250],[2000,3200]]'
 *
 * There are n different online courses numbered from 1 to n. You are given an
 * array courses where courses[i] = [durationi, lastDayi] indicate that the
 * i^th course should be taken continuously for durationi days and must be
 * finished before or on lastDayi.
 * 
 * You will start on the 1^st day and you cannot take two or more courses
 * simultaneously.
 * 
 * Return the maximum number of courses that you can take.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: courses = [[100,200],[200,1300],[1000,1250],[2000,3200]]
 * Output: 3
 * Explanation: 
 * There are totally 4 courses, but you can take 3 courses at most:
 * First, take the 1^st course, it costs 100 days so you will finish it on the
 * 100^th day, and ready to take the next course on the 101^st day.
 * Second, take the 3^rd course, it costs 1000 days so you will finish it on
 * the 1100^th day, and ready to take the next course on the 1101^st day. 
 * Third, take the 2^nd course, it costs 200 days so you will finish it on the
 * 1300^th day. 
 * The 4^th course cannot be taken now, since you will finish it on the 3300^th
 * day, which exceeds the closed date.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: courses = [[1,2]]
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: courses = [[3,2],[4,3]]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= courses.length <= 10^4
 * 1 <= durationi, lastDayi <= 10^4
 * 
 * 
 */

// @lc code=start

int CourseCmp(const void *a, const void *b) {
    return (*(int **)a)[1] - (*(int **)b)[1];
}

int scheduleCourse(int** courses, int coursesSize, int* coursesColSize){
    qsort(courses, coursesSize, sizeof(int **), CourseCmp);
    int tsum = 0, res = 0;
    for (int i = 0; i < coursesSize; i++) {
        if (tsum + courses[i][0] <= courses[i][1]) {
            tsum += courses[i][0];
            courses[res++] = courses[i];
        }
        else {
            int max = i;
            for (int j = 0; j < res; ++j) {
                if (courses[j][0] > courses[max][0]) max = j;
            }
            if (courses[max][0] > courses[i][0]) {
                tsum += courses[i][0] - courses[max][0];
                courses[max] = courses[i];
            }
        }
    }
    return res;
}
// @lc code=end
// @lc HARD