def lectura_inventario():
    inv = open("inventario.txt", "r") #archivo original
    for line in inv:
        #print(line)
        datosrenglon = line.split()
        lista_inventario.append(datosrenglon)
    for i in range(len(lista_inventario)):
        numero_de_art = lista_inventario[i] #identificador del numero de articulo
        sub_lista_numero.append(numero_de_art[0]) #numero
        sub_lista_nombre.append(numero_de_art[1]) #nombre
        sub_lista_cantidad.append(numero_de_art[2]) #cantidad
    print(sub_lista_numero)
    print(sub_lista_nombre)
    print(sub_lista_cantidad)
    
def ingreso(sub_lista_numero,sub_lista_cantidad):
    lectura_inventario()
    print("Numero de articulo que llego")
    num_art = int(input()) #numero del articulo ingresado
    print("Cantidad de articulos que llegaron")
    cant_art = int(input()) #cantidad de articulos ingresados 
    for x in range(len(sub_lista_numero)): # for para separar los numeros de la lista 
        if num_art == (x+1):
            suma = int(sub_lista_cantidad[x]) + cant_art #suma del factor con inventario ingresado
            del sub_lista_cantidad [x] #borra el factor original
            sub_lista_cantidad.insert(x, suma) #inserta el nuevo valor 
    print(sub_lista_numero)
    print(sub_lista_nombre)
    print(sub_lista_cantidad)

def venta(sub_lista_numero,sub_lista_cantidad):
    lectura_inventario()
    print("Numero de articulo vendido")
    num_art = int(input()) #numero del articulo vendido
    print("Cantidad de articulos vendidos")
    cant_art = int(input()) #cantidad de articulos vendidos
    for x in range(len(sub_lista_numero)): # for para separar los numeros de la lista 
        if num_art == (x+1):
            resta = int(sub_lista_cantidad[x]) - cant_art #resta del factor con inventario ingresado
            del sub_lista_cantidad [x] #borra el factor original
            sub_lista_cantidad.insert(x, resta) #inserta el nuevo valor 
    print(sub_lista_numero)
    print(sub_lista_nombre)
    print(sub_lista_cantidad)
    
def vendedores():
    ven = open("vendedores.txt","r")#archivo original
    for line in ven:
        #print Line
        datosrenglon = line.split()
        lista_vendedores.append(datosrenglon)
    for i in range(len(lista_vendedores)):
        v = lista_vendedores[i]
        sub_lista_name.append(v[0]) #nombre del vendedor
        sub_lista_d1.append(v[1])#articulos vendidos dia 1
        sub_lista_d2.append(v[2])#articulos vendidos dia 2
        sub_lista_d3.append(v[3])#articulos vendidos dia 3
        sub_lista_d4.append(v[4])#articulos vendidos dia 4
        sub_lista_d5.append(v[5])#articulos vendidos dia 5
        sub_lista_d6.append(v[6]) #articulos vendidos dia 6
        sub_lista_d7.append(v[7])#articulos vendidos dia 7
    print(sub_lista_name)
    print(sub_lista_d1)
    print(sub_lista_d2)
    print(sub_lista_d3)
    print(sub_lista_d4)
    print(sub_lista_d5)
    print(sub_lista_d6)
    print(sub_lista_d7)
    
def max_vendedor():
    total = []
    suma = 0
    maximo = 0
    vendedores()
    for i in range(len(sub_lista_name)):
        for j in range(1,(len(lista_vendedores[i]))-1):
            suma = suma + (int(lista_vendedores[i][j]))
        total.append(suma)
        suma = 0
    for k in range(len(total)):
            if total[0] < total[k] :
                print(sub_lista_name[k],"es el/la vendedor@ que vendió más en la semana con:",total[k],"ventas")

    
lista_inventario = [] #lista donde se guardan los datos del archivo .txt de inventario
sub_lista_numero = [] #sublista del numero de articulo
sub_lista_nombre = [] #sublista del nombre del articulo
sub_lista_cantidad = [] #sublista de cantidad del articulo

lista_vendedores = [] #lista donde se guardam los datos del archivo .txt de vendedores
sub_lista_name = [] #sublista del nombre del vendedor
sub_lista_d1 = []#sublista del dia domingo
sub_lista_d2 = []#sublista del dia lunes
sub_lista_d3 = []#sublista del dia martes
sub_lista_d4 = []#sublista del dia miercoles
sub_lista_d5 = []#sublista del dia jueves
sub_lista_d6 = []#sublista del dia viernes
sub_lista_d7 = []#sublista del dia sabado
salir = "No"
lista = ["Menú de Inventario = 0", "Menú de Ingresos = 1", "Menú de Ventas = 2", "Menú de Vendedores = 3", "Máximo Vendedor = 4"]
while salir == "No" or salir == "no":
    lista_inventario = [] #lista donde se guardan los datos del archivo .txt de inventario
    sub_lista_numero = [] #sublista del numero de articulo
    sub_lista_nombre = [] #sublista del nombre del articulo
    sub_lista_cantidad = [] #sublista de cantidad del articulo

    lista_vendedores = [] #lista donde se guardam los datos del archivo .txt de vendedores
    sub_lista_name = [] #sublista del nombre del vendedor
    sub_lista_d1 = []#sublista del dia domingo
    sub_lista_d2 = []#sublista del dia lunes
    sub_lista_d3 = []#sublista del dia martes
    sub_lista_d4 = []#sublista del dia miercoles
    sub_lista_d5 = []#sublista del dia jueves
    sub_lista_d6 = []#sublista del dia viernes
    sub_lista_d7 = []#sublista del dia sabado
    for i in range(len(lista)):
        print(lista[i])
    opcion = int(input())
    if opcion == 0:
        print("Inventario")
        lectura_inventario()
    elif opcion == 1:
        print("Ingresos")
        ingreso(sub_lista_numero,sub_lista_cantidad)
    elif opcion == 2:
        print("Ventas")
        venta(sub_lista_numero,sub_lista_cantidad)
    elif opcion == 3:
        print("Vendedores")
        vendedores()
    elif opcion == 4:
        print("Máximo Vendedor")
        max_vendedor()
    print("¿Desea salir del programa?\nTeclee sí si desea salir del programa o no para continuar")
    salir = str(input())