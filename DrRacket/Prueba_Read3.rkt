#lang racket
(define (imprime lista p2)
  (define (despliega lista p2)
    (display (first lista) p2)
    (display " " p2)
    (display (second lista) p2)
    (newline p2)
    1)
  (if (empty? lista)
      0
      (+ (despliega (car lista) p2) (imprime (cdr lista) p2))))

(define (convierte atomo)
  (if (number? atomo)
      (list "ENTERO: " atomo)
      (list "VARIABLE: " atomo)))

(define (recorre-2 p1)
  (if (eof-object? (peek-char p1))
  '()
  (append (list (convierte (read p1))) (recorre-2 p1))))
    
(define (recorre file1 file2)
  (define p1 (open-input-file file1))
  (define p2 (open-output-file file2))
  (define lista (recorre-2 p1))
  (define cantidad (imprime lista p2))
  (display "Cantidad de Tokens: " p2)
  (display cantidad p2)
  (close-output-port p2)
  (close-input-port p1))

