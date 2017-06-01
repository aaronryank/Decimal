# Decimal
Decimal, also called 09D, is an esoteric stack-based programming language that uses the characters `0` through `9` and `D`. Any other characters in the source code are simply printed.

## Syntax

    COMMAND<ARGS>[D]   ;COMMENT

`D` must be appended to values (arguments that have user-defined length). For example, pushing the string `103105108101` (`"file"`) requires `D` because the string can have any length.

The syntax for pushing values to the stack is different. For example, to push the integer 3, one could not simply write (in pseudocode) `PUSH 3`. In Decimal, each value pushed must be a three-digit integer. So, as in the pseudocode example, to push the integer 3, one would write `PUSH 003`.

Commands working with the stack are based on one index, the Default Stack Index (or `[DSI]` for short.) For example, in pseudocode, calling `PRINT` will print the value at `stack[DSI]`. `PUSH` sets the DSI to the index of the value pushed. `SET` sets the DSI to the next value provided. 

## Types

There are three types in Decimal: `INT`, `CHAR`, and `STRING`. These are defined by an enumerator:

    {INT = 1, CHAR = 2, STRING = 3}

...in the interpreter. These integer values are used in `PUSH` to determine the type of the value to be pushed.

## I/O

All input is read and stored/printed as a `CHAR`. `EOF` is stored as `255`. If no input is waiting, `31x` will pause execution until input is available.

## Commands

|Command|Name|Description|Arguments|D?|
|-|-|-|-|-|
|0|SET|Set DSI to next value|value...|Yes|
|1|PUSH|Push variable to stack - next char in source = type, next value = variable value. Set DSI to the index of the variable pushed.|number, value...|Yes|
|2|POP|Pop DSI|N/A|No|
|3|I/O|Next char in source represents what to read from, char after that represents where to put it (0 = stack, 1 = I/O). If the stack is pushed to, set DSI.|from, to|No|
|4|MATH|Next value represents mathematical operation/conditional. Push `[DSI] (math) [DSI-1]`, pop `[DSI]` and `[DSI-1]`|value...|Yes|
|9|JUMP|Next value represents a jump #. If that jump # is undeclared, declare it. Otherwise, jump to it.|value...|Yes|

## Math

As previously stated, all mathematical operations are performed as `[DSI] operation [DSI-1]`.

For example: if `[DSI]` was `{INT, 030}` and `[DSI-1]` was `{INT, 040}`, performing the mathematical operation "minus" would compute `30 - 40`, pop `[DSI]` and `[DSI-1]`, then push the result.

|Number|Operation|Name|
|-|-|-|
|1|`+`|plus|
|2|`-`|minus|
|3|`*`|times|
|4|`/`|divided by|
|5|`%`|modulo|
|6|`&`|bitwise AND|
|7|`|`|bitwise OR|
|8|`^`|bitwise XOR|
|9|`<<`|bitwise left-shift|
|10|`>>`|bitwise right-shift|
|11|`.`|string index **(in the future)**|

Each conditional will push `001` if truthy and `000` if falsy:

|Number|Conditional|Name|
|-|-|-|
|12|`==`|is equal to|
|13|`!=`|is not equal to|
|14|`>=`|is larger than or equal to|
|15|`<=`|is less than or equal to|
|16|`>`|is larger than|
|17|`<`|is less than|

## Examples

 - `11003D` - push integer 3 to stack, set DSI to pushed value
 - `91D 91D` - infinite loop that does nothing
 - `11050D 11050D 41D` - push integer 50 to stack, push integer 50 to stack, pop both then add together and push result
 - `311` - read user input and print, without doing anything with the stack
 - `310` - read user input into stack
 - `91D 311 91D` - cat program
 - `13072069076076079044032087079082076068033010D 301` push "HELLO, WORLD!\n" to stack and print
