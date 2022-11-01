#Diego Vitales Medellin A01611209

#1
print("Ejercicio 1")
x <- c(10, 11, 13, -1, 6, 3)
print(x)

#2
print("Ejercicio 2")
est.x <- c(mean(x), sd(x), var(x))

print(est.x)

#3
print("Ejercicio 3")
a <- seq(from=20, to=50, by=1)
media <- mean(seq(from=20, to=60, by=1))
sumatoria <- sum(seq(from=51, to=91, by=1))

print(a)
print(media)
print(sumatoria)

#4
print("Ejercicio 4")
muestra <- sample(c(-100:50), 10)
print(muestra)

#5
print("Ejercicio 5")
fb <- numeric(10)
fb[1] <- fb[2] <- 1

for(i in 3:10){
  fb[i] <- fb[i - 1] + fb[i - 2]
  
}

print(fb)

#6
print("Ejercicio 6")
b <- c(10, 20, 30, 4, 50, -60)
maximo <- max(b)
minimo <- min(b)

print(maximo)
print(minimo)

#7
print("Ejercicio 7")
multiplica <- function(vector1, vector2)
{
  
  n <- length(vector1)
  m <- length(vector2)
  
  if(n != m)
  {
    
    return("Ambos vectores deben ser de la misma longitud")
    
  }
    
  respuesta <- numeric(n)
  
  for(i in 1:n)
  {
    
    respuesta[i] <- vector1[i] * vector2[i]
    
  }
  
  print(respuesta)
  
}

multiplica(c(10, 20), c(3, 4))

#8
print("Ejercicio 8")
cuenta <- function(v, n)
{
  
  l <- length(v)
  r <- 0
  
  for(i in 1:l)
  {
    
    if(v[i] == n)
    {
      
      r <- r + 1 
      
    }
    
  }
  
  print(r)
  
}

cuenta(c(10, 20, 10, 7, 24, 7, 5), 7)

#9
print("Ejercicio 9")
enesimo <- function(v, n)
{
  
  l <- length(v)
  r <- numeric()
  c <- 0
  
  for(i in 1:l)
  {
    
    if(c %% n == 0)
    {
      
      r <- c(r, v[i])
      
    }
    
    c <- c + 1
    
  }
  
  print(r)
  
}

v <- 1:100
enesimo(v, 5)