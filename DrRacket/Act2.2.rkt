#lang racket

#|Implementación de Métodos Computacionales
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 06/Mar/2022
Actividad: Act 2.2|#

;Algoritmo de O(n)
(define (insert n lst) ;Inserta un elemento a una lista en el orden correspondiente
  (if (empty? lst)
      (cons n lst)
      (if (< n (car lst))
          (cons n lst)
          (cons (car lst) (insert n (cdr lst))))))

;Algoritmo de O(n)
(define (rotate-left-helper n lst) ;Helper para rotate-left
  (if (= n 0)
      lst
      (rotate-left-helper (- n 1) (append (cdr lst) (list (car lst))))))

;Algoritmo de O(n)
(define (rotate-left n lst) ;Rota los elementos de una lista n veces hacia la izquierda, de ser negativo n será a la derecha
  (if (empty? lst)
      (list)
      (rotate-left-helper (modulo n (length lst)) lst)))

;Algoritmo de O(n)
(define (encode-helper n lst) ;Helper para encode
  (if (empty? (cdr lst))
      (list (append (list n (car lst))))
      (if (not (equal? (car lst) (car (cdr lst))))
          (append (list (list n (car lst))) (encode-helper 1 (cdr lst)))
          (encode-helper (+ n 1) (cdr lst)))))

;Algoritmo de O(1)
(define (encode lst) ;Codifica elementos consecutivos de una lista en listas de la forma (n e)
  (if (empty? lst)
  (list)
  (encode-helper 1 lst)))

;Algoritmo de O(2^n)
(define (deep-reverse lst) ;Regresa una lista con la posición de lso elementos en reversa, incluyendo listas anidadas
  (if (empty? lst)
      (list)
      (if (list? (car lst))
          (append (deep-reverse (cdr lst)) (list (deep-reverse (car lst))))
          (append (deep-reverse (cdr lst)) (list (car lst))))))