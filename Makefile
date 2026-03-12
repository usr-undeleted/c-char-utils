compiling:
	echo "use either 'fndchar', 'chchar', for valid funcs"

clean:
	rm -rf fndchar chchar charplc clrchar

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

