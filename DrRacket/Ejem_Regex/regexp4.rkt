#|
  File: regexp4.rkt
  Description: Key differences between #rx and #px
  Author: lqnub <lqnub@pm.me>
  Last Modified: 7 Mar 2022
|#

#lang racket
(regexp-match #px"[[:alpha:]]*" "ABCdef") ; '("ABCdef")
(regexp-match #rx"[[:alpha:]]*" "ABCdef") ; #f
(regexp-match #px"ab{2,4}c" "abbbcd") ; '("abbbc")
(regexp-match #rx"ab{2,4}c" "abbbcd") ; #f
