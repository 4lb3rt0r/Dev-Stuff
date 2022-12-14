## BT1013.4 - An?lisis de Bilog?a Computacional
## Alumnos: 
## Edvin Her?n Narcia Brown A00831109
## Alberto Horacio Orozco Ramos A00831719
## Diego Vitales Medell?n A01611209
## Samuel Jes?s Osorio Cort?s A00832366

## Fecha: 21/Abril/21                Tarea: Evidencia 1

setwd("C:/Users/alber/Desktop/COVID-19") ## ATENCI?N!!: MODIFICAR DE TAL FORMA QUE SE PUEDAN CARGAR LOS ARCHIVOS DE LAS RESPECTIVAS SECUENCIAS

library(seqinr)
sars_cov_2 <- read.fasta("sars_cov_2.fasta")
sars_cov_2_uk <- read.fasta("sars_cov_2_britanico.fasta")
sars_cov_2_bra <- read.fasta("sars_cov_2_brasil.fasta")
sars_cov_2_sa <- read.fasta("sars_cov_2_safrica.fasta")
sars_cov_2_dk <- read.fasta("sars_cov_2_dk.fasta")
sars_cov_2_mys <- read.fasta("sars_cov_2_mys.fasta")

cepas <- c(sars_cov_2,sars_cov_2_uk,sars_cov_2_bra,sars_cov_2_sa,sars_cov_2_dk,sars_cov_2_mys)
nombres <- c("SARS COV 2 Cepa Original","SARS COV 2 Cepa Brit?nica","SARS COV 2 Cepa Brasile?a","SARS COV 2 Cepa Sudafricana","SARS COV 2 Cepa Danesa","SARS COV 2 Cepa Malaya")

print("Parte 1")
virus_length <- function (cepas,nombres) {
  for (i in 1:length(nombres)) {
    print("Longitud de: ")
    print(nombres[i])
    print(getLength(cepas[i]))
  }
}
virus_length(cepas,nombres)

print("Parte 2")
graficas <- function (cepas,nombres) {
  par(mfrow=c(1,length(cepas)))
  for (i in 1:length(cepas)) {
    barplot(table(cepas[i]), col = 1:length(cepas),
            main = nombres[i],
            xlab = "Bases de Binucle?tidos")
  }
  print("Graficado!!")
}

graficas(cepas,nombres)

print("Parte 3")

Porcentaje_GC <- function (cepas,nombres) {
 for (i in 1:length(nombres)) {
   print("Porcentaje de GC en: ")
   print(nombres[i])
   cepa <- cepas[i] 
   porcentaje <- GC(cepa[[1]])
   print(porcentaje)
 }
  }

Porcentaje_GC(cepas,nombres)

print("Parte 4")
inversa <- function (cepas,nombres) {
  inverse <- c()
  for (i in 1:length(nombres)) {
    cepa <- cepas[i]
    for (nucleotido in cepa[[1]]) {
      inverse <- append(inverse,nucleotido,after=length(inverse))
    }
    print("Secuencia Contrasentido de: ")
    print(nombres[i])
    inverse <- rev(inverse)
    print(inverse)
  }
}

inversa(cepas,nombres)

  #Interpretaci?n de gr?ficas:
  #Comparando las gr?ficas de estas seis variantes, podemos ver que son bastante similares,
  #esto se puede corroborar con el hecho de que los porcentajes de GC en cada variante tambi?n
  #son bastante similares con variaciones m?nimas.