;; Write your query here. Use @captures to highlight matches in the source buffer.
;; Completion for grammar nodes is available (see :h compl-omni)

(module
  (module_header
    (ident) @namespace)
  (module_footer
    (ident) @namespace))

(const_decl
  (ident_def
    (ident) @constant))

(type_decl
    (ident_def
        (ident) @type.definition))

(field_list
	(ident_list
    	(ident_def
        	(ident) @property)))

(designator
  (qualident
    (ident) @namespace)
  (selector
      (ident) @property))

(type)  @type

(array_type
  (kArray) @keyword
  (kOf) @keyword)

(variable_decl
  (ident_list
    (ident_def
      (ident) @variable)))

(assignment 
  (designator
    (qualident) @variable))

(formal_params
  returntype: (qualident) @type)

(fp_section
  param: (ident) @variable
  paramtype: (formal_type) @type)

(type
  (base_type
    (qualident
      (ident) @type.builtin
      (#any-of? @type.builtin
	"CHAR"
	"BYTE"
	"BOOLEAN"
	"INTEGER"
	"SHORTING"
	"LONGINT"
	"LONGREAL"
	"REAL"))))
[
 (kImport)
 (kModule)
] @include

(procedure_call
  (designator
    (qualident
      (ident) @function.call)))

(procedure_call
  (designator
    (qualident
      (ident) @namespace)
    (selector) @function.call))

(procedure_call
  (designator
  	(qualident) @function.builtin
    (#any-of? @function.builtin
     ; function procedures
     "ABS"
     "ASH"
     "CAP"
     "CHR"
     "ENTIER"
     "LEN"
     "LONG"
     "MAX"
     "MIN"
     "ODD"
     "ORD"
     "SHORT"
     "SIZE"
     ; proper procedures
     "COPY"
     "DEC"
     "EXCL"
     "HALT"
     "INC"
     "ASSERT"
     "INCL"
     "NEW")))

; -- Keywords
[
  (kDo)
  (kIn)
  (kIs)
  (kOf)

  (kEnd)
  (kVar)

  (kThen)
  (kType)

  (kArray)
  (kBegin)
  (kConst)

  (kModule)
  (kRecord)

  (kPointer)

] @keyword

(kReturn) @keyword.return

(if_statement
  [
    (kIf)
    (kCase)
    (kThen)
    (kElse)
    (kElseif)
  ] @conditional)

(kImport) @include

(for_statement
  [
    (kFor)
    (kTo)
    (kBy)
    (kDo)
    (kEnd)
  ] @repeat)

(repeat_statement
  [
    (kRepeat)
    (kUntil)
  ] @repeat)

(while_statement
  [
    (kWhile)
    (kDo)
    (kEnd)
  ] @repeat)
; -- Punctuation & operators

[
  "("
  ")"
  "["
  "]"
  "{"
  "}"
] @punctuation.bracket

[
  ";"
  ","
  ":"
  ".."
  "."
] @punctuation.delimiter

[
  (kDiv)
  (kOr)
  (kMod)
] @keyword.operator

[
  "&"
  "."
  (kPlus)
  (kStar)
  (kMinus)
  (kSlash)
] @operator


; -- Builtin constants

[
  (kNil)
] @constant.builtin

[
  (kTrue)
  (kFalse)
] @boolean

; -- Literals

(number)   @number
(string)   @string

; -- Comments
(comment)         @comment

; Procedure declaration
(procedure_decl
  (procedure_heading
    (ident_def
      (ident) @function))
  (ident) @function)

(ERROR) @error

(kReturn) @return
(kProcedure) @keyword.function

(field_list
	(ident_list
    	(ident_def
        	(ident) @property)))
