# cs3113sp20-project0
By Fabrizio Deza

This program was coded/run from my GCP VM command line using the command "cat test | ./project0" or "cat test | ./a.out" depending on which makefile I am using (I editted my makefile so that it would work with grade scope). "test" was the file I was using to test my code. I was not able to encounter more bugs after debugging. 

List of libraries used: 
stdlib.h
stdio.h
string.h

The code takes in contents from a file use the "cat" commamnd. My main function reads in a char and distinguishes how many bytes it has. It then calls on my function handleMember() and this function checks if the char already exists in my struct array. If the char is already saved in the char array, the count of that member in struct is incremented. If the char is not already saved, then I used a strcpy function to copy the char to the struct at position, "pos" (passed to the function handleMember). It also sets count to 1 and earliestPos(a member of my struct) to pos. It then increments pos and returns it.  

After all the chars in stdin are added. I then call on the function qsort() with the compare function as one of the parameters. In the compare function, the count of each struct is compared and it returns -1 or 1 depending on the count of the each struch. If count is equal for two structs being compared, I used the earliestPos data member in my struct to order them based on which struct element was added first.

I then use the function printList to print all of my struct array in the desired format. I did this by using a for loop setting the end of the for loop when i < pos. 

