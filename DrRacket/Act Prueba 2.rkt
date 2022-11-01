#lang racket
(define lista1 (list 1 2 3 4 5 6 7 8))
(define lista2 (list 100 200 300 400))
(define lista4 (list 1 2 (list 3 4) 5))
(define lista3 (list 1 2 (list 3 4 5) 6 7 8 9 (list 10 (list 11 12 13 14 15)) 16))
(define lista5 (list (list 1 2)3))

; Cuenta la cantidad de elementos de una lista
(define (countList lis)
  (if (empty? lis)
  0
  (+ 1 (countList (cdr lis)))))

; Generar una lista con n ceros
(define (zeroList n)
  (if (equal? n 0)
      (list)
      (cons 0 (zeroList (- n 1)))))
;Hacer una lista del 1...n
(define (lisAsc n)
  (if (equal? n 0)
      (list)
      (append (lisAsc (- n 1)) (list n))))

; dar reversa a la lista: 1 2 3 ==> 3 2 1
(define (rev lst)
  (if (empty? lst)
      (list)
      (append (rev (cdr lst)) (list (car lst)))))

; contantar los atomos de la lista
(define (cuentaAtomos lst)
  (if (empty? lst)
      (list)
      (if list? (car(lst))
          (+ (cuentaAtomos (car lst)) (cuentaAtomos (cdr lst))))
          (+ 1 (cuentaAtomos (cdr lst)))))

; sumar el contenido de la lista de enteros