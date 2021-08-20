My solutions for the dsa practice sheet by striver
[DSA PRACTICE SHEET](https://docs.google.com/document/d/1SM92efk8oDl8nyVw8NHPnbGexTS9W-1gmTEYfEurLWQ/edit)

> **My profiles:** 
> Rohit Kumar Varma (@immortal_1 at codechef and codeforces)
Amrita Vishwa Vidyapeetham, Amritapuri Campus
3rd year, Electronics and Communication Engineering
Connect @ [LinkedIN](https://www.linkedin.com/in/rohit-kumar-varma-8b880b1b9/)

Day1: Arrays
---
Problem-1:
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

Problem-2:
Title: Repeat and Missing Number 

Overview: Given an array of size n with elements in the range {1,2,...n} inclusive. One number is replaced
with another number, so find the repeating number and the missing number

Brute: Just sort using sort algo from stl
TL:O(nlogn), SC: O(1);

Better: Use Hashing
TL:O(nlogn), SC: O(1);

Optimal: Sum and SquareSum method;
TL:O(n), O(1);

Extra notes: https://www.youtube.com/watch?v=5nMGY4VUoRY&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=3

---

Problem-3:

---

Problem-4:
Title: Kadane's Algo (Maximum Subarray Sum)

Overview: Find the maximum sum of any subarray (consecutive elements), in the given array

Brute: three loops (0 to n-1, i to n-1, i to j here we do sum = sum+arr[k] and maxsum is calculated after this loop)
T.C: O(n^3), S.C: O(1);

Better: two loops (0 to n-1, i to n-1, and add sum at every step over here)
T.C: O(n^2), S.C: O(1);

Optimal: Kadanes algo

Extra notes: https://www.youtube.com/watch?v=w_KEocd__20&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=6

---
