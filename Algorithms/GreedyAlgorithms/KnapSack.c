/* KnapSack Problem
 * Given a Knapsack(a bag or containner) of Capacity M and 
 * n objects of weights w1, w2, w3...wn with profits p1, p2, ...pn.
 * Let x1, x2, x3....xn be the fractions of the objects that are
 * supposed to be added into the knapsack.
 *
 * The objective is to place the objects into the knapsack, so that
 * maximum profit is obtainned and the weights of objects chosen 
 * should not exceed the capacity of knapsack.
 *
 * This problem can be stated as 
 *
 * Maximize: summation(Pi * Xi) i = 1 to n (Optimizing function)
 *
 * Constraint: (summation(Wi * Xi) i = 1 to n) <= M (Constraint)
 *
 * Optimal Solution: The objects are arranged in decreasing order of Pi/Wi
 *
 * Before Solving the problem arrange all objects in decreasing order of Pi/Wi
 * 
*/

/* Algorithm:
 *
 * Purpose: To find the solution vector that shows that shows the fraction
 * of the object selected.
 *
 * Input: m is the capacity of the knapsack
 *        n is the number of objects
 *        w is an array that consists of weights of all n objects
 * Output: x contains the solution vector
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
   int maxCapacity = 0, num_of_elements = 0, i =0, j =0, remainingCapacity = 0;
   float *weights;
   float *profits;
   float ratio[20] = {0.0};
   float solutionVector[20] = {0.0};
   float temp = 0.0, maxProfit = 0.0;

   system("clear");

   printf("\nInput the capacity of the Knapsack");
   scanf("%d",&maxCapacity);

   printf("\nInput the number of elements:");
   scanf("%d",&num_of_elements);
   
   weights = (float *) malloc(num_of_elements * sizeof(float));
   profits = (float *) malloc(num_of_elements * sizeof(float));

   printf("\nInput the weights of the objects");
   for(i = 0; i < num_of_elements;i++)
   {
      scanf("%f",&weights[i]);
   }

   printf("\n Input Profits of the objects");
   for(i=0; i < num_of_elements; i++)
   {
      scanf("%f",&profits[i]);
   }
   
   // Remaining capacity is initialized to maximum capacity of the knapsack
   remainingCapacity = maxCapacity;

   //Arrange it in descending order
   //
   for(i=0; i < num_of_elements ; i ++)
   {
      ratio[i] = profits[i]/weights[i];
   }

   //Selection Sort
   for(i=0;i< num_of_elements;i++)
   {
      for(j=i+1; j < num_of_elements; j++)
      {
         if(ratio[i] < ratio[j])
         {
            temp = ratio[i];
            ratio[i] = ratio[j];
            ratio[j] = temp;

            temp = weights[i];
            weights[i] = weights[j];
            weights[j] = temp;

            temp = profits[i];
            profits[i] = profits[j];
            profits[j] = temp;
         }
      }
   }


   for(i = 0 ; i < num_of_elements; i++)
   {
      if(weights[i] > remainingCapacity)
         break;//ith object cannot be selected

      solutionVector[i] = 1; //Select the ith object
      maxProfit = maxProfit + profits[i];
      remainingCapacity = remainingCapacity - weights[i]; // Find the remaining capacity of the knapsack
   }

   if(i <= num_of_elements) 
      solutionVector[i] = remainingCapacity/weights[i]; 
   
   maxProfit = maxProfit + (solutionVector[i] * profits[i]);

   printf("The resultant vector is:");
   for(i=0;i<num_of_elements;i++)
      printf("%f\t",solutionVector[i]);
   printf("\n");

   printf("Maximum Profit is : %f\n",maxProfit);

   return 0;

}
