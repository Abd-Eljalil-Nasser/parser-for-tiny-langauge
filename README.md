# parser-for-tiny-langauge
### The Parsing Process :
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
