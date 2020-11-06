TRASH =  *.so 


all: wrapper.so
wrapper.so: wrapper.c 
	gcc wrapper.c -shared -fPIC -ldl -o wrapper.so

FILE = test
FILEFIX = testFIX

test: wrapper.so
	touch $(FILE)
	touch $(FILEFIX)

	LD_PRELOAD=./wrapper.so rm $(FILE)
	LD_PRELOAD=./wrapper.so rm $(FILEFIX)

	test -f $(FILEFIX)

	rm $(FILEFIX)

clean:
	rm -f $(TRASH)