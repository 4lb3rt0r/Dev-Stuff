## BT1013.4 - Análisis de Bilogía Computacional
## Alumno: Alberto Horacio Orozco Ramos      Matrícula: A00831719
## Fecha: 26/Mar/21                Tarea: Ejercicios Básicos de R

print("Parte 1")
x <- c(10,11,13,-1,6,3)
vector <- function(x){
  print(x)
  }
vector(x)

print("Parte 2")
valores <- function(x){
  est.x <- c(mean(x),sd(x),var(x))
}
valores(x)

print("Parte 3")
secuencia <- function(){
  a <- seq(from=20, to=50)
print(a)
y <- mean(seq(from=20, to=60))
print(y)
z <- sum(seq(from=51, to=91))
print(z)}

secuencia()

print("Parte 4")
random <- function(){
  x <- sample(seq(from=-100, to=50), 10, replace = TRUE)
  print(x)
}
  random()

print("Parte 5")
fibonacci <- function(){
  n0 <-10
  fibc <- numeric(n0)
  longitud <- length((fibc))
  fibo <- function(longitud,n0){
    n1 <- 0
    n2 <- 1
    
    if (n0==1){
      print(0)
    }
    else if (n0==2){
      print(1)
    }
    else if (n0>2)
      for(i in (3:n0)){
        n3 <- n1 +n2
        n1 <- n2
        n2 <-n3
        fibc[i] <- n3
      }
    print(fibc)
  }
  fibo(longitud,n0)
  
}

fibonacci()

print("Parte 6")
maxmin <- function(m,n){
  print(max(m))
  print(min(m))
  print(max(n))
  print(min(n))
}

m <- c(10,20,30,4,50,-60)
n <- c(10,20,30,4,50,-60)
maxmin(m,n)

print("Parte 7")
vmult <- function(v1,v2){
  
  if (length(v1) == length(v2)) {
    vnueva <- v1*v2
    print(vnueva)
  }
}
v1 <- c(10,20)
v2 <- c(3,4)
vmult(v1,v2)
print("Parte 8")
count <- function(v,n){
  l <- length(v)
  count <- 0
  for(i in 1:l){
    if(v[i] == n){
      count <- count + 1}
  }
  print(count)
}

count(c(10, 20, 10, 7, 24, 7, 5), 7)

print("Parte 9")
enesimo <- function(v,count,n,v2){
  for(i in 1:length(v)){
    if(count %% n == 0){
      v2 <- c(v2,v[i])
    }
    count <- count + 1
  }
  print(v2)
}
v <- (1:100)
count <- 0
n <- 5
v2 <- numeric()
enesimo(v,count,n,v2)
