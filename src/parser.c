#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 4
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 66
#define ALIAS_COUNT 0
#define TOKEN_COUNT 65
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 1
#define PRODUCTION_ID_COUNT 1

enum {
  sym_ident = 1,
  aux_sym_string_token1 = 2,
  aux_sym_integer_token1 = 3,
  aux_sym_integer_token2 = 4,
  sym_kBy = 5,
  sym_kDo = 6,
  sym_kIf = 7,
  sym_kIn = 8,
  sym_kIs = 9,
  sym_kOf = 10,
  sym_kOr = 11,
  sym_kTo = 12,
  sym_kDiv = 13,
  anon_sym_END = 14,
  sym_kFor = 15,
  sym_kMod = 16,
  sym_kNil = 17,
  sym_kVar = 18,
  sym_kCase = 19,
  sym_kElse = 20,
  sym_kThen = 21,
  sym_kTrue = 22,
  sym_kType = 23,
  sym_kArray = 24,
  sym_kBegin = 25,
  sym_kConst = 26,
  sym_kFalse = 27,
  sym_kUntil = 28,
  sym_kWhile = 29,
  sym_kElseif = 30,
  sym_kImport = 31,
  sym_kModule = 32,
  sym_kRecord = 33,
  sym_kRepeat = 34,
  sym_kReturn = 35,
  sym_kPointer = 36,
  sym_kProcedure = 37,
  sym_comment = 38,
  anon_sym_SEMI = 39,
  anon_sym_DOT = 40,
  anon_sym_COMMA = 41,
  anon_sym_COLON_EQ = 42,
  anon_sym_EQ = 43,
  anon_sym_LPAREN = 44,
  anon_sym_RPAREN = 45,
  anon_sym_COLON = 46,
  anon_sym_STAR = 47,
  anon_sym_POUND = 48,
  anon_sym_LT = 49,
  anon_sym_LT_EQ = 50,
  anon_sym_GT = 51,
  anon_sym_GT_EQ = 52,
  anon_sym_PLUS = 53,
  anon_sym_DASH = 54,
  anon_sym_SLASH = 55,
  anon_sym_AMP = 56,
  anon_sym_TILDE = 57,
  anon_sym_LBRACK = 58,
  anon_sym_RBRACK = 59,
  anon_sym_CARET = 60,
  anon_sym_LBRACE = 61,
  anon_sym_RBRACE = 62,
  anon_sym_DOT_DOT = 63,
  anon_sym_PIPE = 64,
  sym_string = 65,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_ident] = "ident",
  [aux_sym_string_token1] = "string_token1",
  [aux_sym_integer_token1] = "integer_token1",
  [aux_sym_integer_token2] = "integer_token2",
  [sym_kBy] = "kBy",
  [sym_kDo] = "kDo",
  [sym_kIf] = "kIf",
  [sym_kIn] = "kIn",
  [sym_kIs] = "kIs",
  [sym_kOf] = "kOf",
  [sym_kOr] = "kOr",
  [sym_kTo] = "kTo",
  [sym_kDiv] = "kDiv",
  [anon_sym_END] = "END",
  [sym_kFor] = "kFor",
  [sym_kMod] = "kMod",
  [sym_kNil] = "kNil",
  [sym_kVar] = "kVar",
  [sym_kCase] = "kCase",
  [sym_kElse] = "kElse",
  [sym_kThen] = "kThen",
  [sym_kTrue] = "kTrue",
  [sym_kType] = "kType",
  [sym_kArray] = "kArray",
  [sym_kBegin] = "kBegin",
  [sym_kConst] = "kConst",
  [sym_kFalse] = "kFalse",
  [sym_kUntil] = "kUntil",
  [sym_kWhile] = "kWhile",
  [sym_kElseif] = "kElseif",
  [sym_kImport] = "kImport",
  [sym_kModule] = "kModule",
  [sym_kRecord] = "kRecord",
  [sym_kRepeat] = "kRepeat",
  [sym_kReturn] = "kReturn",
  [sym_kPointer] = "kPointer",
  [sym_kProcedure] = "kProcedure",
  [sym_comment] = "comment",
  [anon_sym_SEMI] = ";",
  [anon_sym_DOT] = ".",
  [anon_sym_COMMA] = ",",
  [anon_sym_COLON_EQ] = ":=",
  [anon_sym_EQ] = "=",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_COLON] = ":",
  [anon_sym_STAR] = "*",
  [anon_sym_POUND] = "#",
  [anon_sym_LT] = "<",
  [anon_sym_LT_EQ] = "<=",
  [anon_sym_GT] = ">",
  [anon_sym_GT_EQ] = ">=",
  [anon_sym_PLUS] = "+",
  [anon_sym_DASH] = "-",
  [anon_sym_SLASH] = "/",
  [anon_sym_AMP] = "&",
  [anon_sym_TILDE] = "~",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_CARET] = "^",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_DOT_DOT] = "..",
  [anon_sym_PIPE] = "|",
  [sym_string] = "string",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_ident] = sym_ident,
  [aux_sym_string_token1] = aux_sym_string_token1,
  [aux_sym_integer_token1] = aux_sym_integer_token1,
  [aux_sym_integer_token2] = aux_sym_integer_token2,
  [sym_kBy] = sym_kBy,
  [sym_kDo] = sym_kDo,
  [sym_kIf] = sym_kIf,
  [sym_kIn] = sym_kIn,
  [sym_kIs] = sym_kIs,
  [sym_kOf] = sym_kOf,
  [sym_kOr] = sym_kOr,
  [sym_kTo] = sym_kTo,
  [sym_kDiv] = sym_kDiv,
  [anon_sym_END] = anon_sym_END,
  [sym_kFor] = sym_kFor,
  [sym_kMod] = sym_kMod,
  [sym_kNil] = sym_kNil,
  [sym_kVar] = sym_kVar,
  [sym_kCase] = sym_kCase,
  [sym_kElse] = sym_kElse,
  [sym_kThen] = sym_kThen,
  [sym_kTrue] = sym_kTrue,
  [sym_kType] = sym_kType,
  [sym_kArray] = sym_kArray,
  [sym_kBegin] = sym_kBegin,
  [sym_kConst] = sym_kConst,
  [sym_kFalse] = sym_kFalse,
  [sym_kUntil] = sym_kUntil,
  [sym_kWhile] = sym_kWhile,
  [sym_kElseif] = sym_kElseif,
  [sym_kImport] = sym_kImport,
  [sym_kModule] = sym_kModule,
  [sym_kRecord] = sym_kRecord,
  [sym_kRepeat] = sym_kRepeat,
  [sym_kReturn] = sym_kReturn,
  [sym_kPointer] = sym_kPointer,
  [sym_kProcedure] = sym_kProcedure,
  [sym_comment] = sym_comment,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_DOT] = anon_sym_DOT,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_COLON_EQ] = anon_sym_COLON_EQ,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_POUND] = anon_sym_POUND,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_LT_EQ] = anon_sym_LT_EQ,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_GT_EQ] = anon_sym_GT_EQ,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_AMP] = anon_sym_AMP,
  [anon_sym_TILDE] = anon_sym_TILDE,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_CARET] = anon_sym_CARET,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_DOT_DOT] = anon_sym_DOT_DOT,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [sym_string] = sym_string,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_ident] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_string_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_integer_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_integer_token2] = {
    .visible = false,
    .named = false,
  },
  [sym_kBy] = {
    .visible = true,
    .named = true,
  },
  [sym_kDo] = {
    .visible = true,
    .named = true,
  },
  [sym_kIf] = {
    .visible = true,
    .named = true,
  },
  [sym_kIn] = {
    .visible = true,
    .named = true,
  },
  [sym_kIs] = {
    .visible = true,
    .named = true,
  },
  [sym_kOf] = {
    .visible = true,
    .named = true,
  },
  [sym_kOr] = {
    .visible = true,
    .named = true,
  },
  [sym_kTo] = {
    .visible = true,
    .named = true,
  },
  [sym_kDiv] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_END] = {
    .visible = true,
    .named = false,
  },
  [sym_kFor] = {
    .visible = true,
    .named = true,
  },
  [sym_kMod] = {
    .visible = true,
    .named = true,
  },
  [sym_kNil] = {
    .visible = true,
    .named = true,
  },
  [sym_kVar] = {
    .visible = true,
    .named = true,
  },
  [sym_kCase] = {
    .visible = true,
    .named = true,
  },
  [sym_kElse] = {
    .visible = true,
    .named = true,
  },
  [sym_kThen] = {
    .visible = true,
    .named = true,
  },
  [sym_kTrue] = {
    .visible = true,
    .named = true,
  },
  [sym_kType] = {
    .visible = true,
    .named = true,
  },
  [sym_kArray] = {
    .visible = true,
    .named = true,
  },
  [sym_kBegin] = {
    .visible = true,
    .named = true,
  },
  [sym_kConst] = {
    .visible = true,
    .named = true,
  },
  [sym_kFalse] = {
    .visible = true,
    .named = true,
  },
  [sym_kUntil] = {
    .visible = true,
    .named = true,
  },
  [sym_kWhile] = {
    .visible = true,
    .named = true,
  },
  [sym_kElseif] = {
    .visible = true,
    .named = true,
  },
  [sym_kImport] = {
    .visible = true,
    .named = true,
  },
  [sym_kModule] = {
    .visible = true,
    .named = true,
  },
  [sym_kRecord] = {
    .visible = true,
    .named = true,
  },
  [sym_kRepeat] = {
    .visible = true,
    .named = true,
  },
  [sym_kReturn] = {
    .visible = true,
    .named = true,
  },
  [sym_kPointer] = {
    .visible = true,
    .named = true,
  },
  [sym_kProcedure] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_POUND] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_TILDE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CARET] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(8);
      if (lookahead == '#') ADVANCE(26);
      if (lookahead == '&') ADVANCE(34);
      if (lookahead == '(') ADVANCE(22);
      if (lookahead == ')') ADVANCE(23);
      if (lookahead == '*') ADVANCE(25);
      if (lookahead == '+') ADVANCE(31);
      if (lookahead == ',') ADVANCE(19);
      if (lookahead == '-') ADVANCE(32);
      if (lookahead == '.') ADVANCE(18);
      if (lookahead == '/') ADVANCE(33);
      if (lookahead == ':') ADVANCE(24);
      if (lookahead == ';') ADVANCE(17);
      if (lookahead == '<') ADVANCE(27);
      if (lookahead == '=') ADVANCE(21);
      if (lookahead == '>') ADVANCE(29);
      if (lookahead == '[') ADVANCE(36);
      if (lookahead == ']') ADVANCE(37);
      if (lookahead == '^') ADVANCE(38);
      if (lookahead == '{') ADVANCE(39);
      if (lookahead == '|') ADVANCE(42);
      if (lookahead == '}') ADVANCE(40);
      if (lookahead == '~') ADVANCE(35);
      if (('A' <= lookahead && lookahead <= 'F')) ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(10);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(15);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(9);
      END_STATE();
    case 2:
      if (lookahead == ')') ADVANCE(16);
      if (lookahead == '*') ADVANCE(2);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 3:
      if (lookahead == '*') ADVANCE(4);
      END_STATE();
    case 4:
      if (lookahead == '*') ADVANCE(2);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 5:
      if (lookahead == 'X') ADVANCE(9);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(5);
      END_STATE();
    case 6:
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"') ADVANCE(1);
      END_STATE();
    case 7:
      if (eof) ADVANCE(8);
      if (lookahead == '"') ADVANCE(6);
      if (lookahead == '(') ADVANCE(3);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(5);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(aux_sym_string_token1);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(aux_sym_integer_token1);
      if (lookahead == 'H') ADVANCE(12);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(11);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(aux_sym_integer_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(11);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(aux_sym_integer_token2);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(aux_sym_integer_token2);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(15);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'H') ADVANCE(13);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(15);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(sym_ident);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(15);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_DOT);
      if (lookahead == '.') ADVANCE(41);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_COLON_EQ);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      if (lookahead == '*') ADVANCE(4);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == '=') ADVANCE(20);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '=') ADVANCE(28);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(30);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_AMP);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_TILDE);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_CARET);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_DOT_DOT);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    default:
      return false;
  }
}

static bool ts_lex_keywords(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (lookahead == 'A') ADVANCE(1);
      if (lookahead == 'B') ADVANCE(2);
      if (lookahead == 'C') ADVANCE(3);
      if (lookahead == 'D') ADVANCE(4);
      if (lookahead == 'E') ADVANCE(5);
      if (lookahead == 'F') ADVANCE(6);
      if (lookahead == 'I') ADVANCE(7);
      if (lookahead == 'M') ADVANCE(8);
      if (lookahead == 'N') ADVANCE(9);
      if (lookahead == 'O') ADVANCE(10);
      if (lookahead == 'P') ADVANCE(11);
      if (lookahead == 'R') ADVANCE(12);
      if (lookahead == 'T') ADVANCE(13);
      if (lookahead == 'U') ADVANCE(14);
      if (lookahead == 'V') ADVANCE(15);
      if (lookahead == 'W') ADVANCE(16);
      END_STATE();
    case 1:
      if (lookahead == 'R') ADVANCE(17);
      END_STATE();
    case 2:
      if (lookahead == 'E') ADVANCE(18);
      if (lookahead == 'Y') ADVANCE(19);
      END_STATE();
    case 3:
      if (lookahead == 'A') ADVANCE(20);
      if (lookahead == 'O') ADVANCE(21);
      END_STATE();
    case 4:
      if (lookahead == 'I') ADVANCE(22);
      if (lookahead == 'O') ADVANCE(23);
      END_STATE();
    case 5:
      if (lookahead == 'L') ADVANCE(24);
      if (lookahead == 'N') ADVANCE(25);
      END_STATE();
    case 6:
      if (lookahead == 'A') ADVANCE(26);
      if (lookahead == 'O') ADVANCE(27);
      END_STATE();
    case 7:
      if (lookahead == 'F') ADVANCE(28);
      if (lookahead == 'M') ADVANCE(29);
      if (lookahead == 'N') ADVANCE(30);
      if (lookahead == 'S') ADVANCE(31);
      END_STATE();
    case 8:
      if (lookahead == 'O') ADVANCE(32);
      END_STATE();
    case 9:
      if (lookahead == 'I') ADVANCE(33);
      END_STATE();
    case 10:
      if (lookahead == 'F') ADVANCE(34);
      if (lookahead == 'R') ADVANCE(35);
      END_STATE();
    case 11:
      if (lookahead == 'O') ADVANCE(36);
      if (lookahead == 'R') ADVANCE(37);
      END_STATE();
    case 12:
      if (lookahead == 'E') ADVANCE(38);
      END_STATE();
    case 13:
      if (lookahead == 'H') ADVANCE(39);
      if (lookahead == 'O') ADVANCE(40);
      if (lookahead == 'R') ADVANCE(41);
      if (lookahead == 'Y') ADVANCE(42);
      END_STATE();
    case 14:
      if (lookahead == 'N') ADVANCE(43);
      END_STATE();
    case 15:
      if (lookahead == 'A') ADVANCE(44);
      END_STATE();
    case 16:
      if (lookahead == 'H') ADVANCE(45);
      END_STATE();
    case 17:
      if (lookahead == 'R') ADVANCE(46);
      END_STATE();
    case 18:
      if (lookahead == 'G') ADVANCE(47);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(sym_kBy);
      END_STATE();
    case 20:
      if (lookahead == 'S') ADVANCE(48);
      END_STATE();
    case 21:
      if (lookahead == 'N') ADVANCE(49);
      END_STATE();
    case 22:
      if (lookahead == 'V') ADVANCE(50);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym_kDo);
      END_STATE();
    case 24:
      if (lookahead == 'S') ADVANCE(51);
      END_STATE();
    case 25:
      if (lookahead == 'D') ADVANCE(52);
      END_STATE();
    case 26:
      if (lookahead == 'L') ADVANCE(53);
      END_STATE();
    case 27:
      if (lookahead == 'R') ADVANCE(54);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym_kIf);
      END_STATE();
    case 29:
      if (lookahead == 'P') ADVANCE(55);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_kIn);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_kIs);
      END_STATE();
    case 32:
      if (lookahead == 'D') ADVANCE(56);
      END_STATE();
    case 33:
      if (lookahead == 'L') ADVANCE(57);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_kOf);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_kOr);
      END_STATE();
    case 36:
      if (lookahead == 'I') ADVANCE(58);
      END_STATE();
    case 37:
      if (lookahead == 'O') ADVANCE(59);
      END_STATE();
    case 38:
      if (lookahead == 'C') ADVANCE(60);
      if (lookahead == 'P') ADVANCE(61);
      if (lookahead == 'T') ADVANCE(62);
      END_STATE();
    case 39:
      if (lookahead == 'E') ADVANCE(63);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_kTo);
      END_STATE();
    case 41:
      if (lookahead == 'U') ADVANCE(64);
      END_STATE();
    case 42:
      if (lookahead == 'P') ADVANCE(65);
      END_STATE();
    case 43:
      if (lookahead == 'T') ADVANCE(66);
      END_STATE();
    case 44:
      if (lookahead == 'R') ADVANCE(67);
      END_STATE();
    case 45:
      if (lookahead == 'I') ADVANCE(68);
      END_STATE();
    case 46:
      if (lookahead == 'A') ADVANCE(69);
      END_STATE();
    case 47:
      if (lookahead == 'I') ADVANCE(70);
      END_STATE();
    case 48:
      if (lookahead == 'E') ADVANCE(71);
      END_STATE();
    case 49:
      if (lookahead == 'S') ADVANCE(72);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_kDiv);
      END_STATE();
    case 51:
      if (lookahead == 'E') ADVANCE(73);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_END);
      END_STATE();
    case 53:
      if (lookahead == 'S') ADVANCE(74);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_kFor);
      END_STATE();
    case 55:
      if (lookahead == 'O') ADVANCE(75);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_kMod);
      if (lookahead == 'U') ADVANCE(76);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_kNil);
      END_STATE();
    case 58:
      if (lookahead == 'N') ADVANCE(77);
      END_STATE();
    case 59:
      if (lookahead == 'C') ADVANCE(78);
      END_STATE();
    case 60:
      if (lookahead == 'O') ADVANCE(79);
      END_STATE();
    case 61:
      if (lookahead == 'E') ADVANCE(80);
      END_STATE();
    case 62:
      if (lookahead == 'U') ADVANCE(81);
      END_STATE();
    case 63:
      if (lookahead == 'N') ADVANCE(82);
      END_STATE();
    case 64:
      if (lookahead == 'E') ADVANCE(83);
      END_STATE();
    case 65:
      if (lookahead == 'E') ADVANCE(84);
      END_STATE();
    case 66:
      if (lookahead == 'I') ADVANCE(85);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_kVar);
      END_STATE();
    case 68:
      if (lookahead == 'L') ADVANCE(86);
      END_STATE();
    case 69:
      if (lookahead == 'Y') ADVANCE(87);
      END_STATE();
    case 70:
      if (lookahead == 'N') ADVANCE(88);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_kCase);
      END_STATE();
    case 72:
      if (lookahead == 'T') ADVANCE(89);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_kElse);
      if (lookahead == 'I') ADVANCE(90);
      END_STATE();
    case 74:
      if (lookahead == 'E') ADVANCE(91);
      END_STATE();
    case 75:
      if (lookahead == 'R') ADVANCE(92);
      END_STATE();
    case 76:
      if (lookahead == 'L') ADVANCE(93);
      END_STATE();
    case 77:
      if (lookahead == 'T') ADVANCE(94);
      END_STATE();
    case 78:
      if (lookahead == 'E') ADVANCE(95);
      END_STATE();
    case 79:
      if (lookahead == 'R') ADVANCE(96);
      END_STATE();
    case 80:
      if (lookahead == 'A') ADVANCE(97);
      END_STATE();
    case 81:
      if (lookahead == 'R') ADVANCE(98);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym_kThen);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym_kTrue);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym_kType);
      END_STATE();
    case 85:
      if (lookahead == 'L') ADVANCE(99);
      END_STATE();
    case 86:
      if (lookahead == 'E') ADVANCE(100);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(sym_kArray);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(sym_kBegin);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(sym_kConst);
      END_STATE();
    case 90:
      if (lookahead == 'F') ADVANCE(101);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(sym_kFalse);
      END_STATE();
    case 92:
      if (lookahead == 'T') ADVANCE(102);
      END_STATE();
    case 93:
      if (lookahead == 'E') ADVANCE(103);
      END_STATE();
    case 94:
      if (lookahead == 'E') ADVANCE(104);
      END_STATE();
    case 95:
      if (lookahead == 'D') ADVANCE(105);
      END_STATE();
    case 96:
      if (lookahead == 'D') ADVANCE(106);
      END_STATE();
    case 97:
      if (lookahead == 'T') ADVANCE(107);
      END_STATE();
    case 98:
      if (lookahead == 'N') ADVANCE(108);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym_kUntil);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym_kWhile);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym_kElseif);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym_kImport);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym_kModule);
      END_STATE();
    case 104:
      if (lookahead == 'R') ADVANCE(109);
      END_STATE();
    case 105:
      if (lookahead == 'U') ADVANCE(110);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym_kRecord);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(sym_kRepeat);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(sym_kReturn);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(sym_kPointer);
      END_STATE();
    case 110:
      if (lookahead == 'R') ADVANCE(111);
      END_STATE();
    case 111:
      if (lookahead == 'E') ADVANCE(112);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym_kProcedure);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 7},
  [2] = {.lex_state = 7},
  [3] = {.lex_state = 7},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_ident] = ACTIONS(1),
    [aux_sym_integer_token1] = ACTIONS(1),
    [aux_sym_integer_token2] = ACTIONS(1),
    [sym_kBy] = ACTIONS(1),
    [sym_kDo] = ACTIONS(1),
    [sym_kIf] = ACTIONS(1),
    [sym_kIn] = ACTIONS(1),
    [sym_kIs] = ACTIONS(1),
    [sym_kOf] = ACTIONS(1),
    [sym_kOr] = ACTIONS(1),
    [sym_kTo] = ACTIONS(1),
    [sym_kDiv] = ACTIONS(1),
    [anon_sym_END] = ACTIONS(1),
    [sym_kFor] = ACTIONS(1),
    [sym_kMod] = ACTIONS(1),
    [sym_kNil] = ACTIONS(1),
    [sym_kVar] = ACTIONS(1),
    [sym_kCase] = ACTIONS(1),
    [sym_kElse] = ACTIONS(1),
    [sym_kThen] = ACTIONS(1),
    [sym_kTrue] = ACTIONS(1),
    [sym_kType] = ACTIONS(1),
    [sym_kArray] = ACTIONS(1),
    [sym_kBegin] = ACTIONS(1),
    [sym_kConst] = ACTIONS(1),
    [sym_kFalse] = ACTIONS(1),
    [sym_kUntil] = ACTIONS(1),
    [sym_kWhile] = ACTIONS(1),
    [sym_kElseif] = ACTIONS(1),
    [sym_kImport] = ACTIONS(1),
    [sym_kModule] = ACTIONS(1),
    [sym_kRecord] = ACTIONS(1),
    [sym_kRepeat] = ACTIONS(1),
    [sym_kReturn] = ACTIONS(1),
    [sym_kPointer] = ACTIONS(1),
    [sym_kProcedure] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_COLON_EQ] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_POUND] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_LT_EQ] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_GT_EQ] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_AMP] = ACTIONS(1),
    [anon_sym_TILDE] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_CARET] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_DOT_DOT] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
  },
  [1] = {
    [sym_string] = STATE(3),
    [aux_sym_string_token1] = ACTIONS(5),
    [sym_comment] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      ts_builtin_sym_end,
  [7] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 7,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 1),
  [9] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_oberon2(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .keyword_lex_fn = ts_lex_keywords,
    .keyword_capture_token = sym_ident,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
