const
  letter = /[a-zA-Z]/,
  digit = /[0-9]/,
  hex_digit = /[0-9A-F]/,

  // string = """ {character} """ | digit {hex_digit} "X"
  string_literal = choice(
    /"[^"\n]*"/,
    seq(digit, repeat(hex_digit), 'X')
  ),

  // ident = letter {letter | digit}
  identifier = seq(letter, repeat(choice(letter, digit))),

  // int_literal = digit {digit} | digit {hex_digit} "H"
  int_literal = choice(
    seq(digit, repeat(digit)),
    seq(digit, repeat(hex_digit), 'H')
  ),

  // scale_factor = "E" ["+" | "-"] digit {digit}
  scale_factor = seq('E', choice('+', '-'), digit, repeat(digit)),

  // real = digit {digit} "." {digit} [scale_factor]
  real_number = seq(
    digit, repeat(digit), '.', 
    repeat(digit), optional(scale_factor)
  );

module.exports = grammar({
  name: 'oberon07',

  extras: $ => [$.comment, /\s/],

  word: $ => $.ident,

  rules: {

    // module = "MODULE" ident ";"
    // [import_list]
    // declaration_seq
    // ["BEGIN" statement_seq]
    // "END" ident "."
    module: $ => seq(
      $.module_header,
      // declaration_seq
      optional($.import_list),
      optional($.const_decls),
      optional($.type_decls),
      optional($.variable_decls),
      repeat($.procedure_decl),
      // end declaration_seq
      optional($.module_body),
      $.module_footer
    ),

    module_header: $ => seq($.kModule, field("modulename", $.ident), ';'),

    module_footer: $ => seq($.kEnd, field("modulename", $.ident), '.'),

    module_body: $ => seq(
      $.kBegin,
      seq( /* statement_seq hack */
        optional($.statement),
        repeat(seq(
         ';',
         optional($.statement))))
    ),

    // import_list = "IMPORT" import {"," import} ";"
    import_list: $ => seq(
      $.kImport,
      $.import,
      repeat(seq(
        ",",
        $.import
      )),
      ';'
    ),

    // import = ident [":=" ident]
    import: $ => seq(
      field("modulealias", $.ident),
      optional(seq(
        ':=',
        field("impmodule", $.ident)
      ))
    ),

    // the following declarations are a bit of a hack
    // because tree-sitter doesn't permit empty productions
    // besides the first rule
    // This corresponds to the declaration_sequence in the grammar

    // const_decls = "CONST" {const_decl}
    const_decls: $ => seq(
      $.kConst, 
      repeat($.const_decl)
    ),

    // type_decls = "TYPE" {type_decl}
    type_decls: $=> seq(
      $.kType, 
      repeat($.type_decl)
    ),

    // variable_decls = "VAR" {variable_decl}
    variable_decls: $ => seq(
      $.kVar, 
      repeat($.variable_decl)
    ),

    // const_decl = ident_def "=" const_expresion
    const_decl: $ => seq(
      $.ident_def, "=", $.const_expression, ";"
    ),

    // const_expression = expression
    const_expression: $ =>  $.expression,

    // type_decl = ident_def "=" type
    type_decl: $ => seq(
      $.ident_def, '=', $.type, ";"
    ),

    // type = base_type | struct_type
    type: $ => choice(
      $.base_type,
      $.struct_type
    ),
    
    base_type: $ => $.qualident,

    // struct_type = array_type | record_type | pointer_type | procedure_type
    struct_type: $ => choice(
      $.array_type,
      $.record_type,
      $.pointer_type,
      $.procedure_type
    ),

    // array_type = "ARRAY" length {"," length} "OF" type
    array_type: $ => seq(
      $.kArray, $.length, repeat(seq(',', $.length)), $.kOf, $.type
    ),

    // length = const_expression
    length: $ => $.const_expression,

    // record_type = "RECORD" ["(" base_type ")"] [field_list_seq] "END"
    record_type: $ => seq(
      $.kRecord,
      optional(seq(
        '(',
        field("parentrec", $.base_type),
        ')'
      )),
      optional($.field_list_seq),
      optional(";"),
      $.kEnd
    ),

    // base_type = qualident
    base_type: $ => $.qualident,

    // field_list_seq = field_list {";" field_list}
    field_list_seq: $ => prec.left(seq(
      $.field_list, repeat(seq(';', $.field_list))
    )),

    // field_list = ident_list ":" type
    field_list: $ => seq(
      $.ident_list, ':', $.type
    ),

    // ident_list = ident_def {"," ident_def}
    ident_list: $ => seq(
      $.ident_def, repeat(seq(',', $.ident_def))
    ),

    // pointer_type = "POINTER" "TO" type
    pointer_type: $ => seq(
      $.kPointer, $.kTo, $.type
    ),

    // procedure_type = "PROCEDURE" [formal_params]
    procedure_type: $ => seq(
      $.kProcedure, optional($.formal_params)
    ),

    // formal_params = "(" [fp_section {";" fp_section}] ")" [":" qualident]
    formal_params: $ => seq(
      "(",
      optional(seq(
        $.fp_section, repeat(seq(';', $.fp_section))
      )),
      ")",
      optional(seq(
        ':', field("returntype", $.qualident)
      ))
    ),

    // fp_section = ["VAR"] ident {"," ident} ":" formal_type
    fp_section: $ => seq(
      optional($.kVar),
      field("param", $.ident), repeat(seq(',', field("param", $.ident))),
      ':',
      field("paramtype", $.formal_type)
    ),

    // formal_type = {"ARRAY" "OF"} qualident
    formal_type: $ => seq(
      repeat(seq($.kArray, $.kOf)),
      $.qualident
    ),

    // qualident = [ident "."] ident
    qualident: $ => prec.left(choice(
      seq($.ident),
      seq(field("qualifier", $.ident), '.', field("property", $.ident)),
    )),

    // ident_def = ident ["*" | "-"]
    ident_def: $ => seq(
      $.ident, optional(choice($.kStar, $.kMinus))
    ),

    // variable_decl = ident_list ":" type
    variable_decl: $ => seq(
      $.ident_list, ':', $.type, ";"
    ),

    // procedure_decl = procedure_heading ";" procedure_body ident
    procedure_decl: $ => seq(
      $.procedure_heading, ';', $.procedure_body, field("procname", $.ident), ";"
    ),

    // procedure_heading = "PROCEDURE" ident_def [formal_params]
    procedure_heading: $ => seq(
      $.kProcedure, $.ident_def, optional($.formal_params)
    ),

    // procedure_body = declaration_seq ["BEGIN" statement_seq]
    //                  ["RETURN" expression] "END"
    procedure_body: $ => seq(
      //$.declaration_seq, 
      optional($.const_decls),
      optional($.type_decls),
      optional($.variable_decls),
      repeat($.procedure_decl),
      optional(seq($.kBegin, seq( /* statement_seq hack */
        optional($.statement),
        repeat(seq(
          ';',
          optional($.statement)))))),
      optional(seq($.kReturn, $.expression)),
      $.kEnd
    ),

    // expression = simple_expression [relation simple_expression]
    expression: $ => seq(
      $.simple_expression,
      optional(seq($.relation, $.simple_expression))
    ),

    // relation = "=" | "#" | "<" | "<=" | ">" | ">=" | "IN" | "IS"
    relation: $ => choice(
      '=',
      '#',
      '<',
      '<=',
      '>',
      '>=',
      $.kIn,
      $.kIs
    ),

    // simple_expression = ["+" | "-"] term {add_operator term}
    simple_expression: $ => seq(
      optional(choice(
        $.kPlus,
        $.kMinus
      )),
      $.term,
      repeat(seq(
        $.add_operator, $.term
      ))
    ),

    // add_operator = "+" | "-" | "OR"
    add_operator: $ => choice(
      $.kPlus,
      $.kMinus,
      $.kOr
    ),

    // term = factor {mul_operator factor}
    term: $ => seq(
      $.factor, repeat(seq($.mul_operator, $.factor))
    ),

    // mul_operator = "*" | "/" | "DIV" | "MOD" | "&"
    mul_operator: $ => choice(
      $.kStar,
      $.kSlash,
      $.kDiv,
      $.kMod,
      '&'
    ),

    // factor = number | string | "NIL" | "TRUE" | "FALSE" |
    //          set | designator [actual_params] | "(" expression ")" | "~" factor
    factor: $ => choice(
      $.number,
      $.string,
      $.kNil,
      $.kTrue,
      $.kFalse,
      $.set,
      seq($.designator, optional($.actual_params)),
      seq('(', $.expression, ')'),
      seq('~', $.factor)
    ),

    // designator = qualident {selector}
    designator: $ => prec.left(seq(
      $.qualident,
      repeat($.selector)
    )),

    // selector = "." ident | "[" expression_list "]" | "^" | "(" qualident ")"
    selector: $ => choice(
      seq('.', $.ident),
      seq('[', $.expression_list, ']'),
      '^',
      seq('(', $.qualident, ')')
    ),

    // set = "{" [element {"," element}] "}"
    set: $ => seq(
      '{',
      optional(seq(
        $.element, repeat(seq(',', $.element))
      )),
      '}'
    ),

    // element = expression [".." expression]
    element: $ => seq(
      $.expression,
      optional(seq(
        '..', $.expression
      ))
    ),

    // expression_list = expression {"," expression}
    expression_list: $ => seq(
      $.expression, repeat(seq(',', $.expression))
    ),

    // actual_params = "(" [expression_list] ")"
    actual_params: $ => seq(
      '(', optional($.expression_list), ')'
    ),

    // statement = assignment | procedure_call | if_statement | case_statement |
    //              while_statement | repeat_statement | for_statement
    statement: $ => choice(
      $.assignment,
      $.procedure_call,
      $.if_statement,
      $.case_statement,
      $.while_statement,
      $.repeat_statement,
      $.for_statement
    ),

    // assignment = designator ":=" expression
    assignment: $ => seq(
      $.designator, ':=', $.expression
    ),

    // procedure_call = designator [actual_params]
    procedure_call: $ => seq(
      $.designator, optional($.actual_params)
    ),

    // statement_seq = statement {";" statement}
    /*statement_seq: $ => seq(
      $.statement,
      repeat(seq(';', $.statement))
    ),*/

    // if_statement = "IF" expression "THEN" statement_seq
    //                {"ELSIF" expression "THEN" statement_seq}
    //                ["ELSE" statement_seq] "END"
    if_statement: $ => seq(
      $.kIf, $.expression, $.kThen, seq( /* statement_seq hack */
        optional($.statement),
        repeat(seq(
          ';',
          optional($.statement)))),
      repeat(seq($.kElseif, $.expression, $.kThen, seq( /* statement_seq hack */
        optional($.statement),
        repeat(seq(
          ';',
          optional($.statement)))))),
      optional(seq($.kElse, seq( /* statement_seq hack */
        optional($.statement),
        repeat(seq(
          ';',
          optional($.statement)))))),
      $.kEnd
    ),

    // case_statement = "CASE" expression "OF" case {"|" case} "END"
    case_statement: $ => seq(
      $.kCase, $.expression, $.kOf, 
      // case {"|" case}
      optional($.case_clause), repeat(seq('|', optional($.case_clause))), 
      $.kEnd
    ),

    // case = [case_label_list ":" statement_sequence]
    case_clause: $ => seq($.case_label_list, ':', seq( /* statement_seq hack */
        optional($.statement),
        repeat(seq(
          ';',
          optional($.statement))))),

    // case_label_list = label_range {"," label_range}
    case_label_list: $ => seq(
      $.label_range,
      repeat(seq(',', $.label_range))
    ),

    // label_range = label [".." label]
    label_range: $ => seq(
      $.label, optional(seq('..', $.label))
    ),

    // label = integer | string | qualident
    label: $ => choice(
      $.integer,
      $.string,
      $.qualident
    ),

    // while_statement = "WHILE" expression "DO" statement_sequence
    //                   {"ELSIF" expression "DO" statement_sequence} "END"
    while_statement: $ => seq(
      $.kWhile, $.expression, $.kDo, seq( /* statement_seq hack */
        optional($.statement),
        repeat(seq(
          ';',
          optional($.statement)))),
      repeat(seq($.kElseif, $.expression, $.kDo, seq( /* statement_seq hack */
        optional($.statement),
        repeat(seq(
          ';',
          optional($.statement)))))),
      $.kEnd
    ),

    // repeat_statement = "REPEAT" statement_seq "UNTIL" expression
    repeat_statement: $ => seq(
      $.kRepeat, seq( /* statement_seq hack */
        optional($.statement),
        repeat(seq(
          ';',
          optional($.statement)))), 
      $.kUntil, $.expression
    ),

    // for_statement = "FOR" ident ":=" expression "TO" expression ["BY" const_expression]
    //                 "DO" statement_seq "END"
    for_statement: $ => seq(
      $.kFor, $.ident, ':=', $.expression, $.kTo, $.expression, optional(seq($.kBy, $.const_expression)),
      $.kDo, seq( /* statement_seq hack */
        optional($.statement),
        repeat(seq(
          ';',
          optional($.statement)))), 
      $.kEnd
    ),

    string: $ => token(string_literal),
    // number = integer | real
    number: $ => choice($.integer, $.real),

    // real number
    real: $ => token(real_number),

    integer: $ => token(int_literal),

    // mathematical operators
    kPlus:  $ => '+',
    kStar:  $ => '*',
    kMinus: $ => '-',
    kSlash: $ => '/',

    // keywords
    kBy: $ => 'BY',
    kDo: $ => 'DO',
    kIf: $ => 'IF',
    kIn: $ => 'IN',
    kIs: $ => 'IS',
    kOf: $ => 'OF',
    kOr: $ => 'OR',
    kTo: $ => 'TO',

    kDiv: $ => 'DIV',
    kEnd: $ => 'END',
    kFor: $ => 'FOR',
    kMod: $ => 'MOD',
    kNil: $ => 'NIL',
    kVar: $ => 'VAR',

    kCase: $ => 'CASE',
    kElse: $ => 'ELSE',
    kThen: $ => 'THEN',
    kTrue: $ => 'TRUE',
    kType: $ => 'TYPE',

    kArray: $ => 'ARRAY',
    kBegin: $ => 'BEGIN',
    kConst: $ => 'CONST',
    kFalse: $ => 'FALSE',
    kUntil: $ => 'UNTIL',
    kWhile: $ => 'WHILE',

    kElseif: $ => 'ELSIF',
    kImport: $ => 'IMPORT',
    kModule: $ => 'MODULE',
    kRecord: $ => 'RECORD',
    kRepeat: $ => 'REPEAT',
    kReturn: $ => 'RETURN',

    kPointer: $ => 'POINTER',

    kProcedure: $ => 'PROCEDURE',

    ident: $ => token(identifier),

    comment: $ => token(seq(/[(][*]([^*]*[*]+[^)*])*[^*]*[*]+[)]/)),
  }
});
