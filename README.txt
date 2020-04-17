13 April 2020
Nicole Sullivan
@02894357

Infinite Number Calculations


Summary:
I was successful in the addition, multiplication, and factorial calcualtions. However, I 
did encounter a problem during multiplication, where I was unable to call add inside of 
my multiplication function. Due to this,the instances of result and tem_result were not 
dynamically allocated. Also, whenever I try to input a number larger than 9 digits,
the "command" statement get repeated until I have to terminate the program.
I believe this is a bug with the original code due to the size of integers.



Working Session:

nicolesullivan@Nicoles-MBP infinite_num % make    
g++ -c longint.cpp
g++ main.o longint.o -o output
nicolesullivan@Nicoles-MBP infinite_num % ./output
Available commands: a (add), m (multiply), f (factorial), and q (quit).

command: a									//addition
left operand = 0
right operand = 0
0 + 0 = 0
command: a
left operand = 1
right operand = 2
1 + 2 = 3
command: a
left operand = 111111
right operand = 222222
111111 + 222222 = 333333
command: a
left operand = 300000
right operand = 3
300000 + 3 = 300003
command: a
left operand = 999999
right operand = 3
999999 + 3 = 1000002
command: a
left operand = 3
right operand = 999999
3 + 999999 = 1000002
command: a
left operand = 123456789
right operand = 789
123456789 + 789 = 123457578
command: a
left operand = 789
right operand = 123456789
789 + 123456789 = 123457578

command: m										//multiplication
left operand = 1
right operand = 1
1 * 1 = 1
command: m
left operand = 55555
right operand = 1
55555 * 1 = 55555
command: m
left operand = 1
right operand = 55555
1 * 55555 = 55555
command: m
left operand = 66666
right operand = 0
66666 * 0 = 00000
command: m
left operand = 0
right operand = 66666
0 * 66666 = 00000
left operand = 55555
right operand = 66666
55555 * 66666 = 3703629630
command: m 
left operand = 98765
right operand = 9
98765 * 9 = 888885
command: m
left operand = 9
right operand = 98765
9 * 98765 = 888885
command: m
left operand = 100000
right operand = 98765
100000 * 98765 = 9876500000
command: m
left operand = 98765
right operand = 100000
98765 * 100000 = 9876500000
command: m
left operand = 12345
right operand = 98765
12345 * 98765 = 1219253925
command: m
left operand = 98765
right operand = 12345
98765 * 12345 = 1219253925

command: f 
to compute n!, n = 10							//factorials
3628800
command: f 
to compute n!, n = 20
2432902008176640000
command: f
to compute n!, n = 50
30414093201713378043612608166064768844377641568960512000000000000

command: m										//9's edgecases
left operand = 99999999										
right operand = 99999999
99999999 * 99999999 = 9999999800000001
command: a    
left operand = 99999999
right operand = 99999999
99999999 + 99999999 = 199999998
command: a
left operand = 99999999
right operand = 0
99999999 + 0 = 99999999
command: m
left operand = 99999999
right operand = 9999
99999999 * 9999 = 999899990001
command: m
left operand = 9999
right operand = 99999999
9999 * 99999999 = 999899990001
command: q
