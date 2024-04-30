# monty
<dl>
  <dt>But wait a minute...what is a Monty lanugauge?</dt>
  <dd>Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it</dd>
  <dt>Interpeter</dt>
  <dd>A program that directly executes the instructions in a high-level language, without converting it into machine code. In programming, we can execute a program in two ways. Firstly, through compilation and secondly, through an interpreter. And the  common way is to use a compiler</dd>
</dl>

what we are supposed to create is an intepreter for that language as mostly scripts of monty have a .m extension. 
For example let us say there is a script file called new.m, then that file will have a list of commands in it line by line .
as an example for that script is the following:
` push 4
  push 3
  push 2
  pall `
All in different seperate lines, and no more than 2 arguments passed into it. This code will give you a stack with the following output:
` 2 3 4 `
All printed in seperate lines using the pall command which is shortend to "print all" to print the stack content. And that is basically what a monty script is.
## How it works?: ##
1. To have your monty interpreter, you open ` new.m ` with functions like fopen and close it with fclose when you are done with it.
Its implementation is ` ./monty new.m ` Which where the ./monty is the exe. you get after executing the whole source files when you install it.
2. So if there are more than 2 command line arguments, (the file name and the monty excutable command), you print out the error found in the files that handles them.
3. In addition, if the file can't be opened for some reason, you print out the given error.
4. After you open the file, you basically go through the script line by line. you parse it in to an array of char, you use get line or fgets for the line like we used in a command line interpreter.
5. Then you tokenize it based on delimiters. So for examlple in new.m
` push 2 ` becomes two tokens. push is the first token, as 2 is the second token.
6. After that token[0] which is push becomes the opcode. stack_t will be the doubly linked list where you implement these op codes.
7. For pushing opcode you are supposed to write a function, push. You comapre the token[0] with the name which is push and select the respective function. It will be based on the structure provided named instruction_t.
Your push function for example will look like:
` void push(stack_t **stack, unsigned int line_number) `
9. For the rest of the functions, you compare your first token with the name, if the function strcmp returns 0 when you compare them, you select the function that is to be used.
10. That script for example has a list of commands, known in our project as opcodes that implement a stack. As an like example push, pop are opcodes. You open the file then print out errors accordingly if the argument is more than 2 in the file. If it doesnt open with fopen then you print out the error accordingly.
11. token[0] will be the opcode, token[1] will be the argument for the op code.

## How to install it?: ##
compile with the following:
    ` gcc -Wall -Werror -Wextra -pedantic *.c -o monty ` 
### Concpets you need to make yourself familier with before diving here ###
1. DMA (Dynamic Memory Allocation)
2. Stacks and Queues
3. Data structures and algorithems basics
4. File handling
5. Singly and doubly linked lists
---
## *References* ##
1. [How to use extern to share variable between cource files?](https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files)
2. [google](www.google.com)
3. [Stacks and queues in C](https://data-flair.training/blogs/stacks-and-queues-in-c/)
4. [Stack operation](https://www.digitalocean.com/community/tutorials/stack-in-c)
5. [Queue operation](https://www.edureka.co/blog/queue-in-c/)
6. [Toppr website](https://www.toppr.com/guides/computer-science/computer-fundamentals/system-software/interpreter/#:~:text=An%20interpreter%20is%20a%20program,is%20to%20use%20a%20compiler.)

### Authors ###
> 1. Solomon Chidera
> 2. Omnia Ahmed (Moniaar)
