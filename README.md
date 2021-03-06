My solutions for the dsa practice sheet by striver
[DSA PRACTICE SHEET](https://docs.google.com/document/d/1SM92efk8oDl8nyVw8NHPnbGexTS9W-1gmTEYfEurLWQ/edit)

> **My profiles:** 
> Rohit Kumar Varma (@immortal_1 at codechef and codeforces)
Amrita Vishwa Vidyapeetham, Amritapuri Campus
3rd year, Electronics and Communication Engineering
Connect @ [LinkedIN](https://www.linkedin.com/in/rohit-kumar-varma-8b880b1b9/)

Day1: Arrays
---
**Problem-1:**

**Title**: Sort an array of 0’s 1’s 2’s without using extra space or sorting algo 
**Overview**: Given an array and a number n, the array contains n elements consisiting of only 0's, 1's and 2's
sort the array such that 0's are on left 1's in middle and 2's in right. The final target is to acheive.
this without using any space.
**Brute**: Just sort using sort algo from stl
TL:O(nlogn), SC: O(1);

**Better**: Use Count sort
TL:O(n), SC: O(n);

**Optimal**: Ductch national flag algo: Low, mid High pointers at start, start, end respectively and 
move mid till high>mid and swap the (low , mid) if a[mid] ==0 (++low, ++mid), 
and (mid, high) if a[mid]==2 (--high), we need to make sure that everything before low is 0 and 
everything after high is 2.
T.C: O(n), SC: O(1);

**Extra notes:**
https://www.youtube.com/watch?v=oaVa-9wmpns&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=2

---

**Problem-2:**

**Title**: Repeat and Missing Number 

**Overview**: Given an array of size n with elements in the range {1,2,...n} inclusive. One number is replaced
with another number, so find the repeating number and the missing number

**Brute**: Just sort using sort algo from stl
TL:O(nlogn), SC: O(1);

**Better**: Use Hashing
TL:O(nlogn), SC: O(1);

**Optimal**: Sum and SquareSum method;
TL:O(n), O(1);

**Extra notes**: https://www.youtube.com/watch?v=5nMGY4VUoRY&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=3

---

**Problem-3:**

**Title**: Merge two sorted Arrays without extra space 

**Overview**: Given two sorted arrays, merge them both in sorted order. Initially we will try with extra space and then we will optimise without any extra space.

**Brute**: Use a third array and then plug in all the elements of both the arrays, sort the third array and plug the elements back.
TL:O(nlogn), SC: O(n);

**Better**: We will not use any auxilary space, we will traverse the firse array and then we will compare every element of the first array and the second array and if the elements of the second array is greater than the first array, then swap them and place the swapped element from the first array properly in the second array such that the sorted order remains intact (this can be done by traversing through the second array and placing in appropirate postion)
TL:O(n), SC: O(1);

**Optimal**: GAP method (too complex, will implement later).

**Extra notes:** https://www.youtube.com/watch?v=hVl2b3bLzBw&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=5

---

**Problem-4:**

**Title**: Kadane's Algo (Maximum Subarray Sum)

**Overview**: Find the maximum sum of any subarray (consecutive elements), in the given array

**Brute**: three loops (0 to n-1, i to n-1, i to j here we do sum = sum+arr[k] and maxsum is calculated after this loop)
T.C: O(n^3), S.C: O(1);

**Better**: two loops (0 to n-1, i to n-1, and add sum at every step over here)
T.C: O(n^2), S.C: O(1);

**Optimal**: Kadanes algo

**Extra notes:** https://www.youtube.com/watch?v=w_KEocd__20&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=6

---
**Problem-5:**

**Title**: Merge Intervals

**Overview**: given a collection of intervals like [[1,3], [2,6], [8, 10], [15, 18]], merge the overlapping

intervals, O/P: [[1, 6], [8, 10], [15, 18]]

*In interview we need to ask if the array is sorted or not.

If not sorted we sort the array.

**Brute**: We traverse throught the sorted array and check if the the current pair of intervals exisist in the

extra ds if it exisits we skip else we search for merging interval after the pair if exisits it merges

and stores it in the extra ds, else stores the pair itslef in the extra ds

T.C: O(nlogn)+O(n^2), S.C: O(n);

**Optimal**: First sort the vector intervals. Maintain a pair<int, int> and intialize it as first pair in the interval vector, and iterate linearly through the interval array and check if the current pair merges with the pair variable we are maintaining, if it merges replace the variable with the merged pair, and continue till we find non merging
pair, if found push the current value of the variable into a data structure and then replace the curr variable
with the non merging pair of the interval, finally we get all the merging pairs of the interval into the data structure.

T.C: O(nlogn)+O(n), S.C: O(n);

**Extra notes:** https://www.youtube.com/watch?v=2JzRBPFYbKE&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=7

---
**Problem-6:**

**Title**: Find the duplicate in an array of N+1 integers.

**Overview**: Given an array and n, array elements ranging from 1 to n, find the number which is duplicate in the array.

**Brute**: Sort the array and find the duplicate, but this will distort the array
T.C: O(nlogn), S.C: O(1);

**Better**: Hashing (Frequency array)
T.C: O(n), S.C: O(n);

**Optimal**: Linked List Cycle method, create a cycle of the form index->val->index and then as there are duplicate elements of a single value, all of them point to a single index called the intersection element we traverse through the array with fast and slow pointers(floyd cycle detection algo), and find the intersection of fast and slow pointers and then we make the fast pointer slow and point it to the 0th index and move both slow and fast(slowed down fast) till same elements are found and that element is the duplicate element.
T.C: O(n), S.C: O(1);

**Extra notes:**
https://www.youtube.com/watch?v=32Ll35mhWg0&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=2
https://www.youtube.com/watch?v=dfIqLxAf-8s (Very good explanation of the floyd cycle detection algo)

---

Day2: Arrays
---
**Problem-1:**

**Title**: Set Matrix Zeros 

**Overview**: Given an matrix, with zerores at certian positions, if a postion contains zero, make that col
row filled with zeroes. 

**Brute**: We can iterate through the whole array and when we find 0 we traverse its whole row and coloumn and
if the element is not 0 than we change the element to -1, after changing all the required elements to -1
we traverse again and make all -1's 0/
T.C: O((n*m)*(n+m)), S.C: O(1);

**Better**: We take two dummy arrays, we traverse throgught the array and if we find the elemnt to be zero
then we make the col index and row index in the dummy arrays zero and again traverse the matrix, if
one of the col or row at current index is zero we change the curr element to zero.
T.C: O((n*m)+(n*m)), S.C: O(n+m);

**Optimal**: We bring both these dummy arrays into the matrix itself and the first dummy array is the first
row, and the second dummy array is the first col, and we maintain a bool called colval = true initially
which checks if any of the element in the first col is zero, if zero we update the colval = false, this
is done to make sure that the elements dont turn zero due to the elements which turned into zeroes due to
the original zero elements. We traverse from back of the matrix and fill the matrix with zeroes at 
appropirate positions according to the zeroes in the dummy arrays and the colvar.
T.C: O((n*m)+(n*m)), S.C: O(1);

**Extra notes**: https://www.youtube.com/watch?v=M65xBewcqcI&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2

---

**Problem-2:**

**Title**: Pascal Triangle 

**Overview**: We see 3 types of questions here 1. print the whole pascal traingle, print the nth row of a 
pascale traingle or print the mth element in nth row of a pascal traingle.

**Type-1**: **To print the whole pascale traingle:** We just use the basic condition with which pascal traingle
is built i.e. we add the top left and top right elements to get the current element.
T.C: O(n^2) 
S.C: O(n^2);

**Type-2: To print the mth element in the nth row of a pascal traingle:** We use the formula (Row-1)C(Col-1)
this takes time complexity of O(n).
T.C: O(n), S.C: O(1); 

**Type-3: To print the nth row of the pascal traingle:** We use the formula (Row-1)C(Col-1) itself but we 
dont directly do it for every element because doing so we need more time complexuty, i.e, O(n) for every
in the pascals traingle, that is O(n^2) to reduce that we use a trick, that is every previous element
in the row needs to be multiplied by rowno-col and divided by col, and reassign the prev val this makes
the time complexity linear time. 
T.C: O(n), S.C: O(n);

**Extra notes:** https://www.youtube.com/watch?v=6FLvhQjZqvM&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=8

---

Probelm-3:

**Title**: Next Permutation 

**Overview**: Given an array of numbers print the next permuation of the array sequence

**Brute**: use next_permutation() inbuilt in cpp but usually inbuilt is not accepted at interview

**Optimal**: We find the pivot point which is the point at which the next dictionary sequence starts from
like if we take 1 2 3 the pivot point is 2 as the next number in dictionary is 1 3 2. We find this in step-1
by finding the first non-increasing number from the backside and then in step-2 we find the first number
greater than the number we find in step-1, and then we swap the numbers found in step-1 and step-2.
After swapping we reverse the numbers from pivot(step1)+1 to the last index to maintain the lowest rank
sequence.

**Extra notes**: https://www.youtube.com/watch?v=LuLCLgMElus&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=10

---
**Problem-4:**
**Title**: Inversion of Array (Using Merge Sort)

**Overview**: Given an array find the number of count inversions in the array. Count inversion can be

defined as the follows: no of instances when i>j and arr[i]>arr[j].

**Brute**: for(for()) loop and find the number of times this case satisfies.

T.C: O(n^2), S.C: O(1);

**Optimal**: Here we use a kind of merge sort, which is modified for this specific purpose of the qn. In general the merge sort breaks the array into individual elements and compare them in the individual level and the merge them back according to the comparision. So this is also similar
but after breaking into the individual elements before combining them, we count the number of elements
to the right of the smaller element and add them to the inversion count variable, in each iteration of merge process.
T.C: O(nlogn), S.C: O(n);

**Extra notes:** https://www.youtube.com/watch?v=kQ1mJlwW-c0&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=11

---

**Problem-5:**

**Title**: Best Time to BUY and SELL STOCK

**Overview:**
Given an array find the pair of days to buy and sell given that the elements are the prices on the corresponding dates. Find the maximum profit. (NOTE: BUY DATE (INDEX) < SELL DATE (INDEX)).
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

**Brute**: Just make two for loops and find the minimum diff of buy and sell dates by updating for every iteration.
T.C: O(n^2), S.C: O(1);

**Optimal**: Similar to kadane's algo, keep a minimum variable and keep it updating, and while updating, also keep updating the max profit we can acheive with the curr val and the stored minimum.

T.C: O(n), S.C: O(1);

**Extra notes:**
https://www.youtube.com/watch?v=eMSfBgbiEjk&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=12
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/ (leetcode)

---

**Problem-6:**

**Title**: Rotate the matrix by 90 degrees

**Overview**: Given a matrix rotate it by 90 degrees in clockwise direction

**Brute**: We can use temp array and store all the rows in the main array as cols in the temp array.
T.C: O(n^2), S.C: O(n^2);

**Optimal**: We can transpose the array and then reverse each row in the array.
T.C: O(n^2), O(1) (in-place)

**Extra notes:** https://www.youtube.com/watch?v=Y72QeX0Efxw&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=13

---
