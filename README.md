# 09D
09D is an esoteric stack-based programming language that uses the characters 0 through 9 and D. All other characters are simply printed.

## Syntax

    COMMAND<ARGS>[D] ; COMMENT

`D` must be appended to values (arguments that have user-defined length). For example, pushing the string `103105108101` requires `D` because the string can have any length.

## Commands

|Command|Name|Description|Arguments|D?|
|-|-|-|-|-|
|0|SET|Set stack index for other functions to use by default|Integer...|Yes|
|1|PUSH|Push variable to stack - next char in source = type (1=INT,2=CHAR,3=STRING), next value = variable value|type, value...|Yes|
|2|POP|Pop default stack index|N/A|No|
|3|I/O|Next char in source represents what to read from, char after that represents where to put it (0 = stack, 1 = I/O)|from, to|No|
|4|MATH|Next value represents mathematical operation (see Math section). This is performed as (DEFAULT STACK INDEX) (math operation) (DEFAULT STACK INDEX - 1)|operation|Yes|
|9|JUMP|Next char in source represents a jump #. If that jump # is undeclared, declare it. Otherwise, jump to it.|jump #|Yes|

## Math

|Number|Comparison|Name|
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
|12|`==`|is equal to|
|13|`!=`|is not equal to|
|14|`>=`|is larger than or equal to|
|15|`<=`|is less than or equal to|
|16|`>`|is larger than|
|17|`<`|is less than|
