#lang racket

#|

TC2037.607: Implementación de métodos computacionales
Actividad Integradora 3.4 Resaltador de sintaxis
Profesor: Ing. Luis Humberto González G
22 de abril de 2022

Integrantes del Equipo:
Jose Oscar Cazares - A00826747
Alberto Horacio Orozco Ramos - A00831719
Andrés Aguirre Rodríguez - A0128437

|#


#|

INDICACIONES
------------------

Para correr el programa:

Prueba 1--
(resaltador "prueba1.cpp" "salida.html")

Prueba 2--
(resaltador "prueba2.cpp" "salida.html")

Prueba 3--
(resaltador "prueba3.cpp" "salida.html")

NOTA-- No es necesario borrar el archivo "salida.html", ya que si el
programa lo dedecta, simplemente lo reemplaza.

|#


; Inicializa el código esencial para nuestro archivo de HTML
(define (boilerPlateInicialHTML file2)
    (display "<!DOCTYPE html>" file2) (newline file2)
    (display "<html>" file2) (newline file2)
    (display "<head>" file2) (newline file2)
    (display "<title> Actividad 3.4 - Resaltador de sintaxis</title>" file2) (newline file2)
    (display "</head>" file2) (newline file2)
    (display "<body style='background-color:#1E1E1E'>" file2) (newline file2)
    (display "<h1 style='color:white;'> Actividad 3.4 - Resaltador de Sintaxis</h1>" file2) (newline file2)
)

; Finaliza el código esencial para nuestro archivo de HTML
(define (boilerPlateFinalHTML file2)
    (display "</body>" file2) (newline file2)
    (display "</html>" file2)
)


; Se encarga de identificar cada token del archivo e imprimirlo dentro del archivo .html con su color respectivo
(define (convierte atomo file2)
  ; Identifica los números enteros y flotantes
  (if (real? atomo)
      (begin
        (display "<t style=\"color: #AFCFA4;\">" file2)
        (display atomo file2)
        (newline file2))
      ; if, else
      (if (regexp-match #rx"if|else" (symbol->string atomo))
          (begin
            (display "<t style=\"color: #D082C4;\">" file2)
            (display atomo file2)
            (newline file2))
          ; while
          (if (regexp-match-exact? "while" (symbol->string atomo))
              (display "<t style=\"color: #D082C4;\">while" file2)
              (if (regexp-match #rx"cin|cout|std" (symbol->string atomo))
                  (begin
                    (display "<t style=\"color: #389EDB;\">" file2)
                    (display atomo file2)
                    (newline file2))
                  ; int, float, double, char, string, bool, void, namespace, true,false
                  (if (regexp-match #rx"int|float|double|char|string|bool|void|namespace|true|false" (symbol->string atomo))
                      (begin
                        (display "<t style=\"color: #389EDB;\">" file2)
                        (display atomo file2)
                        (newline file2))
                      ; for
                      (if (regexp-match-exact? "for" (symbol->string atomo))
                          (begin
                          (display "<t style=\"color: #D082C4;\">for" file2)
                          (newline file2))
                          ; +, -, *, /, =, ++, ==, >=, <=
                          (if (or (equal? '+ atomo) (equal? '- atomo) (equal? '* atomo) (equal? '/ atomo) (equal? '= atomo) (equal? '++ atomo) (equal? '== atomo) (equal? '>= atomo) (equal? '<= atomo))
                              (begin
                                (display "<t style=\"color: #D4D4D4;\">" file2)
                                (display atomo file2)
                                (newline file2))
                              ; include, using
                              (if (regexp-match #rx"include|using" (symbol->string atomo))
                                  (begin
                                    (display "<t style=\"color: #D082C4;\">" file2)
                                    (display atomo file2))
                                  ; main, endl, status
                                  (if (regexp-match #rx"main|endl|status" (symbol->string atomo))
                                      (begin
                                        (display "<t style=\"color: #DCDCAA;\">" file2)
                                        (display atomo file2)
                                        (newline file2))
                                      ; iostream, vector
                                      (if (regexp-match #rx"iostream|vector" (symbol->string atomo))
                                          (begin
                                            (display "<t style=\"color: #D98E73;\">" file2)
                                            (display atomo file2)
                                            (newline file2))
                                          ; Identificación de variables
                                          (begin
                                            (display "<t style=\"color: #9BDBFD;\">" file2)
                                            (begin
                                            (display atomo file2)
                                            (newline file2))))))))))))))

; Se encarga de reccorer el archivo en si, y caracteres especiales como espacios, saltos de linea, etc.
(define (recorre-2 p1 file2) 
  (define a (peek-char p1))
  (if (eof-object? (peek-char p1))
  '()
  ; newlines/returns
  (if (or (equal? #\newline  a) (equal? #\return  a))
      (and (read-char p1) (display "<br>" file2) (recorre-2 p1 file2))
      ; 'space'/'espacio'
      (if (equal? #\space a)
          (and (read-char p1) (display " " file2) (recorre-2 p1 file2))
          ; " 'string'
          (if (equal? #\" a)
              (and (peek-char p1) (begin
                (display "<t style=\"color: #E58A45;\">" file2)
                (display a file2)
                (display (read p1) file2)
                (display a file2)
                (peek-char p1)) (recorre-2 p1 file2))
              ; (, )
              (if (or (equal? #\( a) (equal? #\) a))
                  (and (read-char p1) (begin (display "<t style=\"color: #FFD500;\">" file2) (display a file2)) (recorre-2 p1 file2))
                  ; {, }
                  (if (or (equal? #\{ a) (equal? #\} a))
                      (and (read-char p1) (begin (display "<t style=\"color: #FF3DBF;\">" file2) (display a file2)) (recorre-2 p1 file2))
                      ;[, ]
                      (if (or (equal? #\[ a) (equal? #\] a))
                          (and (read-char p1) (begin (display "<t style=\"color: #847DFF;\">" file2) (display a file2)) (recorre-2 p1 file2))
                          ; ;, ,
                          (if (or (equal? #\; a) (equal? #\, a))
                              (and (read-char p1) (begin (display "<t style=\"color: white;\">" file2) (display a file2)) (recorre-2 p1 file2))
                              ; #
                              (if (equal? #\# a)
                                  (and (read-char p1) (display "<t style=\"color: #D082C4;\">#" file2) (recorre-2 p1 file2))
                                  ; |
                                  (if (equal? #\| a)
                                      (and (read-char p1) (display "<t style=\"color: white;\">|" file2) (recorre-2 p1 file2))
                                      ; <, >
                                      (if (or (equal? #\< a) (equal? #\> a))
                                          (and (read-char p1) (begin (display "<t style=\"color: #EBE878;\">" file2) (display a file2)) (recorre-2 p1 file2))
                                          (append (list (convierte (read p1) file2)) (recorre-2 p1 file2))))))))))))))



; FUNCIÓN PRINCIPAL (MAIN)
(define (resaltador file1 file2)
  ; Iniciar Puerto 1 y 2, nuestros archivos
  (define p1 (open-input-file file1)) ; file1 -> archivo .cpp
  (define p2 (open-output-file file2 #:exists 'replace)) ; file2 -> archivo .html

  ; Inicializar el código HTML (formato)
  (boilerPlateInicialHTML p2)
  
  (define lista (recorre-2 p1 p2))
  
  ; Finalizar el código HTML (formato)
  (boilerPlateFinalHTML p2)

  ; Cerrar los puertos 1 y 2, nuestros archivos
  (close-output-port p2)
  (close-input-port p1)

  ; Mensaje de Exito
  (display "El archivo de salida se ha generado exitosamente.")
  )