#lang racket
(define (convert atomo)
  (if (number? atomo)
      (list "MULT: " atomo)
      (list "SUMA: " atomo)))

(define (getAtomo caract)
  (if (equal? '* caract)
  (list "MULT: " "*")
  (list "NO ES MULT"  caract)))

(define (recorre p1)
  (if (eof-object? (peek-char p1))
      '()
      (append (list (getAtomo (read p1))) (recorre p1))))

(define (DFA file1)
  (define p1 (open-input-file file1))
  (define lista (recorre p1))
  (display lista)
  (newline)
  (display (length lista))
  (newline)
  (close-input-port p1))