/* First Fit Algorithm
Allocator keeps a list of free blocks(known as the free list)
and on receiving a request for memory,scans along the list for the
first block that is large enough to satisfy the request.

If the chosen block is significantly larger than that requested, then
it is usually split and the remainder added to the list as another free
block.

When Recycling the free blocks, there is a choice as to where
to add the blocks to the free list-- effectively in what order the free
list is kept:
1.Memory Location
2.Increasing Size
3.Decreasing Size
4.Increasing time since last use */

#include <stdio.h>

//Free Blocks or Free list

int main()
{
	printf("\nEnter the Memory Size Needed");
	scanf("%d",&mem_size);

	return 0;
}
