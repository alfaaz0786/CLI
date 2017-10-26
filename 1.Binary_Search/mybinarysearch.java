Title: Using Divide and Conquer strategies design a function for Binary Search using Java/Python 
Roll no:
BE-B 

import java.io.*;
import java.util.*;

public class MyBinarySearch 
{
 
    public void binarySearch(int[] arr, int key,int size) 
    {
         int low_index = 0;
         int high_index = size - 1;
	 int flag = 0; 
	 int mid = (low_index + high_index) / 2;

         while (low_index <= high_index)
 	 {
            mid = (low_index + high_index) / 2;

            if (key == arr[mid])    // if key is middle
	    {
		flag=1;
		break;
            }
            if (key < arr[mid])
	    {
                high_index = mid - 1;    // if key is before the middle element
            } 
            if(key > arr[mid] )          // if key is after the middle element
	    {
                low_index = mid + 1;
            }
        }
        if(flag==1)
	{
	  System.out.println("Key position is : "+ mid);
	}
        else
	{
		System.out.println("Element not found");
	}

    }
    public static void main(String[] args) 
    {
        int low_index,high_index,mid,size,i,key, choice;

	Scanner s = new Scanner(System.in);

        MyBinarySearch mbs = new MyBinarySearch();

	System.out.println("Enter the size of the array:");
	size = s.nextInt();
	int [] arr=new int[size];
	 
	System.out.println("Enter the array elements:");
	for(i=0;i<size;i++)
	{
		arr[i]=s.nextInt();
	}
	System.out.println("Array is:");
	for(i=0;i<size;i++)
	{
	  System.out.println(" "+arr[i]);
	}
	do
	{	

		System.out.println("Enter the number to be searched:");
		key = s.nextInt();

		mbs.binarySearch(arr,key,size); 
		System.out.println("Do you want to continue: yes=1 no=0");
		choice = s.nextInt();
	}
	while(choice != 0 );
    }

}

/*Output:
prjlab@prjlab-dx2480-MT:~/Desktop$ javac MyBinarySearch.java
prjlab@prjlab-dx2480-MT:~/Desktop$ java MyBinarySearch
Enter the size of the array:
3
Enter the array elements:
1
2
3
Array is:
 1
 2
 3
Enter the number to be searched:
1
Key position is : 0
Do you want to continue: yes=1 no=0
1
Enter the number to be searched:
2
Key position is : 1
Do you want to continue: yes=1 no=0
1
Enter the number to be searched:
3
Key position is : 2
Do you want to continue: yes=1 no=0
1
Enter the number to be searched:
4
Element not found
Do you want to continue: yes=1 no=0
0
prjlab@prjlab-dx2480-MT:~/Desktop$ 
*/

