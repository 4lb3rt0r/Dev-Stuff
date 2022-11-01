## BT1013.4 - Análisis de Bilogía Computacional
## Alumno: Alberto Horacio Orozco Ramos      Matrícula: A00831719
## Fecha: 10/Abril/21                Tarea: Ejercicios R

print("Parte 1")
sec_ADN <- function(n) {
  Bases <- c("G","A","T","C")
  ADN <- c()
  for (i in 1:n) {
    x <- sample(1:length(Bases),1,replace=F)
    x <- as.integer(x)
    ADN <- append(ADN,Bases[x],after=length(ADN))
  }
  return(ADN)
}
bool <- FALSE
while (bool == FALSE) {
  n <- readline(prompt="Teclee cuantas letras tendrá la secuencia de ADN (múltiplos de 3): ")
  n <- as.integer(n)
  if (n %% 3 == 0) {
    ADN <- sec_ADN(n)
    print(ADN)
    bool <- TRUE
  }
  else {
    print("Este valor no es compatible con una secuencia de ADN")
  }
}



print("Parte 2")
size_ADN <- function(sec,n1,x){
  while (x != 0) {
    n1 <- readline(prompt="Teclee [0] si terminaste de teclear la secuencia: ")
    if (n1 != 0) {
      sec <- append(sec,n1,after=length(sec))
    }
    else if (n1 == 0){
      x <- 0
      size <- length(sec)
      print("Tamaño de la secuencia: ")
      print(size)
    }
  }
}
n1 <- as.character(n1)
x <- 1
sec <- c()
print("A continuación, teclea una secuencia de ADN: ")

size_ADN(sec,n1,x)

print("Parte 3")
porcentajes <- function(ADN) {
  cG <- 0
  cA <- 0
  cT <- 0
  cC <- 0
  total <- length(ADN)
  for (i in 1:total) {
    if (ADN[i] == "G"){
      cG = cG + 1
    }
    else if (ADN[i] == "A"){
      cA = cA + 1
    }
    else if (ADN[i] == "T"){
      cT = cT + 1
    }
    else if (ADN[i] == "C"){
      cC = cC + 1
    }
  }
  pG <- (cG * 100)/total
  pA <- (cA * 100)/total
  pT <- (cT * 100)/total
  pC <- (cC * 100)/total
  
  print("Porcentaje de la Base G:")
  print(pG)
  print("Porcentaje de la Base A:")
  print(pA)
  print("Porcentaje de la Base T:")
  print(pT)
  print("Porcentaje de la Base C:")
  print(pC)
}
#ADN <- c("G","A","T","A","A","A","T","C","T","G","G","T","C","T","T","A","T","T","T","C","C")
print("Molécula de ADN:")
print(ADN)
porcentajes(ADN)

print("Parte 4")
transcripción <- function(ADN,ARNm) {
  for (i in 1:length(ADN)) {
    if (ADN[i] == "T") {
      bNitro <- "A"
      ARNm <- append(ARNm,bNitro,after=length(ARNm))
    }
    if (ADN[i] == "C") {
      bNitro <- "G"
      ARNm <- append(ARNm,bNitro,after=length(ARNm))
    }
    if (ADN[i] == "A") {
      bNitro <- "U"
      ARNm <- append(ARNm,bNitro,after=length(ARNm))
    }
    if (ADN[i] == "G") {
      bNitro <- "C"
      ARNm <- append(ARNm,bNitro,after=length(ARNm))
    }
  }
  return(ARNm)
}
ARNm <- c()
print("Molécula de ADN a transcribir:")
print(ADN)
ARNm <- transcripción(ADN,ARNm)
print("Molécula de ARNm transcrito:")
print(ARNm)

print("Parte 5")
traducción <- function(ARNm) {
  proteinas <- c()
  trad <- c()
  proteina <- c()
  for (i in length(ARNm):1) {
    trad <- append(trad,ARNm[i],after=length(trad))
  }
  print("Secuencia de ARNm invertida para traducir:")
  print(trad)
  for (j in 3:length(trad)) {
    if (j %% 3 == 0) {
      proteina <- append(proteina,trad[j-2],after=length(proteina))
      proteina <- append(proteina,trad[j-1],after=length(proteina))
      proteina <- append(proteina,trad[j],after=length(proteina))
      if (proteina[j-2] == "U") {
        if (proteina[j-1] == "U") {
          if (proteina[j] == "U") {
            proteinas <- append(proteinas,"Phe",after=length(proteinas)) 
          }
          else if (proteina[j] == "C") {
            proteinas <- append(proteinas,"Phe",after=length(proteinas))
          }
          else if (proteina[j] == "A") {
            proteinas <- append(proteinas,"Leu",after=length(proteinas))
          }
          else if (proteina[j] == "G") {
            proteinas <- append(proteinas,"Leu",after=length(proteinas))
          }
        }
        else if (proteina[j-1] == "C") {
          if (proteina[j] == "U") {
            proteinas <- append(proteinas,"Ser",after=length(proteinas))
          }
          else if (proteina[j] == "C") {
            proteinas <- append(proteinas,"Ser",after=length(proteinas))
          }
          else if (proteina[j] == "A") {
            proteinas <- append(proteinas,"Ser",after=length(proteinas))
          }
          else if (proteina[j] == "G") {
            proteinas <- append(proteinas,"Ser",after=length(proteinas))
          }
        }
        else if (proteina[j-1] == "A") {
          if (proteina[j] == "U") {
            proteinas <- append(proteinas,"Tyr",after=length(proteinas))
          }
          else if (proteina[j] == "C") {
            proteinas <- append(proteinas,"Tyr",after=length(proteinas))
          }
          else if (proteina[j] == "A") {
            proteinas <- append(proteinas,"Stop",after=length(proteinas))
          }
          else if (proteina[j] == "G") {
            proteinas <- append(proteinas,"Stop",after=length(proteinas))
          }
        }
        else if (proteina[j-1] == "G") {
          if (proteina[j] == "U") {
            proteinas <- append(proteinas,"Cys",after=length(proteinas))
          }
          else if (proteina[j] == "C") {
            proteinas <- append(proteinas,"Cys",after=length(proteinas))
          }
          else if (proteina[j] == "A") {
            proteinas <- append(proteinas,"Stop",after=length(proteinas))
          }
          else if (proteina[j] == "G") {
            proteinas <- append(proteinas,"Trp",after=length(proteinas))
          }
        }
      }
      else if (proteina[j-2] == "C") {
        if (proteina[j-1] == "U") {
          if (proteina[j] == "U") {
            proteinas <- append(proteinas,"Leu",after=length(proteinas))
          }
          else if (proteina[j] == "C") {
            proteinas <- append(proteinas,"Leu",after=length(proteinas))
          }
          else if (proteina[j] == "A") {
            proteinas <- append(proteinas,"Leu",after=length(proteinas))
          }
          else if (proteina[j] == "G") {
            proteinas <- append(proteinas,"Leu",after=length(proteinas))
          }
        }
        else if (proteina[j-1] == "C") {
          if (proteina[j] == "U") {
            proteinas <- append(proteinas,"Pro",after=length(proteinas))
          }
          else if (proteina[j] == "C") {
            proteinas <- append(proteinas,"Pro",after=length(proteinas))
          }
          else if (proteina[j] == "A") {
            proteinas <- append(proteinas,"Pro",after=length(proteinas))
          }
          else if (proteina[j] == "G") {
            proteinas <- append(proteinas,"Pro",after=length(proteinas))
          }
        }
        else if (proteina[j-1] == "A") {
          if (proteina[j] == "U") {
            proteinas <- append(proteinas,"His",after=length(proteinas))
          }
          else if (proteina[j] == "C") {
            proteinas <- append(proteinas,"His",after=length(proteinas))
          }
          else if (proteina[j] == "A") {
            proteinas <- append(proteinas,"Gln",after=length(proteinas))
          }
          else if (proteina[j] == "G") {
            proteinas <- append(proteinas,"Gln",after=length(proteinas))
          }
        }
        else if (proteina[j-1] == "G") {
          if (proteina[j] == "U") {
            proteinas <- append(proteinas,"Arg",after=length(proteinas))
          }
          else if (proteina[j] == "C") {
            proteinas <- append(proteinas,"Arg",after=length(proteinas))
          }
          else if (proteina[j] == "A") {
            proteinas <- append(proteinas,"Arg",after=length(proteinas))
          }
          else if (proteina[j] == "G") {
            proteinas <- append(proteinas,"Arg",after=length(proteinas))
          }
        }
      }
      else if (proteina[j-2] == "A") {
        if (proteina[j-1] == "U") {
          if (proteina[j] == "U") {
            proteinas <- append(proteinas,"Ile",after=length(proteinas))
          }
          else if (proteina[j] == "C") {
            proteinas <- append(proteinas,"Ile",after=length(proteinas))
          }
          else if (proteina[j] == "A") {
            proteinas <- append(proteinas,"Ile",after=length(proteinas))
          }
          else if (proteina[j] == "G") {
            proteinas <- append(proteinas,"Met",after=length(proteinas))
          }
        }
        else if (proteina[j-1] == "C") {
          if (proteina[j] == "U") {
            proteinas <- append(proteinas,"Thr",after=length(proteinas))
          }
          else if (proteina[j] == "C") {
            proteinas <- append(proteinas,"Thr",after=length(proteinas))
          }
          else if (proteina[j] == "A") {
            proteinas <- append(proteinas,"Thr",after=length(proteinas))
          }
          else if (proteina[j] == "G") {
            proteinas <- append(proteinas,"Thr",after=length(proteinas))
          }
        }
        else if (proteina[j-1] == "A") {
          if (proteina[j] == "U") {
            proteinas <- append(proteinas,"Asn",after=length(proteinas))
          }
          else if (proteina[j] == "C") {
            proteinas <- append(proteinas,"Asn",after=length(proteinas))
          }
          else if (proteina[j] == "A") {
            proteinas <- append(proteinas,"Lys",after=length(proteinas))
          }
          else if (proteina[j] == "G") {
            proteinas <- append(proteinas,"Lys",after=length(proteinas))
          }
        }
        else if (proteina[j-1] == "G") {
          if (proteina[j] == "U") {
            proteinas <- append(proteinas,"Ser",after=length(proteinas))
          }
          else if (proteina[j] == "C") {
            proteinas <- append(proteinas,"Ser",after=length(proteinas))
          }
          else if (proteina[j] == "A") {
            proteinas <- append(proteinas,"Arg",after=length(proteinas))
          }
          else if (proteina[j] == "G") {
            proteinas <- append(proteinas,"Arg",after=length(proteinas))
          }
        }
      }
      else if (proteina[j-2] == "G") {
        if (proteina[j-1] == "U") {
          if (proteina[j] == "U") {
            proteinas <- append(proteinas,"Val",after=length(proteinas))
          }
          else if (proteina[j] == "C") {
            proteinas <- append(proteinas,"Val",after=length(proteinas))
          }
          else if (proteina[j] == "A") {
            proteinas <- append(proteinas,"Val",after=length(proteinas))
          }
          else if (proteina[j] == "G") {
            proteinas <- append(proteinas,"Val",after=length(proteinas))
          }
        }
        else if (proteina[j-1] == "C") {
          if (proteina[j] == "U") {
            proteinas <- append(proteinas,"Ala",after=length(proteinas))
          }
          else if (proteina[j] == "C") {
            proteinas <- append(proteinas,"Ala",after=length(proteinas))
          }
          else if (proteina[j] == "A") {
            proteinas <- append(proteinas,"Ala",after=length(proteinas))
          }
          else if (proteina[j] == "G") {
            proteinas <- append(proteinas,"Ala",after=length(proteinas))
          }
        }
        else if (proteina[j-1] == "A") {
          if (proteina[j] == "U") {
            proteinas <- append(proteinas,"Asp",after=length(proteinas))
          }
          else if (proteina[j] == "C") {
            proteinas <- append(proteinas,"Asp",after=length(proteinas))
          }
          else if (proteina[j] == "A") {
            proteinas <- append(proteinas,"Glu",after=length(proteinas))
          }
          else if (proteina[j] == "G") {
            proteinas <- append(proteinas,"Glu",after=length(proteinas))
          }
        }
        else if (proteina[j-1] == "G") {
          if (proteina[j] == "U") {
            proteinas <- append(proteinas,"Gly",after=length(proteinas))
          }
          else if (proteina[j] == "C") {
            proteinas <- append(proteinas,"Gly",after=length(proteinas))
          }
          else if (proteina[j] == "A") {
            proteinas <- append(proteinas,"Gly",after=length(proteinas))
          }
          else if (proteina[j] == "G") {
            proteinas <- append(proteinas,"Gly",after=length(proteinas))
          }
        }
      }
    }
  }
  print("Proteínas identificadas en la secuencia:")
  print(proteinas)
}
print("Molécula de ARNm:")
print(ARNm)
traducción(ARNm)

print("Parte 6")
reverse_strand <- function(H1){
  H2 <- c()
  for (i in length(H1):1){
    H2 <- append(H2,H1[i],after=length(H2))
  }
  return(H2)
}
  

print("Hebra Directa:")
H1 <- c("T","G","C","G","A","T","A","C")
print(H1)
H2 <- reverse_strand(H1)
print("Hebra Inversa:")
print(H2)

print("Paso 7")
complementary_strand <- function(H1,H3){
  comp <- c()
  for (i in 1:length(H1)) {
    if (H1[i] == "T") {
      comp <- "A"
      H3 <- append(H3,comp,after=length(H3))
    }
    if (H1[i] == "C") {
      comp <- "G"
      H3 <- append(H3,comp,after=length(H3))
    }
    if (H1[i] == "A") {
      comp <- "T"
      H3 <- append(H3,comp,after=length(H3))
    }
    if (H1[i] == "G") {
      comp <- "C"
      H3 <- append(H3,comp,after=length(H3))
    }
  }
  return(H3)
}
H3 <- c()
H3 <- complementary_strand(H1,H3)
print("Hebra Complementaria")
print(H3)

print("Paso 8")
reverse_complement <- function(H3){
  H4 <- c()
  for (i in length(H3):1){
    H4 <- append(H4,H3[i],after=length(H4))
  }
  return(H4)
}
H4 <- reverse_complement(H3)
print("Hebra Complementaria Inversa")
print(H4)
