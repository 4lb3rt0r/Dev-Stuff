## BT1013.4 - Análisis de Bilogía Computacional
## Alumnos: 
## Edvin Herón Narcia Brown A00831109
## Alberto Horacio Orozco Ramos A00831719
## Diego Vitales Medellín A01611209
## Samuel Jesús Osorio Cortés A00832366

## Fecha: 16/Abril/21                Tarea: Base de datos de virus de NCBI

setwd("C:/Users/alber/Desktop/COVID-19/Secuencias") ## ATENCIÓN!!: MODIFICAR DE TAL FORMA QUE SE PUEDAN CARGAR LOS ARCHIVOS DE LAS RESPECTIVAS SECUENCIAS

library(seqinr)
library(ggplot2)

zika_virus <- read.fasta("zika_virus.fasta")
SARScorona_virus <- read.fasta("sars_cov_2.fasta")
Wuhan_virus <- read.fasta("sars_cov_2.1.fasta")
MERScorona_virus <- read.fasta("MERS_coronavirus.fasta")
dengue1_virus <- read.fasta("dengue_1.fasta")
influenza_virus <- read.fasta("virus_Influenza.fasta")

print("Parte 1")
 
length_virus <- function (zika_virus,SARScorona_virus,Wuhan_virus,MERScorona_virus,dengue1_virus,influenza_virus) {
  viruses <- c("zika_virus","SARScorona_virus","Wuhan_virus","MERScorona_virus","dengue1_virus","influenza_virus")
    print("Tamaño de la Secuencia de ")
    print(viruses[1])
    print(getLength(zika_virus))
    
    print(viruses[2])
    print(getLength(SARScorona_virus))
    
    print(viruses[3])
    print(getLength(Wuhan_virus))
    
    print(viruses[4])
    print(getLength(MERScorona_virus))
    
    print(viruses[5])
    print(getLength(dengue1_virus))
    
    print(viruses[6])
    print(getLength(influenza_virus))
    
}

length_virus(zika_virus,SARScorona_virus,Wuhan_virus,MERScorona_virus,dengue1_virus,influenza_virus)

print("Parte 2")
porcentajes <- function(zika_virus,SARScorona_virus,Wuhan_virus,MERScorona_virus,dengue1_virus,influenza_virus) {
  viruses <- c("zika_virus","SARScorona_virus","Wuhan_virus","MERScorona_virus","dengue1_virus","influenza_virus")
  GC_Zika <- 0
  GC_SARSCov <- 0
  GC_Wuhan <- 0
  GC_MERS <- 0
  GC_D1 <- 0
  for (i in 1:length(viruses)) {
    if (viruses[i] == "zika_virus") {
      zika_composition <- table(zika_virus)
      nucleotidos <- as.vector(zika_composition)
      cG <- nucleotidos[1]
      cA <- nucleotidos[2]
      cT <- nucleotidos[3]
      cC <- nucleotidos[4]
      pG <- (cG * 100)/getLength(zika_virus)
      pA <- (cA * 100)/getLength(zika_virus)
      pT <- (cT * 100)/getLength(zika_virus)
      pC <- (cC * 100)/getLength(zika_virus)
      
      print("Bases del Virus Zika")
      print("Porcentaje de la Base A:")
      print(pG)
      print("Porcentaje de la Base C:")
      print(pA)
      print("Porcentaje de la Base G:")
      print(pT)
      print("Porcentaje de la Base T:")
      print(pC)
      GC_Zika <- cG + cC
    }
    else if (viruses[i] == "SARScorona_virus") {
      SARS_composition <- table(SARScorona_virus)
      nucleotidos <- as.vector(SARS_composition)
      cG <- nucleotidos[1]
      cA <- nucleotidos[2]
      cT <- nucleotidos[3]
      cC <- nucleotidos[4]
      pG <- (cG * 100)/getLength(SARScorona_virus)
      pA <- (cA * 100)/getLength(SARScorona_virus)
      pT <- (cT * 100)/getLength(SARScorona_virus)
      pC <- (cC * 100)/getLength(SARScorona_virus)
      
      print("Bases del Virus SARS coronavirus")
      print("Porcentaje de la Base A:")
      print(pG)
      print("Porcentaje de la Base C:")
      print(pA)
      print("Porcentaje de la Base G:")
      print(pT)
      print("Porcentaje de la Base T:")
      print(pC)
      GC_SARSCov <- cG + cC
    }
    else if (viruses[i] == "Wuhan_virus") {
      Wuhan_composition <- table(Wuhan_virus)
      nucleotidos <- as.vector(Wuhan_composition)
      cG <- nucleotidos[1]
      cA <- nucleotidos[2]
      cT <- nucleotidos[3]
      cC <- nucleotidos[4]
      pG <- (cG * 100)/getLength(Wuhan_virus)
      pA <- (cA * 100)/getLength(Wuhan_virus)
      pT <- (cT * 100)/getLength(Wuhan_virus)
      pC <- (cC * 100)/getLength(Wuhan_virus)
      
      print("Bases del Virus Wuhan-Hu-1")
      print("Porcentaje de la Base A:")
      print(pG)
      print("Porcentaje de la Base C:")
      print(pA)
      print("Porcentaje de la Base G:")
      print(pT)
      print("Porcentaje de la Base T:")
      print(pC)
      GC_Wuhan <- cG + cC
    }
    else if (viruses[i] == "MERScorona_virus") {
      MERS_composition <- table(MERScorona_virus)
      nucleotidos <- as.vector(MERS_composition)
      cG <- nucleotidos[1]
      cA <- nucleotidos[2]
      cT <- nucleotidos[3]
      cC <- nucleotidos[4]
      pG <- (cG * 100)/getLength(MERScorona_virus)
      pA <- (cA * 100)/getLength(MERScorona_virus)
      pT <- (cT * 100)/getLength(MERScorona_virus)
      pC <- (cC * 100)/getLength(MERScorona_virus)
      
      print("Bases del Virus MERS coronavirus")
      print("Porcentaje de la Base A:")
      print(pG)
      print("Porcentaje de la Base C:")
      print(pA)
      print("Porcentaje de la Base G:")
      print(pT)
      print("Porcentaje de la Base T:")
      print(pC)
      GC_MERS <- cG + cC
    }
    else if (viruses[i] == "dengue1_virus") {
      dengue1_composition <- table(dengue1_virus)
      nucleotidos <- as.vector(dengue1_composition)
      cG <- nucleotidos[1]
      cA <- nucleotidos[2]
      cT <- nucleotidos[3]
      cC <- nucleotidos[4]
      pG <- (cG * 100)/getLength(dengue1_virus)
      pA <- (cA * 100)/getLength(dengue1_virus)
      pT <- (cT * 100)/getLength(dengue1_virus)
      pC <- (cC * 100)/getLength(dengue1_virus)
      
      print("Bases del Virus Dengue 1")
      print("Porcentaje de la Base A:")
      print(pG)
      print("Porcentaje de la Base C:")
      print(pA)
      print("Porcentaje de la Base G:")
      print(pT)
      print("Porcentaje de la Base T:")
      print(pC)
      GC_D1 <- cG + cC
    }
    else if (viruses[i] == "influenza_virus") {
      influ_composition <- table(influenza_virus)
      nucleotidos <- as.vector(influ_composition)
      cG <- nucleotidos[1]
      cA <- nucleotidos[2]
      cT <- nucleotidos[3]
      cC <- nucleotidos[4]
      pG <- (cG * 100)/getLength(influenza_virus)
      pA <- (cA * 100)/getLength(influenza_virus)
      pT <- (cT * 100)/getLength(influenza_virus)
      pC <- (cC * 100)/getLength(influenza_virus)
      
      print("Bases del Virus Influenza")
      print("Porcentaje de la Base A:")
      print(pG)
      print("Porcentaje de la Base C:")
      print(pA)
      print("Porcentaje de la Base G:")
      print(pT)
      print("Porcentaje de la Base T:")
      print(pC)
      GC_In09 <- cG + cC
    }
  }
  
  GC_Suma <- c(GC_Zika,GC_SARSCov,GC_Wuhan,GC_MERS,GC_D1,GC_In09)
  return(GC_Suma)
}
GC <- porcentajes(zika_virus,SARScorona_virus,Wuhan_virus,MERScorona_virus,dengue1_virus,influenza_virus)

print("Parte 3")

GC_content <- function (GC) {
  print("Contenido de GC en virus Zika (Número y porcentaje):")
  print(GC[1])
  print((GC[1]* 100)/getLength(zika_virus))
  
  print("Contenido de GC en SARS coronavirus (Número y porcentaje):")
  print(GC[2])
  print((GC[2]* 100)/getLength(SARScorona_virus))
  
  print("Contenido de GC en virus Wuhan-Hu-1 (Número y porcentaje):")
  print(GC[3])
  print((GC[3]* 100)/getLength(Wuhan_virus))
  
  print("Contenido de GC en MERS coronavirus (Número y porcentaje):")
  print(GC[4])
  print((GC[4]* 100)/getLength(MERScorona_virus))
  
  print("Contenido de GC en virus Dengue 1 (Número y porcentaje):")
  print(GC[5])
  print((GC[5]* 100)/getLength(dengue1_virus))
  
  print("Contenido de GC en virus Influenza (Número y porcentaje):")
  print(GC[6])
  print((GC[6]* 100)/getLength(influenza_virus))
}
GC_content(GC)

print("Parte 4")

virus_complementary <- function(viruses)
{
  viruses2 <- c("zika_virus","SARScorona_virus","Wuhan_virus","MERScorona_virus","dengue1_virus","influenza_virus")
  complementaries <- character()
  
  for(i in 1:6)
  {
    
    complementary <- comp(viruses[i][[names(viruses[i])]])
    print("Complementaria de:")
    print(viruses2[i])
    print(complementary)
    complementaries <- c(complementaries, complementary) 
    
  }
  
  return(complementaries)
  
}
viruses <- c(zika_virus,SARScorona_virus,Wuhan_virus,MERScorona_virus,dengue1_virus,influenza_virus)
virus_comps <- virus_complementary(viruses)

print("Parte 5")

graficas <- function (zika_virus,SARScorona_virus,Wuhan_virus,MERScorona_virus,dengue1_virus,influenza_virus) {
  zika_composition <- table(zika_virus)
  SARS_composition <- table(SARScorona_virus)
  Wuhan_composition <- table(Wuhan_virus)
  MERS_composition <- table(MERScorona_virus)
  dengue_composition <- table(dengue1_virus)
  influenza_composition <- table(influenza_virus)
  
  df <- data.frame(nucleotidos=c("A", "C", "G", "T"), porcentajes=c(as.vector(zika_composition)/getLength(zika_virus)))
  p<-ggplot(data=df, aes(x=nucleotidos, y=porcentajes)) +
    geom_bar(stat="identity") + ggtitle("Zika composition")
  print(p)
  
  s <- readline(prompt = "Siguiente grafica")
  
  df <- data.frame(nucleotidos=c("A", "C", "G", "T"), porcentajes=c(as.vector(SARS_composition)/getLength(SARScorona_virus)))
  p<-ggplot(data=df, aes(x=nucleotidos, y=porcentajes)) +
    geom_bar(stat="identity") + ggtitle("SARS composition")
  print(p)
  
  s <- readline(prompt = "Siguiente grafica")
  
  df <- data.frame(nucleotidos=c("A", "C", "G", "T"), porcentajes=c(as.vector(Wuhan_composition)/getLength(Wuhan_virus)))
  p<-ggplot(data=df, aes(x=nucleotidos, y=porcentajes)) +
    geom_bar(stat="identity") + ggtitle("Wuhan composition")
  print(p)
  
  s <- readline(prompt = "Siguiente grafica")
  
  df <- data.frame(nucleotidos=c("A", "C", "G", "T"), porcentajes=c(as.vector(MERS_composition)/getLength(MERScorona_virus)))
  p<-ggplot(data=df, aes(x=nucleotidos, y=porcentajes)) +
    geom_bar(stat="identity") + ggtitle("MERS composition")
  print(p)
  
  s <- readline(prompt = "Siguiente grafica")
  
  df <- data.frame(nucleotidos=c("A", "C", "G", "T"), porcentajes=c(as.vector(dengue_composition)/getLength(dengue1_virus)))
  p<-ggplot(data=df, aes(x=nucleotidos, y=porcentajes)) +
    geom_bar(stat="identity") + ggtitle("Dengue composition")
  print(p)
  
  s <- readline(prompt = "Siguiente grafica")
  
  df <- data.frame(nucleotidos=c("A", "C", "G", "T"), porcentajes=c(as.vector(influenza_composition)/getLength(influenza_virus)))
  p<-ggplot(data=df, aes(x=nucleotidos, y=porcentajes)) +
    geom_bar(stat="identity") + ggtitle("Influenza composition")
  print(p)
}

graficas(zika_virus,SARScorona_virus,Wuhan_virus,MERScorona_virus,dengue1_virus,influenza_virus)
