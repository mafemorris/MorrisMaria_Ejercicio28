from numpy import *
from matplotlib.pylab import *

ed1x = loadtxt("ed1x.txt")
ed1y = loadtxt("ed1y.txt")
ed32x = loadtxt("ed32x.txt")
ed32y = loadtxt("ed32y.txt")
ed2x = loadtxt("ed2x.txt")
ed2y = loadtxt("ed2y.txt")

t = ed1x[:,0]

x1 = ed1x[:,1]
y1 = ed1y[:,1]

x32 = ed32x[:,1]
y32 = ed32y[:,1]

x2 = ed2x[:,1]
y2 = ed2y[:,1]

vx1 = ed1x[:,2]
vy1 = ed1y[:,2]

vx32 = ed32x[:,2]
vy32 = ed32y[:,2]

vx2 = ed2x[:,2]
vy2 = ed2y[:,2]

# figure(figsize=(13,5))
# subplot(1,3,1)
# plot(t,vx1, label = "n=1")
# plot(t,vx32, label = "n=3/2")
# plot(t,vx2, label = "n=2")
# legend()
# title("Vx vs t")

# subplot(1,3,2)
# plot(t,vy1, label = "n=1")
# plot(t,vy32, label = "n=3/2")
# plot(t,vy2, label = "n=2")
# legend()
# title("Vy vs t")

# subplot(1,3,3)
# plot(vx1,vy1, label = "n=1")
# plot(vx32,vy32, label = "n=3/2")
# plot(vx2,vy2, label = "n=2")
# legend()
# title("Vy vs Vx")
# savefig("velocidades.png")

# figure(figsize=(13,5))
# subplot(1,3,1)
# plot(t,x1, label = "n=1")
# plot(t,x32, label = "n=3/2")
# plot(t,x2, label = "n=2")
# legend()
# title("x vs t")

# subplot(1,3,2)
# plot(t,y1, label = "n=1")
# plot(t,y32, label = "n=3/2")
# plot(t,y2, label = "n=2")
# legend()
# title("y vs t")

# subplot(1,3,3)
plot(x1,y1,label = "sin resistencia")
# plot(x32,y32, label = "n=3/2")
plot(x2,y2, label = "con resistencia")
legend()
xlabel("x")
ylabel("y")
title("y vs x")
savefig("posicion.png")
