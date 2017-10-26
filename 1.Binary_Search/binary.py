Title: Using Divide and Conquer strategies design a function for Binary Search using Java/Python 
Roll no:
BE-B 

import time
import os
import sys

def binary_sort(sortedlist,n,x):

 start = 0
 end = n - 1
 while(start <= end):
  mid = (start + end)/2    #if element is  less than middle
  if (x == sortedlist[mid]):
   return mid		   #if element is middle
  elif(x < sortedlist[mid]):
   end = mid - 1	   #if element is more than middle
  else:
   start = mid + 1 
 
 return -1

n = input("Enter the size of the list: ")

sortedlist = []

for i in range(n):
 sortedlist.append(input("Enter %d th element: "%i)) #inserting the elements

while True:
 x = input("Enter the number to search: ")
 position = binary_sort(sortedlist, n, x)

 if(position != -1):
  print(" number %d is present at position: %d"%(x,position))
 else:
  print(" number %d is not present in the list"%x)
  break

'''output:
prjlab@prjlab-dx2480-MT:~/Desktop$ python binary.py
Enter the size of the list: 5
Enter 0 th element: 5
Enter 1 th element: 6
Enter 2 th element: 7
Enter 3 th element: 8
Enter 4 th element: 9
Enter the number to search: 5
 number 5 is present at position: 0
Enter the number to search: 7
 number 7 is present at position: 2
Enter the number to search: 9
 number 9 is present at position: 4
Enter the number to search: 10
 number 10 is not present in the list
prjlab@prjlab-dx2480-MT:~/Desktop$ 
'''

