
prerequisites for execution:

Make sure all these files exist before running the program.

1.lab4.cpp,HashTable.cpp,HashTable.h,Lnode.h,SList.cpp,SList.h

2.all.last.txt(to create the hashtable).

3.HT1.txt to save the elements of the hashtable created by using djb2 hash code function.

4.HT2.txt to save the elements of the hashtable created by using sdbm hash code function.


Process for execution:

On execution of the project,all last names are read from the all.last.txt file creates hashtables with the size 88801 and displays the time took for calcution of hashtables using djb2 and sdbm.
Menu is displayed for performing operations on hashtables created using djb2 and sdbm hash code functions.
Select the operation which you need to perform on the hashtable.
For performing operations on hashtable created by djb2 hash code function:
(A1)Add record to djb2 Hash table:Select 'A1' for adding a record to djb2 Hash table.If you select 'A1',screen prompts to enter the lastname you want to add to the hash table.Enter the lastname.If the latname is already present in the table,it is not added again and prints the message "Duplicate record".Otherwise the record is added and prints the message.
       
(D1)Delete from djb2 Hash table: Select 'D1' to delete a lastname record from djb2 Hash table.If you select 'D1',asks the user to enter the lastname you wanted to delete from the table.If the lastname which is to be deleted is not present in the table,prints the message "Record cannot be deleted".Otherwise deletes the record and displays the success message.
       
(S1)Search from djb2 Hash table: Select 'S1' to search a lastname record from djb2 Hash table.This returns the bucket number of the lastname if the record is present in the hashtable otherwise it displays the message "Record not found".

(L1)Save djb2 Hash table to log file:Select 'L1' to save djb2 Hash table to log file "HT1.txt" and prints the bucket size excluding the empty locations.This will save all the lastnames and displays the lastnames with their bucket numbers and also empty locations as "Empty".

For performing operations on hashtable created by sdbm hash code function:

(A2)Add record to sdbm Hash table:Select 'A2' for adding a record to sdbm Hash table.If you select 'A2',screen prompts to enter the lastname you want to add to the hash table.Enter the lastname.If the latname is already present in the table,it is not added again and prints the message "Duplicate record".Otherwise the record is added and prints the message.
       
(D2)Delete from sdbm Hash table: Select 'D2' to delete a lastname record from sdbm Hash table.If you select 'D2',asks the user to enter the lastname you wanted to delete from the table.If the lastname which is to be deleted is not present in the table,prints the message "Record cannot be deleted".Otherwise deletes the record and displays the success message.
       
(S2)Search from sdbm Hash table: Select 'S2' to search a lastname record from sdbm Hash table.This returns the bucket number of the lastname if the record is present in the hashtable otherwise it displays the message "Record not found".

(L2)Save sdbm Hash table to log file:Select 'L2' to save sdbm Hash table to log file "HT2.txt" and prints the bucket size excluding the empty locations.This will save all the lastnames and displays the lastnames with their bucket numbers and also empty locations as "Empty".

(Q)Quit: Select 'Q' for deleting the elements of the both the hashtables to make sure there is no memory leak and exits from the execution.

On execution of the project,all last names are read from the all.last.txt file creates hashtables with the size 88801 and displays the time took for calcution of hashtables using djb2 and sdbm.It is observed that time taken for hashtable using sdbm is less compared time taken for hashtable using djb2.So sdbm is efficient and have less collisions compared to djb2.So sdbm will have more buckets compared to djb2.


