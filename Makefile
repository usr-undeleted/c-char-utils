
noflag:
	echo "hello! use either 'fndchar', 'chchar', 'charplc', 'clrchar' or 'strapp' to compile example code."

clean:
	rm -rf fndchar chchar charplc clrchar strapp strtolower

fndchar:
	rm -rf bin/fndchar fndchar
	gcc -I ./src -o ./bin/fndchar src/fndchar.c
	ln -s bin/fndchar fndchar

chchar:
	rm -rf bin/chchar chchar
	gcc -I ./src -o ./bin/chchar src/chchar.c
	ln -s bin/chchar chchar

charplc:
	rm -rf bin/charplc charplc
	gcc -I ./src -o ./bin/charplc src/charplc.c
	ln -s bin/charplc charplc

clrchar:
	rm -rf bin/clrchar clrchar
	gcc -I ./src -o ./bin/clrchar src/clrchar.c
	ln -s bin/clrchar clrchar

strapp:
	rm -rf bin/strapp strapp
	gcc -I ./src -o ./bin/strapp src/strapp.c
	ln -s bin/strapp strapp

strtolower:
	rm -rf bin/strtolower strtolower
	gcc -I ./src -o ./bin/strtolower src/strtolower.c
	ln -s bin/strtolower strtolower
