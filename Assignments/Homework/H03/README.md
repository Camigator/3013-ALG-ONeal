## Homework - Data Structures and Complexity
#### Due: 03-13-2020 (Friday @ 3:30 p.m.)

- Given a collection of algorithms that runs on **O(1), O(n log n), O(n), O(n<sup>2</sup>), O(log n), O(n!)**, order the algorithms from fastest to slowest.
- Suppose that the complexity of an algorithm is O(n<sup>2</sup>). Suppose that the program that uses the algorithm run in 10 seconds for a data set of size n. If the data size is doubled, how long will it take (approximately) to run the program? 


- Complexities : **O(1), O(n log n), O(n), O(n<sup>2</sup>), O(log n), O(n!) , O(h)**

<p> 1.Finding the max element in an unordered stack would require <b> O(n) </b> operations? </p>
<p> 2. Finding the min element in an unordered queue would require <b> O(n) </b> operations? </p>
<p> 3. Finding some element in some Binary Search Tree would require <b> O(h) </b> operations? </p>
<p> 4. Finding some element in a balanced Binary Search Tree would require <b> O(log n) </b> operations? </p>
<p> 5. Finding some element in an ordered linked list would require <b> O(n) </b> operations (worst case)? </p>
<p> 6. Finding some element in an ordered linked list would require <b> O(n) </b> operations (average case)? </p>
<p> 7. Finding some element in an unordered linked list would require <b> O(n) </b> operations (worst case)? </p>
   


8. For each of the following, count the number of operations where some_statement is executed based on the loops

```cpp
//A
for (int I = 0; I < n; I++)
    for (int j = 1; j < n; j++)
        {some_statement;}
```
( n<sup>2</sup>)

```cpp
//B
for (int I = 0; I < n; I +=2)
    for (int j = 1; j < n; j++)
        {some_statement;}
```
( n<sup>2</sup>)/2

```cpp
//C
for (int j = 1 ; j < n ; j *= 2)
    for (int I = 1; i<n; i++)
        {some_statement;} 
```
(n * (log n))

At most, how many comparisons are required to search a sorted vector of 1023 elements using the binary
search algorithm?

In each of the following examples, please choose the best data structure(s).
- Options are: **Array, Linked Lists, Stack, Queues, Trees, Graphs, Sets, Hash Tables**. 
- Note that there may not be one clear answer.

 <p>1. You have to store social network “feeds”. You do not know the size, and things may need to be dynamically added. </p>
        <p><b> Linked List </b></p>
<p>2. You need to store undo/redo operations in a word processor. </p>
        <p><b> Stack </b></p>
<p>3. You need to evaluate an expression (i.e., parse). </p>
        <p><b> Stack </b></p>
<p>4. You need to store the friendship information on a social networking site. I.e., who is friends with who. </p>
        <p><b> Graphs </b></p>
<p>5. You need to store an image (1000 by 1000 pixels) as a bitmap.</p>
        <p><b> 2D - Array </b></p>
<p>6. To implement printer spooler so that jobs can be printed in the order of their arrival.</p>
        <p><b> Queue </b></p>
<p>7. To implement back functionality in the internet browser.</p>
        <p><b> Stack </b></p>
<p>8. To store the possible moves in a chess game.</p>
        <p><b> Directional Graph </b></p>
<p>9. To store a set of fixed key words which are referenced very frequently.</p>
        <p><b> Hash </b></p>
<p>10. To store the customer order information in a drive-in burger place. (Customers keep on coming and they have to get their correct food at the payment/food collection window.)</p>
        <p><b> Queue </b></p>
<p>11. To store the genealogy information of biological species.</p>
        <p><b> Graph </b></p>
<p>12. To store an alphabetized list of names in order to look up quickly.</p>
        <p><b> Hash </b></p>


## Deliverables

- Edit this file and add your answers using markdown!
- Create a folder called `H03` in your assignments folder.
- Put a copy of your markdown file in this folder, and call it README.md.
- Upload to github sometime close to the due date.
- Print out your banner ON ITS OWN PAGE

```
H03
3013
O'Neal
```

- Print out a hard copy of the file as well. Do not print directly from github. Either use `gitprint` or make it a pdf and print it.
- Make sure you answer thoroughly using complexities where appropriate and/or explaining your choices etc.

