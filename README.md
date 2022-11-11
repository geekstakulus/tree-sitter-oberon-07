# tree-sitter-oberon-2

Grammar for Oberon-2

## Supported language features

Presently,
the whole Oberon-2 grammar has been implemented.
Type-bound procedures isn't yet implemented.

## Known Issues

Tree Sitter generates the parser without any errors,
but the scanner is not working as it should.
It is not returning the correct tokens.

I've put together this grammar yesterday evening,
and haven't yet explored tree-sitter properly.
I'll dig into it and see if I can solve the tokens issue.
