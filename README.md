# file-indenter
Indents a completely unindented .cpp or .c file.
Takes input from a file. Writes output to a newfile.
The method is simple : identify newlines and count number of opening brackets, and make increase indentation each time. Decrease indentation whenever a bracket is closed.
There may be an extra character at the end.
