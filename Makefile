proc=Honeycomb
cc=gcc

$(proc): src/lib/ch.c
	$(cc) src/lib/hyc.c src/lib/ch.c src/lib/eat.c src/lib/encoder.c src/lib/bytecode.c src/lib/contains.c src/lib/errsimp.c src/lib/parse.c src/lib/tokenize.c -o src/bin/ch
install:
	cp src/bin/ch /usr/local/bin/ch
