## BT1013.4 - Análisis de Bilogía Computacional

## Alumno: Alberto Horacio Orozco Ramos - A00831719
## Profesor: Luis Miguel Figueroa Galván

## Fecha: 29/Abril/21                Tarea: Evidencia 2

setwd("C:/Users/alber/Desktop/COVID 19") ## ATENCIÓN!!: MODIFICAR DE TAL FORMA QUE SE PUEDAN CARGAR LOS ARCHIVOS DE LAS RESPECTIVAS SECUENCIAS

library(seqinr)
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


sars_cov_2 <- read.fasta("sars_cov_2.fasta")
sars_cov_2_usa <- read.fasta("sars_cov_2_usa.fasta")
sars_cov_2_india <- read.fasta("sars_cov_2_india.fasta")
sars_cov_2_bra <- read.fasta("sars_cov_2_brasil.fasta")
sars_cov_2_france <- read.fasta("sars_cov_2_france.fasta")
sars_cov_2_russia <- read.fasta("sars_cov_2_russia.fasta")
sars_cov_2_turkey <- read.fasta("sars_cov_2_turkey.fasta")
sars_cov_2_uk <- read.fasta("sars_cov_2_britanico.fasta")
sars_cov_2_italy <- read.fasta("sars_cov_2_italy.fasta")
sars_cov_2_esp <- read.fasta("sars_cov_2_esp.fasta")
sars_cov_2_deutsch <- read.fasta("sars_cov_2_deutsch.fasta")
sars_cov_2_arg <- read.fasta("sars_cov_2_arg.fasta")
sars_cov_2_colombia <- read.fasta("sars_cov_2_colombia.fasta")
sars_cov_2_poland <- read.fasta("sars_cov_2_poland.fasta")
sars_cov_2_iran <- read.fasta("sars_cov_2_iran.fasta")
sars_cov_2_mex <- read.fasta("sars_cov_2_mex.fasta")
sars_cov_2_peru <- read.fasta("sars_cov_2_peru.fasta")
sars_cov_2_czech <- read.fasta("sars_cov_2_czech.fasta")
sars_cov_2_safrica <- read.fasta("sars_cov_2_safrica.fasta")
sars_cov_2_nld <- read.fasta("sars_cov_2_nld.fasta")
sars_cov_2_canada <- read.fasta("sars_cov_2_canada.fasta")

nombres <- c("Original","Estados Unidos","India","Brasil","Francia",
             "Rusia","Turquía","Reino Unido","Italia","España",
             "Alemania","Argentina","Colombia","Polonia","Irán",
             "México","Perú","República Checa","Sudáfrica","Paises Bajos","Canadá")
variantes <- c(sars_cov_2,sars_cov_2_usa,sars_cov_2_india,sars_cov_2_bra,sars_cov_2_france,
               sars_cov_2_russia,sars_cov_2_turkey,sars_cov_2_uk,sars_cov_2_italy,sars_cov_2_esp,
               sars_cov_2_deutsch,sars_cov_2_arg,sars_cov_2_colombia,sars_cov_2_poland,sars_cov_2_iran,
               sars_cov_2_mex,sars_cov_2_peru,sars_cov_2_czech,sars_cov_2_safrica,sars_cov_2_nld,sars_cov_2_canada)

print("Parte 1")
longitud <- function (variantes,nombres) {
  for (i in 1:length(variantes)) {
    print("Longitud de la variante:")
    print(nombres[i])
    print(getLength(variantes[i]))
  }
}
longitud(variantes,nombres)

s <- readline(prompt = "Presione Enter para pasar a la siguiente sección")

print("Parte 2")
grafica1 <- function (variantes,nombres) {
  win.graph(10,10,12) #Si comentamos esta parte simplemente se desplegarán las gráficas en la ventana plot como normalmente se acostumbra
  # sin embargo he decido desplegarlas en una ventana aparte ya que al ser muchas gráficas, no se pueden entender en un espacio muy pequeño
  layout(matrix(c(1:length(variantes)), nrow=3, byrow=TRUE))
  print("Comparación de Bases de ADN:")
  for (i in 1:length(variantes)) {
    barplot(table(variantes[i]),col = 1:length(variantes),
            main = nombres[i],
            xlab = "Bases de Binucleótidos")
  }
  print("Graficado!!")
  
}
grafica1(variantes,nombres)
s <- readline(prompt = "Presione Enter para pasar a la siguiente sección")
#dev.off() #Deshabilitar solo si la pestaña "Plots" esta vacia

print("Parte 2.2")
grafica2 <- function (variantes,nombres){
  Original <- table(variantes[1])
  USA <- table(variantes[2])
  India <- table(variantes[3])
  Brasil <- table(variantes[4])
  Francia <- table(variantes[5])
  Rusia <- table(variantes[6])
  Turquía <- table(variantes[7])
  Reino_Unido <- table(variantes[8])
  Italia <- table(variantes[9])
  España <- table(variantes[10])
  Alemania <- table(variantes[11])
  Argentina <- table(variantes[12])
  Colombia <- table(variantes[13])
  Polonia <- table(variantes[14])
  Irán <- table(variantes[15])
  México <- table(variantes[16])
  Perú <- table(variantes[17])
  República_Checa<- table(variantes[18])
  Sudáfrica <- table(variantes[19])
  Países_Bajos <- table(variantes[20])
  Canadá <- table(variantes[21])
  m <- rbind(Original,USA,India,Brasil,Francia,Rusia,Turquía,Reino_Unido,Italia,España,Alemania,Colombia,Polonia,Irán,
             México,Perú,República_Checa,Sudáfrica,Países_Bajos,Canadá)
  barplot(m,beside=TRUE,col=1:21,main="Comparación de Bases entre Variantes de SARS COV 2")
}
grafica2(variantes,nombres)

s <- readline(prompt = "Presione Enter para pasar a la siguiente sección")
dev.off()

print("Parte 3")
arbol_filogenético <- function () {
  viruses <- "C:/Users/alber/Desktop/COVID 19/Viruses.fasta" ## ATENCIÓN!!: MODIFICAR DE TAL FORMA QUE SE PUEDA CARGAR EL ARCHIVO DE LA SECUENCIA
  secuencias <- readRNAStringSet(viruses)
  alignment <- AlignSeqs(secuencias)
  writeXStringSet(alignment,
                  file="C:/Users/alber/Desktop/COVID 19/Viruses V2.fasta") ## ATENCIÓN!!: MODIFICAR DE TAL FORMA QUE SE PUEDA CARGAR EL ARCHIVO DE LA SECUENCIA
  viruses2 <- "C:/Users/alber/Desktop/COVID 19/Viruses V2.fasta"
  dnabin <- fasta2DNAbin(viruses2)
  matriz_distancias <- as.matrix(dist.dna(dnabin))
  arbol <- nj(matriz_distancias)
  plot(arbol,cex = 0.8,main="Análisis Jerárquico Global")
}
arbol_filogenético()

# La interpretación que le doy a cada una de las representaciones gráficas que se realizan en el script es que primeramente
# las gráficas de cada uno de los países nos muestran como cada variante de sars cov 2 en su respectivo país difiere una de
# otra, por lo que podemos visualizar las bases de aminoácidos en cantidad por cada país y podemos determinar como varian
# en cantidad  en sus diversas versiones del virus.
# En cuanto al árbol filogenético, podemos concluir que este nos facilita la interpretación visual de las variantes del
# virus y sus clasificaciones basándonos en sus similitudes, diferencias, características en común, familias del virus con un 
# "tronco común", etc. Por lo que esta representación resulta ser sumamente útil al momento de analizar la evolución del
# virus y que tanto puede llegar a cambiar respecto a su versión original. El hecho de que algunas ramas esten muy juntas una de 
# la otra significa que sus bases son sumamente parecidas la una de la otra, y en tre más alejadas más difieren entre ellas, sin
# embargo estamos hablando de variantes de un mismo tipo de virus por lo que en este caso podemos apreciar que en efecto, algunas
# variantes estan alejadas y otras están demasiado pegadas pero se sigue trabajando con una gran familia de un solo virus.
# Esto también es útil por ejemplo con el tema de la vacuna, se analiza todas las variantes para determinar exactamente cuáles 
# no representan un riesgo para la elaboración de la vacuna y cuáles han cambiado tanto que se han "alejado" de su raíz común.

## Bibliografía del Video:
# Rabaan AA, Al-Ahmed SH, Haque S, Sah R, Tiwari R, Malik YS, Dhama K, Yatoo MI, Bonilla-Aldana DK, Rodriguez-Morales AJ. SARS-CoV-2, SARS-CoV, and MERS-COV: A comparative overview. Infez Med. 2020 Ahead Of Print Jun 1;28(2):174-184. PMID: 32275259.
# Wang H, Li X, Li T, Zhang S, Wang L, Wu X, Liu J. The genetic sequence, origin, and diagnosis of SARS-CoV-2. Eur J Clin Microbiol Infect Dis. 2020 Sep;39(9):1629-1635. doi: 10.1007/s10096-020-03899-4. Epub 2020 Apr 24. PMID: 32333222; PMCID: PMC7180649.
# Malik YA. Properties of Coronavirus and SARS-CoV-2. Malays J Pathol. 2020 Apr;42(1):3-11. PMID: 32342926.
# Anónimo. (2020). ¿Cuál es la importancia de los SARS-CoV y MERS-CoV, en comparación con SARS-CoV-2?. abril 29, 2021, de Similitudes del SARS COV 2 con otros virus Sitio web: https://empendium.com/manualmibe/covid19/231147,cual-es-la-importancia-de-los-sarc-cov-y-mers-cov-en-comparacion-con-sars-cov-2