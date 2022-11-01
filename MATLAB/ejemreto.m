%x = [-2.5:2.5]
%y = [-2.5:2.5]

x = linspace(-2.5,2.5,25)
y = linspace(-2.5,2.5,25)

[X,Y]=meshgrid(x,y)

u = X
v = Y

quiver(X,Y,u,v)
%plot(x,y)