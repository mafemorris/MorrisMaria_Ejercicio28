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
vx1 = ed1x[:,2]
y1 = ed1y[:,1]
vy1 = ed1y[:,2]

x32 = ed32x[:,1]
vx32 = ed32x[:,2]
y32 = ed32y[:,1]
vy32 = ed32y[:,2]

x2 = ed2x[:,1]
vx2 = ed2x[:,2]
y2 = ed2y[:,1]
vy2 = ed2y[:,2]

plot(x1,y1, label= "Velocidad y con n=1")
savefig("vy_vs_t.png")
