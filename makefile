posicion.png : rk.py ed1x.txt
	python rk.py
	rm ed1x.txt ed1y.txt ed32x.txt ed32y.txt ed2x.txt ed2y.txt

ed1x.txt : rk.x
	./rk.x
	rm rk.x

rk.x : rk.cpp
	c++ rk.cpp -o rk.x

clear :
	rm posicion.png velocidades.png