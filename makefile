vy_vs_t.png : rk.py ed1x.txt
	python rk.py

ed1x.txt : rk.x
	./rk.x
	rm rk.x

rk.x : rk.cpp
	c++ rk.cpp -o rk.x

clear :
	rm ed1x.txt ed1y.txt ed32x.txt ed32y.txt ed2x.txt ed2y.txt vy_vs_t.png