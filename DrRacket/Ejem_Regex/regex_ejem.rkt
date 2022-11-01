#lang racket

(define (leer file1)
  (define p1 (open-input-file file1))
  (hola p1))

(define (hola st)
  (if (regexp-match-exact? #rx"for" (char (read st)))
      (display "YES")
      (display "NO")))