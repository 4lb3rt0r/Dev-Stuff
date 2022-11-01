## BT1013.4 - Análisis de Bilogía Computacional
## Alumnos: 
## Edvin Herón Narcia Brown A00831109
## Alberto Horacio Orozco Ramos A00831719
## Diego Vitales Medellín A01611209
## Samuel Jesús Osorio Cortés A00832366

## Fecha: 16/Abril/21                Tarea: Árboles Filogenéticos en R

virus <- c("JX869059", "AY508724", "MN908947", "AY390556", "AY278489", "MN985325","AY485277","MT292571")
library(Biostrings)
library(seqinr)
library(adegenet)
library(DECIPHER)
library(viridis)
library(ggmsa)
library(ggplot2)
library(magrittr)
library(tidyr)
library(utils)
library(stats)
library(stringr)
library(aplot)
library(RColorBrewer)
library(seqmagick)
library(rmarkdown)
library(methods)
library(prettydoc)
library(knitr)
library(ggtree)
library(cowplot)
library(ape)
library(plotly)

viruses <- "C:/Users/alber/Desktop/COVID-19/Árboles/Viruses/Viruses.fasta" ## ATENCIÓN!!: MODIFICAR DE TAL FORMA QUE SE PUEDA CARGAR EL ARCHIVO DE LA SECUENCIA
secuencias <- readRNAStringSet(viruses)

print("1. Alineamiento de Secueancias")
alineamiento <- function (viruses,secuencias) {
  alignment <- AlignSeqs(secuencias)
  print(ggmsa(alignment, 0, 45, char_width = 0.5, color = "Chemistry_AA"))
  #BrowseSeqs(alignment,highlight = 0)  # Esto despliega todo el alineamiento em una pestaña del buscador
  writeXStringSet(alignment,
                  file="C:/Users/alber/Desktop/COVID-19/Árboles/Viruses/Viruses V2.fasta") ## ATENCIÓN!!: MODIFICAR DE TAL FORMA QUE SE PUEDA CARGAR EL ARCHIVO DE LA SECUENCIA
return(alignment)
  }
alineado <- alineamiento(viruses,secuencias)

viruses2 <- "C:/Users/alber/Desktop/COVID-19/Árboles/Viruses/Viruses V2.fasta"

s <- readline(prompt = "Presione Enter para la siguiente sección")

print("2. Matriz de Distancia")
mdistancia <- function (viruses2,alineado) {
  dnabin <- fasta2DNAbin(viruses2)
  
  matriz_distancias <- as.matrix(dist.dna(dnabin))
  
  
  dim <- ncol(matriz_distancias)
  names <- row.names(matriz_distancias)
  
  image(1:dim, 1:dim, matriz_distancias, axes = FALSE, xlab = "", ylab = "")
  
  axis(3, 1:dim, names, cex.axis = 0.8, las=3)
  axis(2, dim:1, names, cex.axis = 0.8, las=1)
  
  text(expand.grid(1:8, 8:1), sprintf("%0.5f", matriz_distancias), cex=1)
  
  s <- readline(prompt = "Presione Enter para la siguiente sección")
  
  print("3. Árbol Filogenético")
  arbol <- nj(matriz_distancias)
  plot(arbol,cex = 0.8)
  s <- readline(prompt = "Presione Enter para la siguiente sección")
  print(ggmsa(alineado, 0, 45, char_width = 0.5, color = "Chemistry_AA"))
  
}
mdistancia(viruses2,alineado)


