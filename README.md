# BLIP_Programming_Language
Created a interpreter for the BLIP Programming Languague in C++ using expression trees and other data strucutres and algorithms.


The Blip Language, var, set, output and text commands: We ask that you implement
four language statements. Two of these (var and set) are for creating and assignment
values to variables, and two of these (output and text) are for producing output (i.e.,
printing to the screen). A Blip program consists of zero or more statements.
Each statement begins with a keyword (var, set, output or text).

• text statements result in a text message being displayed on the screen. The text
message can be either a single word, or a quoted string. The following are
examples of legal text statements
text Hello
text “Hello World”

• output statements result in a number being displayed on the screen. The number
displayed is the result of evaluating any legal Blip expression. For now, Blip only
supports integer variables, and so only integer values can be displayed. The
following are examples of output statements. For more information on Blip
expressions, see below
11/6/22 1:10 PM 2
output 42
output + 1 1
output * x x
output + * x x * y y

• var statements initialize a new variable. If a var statement specifies a variable that
already exists, then Blip must generate a warning (not an error), with the text,
“variable <varName> incorrectly re-initialized”, where <VarName> is the
variable’s name. Regardless of whether the warning message is created, the result
of a var statement is to ensure that there is a variable in the Blip internal memory
with the specified value. The variable must be set to the value of a legal Blip
expression. The syntax is: “var <varName> <expr>”. The following are examples
of legal var expressions
var x 42
var y + x 1

• set statements are just like var statements, except a set statement should be used to
re-assign a new value to an existing variable. As such, if a set statement specifies
a variable that does not already exist, then Blip must generate a warning (not an
error) with the text, “variable <varName> not declared”. Regardless of whether
the warning message is created, the result of a set statement is to ensure that there
is a variable in the Blip internal memory with the specified value. The following
are examples of legal set expressions
set x 42
set x + x 1
