# parser for tiny langauge
### Requirements 
- c++ 
- Qt creator 

### The Parsing Process 

- it is the task of the parser to determine the syntactic
structure of a program from the tokens produced by
the scanner and to construct a parse tree or syntax
tree that represents this structure.
- The parsing step of the compiler reduces to a call to
the parser as follows:
syntaxTree = parser();

- The syntax tree is defined as a dynamic data structure,
in which each node consists of a record whose fields
include the attributes needed for the remainder of the
compilation process.

### Syntax of the TINY Language

- A context free Grammar for TINY:

program -> stmt sequence

stmt-sequence -> stmt sequence ; statement | statement

statement -> if-stmt | repeat-stmt | assign-stmt | read-stmt | write-stmt

if-stmt -> if exp then stmt-sequence end |if exp then stmt sequence else stmt-sequence end

repeat-stmt -> repeat stmt-sequence until exp

assign-stmt -> identifier := exp

read-stmt ->read identifier

write-stmt -> write exp

exp-> simple-exp comparison-op simple-exp | simple-exp

comparison-op ->  < | = 
 
simple-exp -> simple-exp addop term | term

addop -> + | -

term -> term mulop factor | factor

mulop -> * | /

factor -> (exp) | number | identifier

### Syntax Tree Structure for the TINY compiler

- In TINY there are two basic kinds of structures:
  statements and expressions.
  
- There are five kind of statements (if
  statements, repeat statements, assign
  statements, read statements, and write
  statements) and three kinds of expressions (
  operator expression, constant expressions,
  and identifier expressions).
  
- We want now to give a visual description of the
  syntax tree structure and show visually the syntax
  tree for a sample program.
  
- We use rectangular boxes to indicate statement
  nodes and round or oval boxes to indicate
  expression nodes.
  
- The kind of statement or expression will be given
  as a label inside the box.

- Sibling pointers will be drawn to the right of node
  boxes, while child pointers will be drawn below
  the boxes.

- Indicate additional, unspecified tree structures in
  diagrams by triangles, with dashed lines to
  indicate structures that may or may not appear.

![](https://github.com/Abd-Eljalil-Nasser/parser-for-tiny-langauge/blob/master/if%20stmt.png)

![](https://github.com/Abd-Eljalil-Nasser/parser-for-tiny-langauge/blob/master/repeat%20.png)

![](https://github.com/Abd-Eljalil-Nasser/parser-for-tiny-langauge/blob/master/Assign%20stmt.png)

![](https://github.com/Abd-Eljalil-Nasser/parser-for-tiny-langauge/blob/master/write%20stmt.png)

![](https://github.com/Abd-Eljalil-Nasser/parser-for-tiny-langauge/blob/master/op%20expression.png)

### input 
- TINY language snippet code ( multiple lines of code written in TINY language syntax). The program will do the scanning process first     (get token value and token type then do the parsing process ) 

### output 
- State whether the statements are accepted by TINY language or not
- Draw Syntax tree

### Test 
#### test 1 
![](https://github.com/Abd-Eljalil-Nasser/parser-for-tiny-langauge/blob/master/parser_test_1.png)
![](https://github.com/Abd-Eljalil-Nasser/parser-for-tiny-langauge/blob/master/parser_test_1.2.png)
#### test 2 
![](https://github.com/Abd-Eljalil-Nasser/parser-for-tiny-langauge/blob/master/paser_test_2.png)
![](https://github.com/Abd-Eljalil-Nasser/parser-for-tiny-langauge/blob/master/paser_test_2.1png.png)
