#|
  File: regexp1.rkt
  Description: Simple regexes
  Author: lqnub <lqnub@pm.me>
  Last Modified: 7 Mar 2022
|#

#lang racket
(regexp-match #rx"abcd" "abcde") ; '("abcd") - Letras con letras
(regexp-match #rx"xyz" "abcde") ; #f - No encuentra match
(regexp-match #rx"xyz|abc" "abcde") ; '("abc") - '|' uno o el otro
(regexp-match #rx"ab.d" "abcde") ; '("abcd") - '.' Cualquier caracter
(regexp-match #rx"abc*d" "abccde") ; '("abccd") - '*' Match mas largo
(regexp-match #rx"abcd?e" "abcef") ; '("abce") - '?' Aparece o no
(regexp-match #rx"abc[dx]f" "abcxfe") ; '("abcxf") - Cualquiera en []
(regexp-match #rx"abc[^xyz]e" "abcdef") ; '("abcde") - Excluir en []
(regexp-match #px"ca{2}at" "caaats") ; '("caaat") - Cantidad exacta
