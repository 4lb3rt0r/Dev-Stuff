#|
  File: regexp2.rkt
  Description: Using <atom> ::= (<regexp>)
  Author: lqnub <lqnub@pm.me>
  Last Modified: 7 Mar 2022
|#

#lang racket
(regexp-match #rx"(a|b|c)" "abc") ; '("a" "a")
(regexp-match #rx"(a|b|c)(a|b|c)(a|b|c)" "abc") ; '("abc" "a" "b" "c")
(regexp-match #rx"(.)(.)(.)" "abc") ; '("abc" "a" "b" "c")
(regexp-match #rx"()(.)(.)" "abc") ; '("ab" "" "a" "b")
(regexp-match #rx"(.*)(.)(.)" "abc") ; '("abc" "a" "b" "c")
(regexp-match #rx"(.*)" "abc") ; '("abc" "abc")
(regexp-match #rx"(.*)(.)?(.)?" "abc") ; '("abc" "abc" #f #f)
(regexp-match #rx"(.*)(.)?(.)" "abc") ; '("abc" "ab" #f "c")
(regexp-match #rx"(.*)(.)(.)?" "abc") ; '("abc" "ab" "c" #f)
(regexp-match #rx"(.*)(.)()?" "abc") ; '("abc" "ab" "c" "")
(regexp-match #rx"(.*)(.)()" "abc") ; '("abc" "ab" "c" "")
(regexp-match #rx"(.*)(.)?()?" "abc") ; '("abc" "abc" #f "")
(regexp-match #rx"(.*)()(.)" "abc") ; '("abc" "ab" "" "c")
(regexp-match #rx"(.*)()(.)?" "abc") ; '("abc" "abc" "" #f)
(regexp-match #rx"(a)(b)" "ab") ; '("ab" "a" "b")
(regexp-match #rx"(a)(b)" "ba") ; #f
