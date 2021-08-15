## Useful links
- http://www.unknownroad.com/rtfm/gdbtut/gdbtoc.html

## Steps

a. Run GDB on the map executable.
```
gdp map
```
b. Set a breakpoint at the beginning of the program’s execution.
```
break map.c:14
```
c. Run the program until the breakpoint.
```
run
```
d. What memory address does argv store?
```
(gdb) print argv
$1 = (char **) 0x7fffffffe098
```
e. Describe what’s located at that memory address. (What does argv point to?)
```
(gdb) print *argv
$2 = 0x7fffffffe320 "/home/vagrant/code/personal/hw0/map"
```
f. Step until you reach the first call to recur.
g. What is the memory address of the recur function?
```
(gdb) print recur
$3 = {int (int)} 0x5555555546cd <recur>
```
h. Step into the first call to recur.
i. Step until you reach the if statement.
j. Switch into assembly view.
k. Step over instructions until you reach the callq instruction.
l. What values are in all the registers?
m. Step into the callq instruction.
n. Switch back to C code mode.
o. Now print out the current call stack. (Hint: what does the backtrace command do?)
```
(gdb) backtrace
#0  __printf (format=0x555555554794 "%i\n") at printf.c:32
#1  0x00005555555546f4 in recur (i=1) at recurse.c:6
#2  0x0000555555554707 in recur (i=2) at recurse.c:9
#3  0x0000555555554707 in recur (i=3) at recurse.c:9
#4  0x00005555555546c6 in main (argc=1, argv=0x7fffffffe098) at map.c:21
```
p. Now set a breakpoint on the recur function which is only triggered when the argument is 0.
q. Continue until the breakpoint is hit.
r. Print the call stack now.
```
(gdb) backtrace
#0  recur (i=0) at recurse.c:8
#1  0x0000555555554707 in recur (i=1) at recurse.c:9
#2  0x0000555555554707 in recur (i=2) at recurse.c:9
#3  0x0000555555554707 in recur (i=3) at recurse.c:9
#4  0x00005555555546c6 in main (argc=1, argv=0x7fffffffe098) at map.c:21
```
s. Now go up the call stack until you reach main. What was argc?
```
(gdb) frame 4
#4  0x00005555555546c6 in main (argc=1, argv=0x7fffffffe098) at map.c:21
21          recur(3);
(gdb) print argc
$4 = 1
```
t. Now step until the return statement in recur.
u. Switch back into the assembly view.
v. Which instructions correspond to the return 0 in C?
```
0x0000555555554709 <+60>:    mov    $0x0,%eax
```
w. Now switch back to the source layout.
x. Finish the remaining 3 function calls.
y. Run the program to completion.
z. Quit GDB.