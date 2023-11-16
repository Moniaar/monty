# monty

Monty is a scripting language. what we are supposed to do is create an intepreter for that language.

mostly scripts of monty have a .m extension. 

for exampe let us say there is a script file called new.m

Then that file will haev a list of commands in it line by line .

for example it might have 


push 2
pop
pall
push 3


SO this file will have 4 lines of commands.

that is basically a monty script.


So to have your monty interpreter

you open new,m with functions like f open and close it with fclose when you are done with it.

its implementation is ./monty new.m

so if there are more than 2 command line arguments, (the file name and the monty excutable command), you print out the error.

if the file cant be opened for some reason you print out the given error.

after you open the file,

you basically go through the script line by line. you parse it in to an array.
use get line or fgets for the line like we used in a command line interpreter.

so after that you tokenize it based on delimiters. 

so forexamlple in new,m

push 2 

becomes two tokens. push is the first token, 2 is the second token.

after that token[0] which is  push becomes the opcode. stack_t will be the doubly linked list where you implement these op codes.

so for push opcode you are supposed to write a function, push. you comapre the token[0] with the name wihich is push and select the respective function.  it will be based on the structre provided named 
instruction_t.

so your push function for example 
will look like 

void push(stack_t **stack, unsigned int line_number)

for the rest of the functions to, you compare your first token with the name, if strcmp returns 0 when you compare them you select the function that is to be used.

from my understanding so far, we are supposed to create an interpreter of a .m extension script (monty language).

That script for example has a list of commands, known in our project as opcodes that implement a stack.

for example push, pop are opcodes. 

its implementation is ./monty file

you open the file

then print out errors accordingly if the argument is more than 2 meaning monty an the file. 

if it doesnt open with fopen then you print out the error accordingly.

after that you parse the script line by line to get an array of tokens. This is similar to what we did in a simple shell interpreter.

then token[0] will be the opcode, token[1] will be the argument for the op code.

for example: the script could be in a file called "new"

so you open the file'

after that it might have 2 lines in its script.

push 2
pop

so you take eachline by get line or fgets, parse it in to tokens. then you execute matching functions whether it is adding to the stack or poping.
