#Brainfuck

Brainfuck is a brainfuck interpreter written in C.

##Argument options

Argument|Description
-|-
`-i "brainfuck instructions"`|Instructions to be interpreted.
`-v`|Verbose mode. Display the memory, the head and the executed instruction.
`-s "speed in ms"` |Speed of the verbose mode in ms (50ms by default).
`-p`|Prompt mode of the verbose mode. You have to press Enter to pass from step to step. Force verbose mode.
`-m "memory in bytes"`|Memory size in bytes (20 bytes by default).
`-d`|Prints the decimal value of each character in the resulting string separated with a space.

##Usage

`./brainfuck` : prints help.
`./brainfuck -i "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+."` : prints `Hello World!`.

##Licence

Distributed under CC-BY Licence by Valentin Lageard (valentin.lageard.pro@gmail.com).
