/*

Kadane’s Algorithm:

Initialize:
    max_so_far = INT_MIN
    max_ending_here = 0

Loop for each element of the array
  (a) max_ending_here = max_ending_here + a[i]
  (b) if(max_so_far < max_ending_here)
            max_so_far = max_ending_here
  (c) if(max_ending_here < 0)
            max_ending_here = 0
return max_so_far


Explanation: 
The simple idea of Kadane’s algorithm is to look for all positive contiguous segments of the array (max_ending_here is used for this). 
And keep track of maximum sum contiguous segment among all positive segments (max_so_far is used for this). 
Each time we get a positive-sum compare it with max_so_far and update max_so_far if it is greater than max_so_far 

*/

#include <stdio.h>
#include <limits.h>

#define SIZE 100

int main()
{
	int a[SIZE] = {
		159, 723, 88, 415, -41, 351, -713, 953, -362, -374, 
		786, 600, 979, -102, -645, 613, 777, -546, -657, 765, 
		-231, 568, 836, -777, 698, 523, 100, 308, 332, -138, 
		-853, 119, -714, 575, -814, -416, -582, 274, 340, -966, 
		189, 435, -821, -711, -225, 291, -198, -698, 136, -316, 
		174, 262, 236, -76, 832, -769, -609, -550, -669, -298, 
		-491, 25, -168, -879, 197, 143, 792, 455, 786, 294, 
		754, 458, -952, -715, 964, 420, -480, 211, -619, 678, 
		-728, 912, -486, 708, -809, -586, -609, 328, -961, 187, 
		787, -382, 994, 593, 240, -134, 313, 512, -671, 221,
	};

	int b[SIZE];

	int max_so_far = INT_MIN, max_ending_here = 0, cnt = 0;
	
	for (int i = 0; i < SIZE; ++i) {
		max_ending_here = max_ending_here + a[i];
		if(max_so_far < max_ending_here) {
			max_so_far = max_ending_here;
			b[cnt] = a[i];
			cnt++;
		}
		if(max_ending_here < 0)
			max_ending_here = 0;
	}

	printf("Max sub-sequence sum = %d\n", max_so_far);
	printf("Max sub-sequence array: ");
	
    for (int i = 0; i < cnt; ++i) {
        printf("%d ", b[i]);
    }
}