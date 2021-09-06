You will use this exact Makefile for your Homework 1.
Failure to do so will result in deduction of points.

To compile on terminal type
  make clean
  make all

To delete executables and object file type
  make clean

To run:

./test_points2d

^^In that case you will provide input from standard input.

To run with a given file that is redirected to standard input:

./test_points2d < test_input_file.txt


Tanmoy Paul

PART 1: 
1. Comments were added describing the class. 

2. For zero-parameter constructor, size_ was changed. 

3. For copy constructor, size and sequence were copied from 
    the parameter object.

4. For copy-assignment, the = operator was redefined with swap()

5. For move constructor, size and sequence were copied from 
    the parameter object with move(). The parameter object 
    was set to null. 

6. For move-assignment, the = operator was redefined by using
    swap() on both size and sequence. 

7. For deconstructor, the dynamically allocated sequence was deleted. 

PART 2: 
8. For the one parameter constructor, the sequence was created 
    with the parameter array item. 

9. For ReadPoints2D(), the size and sequence were defined and 
    the squence was filled with inputted points. 

10. For size(), the size was returned. 

11. For operator[], a point was returned from the sequence based 
    on the location parameter. 

12. For operator+, the sum of two sequences was returned. If one
    sequence was bigger, the extra points were added to the end. 

13. For operator<<, the points in the sequence of the some_points2
    object were formatted for printing. The result was appended to 
    the output stream parameter. 