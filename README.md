# Decimal ![No, really. I typed the entire thing using Microsoft Notepad, no joke.](http://i.imgur.com/FMMMOtk.gif)

Decimal, also called 09D, is an esoteric stack-based programming language that uses the characters `0` through `9` and `D`. Whitespace is ignored. Any other characters in the source code are simply printed.

[Try it online!](//tio.run/#Decimal) [Esolang wiki, probably outdated](//esolangs.org/wiki/Decimal)

## Syntax

    COMMAND<ARGS>[D]   ;COMMENT

`D` must be appended to values (arguments that have user-defined length). For example, pushing the string `103105108101` (`"file"`) requires `D` because the string can have any length.

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
|4|MATH|Next value represents mathematical operation/conditional. Push `[DSI-1] (math) [DSI]`, pop `[DSI]` and `[DSI-1]`|value...|Yes|
|5|COND|If DSI value is truthy, execute all code until the next COND. Otherwise, skip all code until next COND.|N/A|No|
|6|MEM|See section Memory.|number|No|
|8|BUILTIN|Builtin functions. See section Builtins.|value...|Yes|
|9|JUMP|Next value represents a jump #. If that jump # is undeclared, declare it. Otherwise, jump to it. If currently in an IF-statement, exit the IF-statement before performing the jump. `JUMP`ing to 0 will exit the program.|value...|Yes|

## Math

As previously stated, all mathematical operations are performed as `[DSI-1] operation [DSI]`.

For example: if `[DSI-1]` was `{INT,30}` and `[DSI]` was `{INT,40}`, performing the mathematical operation "minus" would compute `30 - 40`, pop `[DSI-1]` and `[DSI]`, then push the result.

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

## Memory

Memory commands:

|Number|Name|Description|Sets DSI?|
|-|-|-|-|
|1|Stash|Pop DSI, store into memory|Yes|
|2|Copy|Copy memory to stack|Yes|

## Builtins

Useful builtins that are ridiculously hard (or even downright impossible) to do with the existing commands.

As builtins kind of ruin the esotericity of a language and lower the complexity to write code in it, I'm only going to write builtins that are unjustifiably difficult to do without them.

|Number|Name|Description|Sets DSI?|Why it's a builtin|
|-|-|-|-|-|
|1|Read|Read INT from input to stack (reads until newline)|Yes|It takes ~50 characters to do this using only standard commands and gets real messy|
|2|Rand|Push random INT to stack|Yes|Impossible to do using only standard commands|

## Examples

 - `11003D` - push integer 3 to stack, set DSI to pushed value
 - `91D 91D` - infinite loop that does nothing
 - `11050D 11050D 41D` - push integer 50 to stack, push integer 50 to stack, pop both then add together and push result
 - `311` - read user input and print, without doing anything to the stack
 - `310` - read user input into stack
 - `91D 311 91D` - cat program that doesn't stop at EOF
 - `91D 310 300 12255D 412D 5 90D 5 2 301 2 91D` - cat program that stops at EOF
 - `13072069076076079044032087079082076068033010D 301` push "HELLO, WORLD!\n" to stack and print

For (possibly) more information, check out the [Decimal language showcase](https://codegolf.stackexchange.com/a/124235/61563) at PPCG StackExchange.
